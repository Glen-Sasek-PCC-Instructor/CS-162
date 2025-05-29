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
#include "generic-list.h"

using namespace std;

char menu();
void menu_do(char c, LinkedList<Task> &tasklist);
void loadTasklist(std::istream &is, LinkedList<Task> &tasklist);
void prettyPrint(std::ostream &os, LinkedList<Task> &tasklist);
void print(std::ostream &os, LinkedList<Task> &tasklist);
void printHeader(std::ostream &os);
void updateMaxLengths(LinkedList<Task> &tasklist);

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

int main() {
    char c = '\0';

    LinkedList<Task> tasklist;

    std::ifstream fin(DATAFILE);
 
    if(fin) {
        loadTasklist(fin, tasklist);
    } else {
        std::cout << "ERROR: cant open: " << DATAFILE << std::endl;
        return 1;
    }
    

    prettyPrint(cout, tasklist);
    //tasklist.prettyPrint(cout);
    
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

void menu_do(char c, LinkedList<Task> &tasklist) {
    switch(c) {
      case 'a':
        //tasklist.interactiveAddTask();
        break;

      case 'b':
        //tasklist.listByTaskName(cout);
        break;

      case 'p':
        //tasklist.listByPersonName(cout);
        break;

     case 'c':
        cout << MESSAGE_TYPE_OPTIONS;
        //tasklist.listByType(cout);
        break;

     case 'd':
        //tasklist.searchByTaskName(cout);
        break;

     case 'e':
        //tasklist.removeByIndex(cout);
        break;

     case 'q':
        // Accept option, nothing to do here.
        break;

    default:
        cout << "ERROR: Unsupported option: " << c << endl;
    }
}


void loadTasklist(std::istream &is, LinkedList<Task> &tasklist) {

    bool next = true;

    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char buffer[Task::MAX_CHARS + 1];

    while(next) {
        Task *task = new Task;

        is >> task->day;
        if(is) {
            is.get(); // Remove one character the comma ','

            is.getline(buffer, Task::MAX_CHARS, ',');
            task->task_name = new char[strlen(buffer) +1]; 
            strcpy(task->task_name, buffer);

            is >> task->duration;
            is.get(); // Remove one character the comma ','

            is.getline(buffer, Task::MAX_CHARS, ',');
            task->person_name = new char[strlen(buffer) +1]; 
            strcpy(task->person_name, buffer);

            is >> task->category;
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            tasklist.append(*task);
        } else {
            next = false;
        }
    }
}

int maxTaskNameLen = 0;
int maxPersonNameLen = 0;
void updateMaxLengths(LinkedList<Task> &tasklist) {
    LinkedList<Task>::Iterator it = tasklist.begin();
	for(; it != tasklist.end(); it++)
	{
        int n = strlen(it->task_name);
        if ( n > maxTaskNameLen)
        {
            maxTaskNameLen = n;
        }

        n = strlen(it->person_name);
        if (n > maxPersonNameLen)
        {
            maxPersonNameLen = n;
        }
	}
}

void print(std::ostream &os, LinkedList<Task> &tasklist) {
    for(Task task: tasklist) {
        task.print(os);
    }
}

void prettyPrint(std::ostream &os, LinkedList<Task> &tasklist) {
    updateMaxLengths(tasklist);

    std::cout << std::endl;
    printHeader(os);

    int index = 1;
    for(Task task: tasklist) {
        task.print(os, index, maxTaskNameLen + 2, maxPersonNameLen + 2);
        index++;
    }
    std::cout << std::endl;
}

void printHeader(std::ostream &os) {
    // Day,task name,duration,person name,category
    os << std::setw(5) << std::left << "INDEX" << ' ';
    os << std::setw(5) << std::left << "DAY" << ' ';
    os << std::setw(maxTaskNameLen + 2) << std::left << "TASK" << ' ';
    os << std::setw(10) << std::left << "DURATION" << ' ';
    os << std::setw(maxPersonNameLen + 2) << std::left << "PERSON" << ' ';
    os << std::left << "CATEGORY" << '\n';
}



















