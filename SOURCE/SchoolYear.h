#pragma once

#include"Semester.h"
#include<iostream>

struct SchoolYear {
	std::string year;
	Semester semesters[3];

	void createSemester();
};
void createASchoolYear(Node<SchoolYear>* &CurYear);
void displayAllSchoolYears(Node<SchoolYear>* CurYear);
