#pragma once

#include"System.h"

template<class T>
struct Node;
struct Student;
struct Class;
struct StudentScore;
struct Course;
struct Semester;
struct SchoolYear;
struct Staff;

struct CourseAddress {
	std::string courseID;
	Node<Node<Course>*>* address = nullptr;
};

bool findStudentAndAddCourse(std::string studentID, Node<Course>*& courseAddress);
void deleteCourseAddressOfAStudent(std::string studentID, Node<Course>*& courseAddress);
void removeDuplicateCourseAddress(Node<CourseAddress>*& list);
void displayTableScoreboardOfAClass(Node<Class>*& claCurr);
void viewScoreboardOfAClass();


