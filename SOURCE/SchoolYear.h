#pragma once

#include "Semester.h"
#include "Class.h"
#include <iostream>

struct SchoolYear {
	std::string year;
	Node<Class>* classes = nullptr;
	Semester semesters[3];

	bool createANewSemester();
};

