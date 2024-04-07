#pragma once

#include"System.h"

bool findStudentAndAddCourse(std::string studentID, Node<Course>*& courseAddress);
void deleteCourseAddressOfAStudent(std::string studentID, Node<Course>*& courseAddress);
void viewScoreboardOfAClass();


