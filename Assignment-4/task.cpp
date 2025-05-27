#ifndef TASK_CPP
#define TASK_CPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include "task.h"

void Task::print(std::ostream &os) {
    os << day << ',' << task_name << ',' << duration << ',' << person_name << ',' << category << std::endl;
}

void Task::print(std::ostream &os, int index, int taskNameWidth, int personNameWidth) {
    os << "[" << index << "]   "; 
    os << std::setw(2) << std::setfill('0') <<  std::right << day << "    " << std::setfill(' ');
    os << std::setw(taskNameWidth) << std::left << task_name << ' ';
    os << std::setw(10) << std::left << duration << ' ';
    os << std::setw(personNameWidth) << std::left << person_name << ' ';
    os << std::left << category << ' ' << CATEGORY_NAMES[category] << '\n';
}

const char* Task::CATEGORY_NAMES[] = {"Operations", "Maintenance", "Inventory", "Communications", "Other"};
#endif