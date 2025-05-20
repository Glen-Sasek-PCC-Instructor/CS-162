//This is the main file
#include "item.h"
#include "itemList.h"



// Given main(), define the following functions:

// An InsertAtFront(Item &) member function in the ItemList class that inserts items at the front of a linked list (always add to the head pointer).
// A findItem() function in the ItemList class that returns something
// Check the prototypes in itemList.h before you write the functions. Do not change these prototypes. 
// Do not change anything else in any other files.

// The code in main() reads input from the user and calls the InsertAtFront() function to add the items. 
// The first input is the number of items followed by the item name and the number of items separated by space.
// Then it reads an item name from the user and finds the item in the list.

int main()
{
    //create a list of items
    ItemList groceryList;
    //create temp variables
    Item anItem;
    int count = 0, newNum = 0;
    char newName[MAXCHAR], findName[MAXCHAR];
    //read from user and add to list
    cin >> count;
    cin.ignore(100, '\n');
    for(int i = 0; i < count; i++)
    {
        cin >> newName;
        cin >> newNum;
        cin.ignore(100, '\n');
        anItem.setItemName(newName);
        anItem.setNumItems(newNum);
        groceryList.InsertAtFront(anItem);
    }
    groceryList.showList();
    cin >> findName;
    if(!groceryList.findItem(findName))
    {
        cout << "Item not found!";
    }
    return 0;
}
