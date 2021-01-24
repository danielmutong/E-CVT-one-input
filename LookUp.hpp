//
//  LookUp.hpp
//  E-CVT SW
//
//  Created by Daniel Wang on 2020-11-18.
//  Copyright © 2020 Daniel Wang. All rights reserved.
//

#ifndef LookUp_hpp
#define LookUp_hpp

#include <iostream>
#include "Table.h"
class LookUp {
private:
    float output;
    float key1;

public:
    LookUp(){}
    ~LookUp(){};
    
    int findkey(float key);
};

#endif /* LookUp_hpp */
