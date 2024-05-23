/*

Karen Reynaga, Noa Uritsky
Wii Can Do It Project

--------- Controller Program ---------
Bluetooth Communication between two HC-05s


Connections:
HC-05
GND -> GND
VCC -> 5V
RX -> TX
TX -> RX

Speaker
GND -> GND
DIGITAL -> 42

HC-SR04
VCC -> 5V
TRIG ->
ECHO ->
GND -> GND
*/

#include "SR04.h"

#define SPEAKER_PIN 42
#define TRIG_PIN 49
#define ECHO_PIN 51

SR04 distanceSensor = SR04(ECHO_PIN,TRIG_PIN);

int input;
int reverse;
int turn;
int horn;
int brake;
long distance;
char start;


void setup() {
  Serial.begin(38400); 
}

void loop() {
  if(Serial.available() > 0) { 

    input = Serial.read() * 10;
    reverse = Serial.read();
    turn = Serial.read();
    horn = Serial.read();
    brake = Serial.read();


    Serial.print("Speed: ");
    Serial.println(input);

    Serial.print("Reverse: ");
    Serial.println(reverse);
    
    Serial.print("Turn: ");
    Serial.println(turn);
    
    Serial.print("Horn: ");
    Serial.println(horn);

    Serial.print("Brake: ");
    Serial.println(brake);
    
    distance = distanceSensor.Distance();
    Serial.print("Distance CM: ");
    Serial.println(distance);
    

    if (horn == 1) {
      tone(SPEAKER_PIN, 450, 300);
      horn = 0;
    }

  }
  
  delay(100);
}
