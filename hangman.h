#include"gamemanager.h"
#ifndef __hangman

    #define __hangman
class hangman : public gamemanager

{
   
    public:
        hangman();

        void loadWord(std::string inputWord);

        void loadWord();

        void printStructure(std::string, bool, bool);

        void printHangman();

        void printLetters(char, char);

        void printAvailableLetters();

        void printInputWord();

        
        
        void play();

        
};
#endif