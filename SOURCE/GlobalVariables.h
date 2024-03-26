#pragma once

#include<string>
#include"SchoolYear.h"
#include"Semester.h"
#include"Course.h"

extern std::string myID;
extern Semester currSem;
extern Node<SchoolYear>* currYear = nullptr;
extern Node<Course>* currCourse = nullptr;
