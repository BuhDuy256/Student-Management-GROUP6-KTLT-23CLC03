#pragma once

#include<iostream>
#include<string>

struct Course;
struct Student;
struct Semester;
struct Course;
struct Class {
    std::string ClassName;
    std::string SchoolYear;
    Student* Students = nullptr;
    Class* ClaNext;
    Class (std::string ClassName, std::string SchoolYear) : ClassName(ClassName), SchoolYear(SchoolYear), ClaNext(nullptr) {}
};

struct Student {
    std::string StudentID;
    std::string StudentName;
    std::string Gender;
    std::string Birthday;
    std::string SocialID;
    std::string ClassOfStudent;
    std::string Password;
    Course* CourseOfStudent = nullptr;
    Student* StuNext;
    Student (std::string StudentID, std::string StudentName, std::string Gender, std::string Birthday, std::string SocialID, std::string ClassOfStudent) : StudentID(StudentID), StudentName(StudentName), Gender(Gender), Birthday(Birthday), SocialID(SocialID), ClassOfStudent(ClassOfStudent), StuNext(nullptr) {}
    void generatePasswordFromID();
};


struct Semester {
    unsigned short SemesterNumber; //1, 2, 3
    std::string SchoolYear;
    std::string StartDate;
    Course* Courses = nullptr;
    Semester* SemNext;
};

struct Course {
    std::string CourseID;
    std::string CourseName;
    std::string ClassName;
    std::string TeacherName;
    std::string CourseSize = "50";
    std::string DayOfWeek;
    std::string Session;
    Student* StudentOfCourse = nullptr;
    Course* CouNext;
};

struct SchoolYear {
    std::string AcademicYear;
    Semester* Semesters = nullptr;
    SchoolYear* syNext;
    SchoolYear (std::string AcademicYear, SchoolYear* syNext) : AcademicYear(AcademicYear), Semesters(nullptr), syNext(syNext) {}
    SchoolYear (std::string AcademicYear) : AcademicYear(AcademicYear), syNext(nullptr) {}
};
struct SY_Queue {
    SchoolYear* head, *tail;
    SY_Queue() : head(nullptr), tail(nullptr) {}
    void enQueue(std::string x);
    void deQueue();
    bool isEmpty();
    std::string front();
    void display();
    void remove();
};

void importCSVSchoolYear(SY_Queue &HCMUS);
void importCSVClass(Class* &Classes);
void displayClass(Class* Classes);
void removeClass(Class* &Classes);
void AddStudentToClass(Student* &ListStudentOfClass, std::string StudentID, std::string StudentName, std::string Gender, std::string Birthday, std::string SocialID, std::string ClassOfStudent);
Class* FindClassWithClassName(Class* Classes, std::string ClassName);
void importCSVStudent(Class* Classes);
void displayAllStudentOfClass(Class* Classes, std::string ClassName);
void deleteAllStudent(Class* Classes);