#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include "Affichage.h"

const char* ssid = "SEAN_BONDON";
const char* password = "123456789";
const String urlStatus = "http://192.168.1.15/status"; 

Affichage monEcran;

float ancienneTemp = -999.0;
float ancienneConsigne = -999.0;
float ancienneTempInterieur = -999.0;
unsigned long dernierScan = 0;

void setup() {
    Serial.begin(115200);
    monEcran.initialiser();
    WiFi.begin(ssid, password);
}

void loop() {
    // Rafraîchissement toutes les 200ms pour plus de fluidité
    if (millis() - dernierScan > 200) { 
        dernierScan = millis();

        if (WiFi.status() == WL_CONNECTED) {
            monEcran.majStatutWifi(true);
            HTTPClient http;
            http.setTimeout(150); // Timeout court pour ne pas bloquer l'écran
            http.begin(urlStatus);
            
            int httpCode = http.GET();
            if (httpCode == HTTP_CODE_OK) {
                JsonDocument doc;
                deserializeJson(doc, http.getString());
                
                float tempActuelle = doc["temp"];     
                float consigneActuelle = doc["setpoint"];
                float tempInterieur = doc["temp_internal"];

                // On rafraîchit l'ambiante si elle bouge de 0.1°C
                if (abs(tempActuelle - ancienneTemp) >= 0.1) {
                    monEcran.mettreAJourAmbiante(tempActuelle);
                    ancienneTemp = tempActuelle;
                }
                
                // On rafraîchit la consigne (vérification stricte)
                if (consigneActuelle != ancienneConsigne) {
                    monEcran.mettreAJourConsigne(consigneActuelle);
                    ancienneConsigne = consigneActuelle;
                }

                // On rafraîchit l'interieur si elle bouge de 0.1°C
                if (abs(tempInterieur - ancienneTempInterieur) >= 0.1) {
                    monEcran.mettreAJourInterieur(tempInterieur);
                    ancienneTempInterieur = tempInterieur;
                }
            }
            http.end();
        } else {
            monEcran.majStatutWifi(false);
        }
    }
}