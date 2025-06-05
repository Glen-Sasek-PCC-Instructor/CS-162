#include "main.h"

// Build, run, test, clean
// clear; make && valgrind --leak-check=full ./main < test-1.txt; make clean

int main(int argc, char ** argv)
{
	ItemList		inventory;
	char			fileName[] = "items.txt";

	//open file to read data and populate inventory
	ifstream		in;
	in.open(fileName);
	if(!in)
	{
		cerr << "Fail to open " << fileName << " for input!" << endl;
		return 1;
	}
	inventory.readList(in);
	
	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();

	// Sample Run 
	// Current Inventory:
	// apple     0.99    Sun 2022-03-20
	// banana  0.69    Wed 2021-04-28
	// cookie    0.50    Sun 2023-02-12
	// donut     1.00    Thu 2021-10-28
	// egg         3.88    Sun 2022-01-30
	// fish         5.88    Mon 2021-02-15
	// milk        2.99    Tue 2021-03-02
	// yogurt    6.38    Sun 2021-06-13

	// Enter the index to find the item (0 to 8): 4
	int i = -1;
	cout << endl;
	cout << "Enter the index to find the item (0 to " << (inventory.getSize() - 1) << ") : ";
	cin >> i;  
    InventoryItem inventoryItem;
	if(inventory.getItem(i, inventoryItem)) {
		// Item found!
	    cout << endl;
		cout << "Item found!" << endl;
		// egg         3.88    Sun 2022-01-30
		inventoryItem.print();
	} else {
		cout << "ERROR index: " << i << " out of bounds ;( " << endl;
	}

	char name[MAX_CHAR];

	// Enter name of the item to remove: milk
	cout << endl;
    cout << "Enter name of the item to remove: ";
	cin >> name;
	if(inventory.removeItem(name)) {
		cout << endl;
		cout << "Item removed! Updated list below: " << endl;
		cout << endl;
		inventory.printList();
	} else {
		cout << "Item: " << name << " not found, list not changed." << endl;
	}

	cout << endl;
	return 0;
}
