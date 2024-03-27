#pragma once

#include"System.h"
#include<iostream>

template<class T>
struct Node;
struct Student;
struct SchoolYear;

struct Class {
	std::string className;
	std::string schoolYear; 
	Node<Student>* students = nullptr;   
};

void importAllClassesCSV();
void saveAllClassesData();
void deleteAllClassesData();

