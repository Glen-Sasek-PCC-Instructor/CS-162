#include "FoodItem.h"
#include <iostream>
#include <iomanip> 
#include <cstring>

using namespace std;

int main() {
   char itemName[101];
   double amountFat, amountCarbs, amountProtein;
   double numServings;
   cout << fixed << setprecision(2);
   
   cin >> itemName;

   if(strcmp(itemName, "Water") == 0 || strcmp(itemName, "water") == 0) {
      FoodItem foodItem;
      foodItem.PrintInfo();
      cout << fixed << setprecision(2);
      cout << "Number of calories for " << 1.0 << " serving(s): " << foodItem.GetCalories(1.0) << endl;
   }
   
   else {
      cin >> amountFat;
      cin >> amountCarbs;
      cin >> amountProtein;
      cin >> numServings;
      
      FoodItem foodItem = FoodItem(itemName, amountFat, amountCarbs, amountProtein);
      foodItem.PrintInfo();
      cout << "Number of calories for " << 1.0 << " serving(s): " 
           << foodItem.GetCalories(1.0) << endl;
      cout << "Number of calories for " << numServings << " serving(s): " 
           << foodItem.GetCalories(numServings) << endl;
   }

   return 0;
}
