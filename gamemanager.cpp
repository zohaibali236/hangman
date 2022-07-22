#include"gamemanager.h"

gamemanager::gamemanager()
{
    this->h_try = 0;
    this->win = false;
    this->input = '\0';
    this->guesses = "";
    this->word = "";
 
}

void gamemanager::loadWord(std::string inputWord)
{
    this->word = inputWord;

    std::ofstream loader("words.txt", std::ios_base::app);

    if(loader.is_open())
    {
        loader << std::endl << inputWord;
    }

    loader.close();

}
void gamemanager::loadWord()
{
    std::ifstream loader("words.txt");
    
    if(loader.is_open())
    {
        std::string temp;        
        std::vector <std::string> vectorArray;

        while(std::getline(loader, temp))
            vectorArray.push_back(temp);   

        int rnd = (std::rand() % vectorArray.size());

        this->word = vectorArray.at(rnd);
    } 
    else
    {
        this->word = "NULL";
        this->win = true;
    }
    loader.close();

}

void gamemanager::checkForWin()
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

}


void gamemanager::triesLeft()
{
    if(this->word.find(this->input) == -1)
    {
        this->h_try++;
    }
}

bool gamemanager::checkFoDuplicate() const
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