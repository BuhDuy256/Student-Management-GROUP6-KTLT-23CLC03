#include"System.h"
#include<iostream>
#include<chrono>

int main () {
	// Start the timer
	auto start = std::chrono::high_resolution_clock::now();
	
	importAllSchoolYearsCSV();
	importAllClassesCSV();
	importAllStudentsCSV();
	importAllSemestersCSV();
	importAllCoursesCSV();
	importAllStudentsInAllCoursesCSV();

	// importCSVStudentsOfAClass_Public();
	exportCSVStudentsOfACourse();
	
	saveAllSchoolYearsData();
	saveAllClassesData();
	saveAllStudentsData();
	saveAllSemestersData();
	saveAllCoursesData();
	saveAllScoreboardsData();

	deleteAllStudentsData();
	deleteAllClassesData();
	deleteAllScoreboardsData();
	deleteAllCourseData();

	auto end = std::chrono::high_resolution_clock::now();
	// Calculate the duration
	std::chrono::duration<double> duration = end - start;
	// Print the duration in seconds
	std::cout << "\nExecution time: " << duration.count() << " seconds." << std::endl;
	return 0;
}