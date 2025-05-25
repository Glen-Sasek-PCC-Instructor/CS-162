#ifndef TASKLIST_CPP
#define TASKLIST_CPP

#include "task.h"
#include "tasklist.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

//constructors
TaskList::TaskList()
{
    init();
}

TaskList::TaskList(std::istream &is) {
    init();
    loadTasklist(is);
}

TaskList::TaskList(char fileName[]) {
    init();
    std::ifstream fin(fileName);
 
    if(fin) {
        // OK
    } else {
        std::cout << "ERROR: cant open: " << fileName << std::endl;
    }
    loadTasklist(fin);
}

TaskList::~TaskList()
{
	Node *	curr = head;
	while(head)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void TaskList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}


// Day,task name,duration,person name,category
// 5,Replace ventilation filters,2,Robbie Mitchell,1
void TaskList::loadTasklist(std::istream &is) {
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
            addTask(task);
        } else {
            next = false;
        }
    }
}


void TaskList::addTask(Task *task) {
    Node *newNode = new Node;
    newNode->data = *task;
    if(size == 0) {
        head = newNode;
        tail = head;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void TaskList::updateMaxLengths() {
    // for (int i = 0; i < size; i++)
    // {
    //     if (strlen(tasks[i].task_name) > maxTaskNameLen)
    //     {
    //         maxTaskNameLen = strlen(tasks[i].task_name);
    //     }

    //     if (strlen(tasks[i].person_name) > maxPersonNameLen)
    //     {
    //         maxPersonNameLen = strlen(tasks[i].person_name);
    //     }
    // }

    Node *it;
	for(it = head; it != nullptr; it = it->next)
	{
        int n = strlen(it->data.task_name);
        if ( n > maxTaskNameLen)
        {
            maxTaskNameLen = n;
        }

        n = strlen(it->data.person_name);
        if (n > maxPersonNameLen)
        {
            maxPersonNameLen = n;
        }
	}
}

void TaskList::print(std::ostream &os) {
    // for (int i = 0; i < tasksSize; i++)
    // {
    //     tasks[i].print(os);
    // }
    Node *it;
	for(it = head; it != nullptr; it = it->next)
	{
        it->data.print(os);
    }
}

void TaskList::prettyPrint(std::ostream &os) {
    updateMaxLengths();

    std::cout << std::endl;
    printHeader(os);
    // for (int i = 0; i < tasksSize; i++)
    // {
    //     tasks[i].print(os, maxTaskNameLen + 2, maxPersonNameLen + 2);
    // }

    int index = 1;

    Node *it;
	for(it = head; it != nullptr; it = it->next)
	{
        it->data.print(os, index, maxTaskNameLen + 2, maxPersonNameLen + 2);
        index++;
    }
    std::cout << std::endl;
}

void TaskList::printHeader(std::ostream &os) {
    // Day,task name,duration,person name,category
    os << std::setw(5) << std::left << "INDEX" << ' ';
    os << std::setw(5) << std::left << "DAY" << ' ';
    os << std::setw(maxTaskNameLen + 2) << std::left << "TASK" << ' ';
    os << std::setw(10) << std::left << "DURATION" << ' ';
    os << std::setw(maxPersonNameLen + 2) << std::left << "PERSON" << ' ';
    os << std::left << "CATEGORY" << '\n';
}

void TaskList::interactiveAddTask() {
    std::ostream &os = std::cout;
    std::istream &is = std::cin;

    Task *task = new Task;
    
    // Day
    bool valid = false;
    while(!valid) {
        int n = 0;
        int MIN = 1;
        int MAX = 30;
        os << "Enter the day of the task (whole numbers between " << MIN << " and " << MAX << "): ";
        is >>  n;
        if(!is) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(n < MIN || n > MAX) {
            os << "Invalid day! Must be  between " << MIN << " and " << MAX << "): " << std::endl;
        } else {
            valid = true;
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove newline character
        }
        task->day = n;
    }

    // Task Name
    char buffer[Task::MAX_CHARS + 1];
    os << "Enter the task name (50 characters or less): ";
    is.getline(buffer, Task::MAX_CHARS, '\n');
    task->task_name = new char[strlen(buffer) +1]; 
    strcpy(task->task_name, buffer);

    // Person Name
    os << "Enter the person’s name (50 characters or less): ";
    is.getline(buffer, Task::MAX_CHARS, '\n');
    task->person_name = new char[strlen(buffer) +1]; 
    strcpy(task->person_name, buffer);

    // Duration
    valid = false;
    while(!valid) {
        int n = 0;
        int MIN = 1;
        int MAX = 10;
        os << "Enter the number of hours (whole numbers between " << MIN << " and " << MAX << "): ";
        is >>  n;
        if(!is) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(n < MIN || n > MAX) {
            os << "Invalid hours! Must be  between " << MIN << " and " << MAX << "): " << std::endl;
        } else {
            valid = true;
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove newline character
        }
        task->duration = n;
    }

    // Category
    valid = false;
    while(!valid) {
        int n = 0;
        int MIN = 0;
        int MAX = 4;
        os << "0-Operations" << std::endl;
        os << "1-Maintenance" << std::endl;
        os << "2-Inventory" << std::endl;
        os << "3-Communications" << std::endl;
        os << "4-Others" << std::endl;
        os << "Enter the task type: " << std::endl;
        is >>  n;
        if(!is) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if(n < MIN || n > MAX) {
            os << "Invalid type! Must be  between " << MIN << " and " << MAX << "): " << std::endl;
        } else {
            valid = true;
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Remove newline character
        }
        task->category = n;
    }

    addTask(task);

    os << "Task added!" << std::endl;
}

int compareByTaskName(Task t1, Task t2) {
    return strcmp(t1.task_name, t2.task_name);
}

void TaskList::listByTaskName(std::ostream &os){
    insertionSort(compareByTaskName);
    prettyPrint(os);
}

int compareByPersonName(Task t1, Task t2) {
    return strcmp(t1.person_name, t2.person_name);
}

void TaskList::listByPersonName(std::ostream &os){
    insertionSort(compareByPersonName);
    prettyPrint(os);
}

void TaskList::listByType(std::ostream &os){
    int n = 0;
    os << "Enter Type number: ";
    std::cin >> n;
    updateMaxLengths();

    std::cout << std::endl;
    printHeader(os);
    Node *it;
    int index = 1;
	for(it = head; it != nullptr; it = it->next)
	{
        if(it->data.category == n) {
            it->data.print(os, index, maxTaskNameLen + 2, maxPersonNameLen + 2);
            index++;
        }
    }
    std::cout << std::endl;
}

void TaskList::searchByTaskName(std::ostream &os){
    os << "Enter task name: ";
    char buffer[Task::MAX_CHARS + 1];
    std::cin.getline(buffer, Task::MAX_CHARS, '\n');

    std::cout << std::endl;
    printHeader(os);
    Node *it;
    int index = 1;
	for(it = head; it != nullptr; it = it->next)
	{

        const char* found = std::strstr(it->data.task_name, buffer);
        if(found) {
            it->data.print(os, index, maxTaskNameLen + 2, maxPersonNameLen + 2);
            index++;
        }
    }
    std::cout << std::endl;
}

void TaskList::removeByIndex(std::ostream &os){
    prettyPrint(os);
    int n = 0;
    os << "Enter index to remove: ";
    std::cin >> n;
    if(n > 0 && n <= size) { // 1 based index
        Node *it;
        if(n == 1) {
            // remove head
            it = head;
            if(head->next) {
                head = head->next;
            }
            delete it;
        }
        else {
            int index = 2;
            Node *prev = head;
            for(it = prev->next; it != nullptr;)
            {
                if(n == index) {
                    prev->next = it->next;
                    delete it;
                    it = nullptr;
                } else {
                    prev = it;
                    index++;
                    it = it->next;
                }
            }
        }
        prettyPrint(os);
    } else {
        os << "Error bad index :( " << n << std::endl; 
    }
}

void TaskList::insertionSort(int (*compare)(Task t1, Task t2)) {
    if (!head || !head->next) { 
        return;
    }
    
    Node* sorted = nullptr;  // New sorted list

    while (head) {
        Node* current = head;
        head = head->next;

        if (!sorted || compare(current->data, sorted->data) < 0 ) {
            // Insert at the beginning
            current->next = sorted;
            sorted = current;
        } else {
            // Find the correct position in the sorted list
            Node* temp = sorted;
            while (temp->next && compare(temp->data, current->data) < 0 ) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
    }
    head = sorted;
}




// Insertion sort for linked list
// Node* insertionSort(Node* head) {

// }

#endif


// TaskList::TaskList(char fileName[])
// {
//     head = NULL;
//     tail = NULL;
//     size = 0;
//     std::ifstream inFile;
//     Task aSong;
//     //char tempTitle[Task::MAX_CHARS], tempArtist[Task::MAX_CHARS];
//     //int tempDuration;
//     //int tempBPS;
//     inFile.open(fileName);
//     if(!inFile)
//     {
//         std::cout << "cannot open file! Exiting!!" << std::endl;
//         exit(0);
//     }
//     inFile.getline(tempTitle, MAXCHAR, ';');
//     while(!inFile.eof())
//     {
//         inFile.getline(tempArtist, MAXCHAR, ';');
//         inFile >> tempDuration;
//         inFile.ignore(5, ';');
//         inFile >> tempBPS;
//         inFile.ignore(5, '\n');
//         //populate aSong;
//         aSong.setSongTitle(tempTitle);
//         aSong.setSongArtist(tempArtist);
//         aSong.setDuration(tempDuration);
//         aSong.setBPS(tempBPS);
//         addSong(aSong);
//         inFile.getline(tempTitle, MAXCHAR, ';');
//     }
//     inFile.close();
// }
