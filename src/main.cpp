/*
Simple serial echo program
- blink the green LED every second
- display time since power ON in seconds
- echo characters typed on Serial Monitor

*/

#include <Arduino.h>

#define GREEN      5                    // The Airboard GREEN LED
#define BAUD   57600                    // communication speed: 57600 for XBee, 9600 otherwise

unsigned long time;
boolean flag = true;

// the setup routine runs once when you switch on the board:
void setup() {
  pinMode(GREEN, OUTPUT);             // initialize the GREEN LED pin as an output
  Serial.begin(BAUD);                 // initialize serial communication
}

// the loop routine runs over and over again forever:
void loop() {
  if(millis() - time > 1000) {        // every second
    time = millis();
    analogWrite(GREEN, flag ^= 1);    // blink LED
    Serial.println(time/1000);        // display time in seconds
  }
  
  if(Serial.available())
    Serial.print((char)Serial.read());// echo characters typed on Serial Monitor
}
