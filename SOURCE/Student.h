#pragma once

#include<iostream>
#include"GlobalVariables.h"

struct Student {
	std::string ID;
	std::string name;
	std::string gender;
	std::string birthday;
	std::string socialID;
	std::string mainClass;
	std::string password = "12345678";  
};

void importAllStudentsCSV();
void saveAllStudentsData();
void deleteAllStudentsData();
