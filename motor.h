/***
motor.h
5-10-24
motor.h file for WiiCanDoItProject
Thaddeus Serna
***/

class Motor{
#define Relay 7// relay pin definition 

#ifndef MOTOR
#define MOTOR

public:
	
	long throttle;
	

//constructor
	Motor();

//methods
	public:
	// PWM output to controller between 1-2 mS or using arduino relay libary 0-180 degrees
	void setThrottle(long input);

	long getThrottle();

	// Stops all throttle input 
	void emergencyBrake();

	// Triggers the relay to swap the A and C motor cables 
	void reverse();

	// Disables the relay
	void forward();


};

#endif
