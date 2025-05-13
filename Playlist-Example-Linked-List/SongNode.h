#include "iostream"
#include <cstring>

using namespace std;

const int MAXCHAR = 101;

class SongNode {
private:
	char songTitle[MAXCHAR];
	char songLength[MAXCHAR];
	char songArtist[MAXCHAR];
	SongNode* nextNodeRef; // Reference to the next node                                   

public:
	SongNode() {
		memset(songTitle, '0', sizeof(songTitle));
		memset(songLength, '0', sizeof(songLength));
		memset(songArtist, '0', sizeof(songArtist));
		nextNodeRef = NULL;
	}

	// Constructor                                                                                     
	SongNode(char *songTitleInit, char *songLengthInit, char *songArtistInit);

	// Constructor                                                                                     
	SongNode(char *songTitleInit, char *songLengthInit, char *songArtistInit, SongNode* nextLoc);

	// insertAfter
	void InsertAfter(SongNode* nodeLoc);

	// Get location pointed by nextNodeRef                                                            
	SongNode* GetNext();
   
   // Prints song information   
	void PrintSongInfo();
};
