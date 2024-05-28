#include "steering.h"
#include <Arduino.h>
Steering::Steering()
{
steeringAngle = 90;
frontWheels.attach(steeringPin);
frontWheels.write(steeringAngle);
}

void Steering::steerCommand(int angle)
{
if(angle >= 0 && angle <= 180)
{
  if(steeringAngle < angle)
  {
    steeringAngle ++; 
    //delay(0.01);
  }
  else if(steeringAngle > angle)
  {
    steeringAngle --;
    //delay(0.01);
  }
  frontWheels.write(steeringAngle);
}
}

int Steering::getAngle()
{
return this->steeringAngle;
}

