#include"struct.h"
#include<iostream>
#include<fstream>
#include<sstream>

int main () {
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
    return 0;
}