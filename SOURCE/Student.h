#pragma once

#include"Course.h"
#include<iostream>

struct Student {
	std::string ID;
	std::string name;
	std::string gender;
	std::string birthday;
	std::string socialID;
	std::string mainClass;
	std::string password = "12345678";
	Course** addressCourses = nullptr; //Use node here (need next)
	void viewProfile();
	void viewCourses();
	void viewScores();
};
