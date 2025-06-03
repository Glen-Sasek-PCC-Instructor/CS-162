#include "main.h"
#include <limits> // cin.ignore(numeric_limits<streamsize>::max(), '\n');

// Run and test
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

	//invoke your functions here to do what is required

	// You should read in the expDate from the user. 
	// Remember to prompt the user! You need to display the returned older items. 
	// You can take advantage of operator << for InventoryItem . Please label your output clearly.

	// Enter the expiration date to find items: 2021/11/10
	cout << endl;
	cout << "Enter the expiration date to find items: ";
	Date maxAge;
    cin >> maxAge;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Requires #include <limits>

	InventoryItem *olderItems;
	int olderItemsSize = inventory.getOlderItems(maxAge, olderItems);

	if(olderItemsSize > 0) {
		cout << "Yes! There are old items in your list." << endl;
		for(int i =0; i < olderItemsSize; i++) {
			olderItems[i].print();
		}
		// Yes! There are old items in your list.
		// banana  0.69    Wed 2021-04-28
		// donut     1.00    Thu 2021-10-28
		// fish         5.88    Mon 2021-02-15
		// milk        2.99    Tue 2021-03-02
		// yogurt    6.38    Sun 2021-06-13
	} else {
		cout << "No older items :(" << endl;
	}

	delete[] olderItems;


	cout << endl;
	cout << "Removing first and last nodes." << endl;
	inventory.removeFirstAndLast();
	cout << "Updated list below:" << endl;
	inventory.printList();


	// banana  0.69    Wed 2021-04-28
	// cookie    0.50    Sun 2023-02-12
	// rice         2.39    Thu 2022-05-12
	// donut     1.00    Thu 2021-10-28
	// egg         3.88    Sun 2022-01-30
	// fish         5.88    Mon 2021-02-15
	// milk        2.99    Tue 2021-03-02


    cout << endl;
	return 0;
}
