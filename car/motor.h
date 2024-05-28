/***
motor.h
5-10-24
motor.h file for WiiCanDoItProject
Thaddeus Serna
***/
#include <servo.h>
class Motor{
#define Relay 7// relay pin definition 
#define motorPin 9 // motor PWM input
#ifndef MOTOR
#define MOTOR

public:
	Servo link;
	int throttle;
  bool brakeEngaged;
	

//constructor
	Motor();

//methods
	public:
	// PWM output to controller between 1-2 mS 
	void setThrottle(int input);

	int getThrottle();

	// Stops all throttle input 
	void brake();

	// Triggers the relay to swap the A and C motor cables 
	void reverse();

	// Disables the relay
	void forward();


};

#endif
