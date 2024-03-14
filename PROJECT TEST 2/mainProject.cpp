#include"structProject.h"
#include<chrono>

int main () {
    auto start = std::chrono::high_resolution_clock::now();
	Queue<SchoolYear> schoolYear;
	Queue<Class> classes;
	importCSVSchoolYear(schoolYear);
	importCSVClass(classes);
	importCSVStudent(classes);
	displayAllSchoolYears(schoolYear);
	displayAllClasses(classes);
	displayAllStudentOfSchool(classes);
	deleteAllStudents(classes);
	deleteAllClasses(classes);
	deleteAllSchoolYears(schoolYear);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " ms" << std::endl;
    return 0;
}