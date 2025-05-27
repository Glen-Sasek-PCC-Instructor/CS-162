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

	//invoke your functions here to do what is required

    InventoryItem item1 = inventory[0];
	InventoryItem item2 = inventory[1];
    //set up item1, item2

    // ..

    if(item1.isLessThan(item2)) 
    {
      cout << (*item1.getExpDate()) << " < " << (*item2.getExpDate()) << endl;
    }
    else
    {
      cout << (*item1.getExpDate()) << " > " << (*item2.getExpDate()) << endl;
    }


	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();
	return 0;
}
