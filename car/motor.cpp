#include "motor.h"
#include <Arduino.h>
Motor::Motor()
{
  link.attach(motorPin);
  throttle = 1000;
  link.writeMicroseconds(throttle);
  pinMode(Relay,OUTPUT);
  pinMode(motorPin, OUTPUT);
  brakeEngaged = false;
}

int Motor::getThrottle()
{
  return this->throttle;
}

void Motor::setThrottle(int input)
{
  if(input <= 2000 && input >= 1000)
  {
    throttle = input;
    link.writeMicroseconds(input);
    delay(10);
  }
}

void Motor::forward()
{
  digitalWrite(Relay,LOW);
}

void Motor::reverse()
{
  digitalWrite(Relay,HIGH);
}

void Motor::brake()
{
  /***for(int i = 0; i < 5; i++) // send low throttle pulse
  {
  link.writeMicroseconds(1000);
  delay(15);
  }
  ***/
  //go opposite direction


  if(!brakeEngaged){
  brakeEngaged = true;
  digitalWrite(Relay,!digitalRead(Relay));
  delay(300);
  throttle = 1000;
  //go to orginal direction
  digitalWrite(Relay,!digitalRead(Relay));
  }
}

