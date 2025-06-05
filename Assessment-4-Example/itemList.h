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

	// Copy the item at position “index” into anItem.
	// Return true is successful.
	// Returns false if index is out of bounds (less than 0 or greater than size - 1). 
	bool getItem(int index, InventoryItem& anItem);


	// Remove the item with itemName from the list. 
	// Return true is successful.
	// Returns false if there is no item with the matching name. 
	bool removeItem(const char* itemName);
};
