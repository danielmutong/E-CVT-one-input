//
//  sensor.cpp
//  E-CVT SW
//
//  Created by Daniel Wang on 2020-11-21.
//  Copyright © 2020 Daniel Wang. All rights reserved.
//
#include "sensor.hpp"
void motor(float output){
    cout << "motor running" << output << endl;
}


float getRPM(){
    float rpm;
    cout << "enter rpm: " << endl;
    cin >> rpm;
    return rpm;
      
}

float getThrottle(){
    float throttle;
    cout << "enter Throttle: " << endl;
    cin >> throttle;
    return throttle;
}

float getTorque(){
  return 1209.6;
}
