#ifndef TASK_CPP
#define TASK_CPP

#include <cstring>
#include <iostream>
#include <iomanip>
#include "task.h"

void Task::print(std::ostream &os) {
    os << day << ',' << task_name << ',' << duration << ',' << person_name << ',' << category << std::endl;
}

void Task::print(std::ostream &os, int taskNameWidth, int personNameWidth) {
    os << std::setw(5) <<std:: right << day << ' ';
    os << std::setw(taskNameWidth) << std::left << task_name << ' ';
    os << std::setw(10) << std::right << duration << ' ';
    os << std::setw(personNameWidth) << std::left << person_name << ' ';
    os << std::setw(10) << std::right << category << '\n';
}

#endif