#include "Course.h"

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

void Course::updateStudentResult()
{
    // Display the the list of students
    std::cout << "List of Students:" << std::endl;
    viewStudentsList();

    // Prompt for student index
    int studentIndex;
    std::cout << "Enter the index of the student you want to update: ";
    std::cin >> studentIndex;

    // Validate the input
    if (studentIndex < 1 || studentIndex > courseSize) {
        std::cerr << "Invalid student index." << std::endl;
        return;
    }

    // Display a menu of score types
    std::string scoreTypes[3] = {"Midterm", "Final", "Other"};
    std::cout << "Select the score type to update:" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << i + 1 << ". " << scoreTypes[i] << std::endl;
   
    // Prompt for the user's choice
    int choice;
    std::cout << "Enter the number corresponding to the score type: ";
    std::cin >> choice;
 
    // Validate the input
    if (choice < 1 || choice > 3) {
        std::cerr << "Invalid choice." << std::endl;
        return;
    }

    // Prompt for the new score
    double newScore;
    std::cout << "Enter the new score: ";
    std::cin >> newScore;

    // Update the selected score
    if (scoreTypes[choice - 1] == "Midterm") scoreList[studentIndex - 1].midTerm = newScore;
    else if (scoreTypes[choice - 1] == "Final") scoreList[studentIndex - 1].final = newScore;
    else if (scoreTypes[choice - 1] == "Other") scoreList[studentIndex - 1].other = newScore;
}