//This is the itemList header file.
//Class for a list of items
#pragma once
#include "item.h"

//define class for a list of items
class ItemList
{
    private:
    //struct for each Node
        struct Node
        {
            Item data;
            Node *next;
        };
        Node *head;
        Node *tail;
        int size;

    public:
        //constructors
        ItemList();
        //destructor
        ~ItemList();
        //database functions
        void InsertAtFront(Item &);
        bool findItem(char *);
        void showList();
        int getSize();
};
