#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <time.h>

#include "hangman.h"

    hangman :: hangman()
{    this->h_try = 0;
    this->win = false;
    std::ifstream loader("words.txt");
    
    if(loader.is_open())
    {
        std::string temp;
        std::vector<std::string> vectorArray;

        while(std::getline(loader, temp))
            vectorArray.push_back(temp);   

        int rnd;

        rnd = std::rand() % vectorArray.size();

        //std::cout << vectorArray.size();

        this->word = vectorArray.at(rnd);

        //std::cout << word;
        loader.close();
    } 
    else
    {
        this->word = "NULL";
        this->win = true;
    }
 }

void hangman::printStructure(std::string msg, bool top = false, bool bottom = false)
{
    if(top)
    {
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|";
    }
    else
        std::cout << "|";
    
    bool truth = true;
    for(int i = msg.length(); i < 33; i++)
    {
        if(truth)
            msg = " " + msg;
        else
            msg = msg + " ";
        truth = !truth;
    }
    std::cout << msg;
    if(bottom)
    {
        std::cout << "|" << std::endl;
        std::cout << "+---------------------------------+" << std::endl;
    }
    else
        std::cout << "|" << std::endl;
}

void hangman::printHangman()
{
    if(this->h_try >= 1)
        printStructure("|");
    else
        printStructure("");

    if(this->h_try >= 2)
        printStructure("|");
    else
        printStructure("");

    if(this->h_try >= 3)
        printStructure("O");
    else
        printStructure("");
        
    if(this->h_try == 4)
        printStructure("/");
        
    if(this->h_try == 5)
        printStructure("/|");
        
    if(this->h_try >= 6)
        printStructure("/|\\");
    else
        printStructure("");
        
    if(this->h_try >= 7)
        printStructure("|");
    else
        printStructure("");

    if(this->h_try == 8)
        printStructure("/");
        
    if(this->h_try >= 9)
        printStructure("/ \\");
    else
        printStructure("");
}

void hangman::printLetters(std::string input, char from, char to)
{
    std::string string;

    for(char i = from; i <= to; i++)
    {
        if(input.find(i) == -1)
        {
            string += i;
            string += " ";
        }
        else
            string += "  ";
    }
    printStructure(string);
}

void hangman::printAvailableLetters(std::string takenLetters)
{
    printStructure("AVAILABLE LETTERS", false, true);
    printLetters(takenLetters, 'A', 'M');
    printLetters(takenLetters, 'N', 'Z');
}

void hangman::printInputWord(std::string guess)
{
    printStructure("GUESS THE WORD", true, true);

    std::string string;

    for(int i = 0; i < this->word.length(); i++)
    {
        if(guess.find(this->word[i]) == -1)
        {
            string += "_ ";
        }
        else
        {
            string += guess[i];
            string += " ";
        }
    }
    printStructure(string, 0, 1);
}

bool hangman::checkForWin()
{
    return this->win;
}

void hangman::triesLeft()
{
    for(int i = 0; i < this->guesses.length(); i++)
    {
        if(this->word.find(this->guesses[i]) == -1)
            this->h_try++;
    }
}

int main()
{
    srand(time(0));
    hangman game;
    do
    {
         system("cls");
        game.printStructure("HANG MAN", 1, 1);
        game.printHangman();
        game.printAvailableLetters(game.guesses);
        game.printInputWord(game.guesses);
        std::cout << ">";
        std::cin >> game.input;
        game.guesses += game.input;
        game.triesLeft();
    }
    while(game.h_try < 10);
    return 0;
}