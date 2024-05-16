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
char input2;
char input3;
char turn;
char turn2;
char horn;

void setup() {
  Serial.begin(38400); 
}

void loop() {
  if(Serial.available() > 0) { 
    input = Serial.read();
    input2 = Serial.read();
    input3 = Serial.read(); 
    Serial.print("Speed: ");
    Serial.print(input);
    Serial.print(input2);
    Serial.println(input3);

    turn = Serial.read();
    turn2 = Serial.read();
    Serial.print("turn: ");
    Serial.print(turn);
    Serial.println(turn2);

    horn = Serial.read();
    Serial.print("horn: ");
    Serial.println(horn);
  }
  
  delay(1000);
}