#include "badobj.h"
#include "TimeController.h"
#include <Time.h>  

int begin_time = 0;
TimeController tc;

void setup (){
    Serial.begin(9600);
    
}

void loop(){
    while(!digitalRead(light_pin)){
        if(tc.check()){
            /* turnlighton */
            begin_time = now();
            digitalWrite(light_pin, 1);
        }
    }
    checkForPain();
}

void checkForPain(){
    pain_reading = analogRead(pain_pin);
    if(pain_reading > 200){
        reactPain();
        bad(pain_reading);
    }
}

badobj getBadObj(power){
    long duration = now() - begin_time;
    badobj bo;
    bo.start_time = now() - duration;
    bo.power = power
    bo.duration = duration;
    return bo;
}
void bad(int power){
    badobj bo = getBadObj(power);
    tc.addToBad(bo);
}

void reactPain(){
    digitalWrite(light_pin, 0);
    showPain();
}

void showPain(){
    
}

