#include "main.h"

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

	cout << endl;
	cout << endl;
	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();

	//invoke your functions here to do what is required
	cout << endl;
	cout << endl;
	cout << "Enter the maximum price and I will print the items below that price $: "; // 5.00
    float max_price = 0.0;
	int count = 0;
	InventoryItem *temp;
	cin >> max_price;
	count = inventory.getLowerCostItems(max_price, temp);
    cout << "There are " << count << " items below that price." << endl;
    cout << "The items in your list below that price are:" << endl;
	for(int i = 0; i < count; i++) {
		temp[i].print();
	}

    inventory.swapFirstAndLast();
	cout << endl;
	cout << endl;
	cout << "After swapping the first and last item the list is:" << endl;
	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();
	return 0;
}
