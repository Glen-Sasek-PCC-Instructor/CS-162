//This is the implementation file for IntList
//See intlist.h for class details.
#include "intlist.h"

//add all your function implementations here

// Given main(), complete the IntList class (in files intlist.h and intlist.cpp) with the following:

// intlist.h - Prototypes for the following functions
// Default constructor
// Destructor
// int getCount() - to return the number of elements in the int array
// void addNum(int) - takes a number and adds to the list of integers
// void printList() - prints the list of numbers in the array
// intlist.cpp
// Write the definitions for the above functions.
// Make sure the constructor allocates memory for the int array
// Make sure the destructor deallocates the memory of the int array

void IntList::addNum(int n) {
    // cout << "TODO: void IntList::addNum(int)" << endl;
    int *temp = new int[count+1];

    // Copy Array Examples...
    // for (int i = 0; i < count; i++) {
    //     temp[i] = list[i];
    // }
    
    int *l_ptr = temp;
    int *r_ptr = list;
    
    // for (int i = 0; i < count; i++) {
    //     (*l_ptr) = *r_ptr;
    //     l_ptr++;
    //     r_ptr++;
    // }

    // for (int i = 0; i < count; i++) {
    //     (*l_ptr++) = *r_ptr++;
    //     // l_ptr++;
    //     // r_ptr++;
    // }

    while(l_ptr < temp + count) {
        *l_ptr = *r_ptr;
        l_ptr++;
        r_ptr++;
    }

    temp[count] = n;
    count++;
    delete[] list;
    list = temp;
 }
 
 void IntList::printList() {
    //cout << "TODO: void IntList::printList()" << endl;
    for (int i = 0; i < count; i++) {
        cout << list[i] << endl;
    }
 }

 int IntList::getCount() {
    return count;
 }
