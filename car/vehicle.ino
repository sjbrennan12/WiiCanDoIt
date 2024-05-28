#include <Arduino.h>
#include "motor.h"
#include "SR04.h"
#include "steering.h"

Steering* wheels;
Motor* myMotor;

#define SPEAKER_PIN 3
#define TRIG_PIN 11
#define ECHO_PIN 10

long distance;
uint8_t i;
int input;
int reverse;
int turn;
int horn;
int brake;

void setup() {
  SR04 distanceSensor = SR04(ECHO_PIN,TRIG_PIN);
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

  distance = distanceSensor.DistanceAvg(70, 15);
  if (distance < 80) {
    for (i = 0; i < 15; i++) {
      tone(SPEAKER_PIN, 450, 50);
      delay(distance / 6.0);
    }
  }

  delay(4);
}
