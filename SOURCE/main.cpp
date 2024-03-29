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
	importAllStaffsCSV();

	Node<Staff>* staCurr = currStaff;
	while(staCurr) {
		std::cout << staCurr -> data.ID << std::endl;
		staCurr = staCurr -> next;
	}

	// importCSVStudentsOfAClass_Public();
	// exportCSVStudentsOfACourse();
	
	saveAllSchoolYearsData();
	saveAllClassesData();
	saveAllStudentsData();
	saveAllSemestersData();
	saveAllCoursesData();
	saveAllScoreboardsData();
	saveAllStaffsData();

	deleteAllStudentsData();
	deleteAllClassesData();
	deleteAllScoreboardsData();
	deleteAllCourseData();
	deleteAllStaffData();

	auto end = std::chrono::high_resolution_clock::now();
	// Calculate the duration
	std::chrono::duration<double> duration = end - start;
	// Print the duration in seconds
	std::cout << "\nExecution time: " << duration.count() << " seconds." << std::endl;
	return 0;
}