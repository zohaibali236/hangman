#include "hangman.h"

void hangman::printStructure(std::string msg, bool top = false, bool bottom = false)
{
    if(top)
    {
        std::cout << "+---------------------------------+" << std::endl;
        std::cout << "|";
    }
    else
        std::cout << "|";
    
    for(int i = msg.length(), truth = true; i < 33; i++, truth = !truth)
    {
        if(truth)
            msg = " " + msg;
        else
            msg = msg + " ";
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

void hangman::printLetters(char from, char to)
{
    std::string string;

    for(char i = from; i <= to; i++)
    {
        if(this->guesses.find(i) == -1)
        {
            string += i;
            string += " ";
        }
        else
            string += "  ";
    }
    printStructure(string);
}

void hangman::printAvailableLetters()
{
    printStructure("AVAILABLE LETTERS", false, true);
    printLetters('A', 'M');
    printLetters('N', 'Z');
}

void hangman::printInputWord()
{
    printStructure("GUESS THE WORD", true, true);

    std::string string;

    for(int i = 0, j = this->word.length(); i < j; i++)
    {
        if(this->guesses.find(this->word[i]) == -1)
        {
            string += "_ ";
        }
        else
        {
            string += word[i];
            string += " ";
        }
    }
    printStructure(string, 0, 1);
}


void hangman::play( )
{
    do
    {
        #if defined(_WIN32)
            system("cls");
        #else
            system("clear");
        #endif
        this->printStructure("HANG MAN", 1, 1);
        this->printHangman();
        this->printAvailableLetters();
        this->printInputWord();
        std::cout << ">";
        std::cin >> this->input;
        this->input = toupper(this->input);
        if(!(this->checkFoDuplicate()))
        {
            this->guesses += this->input;
        }
        else
        {
            std::cout << "> This character is already used";
            Sleep(8*100);
        }
        this->triesLeft();
        this->checkForWin();
    }
    while(this->h_try < 10 && !this->win);

    if(this->win)
    {
        #if defined(_WIN32)
            system("cls");
        #else
            system("clear");
        #endif
        this->printStructure("HANG MAN", 1, 1);
        this->printHangman();
        this->printAvailableLetters();
        this->printInputWord();

        std::cout << "You won!! Great :)";
    }
    else std::cout << "You lost!! Bad luck :(";

    Sleep(2*100);
}

hangman::~hangman() {}