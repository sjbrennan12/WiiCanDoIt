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
int reverse = 0;

void setup() {
  Serial.begin(38400);
   nunchuck = new NunchuckAPI();
}

void loop() {
  // get data from nunchuck
  speed = nunchuck->getSpeed();
  reverse = (int) nunchuck->getReverse();
  turn = nunchuck->getTurn();
  horn = (int)nunchuck->beepHorn();
  brake = (int)nunchuck->emerBreak();

  Serial.write(speed);
  Serial.write(reverse);
  Serial.write(turn);
  Serial.write(horn);
  Serial.write(brake);

  delay(250);
}
