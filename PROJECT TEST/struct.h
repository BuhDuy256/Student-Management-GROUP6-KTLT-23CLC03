#pragma once

#include<iostream>
#include<string>

struct Course;
struct Student;

struct Class {
    std::string ClassName;
    int ClassSize;
    Student* Students;
    Class* ClaNext;
    Class* ClaPrev;
};

struct Student {
    std::string StudentID;
    std::string StudentName;
    std::string Gender;
    std::string Birthday;
    std::string SocialID;
    std::string Class;
    std::string Password = "12345678";
    Course* CourseOfStudent;
    Student* StuNext;
    Student* StuPrev;
    void generatePasswordFromID();
};


struct Semester {
    unsigned short SemesterNumber; //1, 2, 3
    std::string SchoolYear;
    std::string StartDate;
    Course* Courses = nullptr;
    Semester* SemNext;
    Semester* SemPrev;
};

struct Course {
    std::string CourseID;
    std::string CourseName;
    std::string ClassName;
    std::string TeacherName;
    std::string CourseSize = "50";
    std::string DayOfWeek;
    std::string Session;
    Student* StudentOfCourse;
    Course* CouNext;
    Course* CouPrev;
};

struct SchoolYear {
    std::string AcademicYear;
    Class* Classes;
    Semester* Semesters;
    SchoolYear* syNext;
    SchoolYear (std::string AcademicYear, SchoolYear* syNext) : 
    AcademicYear(AcademicYear), syNext(syNext) {}
};

template<class T>
struct Node {
    T val;
    Node* next;
    Node (int val) : val(val), next(nullptr) {}
    Node (int val, T* next) : val(val), next(next) {}
};

template <class T>
struct Queue {
    Node<T>* head, *tail;
    Queue() : head(nullptr), tail(nullptr) {}
    void enQueue(T x);
    void deQueue(T x);
    bool isEmpty();
    T front();
};

