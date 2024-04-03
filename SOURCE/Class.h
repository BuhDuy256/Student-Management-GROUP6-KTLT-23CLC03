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

void importCSVStudentsOfAClass_Public();
void createANewClassInCurrentSYear();
void viewListOfStudentsInAClass();
void displayTableOfClassesInCurrentSemester(int &no); // no is the number of classes to reuse in another function
void viewListOfClassesInCurrentSemeter();
void viewListOfClassesInSystem();