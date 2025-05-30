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
            Node *next = nullptr;
        };
        Node *head;
        Node *tail;
        int size;
        
        void init();

    public:
        //constructors
        TaskList();
        TaskList(char filename[]);
        TaskList(std::istream &is);
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
        
        void addTask(Task *task); 

        void addTaskAtEnd(Task *task); 

        void addTaskAtPosition(Task *task, int pos);
    
        void updateMaxLengths() ;

        int getPositionForName(Task *task);
    
        void prettyPrint(std::ostream &os);
    
        void print(std::ostream &os);
    
        void printHeader(std::ostream &os);

        void loadTasklist(std::istream &is);

        void interactiveAddTask();

        void listByTaskName(std::ostream &os);

        void listByPersonName(std::ostream &os);

        void listByType(std::ostream &os);


        void searchByTaskName(std::ostream &os);

        void removeByIndex(std::ostream &os);

        void insertionSort(int (*compare)(Task, Task));
};
    

#endif