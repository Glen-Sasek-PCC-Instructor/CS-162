#ifndef TASK_H
#define TASK_H

#include <cstring>
#include <iostream>
#include <iomanip>

class Task {
    public:
        enum Category { OPERATIONS, MAINTENANCE, INVENTORY, COMMUNICATIONS, OTHER };
        static const char* CATEGORY_NAMES[OTHER+1];

        static const int MAX_CHARS = 50;
        int day = -1;
        char *task_name = nullptr;
        int duration = -1;
        char *person_name = nullptr;
        int category = -1;
    
        void print(std::ostream &os);
    
        void print(std::ostream &os, int index, int taskNameWidth, int personNameWidth);
    };

    #endif