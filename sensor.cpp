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

float getSheath(){
    float sheath;
    cout << "enter sheath: " << endl;
    cin >> sheath;
    return sheath;
}

