#include "main.h"
// COMPILE and run
// clear; make && ./main && make clean

// Compile and run with test input
// clear; make && ./main < test-2.txt && make clean

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


	cout << endl << "Current Inventory: " << endl;	
	inventory.printList();


    char ** names;
    inventory.getItemNames(names);

    for(int i = 0; i < inventory.getSize(); i++) {
        cout << names[i] << std::endl;
    }


    cout << endl;
    cout << endl;
    
    char buffer[MAX_CHAR + 1];
    float price = 0.0;
    int year = 0;
    int month = 0;
    int day = 0;

    cout << "Enter name of item1: ";
    cin.getline(buffer, MAX_CHAR, '\n');
    
    // Rice
    cout << "Enter price of item: ";
    cin >> price;
    
    // ignore newline because next read is >>
    
    cout << "Enter expiry date of item1: ";
    // required format yyyy/mm/dd
    cin >> year;
    cin.get(); // remove /
    
    cin >> month;
    cin.get();  

    cin >> day;
    cin.get(); // remove newline  


    cout << endl;
    cout << endl;
    
    Date date = Date(year, month, day); 

    InventoryItem inventoryItem = InventoryItem(buffer, price, date);

    inventoryItem.print();



	return 0;
}






























