#pragma once

#include<iostream>
#include"System.h"

template<class T>
struct Node;
struct Student;
struct Class;
struct SchoolYear;
struct Course;

struct Student {
	std::string ID;
	std::string name;
	std::string gender;
	std::string birthday;
	std::string socialID;
	std::string mainClass;
	std::string password = "12345678";
	Node<Node<Course>*>* courseScores = nullptr;
};

void viewStudentProfile();
void viewStudentCourses();
void viewStudentScoresInCurrentSem();
void changeStudentPassword();