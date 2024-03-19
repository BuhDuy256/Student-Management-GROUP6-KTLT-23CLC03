#pragma once

#include<iostream>

struct StudentScore {  
	std::string studentID;
	std::string studentName;
	double midTerm = -1;
	double final = -1;
	double other = -1;
	double total = -1;
	double GPA = -1;
	StudentScore () : midTerm(0), final(0), other(0), total(0), GPA(0) {}
};

struct Course {
	std::string ID; 
	std::string Name;
	std::string className;
	std::string teacherName;
    int courseSize = 50;
	std::string dayOfWeek;
	std::string session;
	StudentScore* score = nullptr;
};