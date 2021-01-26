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
#define MIN_SHEATH 15
#define MAX_SHEATH 80
#define SHIFT_DISPLACEMENT 0.1
using namespace std;



int main(void){
    pid test;
    LookUp a;
    int rpm = 0;
    int measured_sheath = 0;
    int ideal_sheath = 0;
    int throttle = 0;
    float sheath = MAX_SHEATH;
    
    //engagement phase
    while(rpm < 3550){
        rpm = getRPM();
        throttle = getThrottle();
        //if full throttle
        if(throttle == 100){
            //using map to find transient
            ideal_sheath = a.findkey(rpm);
            measured_sheath = getSheath();
            cout << "ideal sheath: " << ideal_sheath << " measured sheath:  " << measured_sheath << endl;
            //moving sheath based on pid difference
            int pid_out = test.pid_task(ideal_sheath, measured_sheath);
            sheath = measured_sheath + pid_out;
            cout << "new sheath is: " << sheath << endl;
        }
        
        
    }
    
    //straight shift phase
    while(1){
        rpm = getRPM();
        throttle = getThrottle();
        if(throttle == 100 && (rpm) > 3550){
            if(sheath > MIN_SHEATH){
                cout << "up shift" << endl;
                motor(100);
                sheath = sheath -  SHIFT_DISPLACEMENT;
                cout << "new sheath is: " << sheath << endl;
            }
            
        }
        //load
        else if( (rpm < 3550 && throttle == 100) ){
            cout << "Experiencing Load" << endl;
            ideal_sheath = a.findkey(rpm);
            measured_sheath = getSheath();
            cout << "ideal sheath: " << ideal_sheath << " measured sheath:  " << measured_sheath << endl;
            //moving sheath based on pid difference
            int pid_out = test.pid_task(ideal_sheath, measured_sheath);
            sheath = measured_sheath + pid_out;
            cout << "new sheath is: " << sheath << endl;
            
        }
        //down shift linearly
        else if(throttle == 0){
            
            cout << "down shift " << endl;
            motor(-100);
            sheath = sheath + SHIFT_DISPLACEMENT;
            cout << "new sheath is: " << sheath << endl;
        }
        
    }
    return 0;
}



