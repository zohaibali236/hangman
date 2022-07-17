#if !defined(__hangman)
    #define __hangman
class hangman : public gamemanager
{  
    public:
        void printStructure(std::string, bool, bool);

        void printHangman();

        void printLetters(char, char);

        void printAvailableLetters();

        void printInputWord();

        void play();
};
#endif