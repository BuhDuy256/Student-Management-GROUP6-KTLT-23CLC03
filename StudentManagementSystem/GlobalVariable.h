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
extern Semester latestSem;
extern int lastSemNumber;
extern Node<SchoolYear>* currSYear;
extern Semester currSem;
extern int currSemNumber;
extern Node<Staff>* listStaff;
extern Node<Staff>* currStaff;
extern Node<Course>* currCourse;
