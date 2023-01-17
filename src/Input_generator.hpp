//
//  Input_generator.hpp
//  task2
//
//  Created by VolkSeriy on 31.10.2022.
//

#ifndef Input_generator_hpp
#define Input_generator_hpp
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

#include "../rapidxml-1.13/rapidxml.hpp"



class Input_generator{
public:
//    static std::tuple<long, long, std::vector<long>> read_xml(std::string filename){
//
//    }
    
    static void write_xml(long q_task, long q_proc, std::vector<long> task_time){
        std::ofstream myfile;
        myfile.open ("generator.txt", std::fstream::in | std::fstream::out | std::fstream::trunc);
        if (!myfile){
            std::cout << "Cannot create file, file does not exist. Creating new file..\n";
            exit(1);
        }
        else{
            myfile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
            myfile << "<generator>" << std::endl;
                myfile << "\t<Quantity_tasks>";
                myfile << q_task;
                myfile << "</Quantity_tasks>" << std::endl;
            
                myfile << "\t<Quantity_processors>";
                myfile << q_proc;
                myfile << "</Quantity_processors>" << std::endl;
            
                myfile << "\t<Tasks_time>" << std::endl;
            
                for (long i = 0; i < task_time.size(); i++){
                    myfile << "\t\t<Task>";
                    myfile << task_time[i];
                    myfile << "</Task>" << std::endl;
                }
            
                myfile << "\t</Tasks_time>" << std::endl;
            myfile << "</generator>" << std::endl;
            
            myfile.close();
        }
    }
    static std::tuple<long, long, std::map<long, long> > read_xml(std::string filename){
        std::string line;
        std::ifstream myfile (filename);
        if (myfile.is_open()){
            rapidxml::xml_document<> doc;
            rapidxml::xml_node<> * root_node;
            std::vector<char> buffer((std::istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());
            buffer.push_back('\0');
            // Parse the buffer using the xml file parsing library into doc
            doc.parse<0>(&buffer[0]);
            
            // reading quantity of tasks
            //std::cout << "q_task : " << doc.first_node("generator")->first_node("Quantity_tasks")->value() << std::endl;
            std::stringstream str_conv(doc.first_node("generator")->first_node("Quantity_tasks")->value());
            long quan_tasks;
            str_conv >> quan_tasks;
            
            
            
            // reading quantity of processors
            str_conv.clear();
            //std::cout << "q_proc : " << doc.first_node("generator")->first_node("Quantity_processors")->value() << std::endl;
            //str_conv << doc.first_node("generator")->first_node("Quantity_processors")->value();
            str_conv.str(doc.first_node("generator")->first_node("Quantity_processors")->value());
            long quan_proc;
            str_conv >> quan_proc;
            
            
            std::map<long, long> task_time;
            long i = 1;
            // reading the tasks time
            for (rapidxml::xml_node<>* node2 = doc.first_node("generator")->first_node("Tasks_time")->first_node("Task"); node2 != nullptr; node2 = node2->next_sibling())
            {
                //std::cout << "B : " << node2->value() << std::endl;
                str_conv.clear();
                str_conv.str(node2->value());
                str_conv >> task_time[i];
                i++;
            }

            myfile.close();
            return std::make_tuple(quan_tasks, quan_proc, task_time);
        }
        else{
            exit(1);
        }

    }
    
    
    
};

#include <stdio.h>

#endif /* Input_generator_hpp */
