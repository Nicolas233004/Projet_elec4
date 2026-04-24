
#include <WiFi.h>
#include <WebServer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PID_v1.h>
#include <EEPROM.h>
#include "Timer.h"

#define SEUIL 0.5 // Seuil de tolérance pour l'activation des résistances
#define EEPROM_SIZE 512
#define EEPROM_SETPOINT_ADDR 0 // Adresse EEPROM pour stocker la consigne


// --- CONFIGURATION WI-FI ---
const char* ssid = "SEAN_BONDON";
const char* password = "123456789";

// Définition du serveur sur le port 80
WebServer server(80);

// FreeRTOS PID task
TaskHandle_t pidTaskHandle = NULL;
const TickType_t PID_TASK_DELAY = pdMS_TO_TICKS(50); // 20 Hz task

//PIN GAUCHE
#define ONE_WIRE_BUS_L 15
#define FAN_PIN_L  2
#define RES_PIN_L  12

//PIN DROITE
#define ONE_WIRE_BUS_R 17
#define FAN_PIN_R  4
#define RES_PIN_R  13

//PIN INFO
#define ONE_WIRE_BUS_INFO 16

//TIMER
Timer TempTime(500); // Timer pour la lecture des températures (500ms)
Timer WebTime(500); // Timer pour la gestion du serveur web (500ms)
Timer PIDTime(100); // Timer pour la mise à jour du PID (100ms)

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire_l(ONE_WIRE_BUS_L);
OneWire oneWire_r(ONE_WIRE_BUS_R);
OneWire oneWire_info(ONE_WIRE_BUS_INFO);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors_l(&oneWire_l);
DallasTemperature sensors_r(&oneWire_r);    
DallasTemperature sensors_info(&oneWire_info);


// Parameters for regulation
double Setpoint, Input_l, Output_l, Input_r, Output_r,tempactuelle;

// Parameters Info
float temp_internal ; // Température dans la ruche (capteur info)

// Page statique en flash (AP léger)
const char USER_PAGE[] PROGMEM =
    "<!DOCTYPE html><html><head><meta charset='UTF-8'><title>ESP32 PID AP</title>"
    "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
    "<style>body{font-family:sans-serif;text-align:center;margin-top:20px;} .data{font-size:1.4em; margin:6px;}fieldset{display:inline-block;margin-top:15px;}</style>"
    "<script>"
    "function refreshStatus(){"
    "fetch('/status').then(r=>r.json()).then(d=>{"
    "document.getElementById('temp').textContent=d.temp.toFixed(1);"
    "document.getElementById('tempInternal').textContent=d.temp_internal.toFixed(1);"
    "document.getElementById('setpointDisplay').textContent=d.setpoint.toFixed(1);"
    "document.getElementById('setpointInput').value=d.setpoint.toFixed(1);"
    "}).catch(e=>console.error('status',e));"
    "}"
    "async function setSetpoint(){"
    "const v=document.getElementById('setpointInput').value;"
    "const r=await fetch('/setpoint?value='+encodeURIComponent(v));"
    "if(r.ok){document.getElementById('message').textContent='Consigne mise à jour';refreshStatus();}else{document.getElementById('message').textContent='Erreur';}"
    "return false;}"
    "window.onload=function(){refreshStatus();setInterval(refreshStatus,2000);};"
    "</script>"
    "</head><body>"
    "<h1>ESP32 PID (AP)</h1>"
    "<div class='data'>Température régulation : <strong id='temp'>--</strong> °C</div>"
    "<div class='data'>Température intérieure : <strong id='tempInternal'>--</strong> °C</div>"
    "<div class='data'>Consigne : <strong id='setpointDisplay'>--</strong> °C</div>"
    "<fieldset><legend>Modifier consigne</legend>"
    "<form onsubmit='return setSetpoint();'>"
    "<input id='setpointInput' type='number' step='0.1' min='10' max='50' value='30.0'> "
    "<button type='submit'>Appliquer</button>"
    "</form>"
    "<div id='message' style='margin-top:8px;color:green;'></div>"
    "</fieldset>"
    "</body></html>";

void resetTEmperature() {
    sensors_info.begin();
    sensors_l.begin();
    sensors_r.begin();
    Serial.println("Capteurs réinitialisés");
}

