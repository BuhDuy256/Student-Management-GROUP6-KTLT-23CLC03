#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include<iomanip>
using namespace std;
template<class T>
struct Node {
	T data;
	Node<T>* next;
	Node<T>** nextt;
    Node(T dataValue) : data(dataValue), next(nullptr) {}
	Node(T dataValue, Node<T>* nextNode) : data(dataValue), next(nextNode) {}
	Node(T dataValue, Node<T>** nexttNode) : data(dataValue), nextt(nexttNode) {}
};
struct Student{
	std::string ID;
	std::string name;
	std::string gender;
	std::string birthday;
	std::string socialID;
	std::string mainClass;
	std::string password = "12345678";
	Node<Node<Course>*>*addressCourses = nullptr;
	void viewProfile();
	void viewCourses();
	void viewScores();
};
struct Class {
	std::string className;
	std::string schoolYear;
	Node<Student>* students = nullptr;
};
struct Course {
	std::string ID;
	std::string Name;
	std::string className;
	std::string teacherName;
    int courseSize = 50;
	std::string dayOfWeek;
	std::string session;
	StudentScore* score = nullptr;
};
struct StudentScore {
	std::string studentID;
	std::string studentName;
	double midTerm = -1;
	double final = -1;
	double other = -1;
	double total = -1;
	double GPA = -1;
	StudentScore () : midTerm(0), final(0), other(0), total(0), GPA(0) {}
};
void pressEnterToContinue();
void displayLoginConsole();
void login();
void displayStudentMenu();
void displayStudentProfile();
void displayCourses();
void changePassword();

#endif // STUDENT_H
