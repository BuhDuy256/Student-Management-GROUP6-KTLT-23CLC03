#pragma once

#include<iostream>

using namespace std;

extern int currYear;

template<class T>
struct Node;

struct SchoolYear;

struct Class;
struct Student;

struct Semester;
struct Course;
struct StudentScore;

template<class T>
struct Node {
	T data;
	Node<T>* next;
    Node(T dataValue) : data(dataValue), next(nullptr) {}
	Node(T dataValue, Node<T>* nextNode) : data(dataValue), next(nextNode) {}
};

struct Class { // Class is not linked to linked list of School Year
	string className;
	string schoolYear; 
	Student* students = nullptr;   
};

struct Staff {
	string ID;
	string name;
	string gender;
	string socialID;
	string password = "123445678";
};

struct Student { // Dynamic array of struct
	string ID;
    string name;
    string gender;
    string birthday;
    string socialID;
    string mainClass; // *
    string password = "12345678"; // *
	Course** addressCourses = nullptr; // Store Address Of Course Node
	void viewProfile();
	void viewCourses();
	void viewScores();
};

struct StudentScore { // An array 
	string studentID;
	string studentName;
	double midTerm = -1;
	double final = -1;
	double other = -1;
	double total = -1;
	double GPA = -1;
	StudentScore () : midTerm(0), final(0), other(0), total(0), GPA(0) {}
};

struct Course { // Singly linked list (Add course in head of list, not tail)
	string ID; // have character 
    string Name;
    string className;
    string teacherName;
    int courseSize = 50;
    string dayOfWeek;
    string session;
	StudentScore* score = nullptr;
};

struct Semester {
	unsigned short number = 0; 
	string startDate;
	string endDate;
	Node<Course>* Courses = nullptr;
};

struct SchoolYear {
	string year;	
	Semester semesters[3];
};







