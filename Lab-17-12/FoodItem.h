#ifndef FOODITEMH
#define FOODITEMH

#include <cstring>

using namespace std;

class FoodItem {
   public:
      // TODO: Declare default constructor

      // TODO: Declare second constructor with arguments
      // to initialize private data members

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
