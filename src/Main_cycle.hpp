//
//  Main_cycle.hpp
//  task2
//
//  Created by VolkSeriy on 30.10.2022.
//

#ifndef Main_cycle_hpp
#define Main_cycle_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <cmath>

#include "Temperaturelaw.hpp"
#include "Koshi_law.hpp"
#include "Bolcman_law.hpp"
#include "Pouhpouoi_law.hpp"
#include "Mutation_apply.hpp"



class Main_cycle{
public:
    static long compute_the_good(std::vector <long> tasks, std::vector <long> task_proc, std::map <long, long> task_time, long number_proc){
        long min_time = 0;
        for (auto const& x : task_time)
        {
            min_time += x.second;
        }
        long max_time = 0;
        
        for ( long i = 1; i < number_proc + 1; i++){
            long local_time = 0;
            for (long j = 0; j < task_proc.size(); j++ ){
                if (task_proc[j] == i){
                    local_time += task_time[tasks[j]];
                }
            }
            if (local_time >= max_time)
                max_time = local_time;
            if (local_time <= min_time)
                min_time = local_time;
        }
        
        return max_time - min_time;
    }
    
    std::tuple< std::vector <long>,  std::vector <long> > main_cycle(std::vector <long> tasks, std::vector <long> task_proc, std::map <long, long> task_time, long number_proc){
        long i = 1;
        long T0 = 1000;
        long T_minimal = 40;
        std::vector <long> best_tasks = tasks;
        std::vector <long>  best_task_proc = task_proc;
        
//
//        Temperaturelaw_koshi Specified_law;
//        Temperaturelaw_bolcman Specified_law;
        Temperaturelaw_PUBG Specified_law;
        // Declare two pointers, one of type Derived * and the other
        //  of type Base *, and initialize them to point to aDerived.
        //Derived *pDerived = &aDerived;
        Temperaturelaw_abstract* T_controller = &Specified_law;
        // Call the functions.
//        pBase->NameOf();           // Call virtual function.
//        pBase->InvokingClass();    // Call nonvirtual function.
//        pDerived->NameOf();        // Call virtual function.
//        pDerived->InvokingClass(); // Call nonvirtual function.
//
        
        //Temperaturelaw_koshi T_controller = Temperaturelaw_koshi();
        T_controller->set_initial_temperature(T0);
        T_controller->set_itearations(i);
        auto cur_temp = T_controller->get_temperature();
        while (cur_temp > T_minimal){
            std::vector <long> prev_tasks = tasks;
            std::vector <long> prev_task_proc = task_proc;

            Mutation_apply::mutate(tasks, task_proc, number_proc);
            auto cur_good = compute_the_good(tasks, task_proc, task_time, number_proc);
            //std::cout << cur_good << std::endl;
            if (!(cur_good < compute_the_good(prev_tasks, prev_task_proc, task_time, number_proc))){ // probability case
                double prob = exp(-(double)cur_good / (double)cur_temp);
                if (!((rand()/RAND_MAX) > prob)){
                    tasks = prev_tasks;
                    task_proc = prev_task_proc;
                }
            }
            
            if (compute_the_good(tasks, task_proc, task_time, number_proc) < compute_the_good(best_tasks, best_task_proc, task_time, number_proc)){
                best_tasks = tasks;
                best_task_proc = task_proc;
            }
            cur_temp = T_controller->get_temperature();
        }
        
        return std::make_tuple(best_tasks, best_task_proc);
        
        
    };
    
    
};

#endif /* Main_cycle_hpp */
