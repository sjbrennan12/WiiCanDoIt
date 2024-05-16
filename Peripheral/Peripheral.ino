/*

Karen Reynaga
Wii Can Do It Project

--------- Peripheral Program ---------
Bluetooth Communication between two HC-05s

Connections:
HC-05
GND -> GND
VCC -> 5V
RX -> TX
TX -> RX

*/

#include "NunchuckAPI.h"

NunchuckAPI *nunchuck;
int speed = 0;
int turn = 0;
bool horn = false;

void setup() {
  Serial.begin(38400);
   nunchuck = new NunchuckAPI();
}

void loop() {
  // get data from nunchuck
  speed = nunchuck->getSpeed();
  turn = nunchuck->getTurn();
  horn = nunchuck->beepHorn();

  // temporary -- for debugging
  // speed = 1;
  // turn = 2;
  // horn = 0;
  Serial.print(speed);
  Serial.print(turn);
  Serial.print(horn);

  delay(100);
}
