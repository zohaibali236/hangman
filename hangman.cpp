#include "hangman.h"

hangman::hangman()
{    
    this->h_try = 0;
    this->win = false;
    std::ifstream loader("words.txt");
    
    if(loader.is_open())
    {
        std::string temp;        
        std::vector <std::string> vectorArray;

        while(std::getline(loader, temp))
            vectorArray.push_back(temp);   

        int rnd = (std::rand() % vectorArray.size());

        this->word = vectorArray.at(rnd);

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

    for(int i = 0, j = this->word.length(); i < j; i++)
    {
        if(guess.find(this->word[i]) == -1)
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

bool hangman::checkForWin()
{
    std::string temp;
    for(int i = 0, j = this->guesses.length(); i < j; i++)
    {
        if((this->word.find(this->guesses[i])) != -1)
        {
            temp += this->guesses[i];
        }
    }

    this->win = false;
    std::string temp2;
    for(int i = 0, j = this->word.length(); i < j; i++)
    {
        for(int k = 0; k < j; k++)
        {
            if(this->word[i] == temp[k])
            {
                temp2 += temp[k];
            }
        }
    }

    if(this->word == temp2)
        this->win = true;

    return this->win;
}

void hangman::triesLeft()
{
    if(this->word.find(this->input) == -1)
    {
        this->h_try++;
    }
}

bool hangman::checkFoDuplicate() const
{
    if(this->guesses.empty())
        return false;

    bool _bool;

    for(int i = 0, j = this->guesses.length(); i < j; i++)
    {
        if(this->guesses[i] == this->input)
        {
            _bool = true;
            break;
        }
        else _bool = false;
    }
    return _bool;
}

void hangman::play( )
{
    do
    {
        #if defined(_WIN32)
            system("cls");
        #elif defined(_WIN64)
            system("cls");
        #elif defined(__linux__)
            system("clear");
        #endif
        this->printStructure("HANG MAN", 1, 1);
        this->printHangman();
        this->printAvailableLetters(this->guesses);
        this->printInputWord(this->guesses);
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
            Sleep(5*100);
        }
        this->triesLeft();
        this->checkForWin();
    }
    while(this->h_try < 10 && !this->checkForWin());

    if(this->checkForWin())
    {
        system("cls");
        this->printStructure("HANG MAN", 1, 1);
        this->printHangman();
        this->printAvailableLetters(this->guesses);
        this->printInputWord(this->guesses);

        std::cout << "You won!! Great :)";
    }
    else std::cout << "You lost!! Bad luck :(";

    Sleep(2*100);
}
