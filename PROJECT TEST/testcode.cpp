#include"struct.h"
#include<iostream>
#include<fstream>
#include<sstream>

void importCSVSchoolYear(std::string& fileName, SY_Stack& syStack) {
    std::ifstream inSY (fileName);
    if (!inSY.is_open()) {
        std::cout << "Cann't Dowload School Year File";
        return;
    }
    std::string line;
    while(std::getline(inSY, line)) {
        syStack.syPush(line);
        // std::cout << line;
    }
    inSY.close();
}

int main () {
    std::string fileName = "SchoolYear.csv";
    SY_Stack syStack;
    importCSVSchoolYear(fileName, syStack); 
    syStack.syDisplay();
    while(!syStack.syIsEmpty()) 
        syStack.syPop();
    return 0;
}