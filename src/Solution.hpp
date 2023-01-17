//
//  Solution.hpp
//  task2
//
//  Created by VolkSeriy on 30.10.2022.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Solution_abstract{
    std::vector<long> solution_task;
    std::vector<long> solution_proc;
    
    virtual void set_solution(std::vector<long>, std::vector<long>)  = 0;
    virtual void print_solution() = 0;
    
    
};

#endif /* Solution_hpp */
