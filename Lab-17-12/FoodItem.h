#ifndef FOODITEMH
#define FOODITEMH

#include <cstring>

using namespace std;

class FoodItem {
   public:
      // TODO: Declare default constructor
      FoodItem();

      // TODO: Declare second constructor with arguments
      // to initialize private data members
      FoodItem(const char* _name, const double& _fat, const double& _carbs, const double& _protein);

      void GetName(char *);

      double GetFat();

      double GetCarbs();

      double GetProtein();

      double GetCalories(double numServings);

      void PrintInfo();

   private:
      char name[101];
      double fat;
      double carbs;
      double protein;
};

#endif
