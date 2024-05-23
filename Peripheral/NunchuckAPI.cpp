#include "NunchuckAPI.h"

NunchuckAPI::NunchuckAPI(){
    this->y = 128;
    this->x = 128;
    this->isReverse = false;
    nunchuckSetup();
}

void NunchuckAPI::nunchuckSetup(){
  nunchuck.begin();
	if (nunchuck.type == Unknown) {
		nunchuck.type = NUNCHUCK;
	}
}

int NunchuckAPI::getSpeed(){
  nunchuck.readData();

  y = nunchuck.getJoyY();
  if(y >= 128){
    this->isReverse = false;
    return map(y, 128, 255, 100, 130);
  }
  else {
    this->isReverse = true;
    return map(y, 128, 0, 100, 130);
  }
}

bool NunchuckAPI::getReverse(){
  return this->isReverse;
}

int NunchuckAPI::getTurn(){
    nunchuck.readData();
    x = nunchuck.getJoyX();
    return map(x, 0, 255, 0, 180);
}

bool NunchuckAPI::beepHorn(){
    nunchuck.readData();
    return nunchuck.getButtonC();
}

bool NunchuckAPI::emerBreak(){
    nunchuck.readData();
    return nunchuck.getButtonZ();
}