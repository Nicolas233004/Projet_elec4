#include "timer.h"
#include <OneWire.h>
#include <DallasTemperature.h>


// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 15

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();

}

float readTemperature(int sensorIndex) {
  sensors.requestTemperatures(); // Lance la conversion des températures
  float val = sensors.getTempCByIndex(sensorIndex); // Retourne la température du capteur spécifié
#ifdef DEBUG
  Serial.print("Capteur ");
  Serial.print(sensorIndex);
  Serial.print(" : ");
  Serial.print(val);
  Serial.println(" °C");
#endif // DEBUG
  return val;
}


void loop() {
  for (int i = 0; i < sensors.getDeviceCount(); i++) {
    readTemperature(i); // Lire et afficher la température de chaque capteur
  }

  delay(1000); // Attente d'une seconde avant de lire à nouveau les capteurs
}
