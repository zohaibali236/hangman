#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#include "hangman.cpp"

int main()
{
    int opt;
    std::cout << "Welcome to hangman game. Choose an option below(1 for multiplayer and 2 for singleplayer)" << std::endl;
    std::cin >> opt;
    srand(time(0));

    std::string input = "play";
    do
    {
        hangman *game;
        game = new hangman;

        if(opt == 1)
        {
            #if defined(_WIN32)
                system("cls");
            #elif defined(_WIN64)
                system("cls");
            #elif defined(__linux__)
                system("clear");
            #endif

            std::string word_to_guess;
            std::cout << "Enter the word you want to be guessed" << std::endl;
            std::cin >> word_to_guess;
            
            std::string temp;
            
            for(int i = 0, j = word_to_guess.length(); i < j; i++)
            {
                temp += toupper(word_to_guess[i]);
            }
            game->loadWord(temp);
        }
        else
        {
            game->loadWord();
        }

        game->play();
        delete(game);
        
        std::cout << "\nType \"play\" to start over or press any key to exit\n";
        std::cin >> input;    
    }
    while(input == "play");
    
    Sleep(3*100);
    return 0;
}