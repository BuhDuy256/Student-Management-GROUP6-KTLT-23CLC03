#pragma once

#include"Student.h"
#include<iostream>

struct Class { 
	std::string className;
	std::string schoolYear; 
	Student* students = nullptr;   
};