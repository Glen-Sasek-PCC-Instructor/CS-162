#include <iostream>
using namespace std;

class GerbilNode {
   public:
      GerbilNode(int pupsValue) {
         pups = pupsValue;
      }

      ~GerbilNode() {
         cout << "Deallocating GerbilNode with " << pups << " pups." << endl;
      }

      int pups;
      GerbilNode* next;
};

class GerbilsList {
   public:
      GerbilsList() {
         head = nullptr;
      }
      
      /* Your code goes here */
      ~GerbilsList() {
         cout << "In GerbilsList destructor" << endl;
         
          // Start at the head of the list
          GerbilNode* it = head;
          
          // Iterate through the list and delete each node
          while (it != nullptr) {
              GerbilNode* next = it->next; // Save the next pointer before deleting current
              delete it; // This will call the DonkeyNode destructor
              it = next; // Move to the next node
          }
         
      }
      
      void Prepend(int pupsValue) {
         GerbilNode* newNode = new GerbilNode(pupsValue);
         newNode->next = head;
         head = newNode;
      }

   private:
      GerbilNode* head;
};

int main() {
   GerbilsList* userGerbils = new GerbilsList();
   int inputValue;
   int gerbilCount;
   int i;
  
   cin >> gerbilCount;
  
   for (i = 0; i < gerbilCount; i++) {
      cin >> inputValue;
      userGerbils->Prepend(inputValue);
   }

   delete userGerbils;
  
   return 0;
}
