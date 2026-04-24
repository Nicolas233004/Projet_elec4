/*
#include "timer.h"



#define FAN_GAUCHE_PIN  2
#define FAN_DROITE_PIN  4


void setup(void)
{
    // start serial port
    Serial.begin(9600);
    pinMode(FAN_GAUCHE_PIN, OUTPUT);
    pinMode(FAN_DROITE_PIN, OUTPUT);  
    Serial.println("Test unitaire Fan");


}


void loop() {
  for (int i = 0; i < 255; i+=5) {
    //analogWrite(FAN_GAUCHE_PIN, 127);
    analogWrite(FAN_GAUCHE_PIN, i);
    analogWrite(FAN_DROITE_PIN, i);
    Serial.print("Vitesse ventilateurs : ");
    Serial.println(i);
    delay(200);
  }
  delay(2000);
}
*/