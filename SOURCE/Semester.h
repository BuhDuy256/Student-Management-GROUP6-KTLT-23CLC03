#pragma once

#include "Node.h"
#include "Course.h"
#include <string>
#include <iostream>
#include <iomanip>

struct Semester {
	bool isCreated = false;
	std::string startDate;
	std::string endDate;
	Node<Course>* Courses = nullptr;

	void addCourse(Course course);
	bool deleteCourse(int index);
	void viewCoursesList();
};