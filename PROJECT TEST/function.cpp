#include"struct.h"

void Student::generatePasswordFromID() {
    if (StudentID.length() >= 4) {
        Password = "KHTN@" + StudentID.substr(StudentID.length() - 4);
    } else {           // Handle case where StudentID has less than 4 characters
        Password = "KHTN@" + StudentID;
    }
}

void SY_Stack::syPush(std::string AcademicYear) {
    SchoolYear* syTop = new SchoolYear(AcademicYear, CurrYear);
    CurrYear = syTop;
}

void SY_Stack::syPop() {
    if (!CurrYear) 
        return;
    else {
        SchoolYear* syTop = CurrYear;
        CurrYear = CurrYear -> syNext;
        delete syTop;
    }
}

bool SY_Stack::syIsEmpty() {
    return CurrYear == nullptr;
}

void SY_Stack::syDisplay() {
    SchoolYear* syTmp = CurrYear;
    while(syTmp) {        
        std::cout << syTmp -> AcademicYear << std::endl;
        syTmp = syTmp -> syNext;
    }   
}