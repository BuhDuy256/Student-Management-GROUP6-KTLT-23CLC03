#pragma once

#include"System.h"

template<class T>
struct Node;
struct Student;
struct Class;
struct StudentScore;
struct Course;
struct Staff;

struct Semester {
	bool isCreated = false;
	std::string startDate;
	std::string endDate;
	Node<Course>* Courses = nullptr;
};

void importAllSemestersCSV();
void saveAllSemestersData();

struct SchoolYear {
	std::string year;
	Node<Class>* classes = nullptr;
	Semester semesters[3];
};

void importAllSchoolYearsCSV();
void reverseSchoolYearsList(Node<SchoolYear>*& syHead);
void saveAllSchoolYearsData();
void deleteAllSchoolYearsData();
void findCurrSem();