/***
motor.h
5-10-24
motor.h file for WiiCanDoItProject
Thaddeus Serna
***/

class Motor{

#ifndef MOTOR
#define MOTOR

public:
	
	long throttle;

//constructor
	Motor();

//methods

	void setThrottle(long input);

	long getThrottle();

	void emergencyBrake();	


};

#endif
