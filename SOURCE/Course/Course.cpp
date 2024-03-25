#include "Course.h"

void Course::addStudent(std::string studentID, std::string studentName)
{
    StudentScore* newScoreList = new StudentScore [courseSize + 1]; 
    for (int i = 0; i < courseSize; i++)
        newScoreList[i] = scoreList[i];
    newScoreList[courseSize].studentID = studentID;
    newScoreList[courseSize].studentName = studentName;
    
    delete [] scoreList;
    scoreList = newScoreList;
    courseSize++;
}

bool Course::deleteStudent(int index)
{
    if (index < 0 || index > courseSize) return false;
    for (int i = index - 1; i < courseSize - 1; i++) scoreList[i] = scoreList[i + 1];
    courseSize--;
    return true;
}


void Course::viewStudentsList()
{
    if (scoreList != nullptr) 
    {
        std::cout << std::left << std::setw(10) << "Index" << std::setw(15) << "Student ID" << std::setw(25) << "Student Name" << std::endl;
        std::cout << std::setfill('-') << std::setw(50) << "-" << std::setfill(' ') << std::endl;

        for (int i = 0; i < courseSize; ++i) 
            std::cout << std::left << std::setw(10) << (i + 1) << std::setw(15) << scoreList[i].studentID << std::setw(25) << scoreList[i].studentName << std::endl;
    } 
    else std::cout << "No students in the course." << std::endl;
}

void Course::viewScoreboard()
{
    if (scoreList != nullptr) 
    {
        std::cout << std::left 
        << std::setw(10) << "Index" << std::setw(15) << "Student ID" << std::setw(25) << "Student Name" << std::setw(10) << "Midterm" 
        << std::setw(10) << "Final" << std::setw(10) << "Other" << std::setw(10) << "Total" << std::setw(10) << "GPA" << std::endl;
        std::cout << std::setfill('-') << std::setw(100) << "-" << std::setfill(' ') << std::endl;

        for (int i = 0; i < courseSize; ++i) 
        {
            std::cout << std::left 
                << std::setw(10) << (i + 1) << std::setw(15) << scoreList[i].studentID << std::setw(25) << scoreList[i].studentName
                << std::setw(10) << scoreList[i].midTerm << std::setw(10) << scoreList[i].final
                << std::setw(10) << scoreList[i].other << std::setw(10) << scoreList[i].total
                << std::setw(10) << scoreList[i].GPA << std::endl;
        }
    } 
    else std::cout << "No students in the course." << std::endl;
}