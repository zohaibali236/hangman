#if !defined(_gamemanager)
	#define _gamemanager
	
    #include <string>
    #include <fstream>
    #include <vector>
    #include <time.h>

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

        virtual ~gamemanager();
};
#endif