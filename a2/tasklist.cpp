#ifndef TASKLIST_CPP
#define TASKLIST_CPP

#include "task.h"
#include "tasklist.h"
#include <cstring>
#include <iostream>
#include <iomanip>

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