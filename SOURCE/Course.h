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
	void viewStudentsList();
	void deleteStudent();
	void viewScoreboard();
	void addStudent();
	void updateInformation();
};

void addACourseInCurrSem(); // 1
void updateInformationOfACourse(); // 2
void deleteACourseInCurrSem(); // 3
void addStudentToACourse(); // 4
void removeAStudentFromACourse(); // 5
void importOutsideCSVStudentsInCourse(Node<Course>* couCurr, std::string fileName);
void uploadCSVFileContainingAListOfStudentsOfACourse(); // 6
void exportCSVStudentsOfACourse(); // 7
void viewListOfCoursesInCurrSem(); // 8
void viewListStudentInACourse(); // 9
void viewScoreboardOfACourse(); // 10
void chooseStudentToUpdateResult(Node<Course>* couCurr);
void updateAStudentResultOfACourse(); // 11


