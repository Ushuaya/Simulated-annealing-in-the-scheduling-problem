//
//  Temperaturelaw.hpp
//  task2
//
//  Created by VolkSeriy on 30.10.2022.
//

#ifndef Temperaturelaw_hpp
#define Temperaturelaw_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Temperaturelaw_abstract{
protected:
    long int T_0;
    long int i = 0;
public:
    virtual void set_initial_temperature(long) = 0;
    virtual void set_itearations(long) = 0;
    virtual long int get_temperature() = 0; // here is law ...
    
    
};

#endif /* Temperaturelaw_hpp */
