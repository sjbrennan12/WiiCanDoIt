#include "steering.h"
#include "motor.h"
#include <Arduino.h>
Steering* wheels;
Motor* myMotor;

int input;
int reverse;
int turn;
int horn;
int brake;

void setup() {
  // put your setup code here, to run once:
  pinMode(steeringPin,OUTPUT);
  pinMode(motorPin, OUTPUT);
  wheels = new Steering();
  myMotor = new Motor();
  myMotor->setThrottle(1000);
  delay(5000);

  Serial.begin(38400); 
  input = 1000;
  reverse = 0;
  turn = 90;
  horn = 0;
  brake = 0;

}

void loop() {



if(Serial.available() > 0) { 

    input = Serial.read() * 10;
    reverse = Serial.read();
    turn = Serial.read();
    horn = Serial.read();
    brake = Serial.read();

    Serial.println(turn);
}

wheels->steerCommand(turn);
if(reverse == 1)
{
  myMotor->reverse();
}
else
{
  myMotor->forward();
}

if(brake == 1)
{
  myMotor->brake();
}
else
{
  myMotor->brakeEngaged = false;
}

myMotor->setThrottle(input);


delay(4);
}




