#include "SchoolYear.h"
#include "GlobalVariables.h"

bool SchoolYear::createANewSemester()
{
    if (semesters[2].isCreated == true)
        return false;

    int i = 0;
    while (semesters[i].isCreated == true) i++;
    semesters[i].isCreated = true;
    currSem = semesters[i];
    return true;
}

void SchoolYear::viewAllCourses()
{
    for (int i = 0; i < 3; i++)
    {
        if (!semesters[i].isCreated) break;
        std::cout << "Semester " << i + 1 << "\n";
        semesters[i].viewCoursesList();
    }
}
