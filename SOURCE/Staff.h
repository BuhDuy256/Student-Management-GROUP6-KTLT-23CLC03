#pragma once

#include"System.h"
#include<iostream>

struct Staff {
	std::string ID;
	std::string name;
	std::string gender;
	std::string birthday;
	std::string socialID;
	std::string password = "123445678";
};

void importAllStaffsCSV();
void saveAllStaffsData();
void deleteAllStaffData();

void viewStaffProfile();
void changeStaffPassword();