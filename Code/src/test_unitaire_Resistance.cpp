/*#include "timer.h"

#define RES_GAUCHE_PIN  12
#define RES_DROITE_PIN  13


void setup(void)
{
    // start serial port
    Serial.begin(9600);
    pinMode(RES_GAUCHE_PIN, OUTPUT);
    pinMode(RES_DROITE_PIN, OUTPUT);  
    Serial.println("Test unitaire resistance");
    
}


void loop() {
    // check for serial commands to control the resistances
    if (Serial.available()) {
        String cmd = Serial.readStringUntil('\n');
        cmd.trim();               // remove whitespace
        cmd.toUpperCase();        // make command case-insensitive

        if (cmd == "ON") {
            digitalWrite(RES_GAUCHE_PIN, HIGH);
            digitalWrite(RES_DROITE_PIN, HIGH);
            Serial.println("Resistance ON");
        } else if (cmd == "OFF") {
            digitalWrite(RES_GAUCHE_PIN, LOW);
            digitalWrite(RES_DROITE_PIN, LOW);
            Serial.println("Resistance OFF");
        } else if (cmd == "LON") {
            digitalWrite(RES_GAUCHE_PIN, HIGH);
            Serial.println("Left resistance ON");
        } else if (cmd == "LOFF") {
            digitalWrite(RES_GAUCHE_PIN, LOW);
            Serial.println("Left resistance OFF");
        } else if (cmd == "RON") {
            digitalWrite(RES_DROITE_PIN, HIGH);
            Serial.println("Right resistance ON");
        } else if (cmd == "ROFF") {
            digitalWrite(RES_DROITE_PIN, LOW);
            Serial.println("Right resistance OFF");
        } else {
            Serial.print("Unknown command: ");
            Serial.println(cmd);
            Serial.println("Use ON, OFF, LON, LOFF, RON or ROFF");
        }
    }

    // keep a small delay so loop doesn't spin too fast
    delay(100);
}
*/
