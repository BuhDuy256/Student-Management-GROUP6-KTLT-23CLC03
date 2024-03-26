#pragma once

#include"Student.h"
#include"Node.h"
#include<iostream>

struct Class {
	std::string className;
	std::string schoolYear; 
	Node<Student>* students = nullptr;   
};
