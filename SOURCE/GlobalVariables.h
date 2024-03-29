#pragma once

#include"System.h"
#include<iostream>

template<class T>
struct Node;
struct Student;
struct Class;
struct StudentScore;
struct Course;
struct Semester;
struct SchoolYear;
struct Staff;

extern std::string myID;
extern Semester currSem;
extern Node<SchoolYear>* currYear;
extern Node<Course>* currCourse;
extern Node<Staff>* currStaff;
