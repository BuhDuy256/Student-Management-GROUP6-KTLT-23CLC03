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
	int maxStudents = 0;
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

void addACourseInCurrSem(); 
void updateInformationOfACourse(); 
void deleteACourseInCurrSem(); 
void addStudentToACourse(); 
void removeAStudentFromACourse(); 
void importOutsideCSVStudentsInCourse(Node<Course>* couCurr, std::string fileName);
void uploadCSVFileContainingAListOfStudentsOfACourse(); 
void exportCSVStudentsOfACourse(); 
void uploadCSVScoreboardOfACourse(Node<Course>* couCurr);
void importScoreboardOfACourse();
void viewListOfCoursesInCurrSem(); 
void viewListStudentInACourse(); 
void viewScoreboardOfACourse(); 
void chooseStudentToUpdateResult(Node<Course>* couCurr);
void updateAStudentResultOfACourse(); 


