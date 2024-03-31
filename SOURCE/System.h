#pragma once

#include"Node.h"
#include"Staff.h"
#include"Student.h"
#include"Class.h"
#include"Course.h"
#include"SchoolYear.h"
#include"GlobalVariables.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<filesystem>
#include<limits>
#include<cstdlib> 
#include<unistd.h>
#include<iomanip>
#include<regex>

void importData();
void saveData();
void deleteData();

void startPage();
int getUser(std::string userID, std::string userPassowrd);
void signInPage();

// Student

void studentHomePage();

// Staff

void staffHomePage();
void staffCommandMenu();
void classManagementPage();

void createANewClassInCurrentSYear();
