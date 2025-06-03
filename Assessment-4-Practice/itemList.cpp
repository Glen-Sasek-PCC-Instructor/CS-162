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


// return the items that are older than the passed in “expDate” in the list. 
// The items are returned through the dynamically allocated array “olderItems” and 
// the function returns the number of items found that are older than “expDate”.
int ItemList::getOlderItems(const Date& maxDate, InventoryItem *& olderItems) const {
	std::cout << "TODO: int ItemList::getOlderItems(const Date& expDate, InventoryItem *& olderItems) const" << std::endl;

	int olderItemsSize = 0;

	Node *node = head;
	while(node->next != nullptr) {
		if(maxDate < (*node->data.getExpDate())) {
			InventoryItem *newArr = new InventoryItem[olderItemsSize + 1];
			for (int i = 0; i < olderItemsSize; i++)
			{
				newArr[i] = olderItems[i];
			}

			newArr[olderItemsSize] = node->data;
			olderItemsSize++;
			delete[] olderItems;
			olderItems = newArr;
		}
		node = node -> next;
	}

	return olderItemsSize;
}


// Remove the data items in the first node and the last node along with the nodes. 
// If there are less than 2 nodes, the function does nothing. 
void ItemList::removeFirstAndLast() {
	// std::cout << "TODO: void ItemList::removeFirstAndLast()" << std::endl;	
	if(size < 2) {
		return;
	}

	Node *node = head;
	// Remove head
    head = head->next;
	delete node; 

	// Find node before tail
	node = head;
	while(node->next != nullptr && node->next->next != nullptr) {
		node = node->next;
	}

	delete node->next;
	node->next = nullptr;
}





