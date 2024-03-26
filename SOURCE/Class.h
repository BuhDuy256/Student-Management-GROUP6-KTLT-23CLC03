#pragma once

#include"Student.h"
#include"Node.h"
#include "SchoolYear.h"
#include<iostream>

struct SchoolYear;

struct Class {
	std::string className;
	std::string schoolYear; 
	Node<Student>* students = nullptr;   
};

void createANewClass(Node<Class>* &CurClass,std::string classname,Node<SchoolYear>* CurYear);
void viewAllClassesInSchool(Node<Class>* CurClass);
void viewAllClassesInASchoolYear(Node<Class>* CurClass,Node<SchoolYear>* CurYear);
