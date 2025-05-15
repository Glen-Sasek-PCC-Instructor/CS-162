#ifndef TASK_H
#define TASK_H

#include <cstring>
#include <iostream>
#include <iomanip>

class Task {
    public:
        static const int MAX_CHARS = 50;
        int day = -1;
        char *task_name = nullptr;
        int duration = -1;
        char *person_name = nullptr;
        int category = -1;
    
        void print(std::ostream &os);
    
        void print(std::ostream &os, int taskNameWidth, int personNameWidth);
    };

    #endif