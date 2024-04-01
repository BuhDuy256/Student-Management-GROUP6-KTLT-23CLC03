#pragma once

#include"System.h"

void importData();
void saveData();
void deleteData();
bool getChoice(int numberOfChoices, std::string prompt, int &choice);
bool checkNameValid(std::string name);
void formalize(std::string &name);
bool checkIDValid(std::string id);
std::string doubleToString(double value);
std::string removeQuotesFromPath(const std::string& path);
int getUser(std::string userID, std::string userPassowrd);
void findCurrSem();
bool checkClassExist(std::string className);
bool isValidClassName(std::string className);
bool ends_with(const std::string& str, const std::string& suffix);
std::string getNextSchoolYear(const std::string& currentYear);
void menuCommandHeader();