//The implementation file itemList.h, ItemList class
#include "itemList.h"

//constructors
ItemList::ItemList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

//destructor
ItemList::~ItemList()
{
    //delete list
    Node *curr = head;
    while(curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    tail = NULL;
}

//Add an item to the list
/*Your code goes here */
void ItemList::InsertAtFront(Item &item)
{
    //cout << "START --> ItemList::InsertAtFront(Item &item)" << endl;
    // item.printItem();

    Node *node = new Node;
    // cout << "      --> Node *node = new Node;" << endl;
    node->data = item;
    // cout << "      --> node->data = item;" << endl;
    node->next = head;
    // cout << "      --> node->next = head;" << endl;
    head = node;
    // cout << "      --> head = node;" << endl;
    // cout << "END   --> ItemList::InsertAtFront(Item &item)" << endl;
}

//Returns the size of the list
int ItemList::getSize(){
    return size;
}

//displays the list
void ItemList::showList()
{
    Node *curr;
    for(curr = head; curr; curr = curr->next)
    {
        curr->data.printItem();
    }
    cout << endl;
}

//finds an item with the given name
/* Your code goes here */
bool ItemList::findItem(char *name)
{
    Node *curr;
    bool found = false;
    for(curr = head; curr && !found; curr = curr->next)
    {
        char str[MAXCHAR];
        curr->data.getItemName(str);
        if(strcmp(str, name) == 0) {
            found = true;
            cout << "Item found." << endl;
            curr->data.printItem();
        }
    }
    return found;
}



