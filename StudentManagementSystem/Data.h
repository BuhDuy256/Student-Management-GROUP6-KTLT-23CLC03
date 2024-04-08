#pragma once

#include"System.h"

void importAllSchoolYearsCSV();
void importAllClassesCSV();
void importAllStudentsCSV();
void importContainingStudentsEnrolledInCourse(Node<Course>* couCurr);
void importAllSemestersCSV();
void importAllCoursesCSV();
void importAllStudentsInAllCoursesCSV();

void saveAllStudentsData();
void saveAllClassesData();
void saveAllCoursesData();
void saveScoreboardOfACourse(Node<Course>* couCurr);
void saveAllScoreboardsData();
void saveAllSemestersData();
void saveAllSchoolYearsData();

void deleteAllStudentsData();
void deleteAllClassesData();
void deleteAllScoreboardsData();
void deleteAllCourseData();
void deleteAllSchoolYearsData();
