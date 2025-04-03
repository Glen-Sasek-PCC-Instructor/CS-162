//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>
#include <fstream>
#include <cstring> // https://en.cppreference.com/w/cpp/header/cstring
#include "activity.h"
#include "main.h"

using namespace std;


int main() {

  
  size_t MAX_ACTIVITIES = 30;

  size_t activitiesSize = 0;

  Activity activities[MAX_ACTIVITIES];

  ifstream fin = ifstream("activities.txt"); 

  loadActivities(fin, activities, activitiesSize);

  printAll(cout, activities, activitiesSize);
 
  return 0;
}



// Skiing;Mt Hood Meadows;Difficult;6;0
void loadActivities(istream &is, Activity arr[], size_t &size) {
  char const DELIMITER = ';';
  size = 0;
  while(is && !is.peek() != EOF){
    Activity it;
    // read data from fil
    is.getline(it.name, Activity::MAX_CHARS, DELIMITER);
    is.getline(it.location, Activity::MAX_CHARS, DELIMITER);
    is.getline(it.level, Activity::MAX_CHARS, DELIMITER);
    is >> it.rating;
    is.get(); // Remove delimiter
    is >> it.type;
    is.get(); // Remove \n newline character

    // find sorted position
    int pos = 0;

    // while(true) {
    //   if (pos == size) {
    //     break;
    //   }

    //   if(strcmp(arr[pos].name, it.name) > 0) {
    //     pos++;
    //   } else {
    //     break;
    //   }
    // }

    // refactored to not use while true
    bool next = true;
    while(next) {
      if (pos == size) {
        next = false;
      } else if(strcmp(arr[pos].name, it.name) > 0) {
        pos++;
      } else {
        next = false;
      }
    }

    
    // insert at position
    insert(arr, size, it, pos);

  }
}


void insert(Activity arr[], size_t &size, Activity it, size_t pos) {
  for(size_t i = size + 1; i > pos; i-- ) {
    arr[i] = arr[i-1];
  }
  arr[pos] = it;
  size++;
}

