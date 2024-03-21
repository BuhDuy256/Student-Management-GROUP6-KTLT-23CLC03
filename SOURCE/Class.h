#pragma once

#include"Student.h"
#include<iostream>

struct Class {
	std::string className;
	std::string schoolYear;
	Student* students = nullptr; //USE NODE HERE BECAUSE WE NEED NEXT (Node<Student>* students = nullptr)
};
void createANewClass(Node<Class>* &CurClass,string classname,Node<SchoolYear>* CurYear);
void viewAllClassesInSchool(Node<Class>* CurClass);
void viewAllClassesInASchoolYear(Node<Class>* CurClass,Node<SchoolYear>* CurYear);
