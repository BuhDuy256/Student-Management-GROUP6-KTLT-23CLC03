#pragma once

#include<iostream>
#include"System.h"

template<class T>
struct Node;
struct Student;
struct Class;
struct SchoolYear;
struct Staff;

struct StudentScore {
	std::string studentID;
	std::string studentName;
	double midTerm = -1;
	double final = -1;
	double other = -1;
	double total = -1;
};

struct Course {
	std::string ID;
	std::string Name;
	std::string className;
	std::string teacherName;
	int nCredits = 0;
	int courseSize = 0;
	std::string dayOfWeek;
	std::string session;
	std::string couSY;	
	int couSem;
	StudentScore* score = nullptr;
};

void importAllCoursesCSV();
void importContainingStudentsEnrolledInCourse(Node<Course>* couCurr);
void importAllStudentsInAllCoursesCSV();
void saveAllCoursesData();
void saveScoreboardOfACourse(Node<Course>* couCurr);
void saveAllScoreboardsData();
void deleteAllScoreboardsData();
void deleteAllCourseData();

std::string formatSchoolYear(const std::string& inputYear);
void exportCSVStudentsOfACourse();
void addACourseInCurrSem();
void displayTableListOfCoursesInCurrSem(int &no);
void viewListOfCoursesInCurrSem();
void updateInformationOfACoursePage();
void updateInformationOfACourse(int choice);
void deleteACourseInCurrSem();
void addStudentToACourse();