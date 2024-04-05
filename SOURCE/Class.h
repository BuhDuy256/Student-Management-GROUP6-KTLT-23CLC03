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
void importCSVStudentsOfAClass(Node<Class>* claCurr);
void importCSVStudentsOfAFirstYearClassPage();
void displayTableOfFirstYearClasses(int &no); // no is the number of classes to reuse in another function
void viewListOfStudentsInAFirstYearClass();
void viewListOfFirstYearClasses();
void displayTableOfClassesInSystem(int &no);
void viewListOfClassesInSystem();