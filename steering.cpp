#include "steering.h"

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
  steeringAngle = angle;
  frontWheels.write(steeringAngle);
}
}

int Steering::getAngle()
{
return this->steeringAngle;
}

