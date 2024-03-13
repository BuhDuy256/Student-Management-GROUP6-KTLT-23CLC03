#include"struct.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<chrono>

// FIXME:
/*
Cần check lại làm sao để đẩy data của các semester lên program
Thuật toán addCourse vào các Semester của các SchoolYear 
*/ 
// void importCSVCourse(SY_Queue HCMUS) {
//     std::ifstream inF ("CourseList.csv");
//     if (!inF.is_open()) {
//         std::cout << "Course Data Error";
//         return;
//     }
//     std::string line;
//     while(std::getline(inF, line)) {
//         std::stringstream ss(line);
//         std::string CourseToken;
//         std::getline(ss, CourseToken, ',');
//     }
//     inF.close();
// }

int main () {
    auto start = std::chrono::high_resolution_clock::now();
    SY_Queue HCMUS;
    importCSVSchoolYear(HCMUS);
    Class* Classes = nullptr;
    importCSVClass(Classes);
    importCSVStudent(Classes);
    displayAllStudentOfClass(Classes, "23CLC03");
    displayAllStudentOfClass(Classes, "23APCS3");
    deleteAllStudent(Classes);
    HCMUS.display();
    HCMUS.remove();
    displayClass(Classes);
    removeClass(Classes); 
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Execution time: " << duration << " ms" << std::endl;
    return 0;
}