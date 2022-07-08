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

    std::string input = "play";

    do
    {
        hangman *game;
        game = new hangman;
        game->play();
        delete(game);

        std::cout << "\nType \"play\" to start over or press any key to exit\n";
        std::cin >> input;    
    }
    while(input == "play");
    Sleep(3*100);
    return 0;
}