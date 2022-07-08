#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

#include "hangman.cpp"

int main()
{
    srand(time(0));
    hangman *game;
    game = new hangman;
    game->play();
    delete game;
    std::string input;
    std::cout << "\nType \"play\" to start over\n";
    std::cin >> input;
    if(input == "play")
    {
        hangman *game;
        game = new hangman;
        game->play();
        delete game;
    }
    else return 0;
}