//
//  main.cpp
//  task2
//
//  Created by VolkSeriy on 29.10.2022.
//

#include <iostream>
#include <numeric>
#include <utility>
#include <chrono>


#include "./src/Main_cycle.hpp"
#include "./src/Input_generator.hpp"

void write_to_xml(long q_tasks, long number_proc, std::map <long, long> task_time){
    std::vector<long> outfile_time;
    for(std::map <long, long>::iterator it = task_time.begin(); it != task_time.end(); ++it ) {
        outfile_time.push_back( it->second );
    }
    Input_generator::write_xml(q_tasks, number_proc, outfile_time);
}

void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<double>>> dataset){
    // Make a CSV file with one or more columns of integer values
    // Each column of data is represented by the pair <column name, column data>
    //   as std::pair<std::string, std::vector<int>>
    // The dataset is represented as a vector of these columns
    // Note that all columns should be the same size
    
    // Create an output filestream object
    std::ofstream myFile(filename);
    
    // Send column names to the stream
    for(int j = 0; j < dataset.size(); ++j)
    {
        myFile << dataset.at(j).first;
        if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
    }
    myFile << "\n";
    
    // Send data to the stream
    for(int i = 0; i < dataset.at(0).second.size(); ++i)
    {
        for(int j = 0; j < dataset.size(); ++j)
        {
            myFile << dataset.at(j).second.at(i);
            if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }
    
    // Close the file
    myFile.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    srand (time(NULL));
    std::cout << "Hello, World!\n";
    
    
//------------------WRITING-------TO-------XML-------------------

    //long number_proc = 3;
    //long number_tasks = 7;
//    std::vector <long> tasks = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
//    auto task_proc = std::vector<long>(tasks.size(), 1);
//    std::map <long, long> task_time;
//    for (long i = 1; i <= tasks.size(); i++){
//        task_time[i] = i;
//    }
//    write_to_xml(tasks.size(), number_proc, task_time);
    
//---------------------------------------------------------------

    
//------------------------READING-------XML----------------------
//    auto tuple_read = Input_generator::read_xml("generator.txt"); // quan_tasks, quan_proc, task_time
//    std::vector<long> tasks((long) std::get<0>(tuple_read));
//    std::iota(tasks.begin(), tasks.end(), 1);
//
//    long number_proc = (long) std::get<1>(tuple_read);
//
//    std::map <long, long> task_time = std::get<2>(tuple_read);
//
//    auto task_proc = std::vector<long>(tasks.size(), 1);
    
//---------------------------------------------------------------
    
    
//------------------RUNNING----------ALGO------------------------
    
//    auto result = Main_cycle().main_cycle(tasks, task_proc, task_time, number_proc);
//    std::cout << Main_cycle::compute_the_good(std::get<0>(result), std::get<1>(result), task_time, number_proc) << std::endl;
    
//---------------------------------------------------------------

//------------------WRITING-------TO-------CSV-------------------

    std::vector<double> vec_task_number;
    std::vector<double> vec_proc_number;
    std::vector<double> vec_work_time;


    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    
    for (long number_proc = 1; number_proc < 20;  number_proc ++)
        for (long number_tasks = 10; number_tasks < 500; number_tasks+=20){
            std::map <long, long> task_time;
            for (int i = 1; i <= number_tasks; i++){
                int b = rand() % 20 + 1;
                //task_time.push_back(b);
                task_time[i] = b;
            }
            std::vector<long> tasks((long) number_tasks);
            std::iota(tasks.begin(), tasks.end(), 1);
            
            auto task_proc = std::vector<long>(tasks.size(), 1);
            
            auto t1 = high_resolution_clock::now();
            
            auto result = Main_cycle().main_cycle(tasks, task_proc, task_time, number_proc);
            
            auto t2 = high_resolution_clock::now();

            /* Getting number of milliseconds as a double. */
            duration<double, std::milli> ms_double = t2 - t1;
            
            vec_task_number.push_back((double)number_tasks);
            vec_proc_number.push_back((double)number_proc);
            vec_work_time.push_back((double)ms_double.count());
            
        }
        //-----ALGO-----
        
    
        
        // Wrap into a vector
        std::vector<std::pair<std::string, std::vector<double>>> vals = {{"Tasks_number", vec_task_number}, {"Proc_number", vec_proc_number}, {"Time_work", vec_work_time}};
        
        // Write the vector to CSV
        write_csv("three_cols.csv", vals);
    
//---------------------------------------------------------------
    
    
    
    //std::map <long, long> task_time = {{1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}};
    
    
    
    //auto result2 = result;
    
    

    
    
    return 0;
}
