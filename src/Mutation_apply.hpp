//
//  Mutation_apply.hpp
//  task2
//
//  Created by VolkSeriy on 30.10.2022.
//

#ifndef Mutation_apply_hpp
#define Mutation_apply_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>     /* srand, rand */
#include <ctime>

#include "Mutation.hpp"

class Mutation_apply : Mutation_abstract{
public:
    static void mutate(std::vector<long> &tasks, std::vector<long> &proc, long number_proc){
        long tmp1 = (long) rand() % tasks.size();
        long tmp2 = (long) rand() % tasks.size();
        long tmp3 = (long) rand() % number_proc + 1;
        long tmp4 = (long) rand() % number_proc + 1;
        std::swap(tasks[tmp1], tasks[tmp2]);
        proc[tmp1] = tmp3;
        proc[tmp2] = tmp4;
    };
};


#endif /* Mutation_apply_hpp */
