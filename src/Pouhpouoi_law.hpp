//
//  Pouhpouoi_law.hpp
//  task2
//
//  Created by VolkSeriy on 31.10.2022.
//

#ifndef Pouhpouoi_law_hpp
#define Pouhpouoi_law_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

#include "Temperaturelaw.hpp"

class Temperaturelaw_PUBG : public Temperaturelaw_abstract{
//    long int T_0;
//    long int i = 0;
        
public:
    void set_initial_temperature(long temp_out){
        this->T_0 = temp_out;
    };
    void set_itearations(long i_out){
        this->i = i_out;
    }
    long int get_temperature(){
        auto tmp1 = (this->T_0);
        auto tmp2 = (1 + this->i++);
        auto tmp3 = tmp1/tmp2;
        return tmp3;
        return (double) ((this->T_0) * log(1 + this->i))/(1 + this->i++);
    }// here is law ...
    
    
};

#endif /* Pouhpouoi_law_hpp */
