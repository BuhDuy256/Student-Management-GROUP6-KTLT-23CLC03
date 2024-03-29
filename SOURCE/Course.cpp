#include "Course.h"
#include "System.h"

void Course::updateInformation()
{
     // Display a menu of options for information update
    std::cout << "What information do you want to update?" << std::endl;
    std::cout << "1. Class Name" << std::endl;
    std::cout << "2. Teacher Name" << std::endl;
    std::cout << "3. Day of Week" << std::endl;
    std::cout << "4. Session" << std::endl;

    int choice;
    while (true)
        if (getChoice(4, "Enter the number corresponding to your choice: ", choice)) break;

    // Prompt for the new value based on the user's choice
    std::string newValue;
    switch (choice) {
        case 1:
            std::cout << "Enter the new Class Name: ";
            std::getline(std::cin, newValue);
            className = newValue;
            break;
        case 2:
            std::cout << "Enter the new Teacher Name: ";
            std::getline(std::cin, newValue);
            teacherName = newValue;
            break;
        case 3:
        {
            std::string daysOfWeek[6] = {"MON", "TUE", "WED", "THU", "FRI", "SAT"};
            std::cout << "Select the new day of week:\n";
            for (int i = 0; i < 6; ++i) std::cout << i + 1 << ". " << daysOfWeek[i] << std::endl;
            int choice;
            while (true)
                if (getChoice(6, "Enter the number of the new day of week: ", choice)) break;
            dayOfWeek = dayOfWeek[choice - 1];
            break;
        }
        case 4:
        {
            std::string sessions[4] = {"S1 (07:30)", "S2 (09:30)", "S3 (13:30)", "S4 (15:30)"};
            std::cout << "Select the new session:\n";
            for (int i = 0; i < 4; ++i) std::cout << i + 1 << ". " << sessions[i] << std::endl;
            int choice;
            while (true)
                if (getChoice(4, "Enter the number of the new session: ", choice)) break;
            session = sessions[choice - 1];
            break;
        }
    }
    std::cout << "Information updated successfully." << std::endl;
}

void Course::viewStudentsList()
{
    if (score != nullptr) 
    {
        std::cout << std::left << std::setw(10) << "Index" << std::setw(15) << "Student ID" << std::setw(25) << "Student Name" << std::endl;
        std::cout << std::setfill('-') << std::setw(50) << "-" << std::setfill(' ') << std::endl;

        for (int i = 0; i < courseSize; ++i) 
        {
            std::cout << std::left << std::setw(10) << (i + 1) << std::setw(15) << score[i].studentID << std::setw(25) << score[i].studentName << std::endl;
            std::cout << std::setfill('-') << std::setw(50) << "-" << std::setfill(' ') << std::endl;
        }
    } 
    else std::cout << "No students in the course." << std::endl;
}

void Course::addStudent()  
{
    std::string studentID, studentName;
    while (true)
    {
        std::cout << "Enter the student's ID: ";
        std::getline(std::cin, studentID);
        if (checkIDValid(studentID)) break;
    }
    
    while (true)
    {
        std::cout << "Enter the student's name: ";
        std::getline(std::cin, studentName);
        if (checkNameValid(studentName)) break;
    }
    formalize(studentName);

    StudentScore* newScoreList = new StudentScore [courseSize + 1];    
    for (int i = 0; i < courseSize; i++)
        newScoreList[i] = score[i];
    newScoreList[courseSize].studentID = studentID;
    newScoreList[courseSize].studentName = studentName;
    
    delete [] score;
    score = newScoreList;
    courseSize++;

    std::cout << "Student is added sucessfully\n";
}

void Course::deleteStudent()
{ 
    viewStudentsList();
    int index;
    
    while (true)
        if (getChoice(courseSize, "Please enter the index of the student you want to delete: ", index))
            break;                        
    
    for (int i = index - 1; i < courseSize - 1; i++) score[i] = score[i + 1];
    courseSize--;
    
    std::cout << "Student is deleted sucessfully\n";
}

void Course::viewScoreboard()
{
    if (score != nullptr) 
    {
        std::cout << std::left 
        << std::setw(10) << "Index" << std::setw(15) << "Student ID" << std::setw(25) << "Student Name" << std::setw(10) << "Midterm" 
        << std::setw(10) << "Final" << std::setw(10) << "Other" << std::setw(10) << "Total" << std::endl;
        std::cout << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;

        for (int i = 0; i < courseSize; ++i) 
        {
            std::cout << std::left 
                << std::setw(10) << (i + 1) << std::setw(15) << score[i].studentID << std::setw(25) << score[i].studentName
                << std::setw(10) << score[i].midTerm << std::setw(10) << score[i].final
                << std::setw(10) << score[i].other << std::setw(10) << score[i].total << std::endl;
            std::cout << std::setfill('-') << std::setw(90) << "-" << std::setfill(' ') << std::endl;
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
    while (true)
        if (getChoice(courseSize, "Enter the index of the student you want to update: ", studentIndex)) break;

    // Display a menu of score types
    std::string scoreTypes[3] = {"Midterm", "Final", "Other"};
    std::cout << "Select the score type to update:" << std::endl;
    for (int i = 0; i < 3; ++i) std::cout << i + 1 << ". " << scoreTypes[i] << std::endl;
   
    // Prompt for the user's choice
    int choice;
    while (true)
        if (getChoice(3, "Enter the number corresponding to your choice: ", choice)) break;

    // Prompt for the new score
    double newScore;
    std::cout << "Enter the new score: ";
    std::cin >> newScore;

    // Update the selected score
    if (scoreTypes[choice - 1] == "Midterm") score[studentIndex - 1].midTerm = newScore;
    else if (scoreTypes[choice - 1] == "Final") score[studentIndex - 1].final = newScore;
    else if (scoreTypes[choice - 1] == "Other") score[studentIndex - 1].other = newScore;
    
    std::cout << "Student's result updated successfully." << std::endl;
}
