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

        void loadWord(std::string);

        void printStructure(std::string, bool, bool);

        void printHangman();

        void printLetters(char, char);

        void printAvailableLetters();

        void printInputWord();

        void triesLeft();
        
        void play();

        void checkForWin();

        bool checkFoDuplicate() const;
};
#endif