//This is the implementation file for item.h (the Item class)
#include "item.h"

//default constructor
Item::Item()
{
    //allocate memory for itemName
    itemName = new char[MAXCHAR];
    strcpy(this->itemName, "no name");
    numberOfItems = 0;
}

//constructor with parameters
Item::Item(char tempItemName[], int tempNumItems)
{
    //allocate memory for itemName
    itemName = new char[strlen(tempItemName) + 1];
    strcpy(itemName, tempItemName);
    numberOfItems = tempNumItems;
}

//Copy Constructor
Item::Item(const Item &anItem)
{
    //allocate memory for itemName
    itemName = new char[strlen(anItem.itemName) + 1];
    strcpy(itemName, anItem.itemName);
    numberOfItems = anItem.numberOfItems;
}

//destructor
Item::~Item()
{
   //deallocate the memory for itemName
   if(itemName)
   {
        delete [] itemName;
        itemName = NULL;
    }
}

//mutator functions
void Item::setItemName(char *newItemName)
{
    if(itemName)
    {
        delete [] itemName;
    }
    itemName = new char[strlen(newItemName) + 1];
    strcpy(itemName, newItemName);
}

//for numberofitems
void Item::setNumItems(int newNum)
{
    numberOfItems = newNum;
}

//accessor functions
void Item::getItemName(char *returnItemName)
{
    strcpy(returnItemName, itemName);
}

int Item::getNumItems()
{
    return numberOfItems;
}

//print the item
void Item::printItem()
{
    cout << numberOfItems << ' ' << itemName << endl;
}

//assignment operator overload
Item& Item::operator= (const Item& anItem)
{
    //if it is a self copy, don't do anything
    if (this == &anItem)
        return *this;
    //make current object *this a copy of the passed in item
    else
    {
        this->setItemName(anItem.itemName);
        this->numberOfItems = anItem.numberOfItems;

        return *this;
    }
}

