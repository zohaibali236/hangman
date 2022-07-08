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
    srand(time(0));
    hangman *game;
    game = new hangman;
    game->play();
    delete(game);
    std::string input;
    std::cout << "\nType \"play\" to start over\n";
    std::cin >> input;
    
    while
    (input == "play")
    {
        hangman *game;
        game = new hangman;
        game->play();
        delete(game);
        std::cout << "\nType \"play\" to start over\n";
        std::cin >> input;
    
    }
    return 0;
}