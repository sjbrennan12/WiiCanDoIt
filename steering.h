/***
steering.h
5-15-24
Jack Liam Brennan
***/

class steering{


#ifndef STEERING
#define STEERING
#define steeringPin = 5;
public:
	
	int steeringAngle;
	

//constructor
	steering();

//methods
    // PWM signal 1-2 mS or 0-180 degrees. Center is 90 degrees. 
    void steering::steerCommand(int angle);
    // Return current steering PWM setting
    int steering::getAngle();
};

#endif