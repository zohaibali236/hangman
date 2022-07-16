#ifndef _gamemanager
  #define _gamemanager
class gamemanager 
{
    protected:
        char input;
        std::string word;
        bool win;
        int h_try;
        std::string guesses;
        

    public:
    gamemanager();

    void loadWord();

    void loadWord(std::string);
         
    void triesLeft();

    void printHangman();
        
    void checkForWin();

    bool checkFoDuplicate() const;
};
#endif


