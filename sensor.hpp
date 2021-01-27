//
//  sensor.hpp
//  E-CVT SW
//
//  Created by Daniel Wang on 2020-11-21.
//  Copyright © 2020 Daniel Wang. All rights reserved.
//

#ifndef sensor_hpp
#define sensor_hpp
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 Used to send signal to motor, currently just printing
 */
void motor(float output);

/*
 This function is used to read the RPM from a sensor
 */
float getRPM();

/*
 This function is used to read the primary sheath position from a sensor
 */
float getSheath();

/*
 This function is used to read the current throttle position from a sensor
 */
int getThrottle();




#endif /* sensor_hpp */
