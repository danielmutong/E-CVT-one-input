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
#define MAX_KEY1 2501
#define MAX_KEY2 101
using namespace std;



int main(void){
    pid test;
    while(1){
        float key1 = 0;
        float key2 = 0;
        float value = 0;
        float sensor_value = 0;
        key1 = getRPM();
        key2 = getThrottle();
        cout << "key 1 is " << key1 << " and key 2 is " << key2 << endl;
        if((key1 < 0) || (key1 > MAX_KEY1) || (key2 < 0) || (key2 > MAX_KEY2))
            cout << "key out of range" << endl;
        else{
            LookUp a(key1, key2);
            value = a.findkey();
            cout << "output is: " << value << endl;
            sensor_value = getTorque();
            test.pid_task(value, sensor_value);

        }
    }

    
    return 0;
    
}



