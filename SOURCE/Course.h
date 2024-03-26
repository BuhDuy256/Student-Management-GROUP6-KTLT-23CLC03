#pragma once

#include<iostream>
#include "Student.h"

struct StudentScore {  
	std::string studentID;
	std::string studentName;
	double midterm = -1;
	double final = -1;
	double other = -1;
	double total = -1;
};

struct Course {
	std::string ID; 
	std::string name;
	std::string className;
	std::string teacherName;
    int courseSize = 0;
	std::string dayOfWeek;
	std::string session;
	StudentScore* scoreList = nullptr;

	void updateInformation();
	
	void viewAllStudent();
	void addStudent(Student student);
	void deleteStudent(Student student);

	void viewScoreboard();
	void updateStudentResult();
};