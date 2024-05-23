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

*/

int input;
int reverse;
int turn;
int horn;
int brake;

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
  }
  
  if(horn == 1){
    tone(42, 450, 300);
    horn = 0;
  }

  delay(250);
}
