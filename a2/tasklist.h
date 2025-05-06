#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"

#include <cstring>
#include <iostream>
#include <iomanip>

class TaskList {
    public:
        static const int MAX_TASKS = 30;
        Task *tasks = nullptr;    
        int tasksSize = 0;
        int maxTaskNameLen = 0;
        int maxPersonNameLen = 0;
    
        // CRUD 
        // Create
        // Read
        // Update
        // Delete
        
        void addTask(Task *task);
    
        void updateMaxLengths() ;
    
        void prettyPrint(std::ostream &os);
    
        void print(std::ostream &os);
    
        void printHeader(std::ostream &os);
    };
    

    #endif