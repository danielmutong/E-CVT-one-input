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


#define MIN_SHEATH 15 // minimum sheath position before limit switch
#define MAX_SHEATH 80 // starting sheath position
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
        if(limitSwitch(getSheath()) == TRUE)
            shutdown();
        
        rpm = getRPM();
        throttle = getThrottle();
        //if full throttle
        if(throttle == 100){
            //using map to find the optimal sheath given a pid in the transient phase
            ideal_sheath = a.findkey(rpm);
            measured_sheath = getSheath();
            cout << "ideal sheath: " << ideal_sheath << " measured sheath:  " << measured_sheath << endl;
            int pid_out = test.pid_task(ideal_sheath, measured_sheath);  //feeding measured sheath and ideal sheath into pid to find the adjustment
            sheath = measured_sheath + pid_out;   //moving sheath based on pid difference
            cout << "new sheath is: " << sheath << endl;
        }
        
        
    }
    
    //Once we get to 3550 rpm, we enter the straight shift phase where we want to keep rpm constant
    while(1){
        if(limitSwitch(getSheath()) == TRUE)
            shutdown();
        
        rpm = getRPM();
        throttle = getThrottle();
        if(throttle == 100 && (rpm) > 3550){
            if(sheath > MIN_SHEATH){ //makes sure sheath position doesnt exceed kill switch limit
                cout << "up shift" << endl;
                motor(100);
                sheath = sheath -  SHIFT_DISPLACEMENT; //used for modelling
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
            sheath = measured_sheath + pid_out; //used for modelling
            cout << "new sheath is: " << sheath << endl;
            
        }
        //down shift linearly
        else if(throttle == 0){
            
            cout << "down shift " << endl;
            motor(-100);
            sheath = sheath + SHIFT_DISPLACEMENT; //used for modelling
            cout << "new sheath is: " << sheath << endl;
        }
        
    }
    return 0;
}



