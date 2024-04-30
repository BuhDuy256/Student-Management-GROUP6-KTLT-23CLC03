#pragma once

#include"System.h"

void importData();
void saveData();
void deleteData();

void getChoiceInt(int startChoiceNum, int endChoiceNum, std::string prompt, int& choice);

bool isValidClassName(const std::string& className, const std::string& currentYear);
bool isValidCouOrStuName(const std::string& name);
bool isValidCourseID(const std::string& courseID);
bool isValidStudentID(std::string id);
bool notExistclassNameOfCourse(const std::string& courseID, const std::string& className, const std::string& currentYear);

void formalize(std::string& name);
std::string doubleToString(double value);
std::string removeQuotesFromPath(const std::string& path);
int getUser(std::string userID, std::string userPassowrd);
void findCurrSem();
bool isClassExisted(std::string className);
bool ends_with(const std::string& str, const std::string& suffix);
std::string getNextSchoolYear(const std::string& currentYear);
void menuCommandHeader();
bool isValidDateFormat(const std::string& date); 
int dateToInt(std::string date);
bool isLeapYear(int year);
int daysInMonth(int month, int year);
int daysBetweenDates(const std::string& date1, const std::string& date2);
char getYesNo(std::string prompt);
bool checkMatchStudentIDAndName(std::string studentID, std::string studentName);