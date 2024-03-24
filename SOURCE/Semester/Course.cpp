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
}