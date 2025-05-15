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
    head = NULL;
    tail = NULL;
    size = 0;
}

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

// Day,task name,duration,person name,category
// 5,Replace ventilation filters,2,Robbie Mitchell,1
void TaskList::loadTasklist(std::istream &is) {
    bool next = true;

    TaskList tasklist;

    is.ignore(numeric_limits<streamsize>::max(), '\n');

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
            is.ignore(numeric_limits<streamsize>::max(), '\n');
            tasklist.addTask(task);
        } else {
            next = false;
        }
    }

    return tasklist;
}



void TaskList::addTask(Task *task) {
    Task *newTasks = new Task[tasksSize + 1];
    for (int i = 0; i < tasksSize; i++)
    {
        newTasks[i] = tasks[i];
    }

    newTasks[tasksSize] = *task;
    tasksSize++;
    delete[] tasks;
    tasks = newTasks;
}

void TaskList::updateMaxLengths() {
    for (int i = 0; i < tasksSize; i++)
    {
        if (strlen(tasks[i].task_name) > maxTaskNameLen)
        {
            maxTaskNameLen = strlen(tasks[i].task_name);
        }

        if (strlen(tasks[i].person_name) > maxPersonNameLen)
        {
            maxPersonNameLen = strlen(tasks[i].person_name);
        }
    }
}

void TaskList::print(std::ostream &os) {
    for (int i = 0; i < tasksSize; i++)
    {
        tasks[i].print(os);
    }
}

void TaskList::prettyPrint(std::ostream &os) {
    updateMaxLengths();

    std::cout << std::endl;
    printHeader(os);
    for (int i = 0; i < tasksSize; i++)
    {
        tasks[i].print(os, maxTaskNameLen + 2, maxPersonNameLen + 2);
    }
    std::cout << std::endl;
}

void TaskList::printHeader(std::ostream &os) {
    // Day,task name,duration,person name,category
    os << std::setw(5) << std::right << "DAY" << ' ';
    os << std::setw(maxTaskNameLen + 2) << std::left << "TASK" << ' ';
    os << std::setw(10) << std::right << "DURATION" << ' ';
    os << std::setw(maxPersonNameLen + 2) << std::left << "PERSON" << ' ';
    os << std::setw(10) << std::right << "CATEGORY" << '\n';
}

#endif