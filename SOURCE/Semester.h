#pragma once

#include"Node.h"
#include"Course.h"
#include<iostream>

struct Semester {
	bool isCreated = false; 
	std::string startDate;
	std::string endDate;
	Node<Course>* Courses = nullptr;
};

void importAllSemestersCSV();
void saveAllSemestersData();