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
#define SIZE_OF_MAP 39

using namespace std;

map mymap[SIZE_OF_MAP];

map map0[SIZE_OF_MAP] = {
                 {0,80},
                 {500,70},
                 {1000,60},
                 {1500,55},             
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

map map1[SIZE_OF_MAP] = {
                 {0,80},
                 {100,70},
                 {200,60},
                 {230,55},
                 {1000,50},
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

void LookUp::configure_map(void){
    int variation;
    cout << "enter map number" << endl;
    cin >> variation;
    if(variation == 0)
        memcpy (&mymap, &map0, sizeof (map0));
    else
        memcpy (&mymap, &map1, sizeof (map1));
    
    for(int i = 0; i < 39; i++){
        cout << mymap[i].rpm << " " << mymap[i].sheath << endl;
    }

}

int LookUp::findkey(float key){
    int i = 0;
    int output;
    
    //finding key1
    for(i = 0; i < SIZE_OF_MAP; i++){
        if(key <= mymap[i].rpm)
            break;
    }
    
    if(key == mymap[i].rpm)
           output = mymap[i].sheath;
    else{
    //comparing lower and upper bounds for key1
   
        if((key - mymap[i-1].rpm) > (mymap[i].rpm - key1))
            output = mymap[i].sheath;
    
        else
            output = mymap[i-1].sheath;
    }

    return output;
}
