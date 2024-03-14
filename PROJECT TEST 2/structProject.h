#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<iomanip>

template<class T>
struct Node;
template<class T>
struct Queue;
struct Class;
struct Student;
struct Semester;
struct Course;
struct SchoolYear;

template<class T>
struct Node {
	T data;
	Node<T>* next;
    Node(T dataValue) : data(dataValue), next(nullptr) {}
	Node(T dataValue, Node<T>* nextNode) : data(dataValue), next(nextNode) {}
};

template<class T>
struct Queue {
    Node<T>* head;
    Node<T>* tail;
    Queue() : head(nullptr), tail(nullptr) {}
	bool isEmpty();
    int size();
    T front();
    T back();
    void push(T value);
	void pushSchoolYear(SchoolYear value);
	void pushClass(Class value);
    void pushStudent(Student value);
    void pop();
};

struct Class {
    std::string className;
    std::string schoolYear;
    Queue<Student> students;
};

struct Student {
    std::string StudentID;
    std::string StudentName;
    std::string gender;
    std::string birthday;
    std::string socialID;
    std::string classOfStudent;
    std::string password;
    Queue<Course> courses;
    void generatePasswordFromID();
};

struct Semester {
    unsigned short semesterNumber;
    std::string startDate;
    std::string endDate;
    Queue<Course> courses;
};

struct Course {
    std::string courseID;
    std::string courseName;
    std::string className;
    std::string teacherName;
    std::string courseSize = "50";
    std::string dayOfWeek;
    std::string session;
    Queue<Student> students;
};

struct SchoolYear {
    std::string yearRange;
    Semester semesters[3];
    void addSemester(unsigned short semesterNumber, std::string startDate, std::string endDate);
};

void importCSVSchoolYear(Queue<SchoolYear> &HCMUS);
void displayAllSchoolYears(Queue<SchoolYear> &HCMUS);
void deleteAllSchoolYears(Queue<SchoolYear> &HCMUS);
void importCSVClass(Queue<Class> &classes);
void displayAllClasses(Queue<Class> &classes);
void deleteAllClasses(Queue<Class> &classes);
void printFormattedTableHeader();
Node<Class>* findClass(Queue<Class> &classes, std::string className);
void importCSVStudent(Queue<Class> &classes);
void displayAllStudentOfSchool(Queue<Class> &classes);
void deleteAllStudents(Queue<Class> &classes);


