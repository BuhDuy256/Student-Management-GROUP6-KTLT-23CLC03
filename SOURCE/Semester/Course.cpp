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
    if (index < 0 || index >= courseSize) return false;
    for (int i = index - 1; i < courseSize; i++) scoreList[i] = scoreList[i + 1];
    courseSize--;
    return true;
}