// Fonctions EEPROM pour sauvegarder/charger la consigne
void saveSetpointToEEPROM(double setpoint) {
    EEPROM.put(EEPROM_SETPOINT_ADDR, setpoint);
    EEPROM.commit();
    Serial.print("Consigne sauvegardée en EEPROM: ");
    Serial.println(setpoint);
}

double loadSetpointFromEEPROM() {
    double setpoint = 0.0;
    EEPROM.get(EEPROM_SETPOINT_ADDR, setpoint);
    // Vérification que la valeur est valide
    if (setpoint < 10.0 || setpoint > 50.0) {
        setpoint = 35.0; // Valeur par défaut
    }
    Serial.print("Consigne chargée de l'EEPROM: ");
    Serial.println(setpoint);
    return setpoint;
}


// --- Fonctions de lecture et PID ---

double readTemperature(DallasTemperature sensors, int index) {
    sensors.requestTemperatures(); 
    double val = 0;
    // ATTENTION : Assurez-vous d'avoir réellement 3 capteurs pour cette moyenne
    val += sensors.getTempCByIndex(index);
    //val += sensors.getTempCByIndex(2);

    //for (int sensorIndex = 0; sensorIndex < 3; sensorIndex++) { 
    //    val += sensors.getTempCByIndex(sensorIndex); 
    //}
    //val /= 2.0; // Moyenne des températures lues
    if (val == -127.0) resetTEmperature(); // Cas d'erreur de lecture, tentative de réinitialisation
    Serial.print("Temp Moyenne: ");
    Serial.println(val);
    return val;
}

void RESpwmWrite(int output, int pin) {
    int offset = 20; // Car 50/50 != 15V
    int time1 = map(output, 0, 255, 0, 100) - offset; // Temps HIGH
    if (time1 <= 0) time1 = 5;
    int time2 = 100 - time1 + offset;                 // Temps LOW

    digitalWrite(pin, HIGH);
    delay(time1);
    digitalWrite(pin, LOW);
    delay(time2);
}

void PID_update() {

    temp_internal = readTemperature(sensors_info, 0);
    Input_r = readTemperature(sensors_r, 2);
    Input_l = readTemperature(sensors_r , 2); // ATTENTION : même capteur que droite pour test, à corriger si besoin
    tempactuelle = (Input_l + Input_r) / 2.0;
    if (Input_r < (Setpoint - SEUIL) ) digitalWrite(RES_PIN_L, HIGH);
    else digitalWrite(RES_PIN_L, LOW);
    if (Input_l < (Setpoint - SEUIL) ) digitalWrite(RES_PIN_R, HIGH);
    else digitalWrite(RES_PIN_R, LOW);


    //PID_hot_l.Compute();
    //PID_hot_r.Compute();
    //if (Output_l > 20) digitalWrite(RES_PIN_L, HIGH); 
    //else digitalWrite(RES_PIN_L, LOW);
    //if (Output_r > 20) digitalWrite(RES_PIN_R, HIGH); 
    //else digitalWrite(RES_PIN_R, LOW);
    
}

void PIDTask(void *parameter) {
    while (true) {
        if (TempTime.isElapsed()) {
            PID_update();
            TempTime.reset();
        }

        // On retire la réinitialisation AP automatique ici :
        // ce comportement provoque des resets s'il est exécuté à répétition.
        // Si l'AP reste stable, aucune reconfiguration nécessaire dans la task PID.

        vTaskDelay(PID_TASK_DELAY);
    }
}

// --- Fonctions de gestion du Serveur Web ---

// Passage à une page statique plus légère (en flash)
void handleUserPage() {
    server.send_P(200, "text/html", USER_PAGE);
}

// Route JSON de statut léger pour l'AP Wi-Fi
void handleStatus() {
    char json[128];
    int len = snprintf(json, sizeof(json),
        "{\"temp\":%.1f,\"temp_internal\":%.1f,\"setpoint\":%.1f,\"input_l\":%.1f,\"input_r\":%.1f,\"output_l\":%.1f,\"output_r\":%.1f}",
        tempactuelle, temp_internal, Setpoint, Input_l, Input_r, Output_l, Output_r);
    if (len < 0) {
        server.send(500, "application/json", "{\"error\":\"format_error\"}");
        return;
    }
    server.send(200, "application/json", json);
}


