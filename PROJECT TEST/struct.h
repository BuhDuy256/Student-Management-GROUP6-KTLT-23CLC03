#pragma once

#include<iostream>
#include<string>

struct Course;
struct Student;

struct Class {
    std::string ClassName;
    std::string SchoolYear;
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
    Semester* Semesters;
    SchoolYear* syNext;
    SchoolYear (std::string AcademicYear, SchoolYear* syNext) : AcademicYear(AcademicYear), syNext(syNext) {}
    SchoolYear (std::string AcademicYear) : AcademicYear(AcademicYear), syNext(nullptr) {}
};

template <class T>
struct Queue {
    T* head, *tail;
    Queue() : head(nullptr), tail(nullptr) {}
    void enQueue(T x);
    void deQueue();
    bool isEmpty();
    T front();
};

