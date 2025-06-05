#include "itemList.h"
ItemList::ItemList()
{
	size = 0;
	head = nullptr;
}

ItemList::ItemList(const ItemList& aList)
{
	size = aList.size;

	if(!aList.head)
	{
		this->head = nullptr;
		return;
	}

	copy(aList);
}

ItemList::ItemList(ItemList&& aList)
{
	this->size = aList.size;
	this->head = aList.head;
	aList.head = nullptr;
	aList.size = 0;
}

ItemList::~ItemList()
{
	destroy();
}

void ItemList::destroy()
{
	Node *	curr = head;
	while(head)
	{
		head = curr->next;
		delete curr;
		curr = head;
	}
}

void ItemList::copy(const ItemList& aList)
{
	//copy the first node
	this->head = new Node((aList.head)->data);
	Node * currSource = (aList.head)->next;
	Node * currDestination = this->head;
		

	//copy the rest of the list
	while(currSource)
	{
		currDestination->next = new Node(currSource->data);
		currSource = currSource->next;
		currDestination = currDestination->next;
	} 	
}

ItemList& ItemList::operator= (ItemList&& aList)
{
	if (this == &aList)
	{
		return *this;
	}
	this->size = aList.size;
	if (this->head)
	{
		destroy();
	}
	this->head = aList.head;
	aList.head = nullptr;
	aList.size = 0;
	return *this;
}

const ItemList& ItemList::operator= (const ItemList& aList)
{
	if(this == &aList)
	{
		return *this;
	}
	size = aList.size;
	if(this->head != nullptr)
	{
		destroy();
	}
	copy(aList);
	return *this;
}

int ItemList::getSize() const
{
	return size;
}

InventoryItem& ItemList::operator[] (int index)
{
	Node *	curr = head;
	int		position;
	for(position = 0; position < index; position++)
	{
		curr = curr->next;
	}
	return curr->data;	
}

const InventoryItem& ItemList::operator[] (int index) const
{
	Node *	curr = head;
	int		position;
	for(position = 0; position < index; position++)
	{
		curr = curr->next;
	}
	return curr->data;	
}

void ItemList::append(const InventoryItem& anItem)
{
	Node *	newNode = new Node(anItem);
	if(!head)
	{
		head = newNode;
		size++;
		return;
	}
	Node * prev = nullptr;
	Node * curr = head;
	while(curr)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = newNode;
	
	size++;
}
		
void ItemList::readList(istream& in)
{
	char			itemName[MAX_CHAR];
	float			itemPrice;
	Date			expDate;
	int				year;
	int				month;
	int				day;
	InventoryItem	anItem;

	in.get(itemName, MAX_CHAR, ':');
	while (!in.eof())
	{
		in.get();
		in >> itemPrice;
		in.get();
		in >> year;
		in.get();
		in >> month;
		in.get();
		in >> day;
		in.ignore(MAX_CHAR, '\n');

		anItem.setItemName(itemName);
		anItem.setItemPrice(itemPrice);
		expDate.setDate(year, month, day);
		anItem.setExpDate(expDate);

		append(anItem);

		in.get(itemName, MAX_CHAR, ':');
	}
}
	
void ItemList::printList() const
{
	Node * curr;
	for(curr = head; curr; curr = curr->next)
	{
		curr->data.print();
	}
}


// Copy the item at position “index” into anItem.
// Return true is successful.
// Returns false if index is out of bounds (less than 0 or greater than size - 1). 
bool ItemList::getItem(int index, InventoryItem& anItem) {
	//std::cout << "TODO: bool ItemList::getItem(int index, InventoryItem& anItem)" << endl;
	
	bool success = false; 

	if(index > 0 && index <= (getSize() - 1)) {
		// Call overloaded [] within implementation file
		// https://chatgpt.com/share/6841dd6d-99b0-8013-8842-ff26b9a1dfce
		anItem = (*this)[index];
		success = true;
	}
	return success;
}

// Remove the item with itemName from the list. 
// Return true is successful.
// Returns false if there is no item with the matching name. 
bool ItemList::removeItem(const char* itemName) {
	
	// std::cout << "TODO: bool ItemList::removeItem(const char* itemName)" << endl;

	bool success = false; 

	Node *node = head;
	Node *prev;
	while(node != nullptr && !success) {
		if(strcmp(node->data.getItemName(), itemName) == 0) {
			success = true;
		} else {
			prev = node;
			node = node->next;
		}
	}

	// Not Found 
	if(!success) {
		// Sad :(  nothing to do.
	} else if(node == head) {
		head = head->next;
		delete node;
	} else {
		prev->next = node->next;
		delete node;
	}

	return success;	
}
