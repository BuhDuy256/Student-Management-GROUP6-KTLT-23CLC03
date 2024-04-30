#pragma once

#include"System.h"

void deleteDuplicateTempCourses(Node<std::string>* TempCourses);	
int countUniqueTempCourses(Node<std::string>* TempCourses);
bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind);
Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check);
Node<Class>* ChooseClass(int choice);
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass,Node<std::string>* StuUniqueCours);
void viewScoreBoardOfAClass();
