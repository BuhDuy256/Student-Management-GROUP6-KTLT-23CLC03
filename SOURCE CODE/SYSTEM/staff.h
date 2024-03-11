#pragma once
#ifndef STAFF_H
#define STAFF_H
#include<iostream>
using namespace std;
struct Student{
  int No;
  string StudentID,FirstName,LastName,Gender,DateofBirth,SocialID;
  Student* next;
  //showcourseofstu
};
struct Class{
 Student *First,*Last;
};
struct Course{
 Class *classes = new Class[20];
 //1coursenhieuclass->nhieusession
 string ID,Name,ClassName,TeacherName,NumofCredits,SessionDay,SessionTime;
 int MaxofStudents = 50;
 void ListofStudents();
 void updateInfor();
 void addStudent();
 void removeStudent();
};
struct Semester{
 int SchoolYear,StartDate,EndDate;
 int NumofSemCourse = 4;
 Course courses[4];
 void addCourse();
 void showCourse();
 void deleteCourse();
};
struct SchoolYear{
 Class *Classes = new Class[50];
 Semester *semesters = new Semester[3];
 void add1stStudentto1stClass();
};
#endif // STAFF_H
