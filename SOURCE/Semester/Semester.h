#pragma once

#include "Node.h"
#include "Course.h"
#include <string>
#include <iostream>
#include <iomanip>

struct Semester {
	unsigned short number = 0; 
	std::string startDate;
	std::string endDate;
	Node<Course>* coursesList = nullptr;

	void addCourse(Course course);
	bool deleteCourse(int index);
	void viewCoursesList();
};