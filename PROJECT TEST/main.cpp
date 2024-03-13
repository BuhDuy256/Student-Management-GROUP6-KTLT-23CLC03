#include"struct.h"
#include<iostream>
#include<fstream>
#include<sstream>

int main () {
    SY_Queue HCMUS;
    importCSVSchoolYear(HCMUS);
    Class* Classes = nullptr;
    importCSVClass(Classes);
    HCMUS.display();
    HCMUS.remove();
    displayClass(Classes);
    removeClass(Classes);
    return 0;
}