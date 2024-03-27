#pragma once

#include"Semester.h"
#include"Class.h"
#include<iostream>
#include"GlobalVariables.h"

struct SchoolYear {
	std::string year;
	Node<Class>* classes = nullptr;
	Semester semesters[3];
};

void importAllSchoolYearsCSV();
void reverseSchoolYearsList(Node<SchoolYear>* &syHead);
void saveAllSchoolYearsData();
void deleteAllSchoolYearsData();