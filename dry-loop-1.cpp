//*****************************************************************************
// Author: 
// Assignment:
// Date:
// Description:
// Sources: 
//*****************************************************************************

#include <iostream>
#include <cstring>
using namespace std;

int main() {
  char userString[50];
  char* stringPointer = nullptr;

  cout << endl;
  cout << "// NON-DRY " << endl;
  strcpy(userString, "Hello world. How are you.");
  // NON-DRY 
  stringPointer = strchr(userString, '.');
  while (stringPointer != nullptr) {
    *stringPointer = '?';
    stringPointer = strchr(userString, '.');
  }
  cout << userString << endl;

  cout << endl;
  cout << "// break while(true) not allowed " << endl;
  strcpy(userString, "Hello world. How are you.");
  // break while(true) not allowed
  bool next = true;
  while (next) {
    stringPointer = strchr(userString, '.');
    if(stringPointer != nullptr ) {
      *stringPointer = '?';
    } else {
      next = false;
    }
  }
  cout << userString << endl;

  cout << endl;
  cout << "// break while(true) allowed " << endl;
  strcpy(userString, "Hello world. How are you.");
  // break while(true) allowed
  while (true) {
    stringPointer = strchr(userString, '.');
    if(stringPointer != nullptr ) {
      *stringPointer = '?';
    } else {
      break;
    }
  }
  cout << userString << endl;

  cout << endl;
  cout << "// Condensed/Minimized maybe to clever" << endl;
  strcpy(userString, "Hello world. How are you.");
  // Condensed/Minimized maybe to clever
  // But also common to do an assignment in while expression
  while ( ( stringPointer = strchr(userString, '.') ) != nullptr ) {
    *stringPointer = '?';
  }
  cout << userString << endl;

  return 0;
}