#pragma once

#include"system.h"

template<class T>
struct Node;
struct Student;
struct SchoolYear;
struct Course;
struct Class {
    std::string className;
    std::string schoolYear;
    Node<Student>* students = nullptr;
};

void createANewClassInCurrentSYear();
void displayTableOfFirstYearClasses(int &no);
void add1stStudentsTo1stClass(Node<Class>* claCurr);
void add1stStudentsTo1styearClassPage();
void importCSVStudentsOfAClass(Node<Class>* claCurr);
void importCSVStudentsOfAFirstYearClassPage();
void displayTableOfStudentsInAClass(Node<Class>* claCurr, int &no);
void viewListOfStudentsInAClassPage();
void displayTableOfClassesStudyingInCurrentSemester(int &no);
void viewListOfClassesStudyingInCurrentSemesterPage();
void displayTableOfClassesInSystem(int &no);
void viewListOfClassesInSystemPage();
void deleteDuplicateTempCourses(Node<std::string>* TempCourses);
int countUniqueTempCourses(Node<std::string>* TempCourses);
bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind);
Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check);
Node<Class>* ChooseClass(int choice);
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass,Node<std::string>* StuUniqueCours);
void viewScoreBoardOfAClass();
