#ifndef __hangman
    #define __hangman
class hangman
{
    private:
        int h_try;
        char input;
        std::string guesses;
        std::string word;
        bool win;

    public:
        hangman();

        void loadWord();

        void printStructure(std::string, bool, bool) ;

        void printHangman();

        void printLetters(std::string, char, char);

        void printAvailableLetters(std::string);

        void printInputWord(std::string);

        void triesLeft();
        
        void play( );

        bool checkForWin();

        bool checkFoDuplicate() const;
};
#endif