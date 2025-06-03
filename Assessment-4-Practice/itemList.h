#pragma once
#include "item.h"

class ItemList
{
private:
	//node for the linked list
	struct Node
	{
		InventoryItem 	data;
		Node *			next;
		Node(const InventoryItem& aData)
		{
			data = aData;
			next = nullptr;
		} 
	};

	//data members for ItemList
	Node *	head;
	int		size;

	//helper functions 
	void destroy();
	void copy(const ItemList& aList);
	void append(const InventoryItem& anItem);
	
public:
	ItemList();
	ItemList(const ItemList& aList);
	ItemList(ItemList&& aList);
	~ItemList();

	const ItemList& operator= (const ItemList& aList);
	ItemList& operator= (ItemList&& aList);

	int getSize() const;

	InventoryItem& operator[] (int index);
	const InventoryItem& operator[] (int index) const;

	void printList() const;
	void readList(istream& in);

	// return the items that are older than the passed in “expDate” in the list. 
	// The items are returned through the dynamically allocated array “olderItems” and 
	// the function returns the number of items found that are older than “expDate”.
	int getOlderItems(const Date& expDate, InventoryItem *& olderItems) const;

    // Remove the data items in the first node and the last node along with the nodes. 
	// If there are less than 2 nodes, the function does nothing. 
	void removeFirstAndLast();
};
