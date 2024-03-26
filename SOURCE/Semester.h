#pragma once

#include "Node.h"
#include "Course.h"
#include <iostream>
#include <iomanip>

struct Semester {
	bool isCreated = false; 
	std::string startDate;
	std::string endDate;
	Node<Course>* coursesList = nullptr;

	void addCourse(Course course);
	void deleteCourse(Course course);
	void viewCourses();
};