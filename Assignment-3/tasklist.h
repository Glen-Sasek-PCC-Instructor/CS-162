#ifndef TASKLIST_H
#define TASKLIST_H

#include "task.h"

#include <cstring>
#include <iostream>
#include <iomanip>

class TaskList {
    private:
        //struct for each Node
        struct Node
        {
            Task data;
            Node *next;
        };
        Node *head;
        Node *tail;
        int size;
    public:
        //constructors
        TaskList();
        TaskList(char filename[]);
        //destructor
        ~TaskList();

        static const int MAX_TASKS = 30;
        // Task *tasks = nullptr;       Replaced by Node *head above
        // int tasksSize = 0;           Replacerd by size
        int maxTaskNameLen = 0;
        int maxPersonNameLen = 0;
    
        // CRUD 
        // Create
        // Read
        // Update
        // Delete
        
        void addTask(Task *task); // A3-TODO: update, maybe
    
        void updateMaxLengths() ;
    
        void prettyPrint(std::ostream &os);
    
        void print(std::ostream &os);
    
        void printHeader(std::ostream &os);

        void loadTasklist(std::istream &is);
};
    

#endif