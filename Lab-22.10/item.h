//Item header file
//
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

//constant for char arrays
const int MAXCHAR = 101;

//class definition
class Item {
private:
    char *itemName;
    int numberOfItems;

public:
    //Constructors
    Item();
    Item(char *, int);
    //copy constructor
    Item(const Item &anItem);
    //destructor
    ~Item();
    //mutators
    void setItemName(char *);
    void setNumItems(int);
    //accessors
    void getItemName(char *);
    int getNumItems();
    //print item
    void printItem();
    //assignment op overloading
    Item& operator= (const Item& anItem);
};

