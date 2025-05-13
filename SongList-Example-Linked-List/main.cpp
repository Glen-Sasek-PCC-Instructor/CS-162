//The driver file with main() to test the Song class.
#include "song.h"
#include "tools.h"

//main
int main()
{
    //create a list of songs.
    char fileName[MAXCHAR] = "songs.txt";
    SongList playList(fileName);
    char option;
    do
    {
        displayMenu();
        option = readOption();
        exeCmd(option, playList);
    }while(tolower(option != 'q'));
    playList.writeData(fileName);

    return 0;
}
