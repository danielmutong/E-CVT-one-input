//
//  LookUp.cpp
//  E-CVT SW
//
//  Created by Daniel Wang on 2020-11-18.
//  Copyright © 2020 Daniel Wang. All rights reserved.
//

#include "LookUp.hpp"
#include "Table.h"
#include <iostream>
using namespace std;

map mymap[33] = {
    {2000,50},
    {2050,49},
    {2100,48},
    {2150,47},
    {2200,46},
    {2250,45},
    {2300,44},
    {2350,43},
    {2400,42},
    {2450,41},
    {2500,40},
    {2550,39},
    {2600,38},
    {2650,37},
    {2700,36},
    {2750,35},
    {2800,34},
    {2850,33},
    {2900,32},
    {2950,31},
    {3000,30},
    {3050,29},
    {3100,28},
    {3150,27},
    {3200,26},
    {3250,25},
    {3300,24},
    {3350,23},
    {3400,22},
    {3450,21},
    {3500,20},
    {3550,19},
    {3600,18}
    };

int LookUp::findkey(){
    int i = 0;
    int temp1;
    //finding key1
    for(i = 0; i < 33; i++){
        if(key1 <= mymap[i].rpm)
            break;
    }
    
    if(key1 == mymap[i].rpm)
           temp1 = key1;
    else{
    //comparing lower and upper bounds for key1
   
        if((key1 - mymap[i-1].rpm) > (mymap[i].rpm - key1))
            temp1 = mymap[i].rpm;
    
        else
            temp1 = mymap[i-1].rpm;
    }
    
    //finding final output based on key1 and key2
    for(i = 0; i < 33; i++){
        if(mymap[i].rpm == temp1){
            output = mymap[i].sheath;
            break;
        }
    }
    cout << output <<endl;
    return output;
}
