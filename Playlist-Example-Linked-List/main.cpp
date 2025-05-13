#include <iostream>
#include "SongNode.h"

// TODO: Write PrintPlaylist() function
void PrintPlaylist(SongNode *);

int main() {
	SongNode* headNode;
	SongNode* currNode;
	SongNode* lastNode;

	char songTitle[MAXCHAR];
	char songLength[MAXCHAR];
	char songArtist[MAXCHAR];

	// Front of nodes list                                                                         
	headNode = new SongNode();
	lastNode = headNode;

	// Read user input until -1  entered
	cin.getline(songTitle, MAXCHAR);
	while (strcmp(songTitle, "-1") != 0) {
		cin.getline(songLength, MAXCHAR);
		cin.getline(songArtist, MAXCHAR);

		currNode = new SongNode(songTitle, songLength, songArtist);
		lastNode->InsertAfter(currNode);
		lastNode = currNode;

		cin.getline(songTitle, MAXCHAR);
	}

	// Print linked list
	cout << "LIST OF SONGS" << endl;
	cout << "-------------" << endl;
	PrintPlaylist(headNode);
	
	return 0;
}

void PrintPlaylist(SongNode *head)
{
   SongNode *curr;
   for(curr = head->GetNext(); curr; curr = curr->GetNext())
   {
      curr->PrintSongInfo();
      cout << endl;
   }
}
   
