//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>

using namespace std;


class Task {
public:
    static const int MAX_CHARS = 50;
    int day = -1;
    char task_name[MAX_CHARS + 1] = {0};
    int duration = -1;
    char person_name[MAX_CHARS +1] = {0};
    int category = -1;
};

class TaskList {
public:
    static const int MAX_TASKS = 30;
    Task tasks[MAX_TASKS];    
    int tasksSize = 0;

    // CRUD 
    // Create
    // Read
    // Update
    // Delete
    
    
};


char menu();

void menu_do(char c);

int main() {
    char c = '\0';
    do {
        c = menu();
        menu_do(c);
    } while (c != 'q');  

    return 0;
}


char menu() {
    cout << 
        "Pick an option from below:\n"  
        "(a)Add a new task\n" 
        "(b)List tasks by name\n"
        "(c)List tasks by Type\n"
        "(d)Search by task name\n"
        "(e)Remove tasks by index\n"
        "(q)Quit\n";

    char c = 'q';
    cin >> c;
    return c;
}


void menu_do(char c) {
    switch(c) {
      case 'a':
        cout << "TODO: Add" << endl;
        break;

      case 'b':
        cout << "TODO: List by name" << endl;
        break;

     case 'c':
        cout << "TODO: List by type" << endl;
        break;

     case 'd':
        cout << "TODO: Search by task name" << endl;
        break;

     case 'e':
        cout << "TODO: Remove by index" << endl;
        break;

     case 'q':
        // Accept option, nothing to do here.
        break;

    default:
        cout << "ERROR: Unsupported option: " << c << endl;
    }
}



















