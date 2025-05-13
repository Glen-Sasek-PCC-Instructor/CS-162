//class definition for a list of songs and its size
//This class encapsulates the SongType object (an array of Songs and its size - like a playlist)
//This has been modified to have a struct for a Node and a Linked List.
#pragma once
#include "song.h"


//define class SongList for linked list of songs and size

class SongList
{
    private:
        //struct for each Node
        struct Node
        {
            SongType data;
            Node *next;
        };
        Node *head;
        Node *tail;
        int size;
    public:
        //constructors
        SongList();
        SongList(char []);
        //destructor
        ~SongList();
        //database functions
        void addSong(SongType &);
        void searchByTitle();
        void searchByArtist();
        void showList();
        int getSize();
        void writeData(char []);
        bool isLessThan(char [], char[]);
        void removeSong();
};
