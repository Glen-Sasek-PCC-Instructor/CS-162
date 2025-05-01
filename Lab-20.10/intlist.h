//Class for a list of numbers
//Implemented using dynamic int array


// Run and test:
// g++ -Wall -Werror *.cpp && ./a.out < test-1.txt && rm ./a.out
// With valgrind memory check
// g++ -Wall -Werror *.cpp && valgrind ./a.out && rm ./a.out

#pragma once
#include <iostream>
using namespace std;
//global constants
const int CAP = 10;

//class definition for a list of numbers and its count
class IntList
{
  public:
    //To Do: constructor
    IntList(){
      count = 0;
      list = nullptr; 
    }

    ~IntList() {
      delete[] list;
    }
    
    //To Do: getCount function
    int getCount(); // - to return the number of elements in the int array

    void addNum(int);
    void printList();
     
  private:
    int *list;
    int count;
};
