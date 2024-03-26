#pragma once

#include <iostream>
#include <iomanip>
#include <string>
struct Student;

struct StudentScore {  
	std::string studentID;
	std::string studentName;
	double midTerm = -1;
	double final = -1;
	double other = -1;
	double total = -1;
	double GPA = -1;
};

struct Course {
	std::string ID; 
	std::string Name;
	std::string className;
	std::string teacherName;
    int courseSize = 0;
	std::string dayOfWeek;
	std::string session;
	StudentScore* scoreList = nullptr;

	void updateInformation();
	
	void viewStudentsList();
	void addStudent(std::string studentID, std::string studentName);
	bool deleteStudent(int index);

	void viewScoreboard();
	void updateStudentResult();
};

