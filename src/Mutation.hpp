//
//  Mutation.hpp
//  task2
//
//  Created by VolkSeriy on 30.10.2022.
//

#ifndef Mutation_hpp
#define Mutation_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Mutation_abstract{
    virtual  std::tuple<std::vector<long>, std::vector<long>> mutate(std::vector<long> tasks,  std::vector<long> proc, long number_proc) = 0;
};

#endif /* Mutation_hpp */
