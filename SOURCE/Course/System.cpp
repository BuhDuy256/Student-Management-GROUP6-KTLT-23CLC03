#include "System.h"

bool getChoice(int numberOfChoices, std::string prompt, int &choice)
{
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);

    if (line.length() > 1 || !isdigit(line[0]) || line[0] < '1' || line[0] > numberOfChoices + '0')
    {
        std::cout << "Please choose valid choice.\n";
        return false;
    }
    
    choice = line[0] - '0';
    return true;
}