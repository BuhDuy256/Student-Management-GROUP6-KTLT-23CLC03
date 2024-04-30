#pragma once

#include"System.h"

template<class T>
struct Node;
struct Student;
struct SchoolYear;

struct Class {
	std::string className;
	std::string schoolYear;
	Node<Student>* students = nullptr;
};

void createANewClassInCurrentSYear();
void displayTableOfFirstYearClasses(int &no);
void add1stStudentsTo1stClass(Node<Class>* claCurr);
void add1stStudentsTo1styearClassPage();
void importCSVStudentsOfAClass(Node<Class>* claCurr);
void importCSVStudentsOfAFirstYearClassPage();	
void displayTableOfStudentsInAClass(Node<Class>* claCurr, int &no);
void viewListOfStudentsInAClassPage();
void displayTableOfClassesStudyingInCurrentSemester(int &no);
void viewListOfClassesStudyingInCurrentSemesterPage();
void displayTableOfClassesInSystem(int &no);
void viewListOfClassesInSystemPage();