void handleSetPoint() {
    if (server.hasArg("value")) {
        float nouvelleConsigne = server.arg("value").toFloat();
        if (nouvelleConsigne >= 10.0 && nouvelleConsigne <= 50.0) {
            Setpoint = (double)nouvelleConsigne;
            saveSetpointToEEPROM(Setpoint); // Sauvegarder dans l'EEPROM
            Serial.print("Consigne mise à jour : ");
            Serial.println(Setpoint);
            server.send(200, "text/plain", "ok");
            return;
        }
    }
    server.send(400, "text/plain", "bad_request");
}


void setup(void)
{
    setCpuFrequencyMhz(80); // Réduction de la fréquence pour économiser de l'énergie et éviter les reset
    
    // Initialisation Série
    Serial.begin(9600);    

    // Configuration des PINS
    pinMode(FAN_PIN_L, OUTPUT);
    pinMode(FAN_PIN_R, OUTPUT);
    pinMode(RES_PIN_L, OUTPUT);
    pinMode(RES_PIN_R, OUTPUT);

    // Démarrage des capteurs
    sensors_l.begin();
    sensors_r.begin();
    sensors_info.begin();

    
    // --- 1. Démarrage du WIFI en mode Access Point ---
    // Initialisation des variables de température
    temp_internal = 0.0;
    Input_l = 0.0;
    Input_r = 0.0;
    tempactuelle = 0.0;
    
    WiFi.disconnect(true); // déconnecter éventuellement STA et nettoyer le stack
    delay(100);
    WiFi.mode(WIFI_AP); // mode AP explicite pour limitation du stack
    IPAddress local_ip(192,168,1,15);
    IPAddress gateway(192,168,1,1);
    IPAddress subnet(255,255,255,0);
    WiFi.softAPConfig(local_ip, gateway, subnet); // IP fixe en AP
    WiFi.softAP(ssid, password);

    // Forte stabilité Wi-Fi : éviter le power-save AP qui coupe le stack
    WiFi.setSleep(false);

    // Affichage debug (peut être commenté si reset fréquent)
    Serial.println("Point d'accès Wi-Fi démarré!");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.softAPIP()); 
    
    // --- 2. Configuration du Serveur Web ---
    server.on("/", HTTP_GET, handleUserPage);      // Page Utilisateur (Lecture Seule)
    server.on("/status", HTTP_GET, handleStatus);  // Statut allégé JSON
    server.on("/setpoint", HTTP_GET, handleSetPoint);  // Modification de la consigne
    server.begin();
    Serial.println("Serveur Web démarré."); 
    
    // --- 3. Démarrage du PID ---
    EEPROM.begin(EEPROM_SIZE); // Initialiser l'EEPROM
    Setpoint = loadSetpointFromEEPROM(); // Charger la consigne de l'EEPROM
    analogWrite(FAN_PIN_L, 200);
    analogWrite(FAN_PIN_R, 200);

    // Timer
    TempTime.start();
    WebTime.start();

    // Création tâche PID sur core 1 (gestion régulation)
    xTaskCreatePinnedToCore(
        PIDTask,
        "PIDTask",
        4096,
        NULL,
        2,
        &pidTaskHandle,
        1); // core 1

    Serial.println("Start loop");
}


void loop() {
    
    if (WebTime.isElapsed()) {
        server.handleClient(); // Gérer les requêtes web
        WebTime.reset();
    }

    // la lecture capteur + PID est maintenant dans PIDTask sur core 1
    // inutile de refaire ici

    // Watchdog/mémoire : reconf AP si rien connecté > 30s
    static unsigned long lastNoClientMs = 0;
    if (WiFi.softAPgetStationNum() == 0) {
        if (lastNoClientMs == 0) lastNoClientMs = millis();
        else if (millis() - lastNoClientMs > 30000) {
            WiFi.softAPdisconnect(true);
            WiFi.mode(WIFI_OFF);
            delay(100);
            WiFi.mode(WIFI_AP);
            WiFi.softAPConfig(IPAddress(192,168,1,15), IPAddress(192,168,1,1), IPAddress(255,255,255,0));
            WiFi.softAP(ssid, password);
            WiFi.setSleep(false);
            lastNoClientMs = 0;
        }
    } else {
        lastNoClientMs = 0;
    }
}

