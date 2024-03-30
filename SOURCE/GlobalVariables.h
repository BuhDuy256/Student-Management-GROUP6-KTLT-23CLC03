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

extern Node<Student>* currStudent;
extern Node<SchoolYear>* latestSYear;
extern int latestSem;
extern Node<SchoolYear>* currSYear;
extern Semester currSem;
extern Node<Staff>* listStaff;
extern Node<Staff>* currStaff;

