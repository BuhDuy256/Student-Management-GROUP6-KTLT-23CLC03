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

struct SchoolYear {
	string year;	
	Semester semesters[3];
};

struct Class { // Class is not linked to linked list of School Year
	string className;
	string schoolYear; 
	Node<int>* listStuID;   
};

struct Student { // Dynamic array of struct
	int studentID;
    string studentName;
    string gender;
    string birthday;
    string socialID;
    string mainClass; // *
    string password; // *
	Node<string>* stuCourses = nullptr; // Storing List of all courses ID that student studied 
};

struct Course { // Singly linked list (Add course in head of list, not tail)
	string courseID; // have character 
    string courseName;
    string className;
    string teacherName;
    string courseSize = "50";
    string dayOfWeek;
    string session;
	StudentScore score[50];
};

struct StudentScore { // An array 
	string studentID;
	string studentName;
	double midTerm;
	double final;
	double other;
	double total;
	double GPA;
	StudentScore () : midTerm(0), final(0), other(0), total(0), GPA(0) {}
};

struct Semester {
	unsigned short semesterNumber; // whyneedthis
	string startDate;
	string endDate;
	Node<Course>* Courses = nullptr;
};








