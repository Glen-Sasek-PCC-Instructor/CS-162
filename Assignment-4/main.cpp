//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

// Run Command
// g++ -Wall -Werror -Wfatal-errors *.cpp && ./a.out && rm ./a.out

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




















