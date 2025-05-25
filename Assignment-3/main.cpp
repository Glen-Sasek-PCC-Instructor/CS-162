//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>
#include <fstream>
#include <limits>
#include <cstring>
#include <iomanip>
#include "task.h"
#include "tasklist.h"

using namespace std;

char DATAFILE[] = "tasks.csv";

const char* MESSAGE_WELCOME = "Welcome!";
const char* MESSAGE_GOODBYE = "Thank you for using my program!!";
const char* MESSAGE_WELCOME_DETAILS = "This program will help you manage your tasks for this Space Station.";
const char* MESSAGE_TASK_ADDED = "Task added!";
const char* MESSAGE_TASK_REMOVED = "Task Removed!";
const char* MESSAGE_TASKS_WRITTEN_TO_FILE = "Tasks written to file! ";

const char *MESSAGE_INVALID_OPTION = "Invalid option!!"; 

const char* PROMPT_PICK_OPTION = "Pick an option from below: ";
const char* PROMPT_TRY_AGAIN = "Please try again! ";
const char* PROMPT_INDEX_TO_REMOVE = "Enter index of task to remove:  ";
const char* PROMPT_TYPE_NUMBER = "Enter Type number ";
const char* PROMPT_TASK_NAME = "Enter task name:  ";

const char* MESSAGE_MENU_OPTIONS = 
    "\n"
    "(a) Add a new task\n" 
    "(b) List tasks by task name\n"
    "(p) List tasks by person name\n"
    "(c) List tasks by Type\n"
    "(d) Search by task name\n"
    "(e) Remove tasks by index\n"
    "(q) Quit\n";
    
const char* MESSAGE_TYPE_OPTIONS = 
    "\n"
    "(0) Operations\n" 
    "(1) Maintenance\n"
    "(2) Inventory\n"
    "(3) Communications\n"
    "(4) Others\n";    

char menu();

void menu_do(char c, TaskList &tasklist);

int main() {
    char c = '\0';

    TaskList tasklist(DATAFILE);
    tasklist.prettyPrint(cout);
    
    cout << MESSAGE_WELCOME << endl;

    do {
        c = menu();
        menu_do(c, tasklist);
    } while (c != 'q');  

    cout << MESSAGE_GOODBYE << endl;
    return 0;
}

char menu() {
    cout << PROMPT_PICK_OPTION << endl;
    cout << MESSAGE_MENU_OPTIONS << endl;

    char c = 'q';
    cin >> c;
    return c;
}


void menu_do(char c, TaskList &tasklist) {
    switch(c) {
      case 'a':
        tasklist.interactiveAddTask();
        break;

      case 'b':
        tasklist.listByTaskName(cout);
        break;

      case 'p':
        tasklist.listByPersonName(cout);
        break;

     case 'c':
        cout << MESSAGE_TYPE_OPTIONS;
        tasklist.listByType(cout);
        break;

     case 'd':
        tasklist.searchByTaskName(cout);
        break;

     case 'e':
        tasklist.removeByIndex(cout);
        break;

     case 'q':
        // Accept option, nothing to do here.
        break;

    default:
        cout << "ERROR: Unsupported option: " << c << endl;
    }
}


// Day,task name,duration,person name,category
// 5,Replace ventilation filters,2,Robbie Mitchell,1
// TaskList loadTasklist(istream &is) {
//     bool next = true;

//     TaskList tasklist;

//     is.ignore(numeric_limits<streamsize>::max(), '\n');

//     char buffer[Task::MAX_CHARS + 1];

//     while(next) {
//         Task *task = new Task;

//         is >> task->day;
//         if(is) {
//             is.get(); // Remove one character the comma ','

//             is.getline(buffer, Task::MAX_CHARS, ',');
//             task->task_name = new char[strlen(buffer) +1]; 
//             strcpy(task->task_name, buffer);

//             is >> task->duration;
//             is.get(); // Remove one character the comma ','

//             is.getline(buffer, Task::MAX_CHARS, ',');
//             task->person_name = new char[strlen(buffer) +1]; 
//             strcpy(task->person_name, buffer);

//             is >> task->category;
//             is.ignore(numeric_limits<streamsize>::max(), '\n');
//             tasklist.addTask(task);
//         } else {
//             next = false;
//         }
//     }

//     return tasklist;
// }


// class Task {
// public:
//     static const int MAX_CHARS = 50;
//     int day = -1;
//     char *task_name = nullptr;
//     int duration = -1;
//     char *person_name = nullptr;
//     int category = -1;

//     void print(ostream &os) {
//         os << day << ',' << task_name << ',' << duration << ',' << person_name << ',' << category << endl;
//     }

//     void print(ostream &os, int taskNameWidth, int personNameWidth) {
//         os << setw(5) << right << day << ' ';
//         os << setw(taskNameWidth) << left << task_name << ' ';
//         os << setw(10) << right << duration << ' ';
//         os << setw(personNameWidth) << left << person_name << ' ';
//         os << setw(10) << right << category << '\n';
//     }
// };

// class TaskList {
// public:
//     static const int MAX_TASKS = 30;
//     Task *tasks = nullptr;    
//     int tasksSize = 0;
//     int maxTaskNameLen = 0;
//     int maxPersonNameLen = 0;

//     // CRUD 
//     // Create
//     // Read
//     // Update
//     // Delete
    
//     void addTask(Task *task) {
//         Task *newTasks = new Task[tasksSize + 1];
//         for(int i =0; i < tasksSize; i++) {
//             newTasks[i] = tasks[i];
//         }

//         newTasks[tasksSize] = *task;
//         tasksSize++;
//         delete[] tasks;
//         tasks = newTasks;
//     }

//     void updateMaxLengths() {
//         for(int i =0; i < tasksSize; i++) {
//             if(strlen(tasks[i].task_name) > maxTaskNameLen) {
//                 maxTaskNameLen = strlen(tasks[i].task_name);
//             } 

//             if(strlen(tasks[i].person_name) > maxPersonNameLen) {
//                 maxPersonNameLen = strlen(tasks[i].person_name);
//             } 
//         }
//     }

//     void prettyPrint(ostream &os) {
//         updateMaxLengths();
        
//         cout << endl;
//         printHeader(os);
//         for(int i =0; i < tasksSize; i++) {
//             tasks[i].print(os, maxTaskNameLen + 2, maxPersonNameLen + 2);
//         }
//         cout << endl;
//     }

//     void print(ostream &os) {
//         for(int i =0; i < tasksSize; i++) {
//             tasks[i].print(os);
//         }
//     }

//     void printHeader(ostream &os) {
//         // Day,task name,duration,person name,category
//         os << setw(5) << right << "DAY" << ' ';
//         os << setw(maxTaskNameLen + 2) << left << "TASK" << ' ';
//         os << setw(10) << right << "DURATION" << ' ';
//         os << setw(maxPersonNameLen + 2) << left << "PERSON" << ' ';
//         os << setw(10) << right << "CATEGORY" << '\n';        
//     }
// };




















