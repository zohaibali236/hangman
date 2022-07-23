#if !defined(__hangman)
    #define __hangman

    #include "gamemanager.h"

    #include <iostream>
    #include <string>
    #include <fstream>
    #include <vector>
    #include <time.h>

    #ifdef _WIN32
        #include <windows.h>
    #else
        #include <unistd.h>
    #endif

class hangman : public gamemanager
{  
    public:
        void printStructure(std::string, bool, bool);

        void printHangman();

        void printLetters(char, char);

        void printAvailableLetters();

        void printInputWord();

        void play();

        ~hangman();
};
#endif