//This is the implementation file for the SongList class
#include "songlist.h"
#include "tools.h"
#include <fstream>

//constructors
SongList::SongList()
{
    head = NULL;
    tail = NULL;
    size = 0;
}

//constructor from file
SongList::SongList(char fileName[])
{
    head = NULL;
    tail = NULL;
    size = 0;
    ifstream inFile;
    SongType aSong;
    char tempTitle[MAXCHAR], tempArtist[MAXCHAR];
    int tempDuration;
    int tempBPS;

    inFile.open(fileName);
    if(!inFile)
    {
        cout << "cannot open file! Exiting!!" << endl;
        exit(0);
    }
    inFile.getline(tempTitle, MAXCHAR, ';');
    while(!inFile.eof())
    {
        inFile.getline(tempArtist, MAXCHAR, ';');
        inFile >> tempDuration;
        inFile.ignore(5, ';');
        inFile >> tempBPS;
        inFile.ignore(5, '\n');
        //populate aSong;
        aSong.setSongTitle(tempTitle);
        aSong.setSongArtist(tempArtist);
        aSong.setDuration(tempDuration);
        aSong.setBPS(tempBPS);
        addSong(aSong);
        inFile.getline(tempTitle, MAXCHAR, ';');
    }
    inFile.close();
}

//destructor
SongList::~SongList()
{
    //delete list
    Node *curr = head;
    while(curr)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
    tail = NULL;
}

//Add a song to the playlist
//Note the changes to this function
void SongList::addSong(SongType &aSong)
{
    Node *newNode = NULL, *curr = NULL, *prev = NULL;
    char str1[MAXCHAR], str2[MAXCHAR];
    //populate newNode
    newNode = new Node;
    newNode->data = aSong;
    newNode->next = NULL;
    //check to see if list is empty
    if(!head)
    {
        head = newNode;
        tail = newNode;
    }
    //if list is not empty, then insert sorted by title
    else
    {
        curr = head;
        curr->data.getSongTitle(str1);
        newNode->data.getSongTitle(str2);
        while(curr && isLessThan(str1, str2))
        {
            prev = curr;
            curr = curr->next;
            if(curr)
            {
                curr->data.getSongTitle(str1);
            }
        }
        //check to see if we are at the end of our list
        if(!curr)
        {
            tail->next = newNode;
            tail = newNode;
        }
        //insert in between
        else if(prev)
        {
            newNode->next = curr;
            prev->next = newNode;
        }
        //insert at the beginning
        else
        {
            newNode->next = curr;
            head = newNode;
        }
    }
    size++;
}

//search by Title
void SongList::searchByTitle()
{
    char searchTitle[MAXCHAR];
    char tempTitle[MAXCHAR];
    cout << "Please enter title to search for:";
    cin.get(searchTitle, MAXCHAR);
    convertCase(searchTitle);
    for(Node *curr = head; curr; curr = curr->next)
    {
        curr->data.getSongTitle(tempTitle);
        convertCase(tempTitle);
        if(strstr(tempTitle, searchTitle) != NULL)
        {
            curr->data.printSong();
        }
    }
    cout << endl;
}

//search by Artist
void SongList::searchByArtist()
{
    char tempArtist[MAXCHAR], srchArtist[MAXCHAR];
    cout << "Please enter the artist to search for: ";
    cin.getline(srchArtist, MAXCHAR);
    for(Node *curr = head; curr; curr = curr->next)
    {
        curr->data.getSongArtist(tempArtist);
        if(strstr(tempArtist, srchArtist) != NULL)
        {
            curr->data.printSong();
        }
    }
    cout << endl;
}

//writes the data to the file
void SongList::writeData(char fileName[])
{
    ofstream outFile;
    outFile.open(fileName);
    Node *curr;
    for(curr = head; curr; curr = curr->next)
    {
      curr->data.printSong(outFile);
    }
    cout << endl;
}

//displays the list
void SongList::showList()
{
    int count = 1;
    Node *curr;
    for(curr = head; curr; curr = curr->next)
    {
        cout << count << ".";
        curr->data.printSong();
        count++;
    }
    cout << endl;
}

//function to compare 2 strings
bool SongList::isLessThan(char str1[], char str2[])
{
    if(strcmp(str1, str2) < 0)
        return true;
    return false;
}


void SongList::removeSong()
{
    cout << "TODO: void SongList::removeSong()" << endl;    
}
