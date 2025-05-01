#include <iostream>
#include "Car.h"
using namespace std;

// Run and test:
// g++ *.cpp && ./a.out < test-1.txt && rm ./a.out

int main() {
   int modleYear;
   int purchasePrice;
   int currentYear;
   
   cin >> modleYear;
   cin >> purchasePrice;
   cin >> currentYear;
   
   /*TODO: Declare a pointer variable myCar to a Car object*/
   Car *car = new Car();  
   
   /* Call the mutator functions and then the PrintInfo function*/
   car -> SetModelYear(modleYear);
   car -> SetPurchasePrice(purchasePrice);
   car -> CalcCurrentValue(currentYear);
   
   car -> PrintInfo();
   
   delete car;
   
   return 0;
}
