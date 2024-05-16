/*

Karen Reynaga, Noa Uritsky
Wii Can Do It Project

--------- Peripheral Program ---------
Bluetooth Communication between two HC-05s

Connections:
HC-05
GND -> GND
VCC -> 5V
RX -> TX
TX -> RX

Nunchuck to Mega
SDA -> SDA
SCL -> SCL
GND -> GND
VIN -> 5V

*/

#include "NunchuckAPI.h"

NunchuckAPI *nunchuck;
int speed = 0;
int turn = 0;
int horn = 0;
int brake = 0;

void setup() {
  Serial.begin(38400);
   nunchuck = new NunchuckAPI();
}

void loop() {
  // get data from nunchuck
  speed = nunchuck->getSpeed();
  turn = nunchuck->getTurn();
  horn = (int)nunchuck->beepHorn();
  brake = 0; // TODO: implement brake on nunchuck api

  Serial.write(speed);
  Serial.write(turn);
  Serial.write(horn);
  Serial.write(brake);

  delay(250);
}
