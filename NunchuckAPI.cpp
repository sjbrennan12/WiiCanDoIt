#include "NunchuckAPI.h"

NunchuckAPI::NunchuckAPI(){
    this->y = 128;
    this->x = 128;
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
    return nunchuck.getJoyY();
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