//
//  main.cpp
//  E-CVT SW
//
//  Created by Daniel Wang on 2020-11-18.
//  Copyright © 2020 Daniel Wang. All rights reserved.
//

#include <iostream>
#include "LookUp.hpp"
#include "pid.hpp"
#define ROWS 21
#define COLS 7
#define MIN_KEY1 1999
#define MAX_KEY2 3601
using namespace std;



int main(void){
    pid test;
    int rpm = 0;
    int measured_sheath = 0;
    int ideal_sheath = 0;
    /*
    while(rpm < 2000){
        rpm = getRPM();
    }
     */
    while(rpm < 3550){
        rpm = getRPM();
        LookUp a(rpm);
        ideal_sheath = a.findkey();
        measured_sheath = getSheath();
        test.pid_task(ideal_sheath, measured_sheath);
        
    }
    while(1){
        rpm = getRPM();
        test.pid_task(3600, rpm);
    }

    
    return 0;
    
}



