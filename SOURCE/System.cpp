#include "System.h"

bool getChoice(int numberOfChoices, std::string prompt, int &choice)
{
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);

    if (line.length() > 1 || !isdigit(line[0]) || line[0] < '1' || line[0] > numberOfChoices + '0')
    {
        std::cout << "Please choose valid choice between " << 1 << " and " << numberOfChoices << std::endl;
        return false;
    }
    
    choice = line[0] - '0';
    return true;
}

bool checkNameValid(std::string name)
{   
    for (char c : name) 
    {
        if (!std::isalpha(c) && !isspace(c))
        {
            std::cerr << "Please input properly name with no special characters or digits\n";
            return false;
        }
    }
    return true;
}

bool checkIDValid(std::string id)
{
    for (char c : id) 
    {
        if (!isdigit(c))
        {
            std::cerr << "Please input properly id with no characters other than digits\n";
            return false;
        }
    }
    return true;
}

void formalize(std::string &name)
{
    std::string formalizedName;
    bool lastWasSpace = true;
    for (char c : name) 
    {
        if (std::isspace(c)) 
        {
            if (!lastWasSpace) 
            {
                formalizedName += ' ';
                lastWasSpace = true;
            }
        } 
        else 
        {
            if (lastWasSpace) c = toupper(c);
            else c = tolower(c);

            formalizedName += c;
            lastWasSpace = false;
        }
    }
    name = formalizedName;
    if (*(name.end() - 1) == ' ') name.pop_back();
}

