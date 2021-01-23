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
  int throttle = 0;
  float sheath = 0;
 
    //engagement phase
  while(rpm < 3550){
    rpm = getRPM();
    throttle = getThrottle();
      //if full throttle
    if(throttle == 100){
        //using map to find transient
      LookUp a(rpm);
      ideal_sheath = a.findkey();
      measured_sheath = getSheath();
        //moving sheath based on pid difference
      int x = test.pid_task(ideal_sheath, measured_sheath);
      sheath = measured_sheath + x;
      cout << "new sheath is: " << sheath << endl;
    }
      
        
  }
    //set sheath value as placeholder
  sheath = 18;
    //straight shift phase
  while(1){
    rpm = getRPM();
    throttle = getThrottle();
      //upshift linearly
    if(throttle == 100 && (rpm) > 3550){

      cout << "up shift" << endl;
      motor(100);
      sheath = sheath -  0.1;
      cout << "new sheath is: " << sheath << endl;
      
    }
      //load
    else if( (rpm < 3550 && throttle == 100) ){
      int x = test.pid_task(3600, rpm);
      sheath = sheath + x * 0.01; 
      cout << "new sheath is: " << sheath << endl;

    }
      //down shift linearly
    else if(throttle == 0){

      cout << "down shift " << endl;
      motor(-100);
      sheath = sheath + 0.1;
      cout << "new sheath is: " << sheath << endl;
    }
        
  }

    
  return 0;
    
}



