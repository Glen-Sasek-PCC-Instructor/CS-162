//implementation file for song.h
//with pointers and dynamic char arrays
#include "song.h"
#include <fstream>

//constructors
//default constructor
SongType::SongType()
{
    //allocate memory for title first!!!
    title = new char[MAXCHAR];
    strcpy(title, "No title");
    //allocate memory for artist next!!!
    artist = new char[MAXCHAR];
    strcpy(artist, "no artist");
    //set values to 0
    duration = 0;
    BPS = 0;
}

//constructor with parameters
SongType::SongType(char *newTitle, char *newArtist, int newDuration, int newBPS)
{
   //allocate memory for title first!!!
    title = new char[MAXCHAR];
    strcpy(title, newTitle);
    //allocate memory for artist next!!!
    artist = new char[MAXCHAR];
    strcpy(artist, newArtist);
    duration = newDuration;
    BPS = newBPS;
}

//Copy Constructor
SongType::SongType(const SongType &aSong)
{
    title = new char[strlen(aSong.title) + 1];
    artist = new char[strlen(aSong.artist) + 1];
    *this = aSong;
}

//destructor
SongType::~SongType()
{
    //deallocate memory for title
    if(title)
    {
        delete [] title;
        title = NULL;
    }
    //deallocate memory for artist
    if(artist)
    {
        delete [] artist;
        artist = NULL;
    }
}

//mutator functions
//for Song title
void SongType::setSongTitle(char *newTitle)
{
    //if title exists, delete and reallocate just enough for newTitle
    if(title)
    {
        delete [] title;
        title = NULL;
    }
    title = new char[strlen(newTitle)+1];
    strcpy(title, newTitle);
}

//for Song artist
void SongType::setSongArtist(char *newArtist)
{
    //if artist exists, delete and reallocate just enough for newArtist
    if(artist)
    {
        delete [] artist;
        artist = NULL;
    }
    artist = new char[strlen(newArtist)+1];
    strcpy(artist, newArtist);
}

//for Song duration
void SongType::setDuration(int newDuration)
{
    duration = newDuration;
}

//for song BPS
void SongType::setBPS(int newBPS)
{
    BPS = newBPS;
}

//accessor functions
void SongType::getSongTitle(char *returnTitle)
{
    strcpy(returnTitle, title);
}

void SongType::getSongArtist(char *returnArtist)
{
    strcpy(returnArtist, artist);
}

int SongType::getSongDuration()
{
    return duration;
}

int SongType::getSongBPS()
{
    return BPS;
}

//comparison method for durations for 2 songs
bool SongType::isLonger(SongType aSong)
{
    if(duration > aSong.duration)
        return true;
    else
        return false;
}

//search for an artist name and print the song if it exists
bool SongType::isArtist(char *srchArtist)
{
    if(strstr(artist, srchArtist) != NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//print the song
void SongType::printSong()
{
    cout << title << ';' << artist << ';' << duration << ';' << BPS << endl;
}

//print to the file
void SongType::printSong(ofstream &out)
{
    out << title << ';' << artist << ';' << duration << ';' << BPS << endl;
}

//assignment operator overloaded
const SongType& SongType::operator= (const SongType& aSong)
{
    //if it is a self copy, don't do anything
    if (this == &aSong)
        return *this;
    //make current object *this a copy of the passed in song
    else
    {
        this->setSongTitle(aSong.title);
        this->setSongArtist(aSong.artist);
        this->duration = aSong.duration;
        this->BPS = aSong.BPS;

        return *this;
    }
}
