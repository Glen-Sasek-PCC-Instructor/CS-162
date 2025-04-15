//*****************************************************************************
// Author: Glen
// Assignment: Example Discussion 3
// Date:
// Description:
// Sources: 
//*****************************************************************************


// write a program that reads a list of integers from input into an array and outputs "yes" if the list is sorted in ascending order between two provided positions. 
// Otherwise, output "no". The first input specifies the number of items in the list. The next set of inputs is the list. 
// The last two inputs are the start and end positions (inclusive, between 0 and count where count is the number of values in the array). 
// Assume the list contains no more than 20 integers and position 0 is the first element.

// ~~~~~~~ Ex: 1 ~~~~~~~
// Number of integers: 8 
// Enter the values: 5 6 7 4 3 2 1 0
// Enter start and end index: 0 2
// yes

// ~~~~~~~ Ex: 2 ~~~~~~~
// Number of integers: 6
// Enter the values: 1 2 3 4 5 2
// Enter start and end index: 2 5
// no

// Task:
// Must have at least 2 functions other than main. 
// Must use a for loop to read input and to check if the list is sorted.


// Compile command
// g++ main.cpp

// Run command
// ./a.out

// Compile and run test command
// g++ main.cpp && ./a.out

// Compile and run test command
// g++ main.cpp && ./a.out < test-1.txt && rm ./a.out

// Compile and run all tests command
// g++ main.cpp && for f in test*.txt; do ./a.out < $f; done &&  rm ./a.out


#include <iostream>

using namespace std;

const char PROMPT_NUMBER_OF_INTS[] = "Number of integers: "; 
const char PROMPT_ENTER_VALUES[] = "Enter the values: "; 
const char PROMPT_START_END_INDEX[] = "Enter start and end index: ";
const char MSG_YES[] = "yes";
const char MSG_NO[] = "no";

void getOptions(int &startIndex, int &endIndex, int arr[], int &arrSize);

bool sortedWithinRange(int startIndex, int endIndex, int arr[], int arrSize);

int main() {
  const int MAX_ARR_SIZE = 20;

  int arr[MAX_ARR_SIZE] = {0};
  int arrSize = 0;

  int startIndex = 0;
  int endIndex = 0;

  getOptions(startIndex, endIndex, arr, arrSize);

  cout << endl;
  if(sortedWithinRange(startIndex, endIndex, arr, arrSize)) {
    cout << MSG_YES << endl;
  } else {
    cout << MSG_NO << endl;
  }

  return 0;
}

void getOptions(int &startIndex, int &endIndex, int arr[], int &arrSize){
  cout << endl;
  cout << PROMPT_NUMBER_OF_INTS;
  cin >> arrSize;

  cout << endl;
  cout << PROMPT_ENTER_VALUES;
  for(int i = 0; i < arrSize; i++) {
    cin >> arr[i];
  }

  cout << endl;
  cout << PROMPT_START_END_INDEX;
  cin >> startIndex;
  cin >> endIndex;
}

bool sortedWithinRange(int startIndex, int endIndex, int arr[], int arrSize){
  bool sorted = true;

  for(int i = startIndex; i < endIndex && sorted; i++) {
    sorted = arr[i] < arr[i+1];
  }

  return sorted;
}