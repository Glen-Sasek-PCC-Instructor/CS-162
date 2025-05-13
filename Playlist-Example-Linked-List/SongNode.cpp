#include "SongNode.h"

// Constructor                                                                                     
SongNode::SongNode(char *songTitleInit, char *songLengthInit, char *songArtistInit) {
	strcpy(this->songTitle, songTitleInit);
	strcpy(this->songLength, songLengthInit);
	strcpy(this->songArtist, songArtistInit);
	this->nextNodeRef = NULL;
}

// Constructor                                                                                     
SongNode::SongNode(char *songTitleInit, char *songLengthInit, char *songArtistInit, SongNode* nextLoc) {
	strcpy(this->songTitle, songTitleInit);
	strcpy(this->songLength, songLengthInit);
	strcpy(this->songArtist, songArtistInit);
	this->nextNodeRef = nextLoc;
}

// insertAfter
void SongNode::InsertAfter(SongNode* nodeLoc) {
	SongNode* tmpNext;
	tmpNext = this->nextNodeRef;
	this->nextNodeRef = nodeLoc;
	nodeLoc->nextNodeRef = tmpNext;
}

// Get location pointed by nextNodeRef                                                            
SongNode* SongNode::GetNext() {
	return this->nextNodeRef;
}

// TODO: Write PrintSongInfo() function
void SongNode::PrintSongInfo() {
	cout << "Title: " << this->songTitle << endl << "Length: " << this->songLength << endl << "Artist: " << this->songArtist << endl;
}
