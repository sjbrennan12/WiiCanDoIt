/***
steering.h
5-15-24
Jack Liam Brennan
***/
#include <Servo.h>	
class Steering{


#ifndef STEERING
#define STEERING
#define steeringPin 10

int steeringAngle;
Servo frontWheels;
public:
//constructor
	Steering();

//methods
    // PWM signal 1-2 mS or 0-180 degrees. Center is 90 degrees. 
    void steerCommand(int angle);
    // Return current steering PWM setting
    int getAngle();
};

#endif