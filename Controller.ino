/*

Karen Reynaga
Wii Can Do It Project

--------- Controller Program ---------
Bluetooth Communication between two HC-05s

Connections:
HC-05
GND -> GND
VCC -> 5V
RX -> TX
TX -> RX

*/

char input;
char turn;
char horn;

void setup() {
  Serial.begin(38400); 
}

void loop() {
  if(Serial.available() > 0) { 
    input = Serial.read(); 
    Serial.print("Speed: ");
    Serial.println(input);

    turn = Serial.read();
    Serial.print("turn: ");
    Serial.println(turn);

    horn = Serial.read();
    Serial.print("horn: ");
    Serial.println(horn);
  }
  
  delay(1000);
}