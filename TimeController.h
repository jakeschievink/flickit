#include <Arduino.h>

class TimeController{
    public:
        void init();

    private: 
        void loadBrain();  
        int getTime();
        void addToGoodList();
        void addToBadList();
        int checkDistance();
}
