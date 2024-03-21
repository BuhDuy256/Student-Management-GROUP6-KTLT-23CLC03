#pragma once

#include "Node.h"
#include "Course.h"
#include <iostream>

struct Semester {
	unsigned short number = 0; 
	std::string startDate;
	std::string endDate;
	Node<Course>* coursesList = nullptr;

	void addCourse(Course course);
	void deleteCourse(Course course);
	void viewCourses();
};