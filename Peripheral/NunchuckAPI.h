#include <WiiChuck.h>

#ifndef _NUNCHUCK_API
#define _NUNCHUCK_API

class NunchuckAPI {

    private:
        Accessory nunchuck;
        int x;
        int y;
        bool isReverse;
        void nunchuckSetup();

    public:
        NunchuckAPI();
        int getSpeed();
        int getTurn();
        bool beepHorn();
        bool emerBreak();
        bool getReverse();
    
};

#endif
