#ifndef TimeController _H
#define TimeController _H

#include <Arduino.h>
#include "badobj.h"

class TimeController{
    public:
        void init();

    private: 
        void loadBrain();  
        int getTime();
        void addToBad(badobj bo);
        int checkDistance();
}
#endif
