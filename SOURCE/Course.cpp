#include"Course.h"

void Course::viewStudentsList() {
    std::cout << "\t+--------+------------+------------------------------+\n";
    std::cout << "\t| No     | Student ID | Student Name                 |\n";
    std::cout << "\t+--------+------------+------------------------------+\n";

    for (int i = 0; i < courseSize; i++) {
        std::cout << "\t| " << std::setw(7) << std::left << (i + 1)
            << "| " << std::setw(11) << std::left << score[i].studentID
            << "| " << std::setw(29) << std::left << score[i].studentName
            << "|\n";
    }
    std::cout << "\t+--------+------------+------------------------------+\n";
}

void Course::deleteStudent() {
    menuCommandHeader();
    viewStudentsList();
    int index;

    while (true) {
        std::cout << "Enter the student number you want to delete: ";
        std::cin >> index;
        if (index < 1 || index > courseSize) {
            std::cout << "Invalid student number. Please enter a valid integer between 1 and " << courseSize << ".\n";
            continue;
        }
        break;
    }

    for (int i = index - 1; i < courseSize - 1; i++) score[i] = score[i + 1];
    courseSize--;

    std::cout << "Student is deleted sucessfully\n";
}

void Course::viewScoreboard() {
    std::cout << "\t+--------+------------+------------------------------+----------+----------+----------+----------+" << std::endl;
    std::cout << "\t| NO     | Student ID | Student Name                 | Midterm  | Final    | Others   | Total    |" << std::endl;
    std::cout << "\t+--------+------------+------------------------------+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < courseSize; i++) {
        std::cout << "\t| " << std::setw(7) << std::left << i + 1
            << "| " << std::setw(11) << std::left << score[i].studentID
            << "| " << std::setw(29) << std::left << score[i].studentName
            << "| " << std::setw(9) << std::left << (score[i].midTerm > 0 ? doubleToString(score[i].midTerm) : "")
            << "| " << std::setw(9) << std::left << (score[i].final > 0 ? doubleToString(score[i].final) : "")
            << "| " << std::setw(9) << std::left << (score[i].other > 0 ? doubleToString(score[i].other) : "")
            << "| " << std::setw(9) << std::left << (score[i].total > 0 ? doubleToString(score[i].total) : "")
            << "|" << std::endl;
    }
    std::cout << "\t+--------+------------+------------------------------+----------+----------+----------+----------+" << std::endl;
    return;
}

void Course::addStudent()
{
    StudentScore studentScore;
    while (true) {
        std::cout << "\tEnter the student's ID: ";
        std::cin.ignore();
        std::getline(std::cin, studentScore.studentID);
        if (isValidID(studentScore.studentID)) break;
    }
    while (true) {
        std::cout << "\tEnter the student's name: ";
        std::cin.ignore();
        std::getline(std::cin, studentScore.studentName);
        if (isValidCouOrStuName(studentScore.studentName)) break;
    }
    formalize(studentScore.studentName);
    score[courseSize] = studentScore;
    courseSize++;

    std::cout << "Student is added sucessfully...\n";
}

void Course::updateInformation()
{
    // // Display a menu of options for information update
    // std::cout << "What information do you want to update?" << std::endl;
    // std::cout << "1. Class Name" << std::endl;
    // std::cout << "2. Teacher Name" << std::endl;
    // std::cout << "3. Day of Week" << std::endl;
    // std::cout << "4. Session" << std::endl;

    // int choice;
    // while (true)
    //     if (getChoice(4, "Enter the number corresponding to your choice: ", choice)) break;

    // // Prompt for the new value based on the user's choice
    // std::string newValue;
    // switch (choice) {
    // case 1:
    //     // FIXME: New class shouldn't be the same as the old one
    //     std::cout << "Enter the new Class Name: ";
    //     std::getline(std::cin, newValue);
    //     className = newValue;
    //     break;
    // case 2:
    //     std::cout << "Enter the new Teacher Name: ";
    //     std::getline(std::cin, newValue);
    //     teacherName = newValue;
    //     break;
    // case 3:
    // {
    //     std::string daysOfWeek[6] = { "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    //     std::cout << "Select the new day of week:\n";
    //     for (int i = 0; i < 6; ++i) std::cout << i + 1 << ". " << daysOfWeek[i] << std::endl;
    //     int choice;
    //     while (true)
    //         if (getChoice(6, "Enter the number of the new day of week: ", choice)) break;
    //     dayOfWeek = dayOfWeek[choice - 1];
    //     break;
    // }
    // case 4:
    // {
    //     std::string sessions[4] = { "S1 (07:30)", "S2 (09:30)", "S3 (13:30)", "S4 (15:30)" };
    //     std::cout << "Select the new session:\n";
    //     for (int i = 0; i < 4; ++i) std::cout << i + 1 << ". " << sessions[i] << std::endl;
    //     int choice;
    //     while (true)
    //         if (getChoice(4, "Enter the number of the new session: ", choice)) break;
    //     session = sessions[choice - 1];
    //     break;
    // }
    // }
    // std::cout << "Information updated successfully." << std::endl;
}

void addACourseInCurrSem() {
    menuCommandHeader();
    std::cout << "[1]. Add a course in current semester:\n";
    Course newCourse;
    std::cout << "\n\t(?) Enter course ID: ";
    while (true) {
        std::cin >> newCourse.ID;
        if (isCourseIDValid(newCourse.ID)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid course ID. Please try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "\t(?) Enter course name: ";
    while (true) {
        std::cin.ignore();
        std::getline(std::cin, newCourse.Name);
        if (isValidCouOrStuName(newCourse.Name)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid course name. Please try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "\t(?) Enter the class name (Format: dd/U[2,4]/dd. 'dd': two consecutive digits, 'U[2,4]': 2-4 uppercase letter): ";
    while (true) {
        std::cin >> newCourse.className;
        if (!isValidClassName(newCourse.className, currSYear->data.year)) {
            std::cout << "\t(X) Invalid class name. Please try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (!notExistclassNameOfCourse(newCourse.ID, newCourse.className, currSYear->data.year)) {
            std::cout << "\t(X) The class name already exists. Please try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }  
        break;
    }
    std::cout << "\t(?) Enter teacher name: ";
    while (true) {
        std::cin.ignore();
        std::getline(std::cin, newCourse.teacherName);
        if (isValidCouOrStuName(newCourse.teacherName)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid teacher name. Please try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "\t(?) Enter number of credits: ";
    while (!(std::cin >> newCourse.nCredits) || newCourse.nCredits < 2 || newCourse.nCredits > 4) {
        std::cout << "Invalid number of credits. The number of credits of a course should be between 2 and 4. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string daysOfWeek[6] = { "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    std::cout << "\t(*) Select the new day of week:\n";
    for (int i = 0; i < 6; ++i)
        std::cout << "\t\t" << i + 1 << ". " << daysOfWeek[i] << std::endl;
    int choice;
    getChoiceInt(1, 6, "\t(?) Enter the number of the new day of week: ", choice);
    newCourse.dayOfWeek = daysOfWeek[choice - 1];

    std::string sessions[4] = { "07:30", "09:30", "13:30", "15:30" };
    std::cout << "\t(*) Select the new session:\n";
    for (int i = 0; i < 4; ++i)
        std::cout << "\t\t" << i + 1 << ". " << sessions[i] << std::endl;
    // int choice;
    getChoiceInt(1, 4, "\t(?) Enter the number of the new session: ", choice);
    newCourse.session = sessions[choice - 1];

    newCourse.couSY = currSYear->data.year;
    newCourse.couSem = currSemNumber;
    Node<Course>* newCourseNode = new Node<Course>(newCourse, currSem.Courses);
    currSem.Courses = newCourseNode;
    std::cout << "(!) Course added successfully." << std::endl;
    system("pause");
    courseManagementPage();
    return;
}

void viewListOfCoursesInCurrSem() {
    menuCommandHeader();
    std::cout << "[8]. List of courses in current semester:\n";
    int no;
    currSem.viewCoursesList(no);
    system("pause");
    courseManagementPage();
    return;
}

void deleteACourseInCurrSem() {
    menuCommandHeader();
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course number you want to delete: ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            currSem.deleteCourse(choice);
            break;
        }
    }
    system("pause");
    courseManagementPage();
    return;
}

void addStudentToACourse() {
    menuCommandHeader();
    std::cout << "[4]. Add student to a course\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "Enter the course number you want to add students (1 to " << no << "): ";
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            int count;
            Node<Course>* couCurr = currSem.Courses;
            bool isAdded = false;
            while (couCurr) {
                count++;
                if (count == choice) {
                    system("cls");
                    menuCommandHeader();
                    std::cout << "[4]. Add student to a course\n";
                    couCurr->data.viewStudentsList();
                    couCurr->data.addStudent();
                    system("pause");
                    courseManagementPage();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void viewScoreboardOfACourse() {
    menuCommandHeader();
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course number you want to view scoreboard (1 to " << no << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            int count = 0;
            Node<Course>* couCurr = currSem.Courses;
            while (couCurr) {
                count++;
                if (count == choice) {
                    menuCommandHeader();
                    std::cout << "List of students in course " << couCurr->data.ID << " - " << couCurr->data.Name << " - " << couCurr->data.className << ":\n";
                    couCurr->data.viewScoreboard();
                    system("pause");
                    courseManagementPage();
                    break;
                }
                couCurr = couCurr->next;
            }
            break;
        }
    }

}

void removeAStudentFromACourse() {
    menuCommandHeader();
    std::cout << "[5]. Remove student from a course\n";
    std::cout << "List of courses in current semester:" << std::endl;
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course number you want to remove students: ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            int count = 0;
            Node<Course>* couCurr = currSem.Courses;
            while (couCurr) {
                count++;
                if (count == choice) {
                    std::cout << "[5]. Remove student from a course\n";
                    couCurr->data.deleteStudent();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void viewListStudentInACourse() {
    menuCommandHeader();
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course you want to view student (between 1 and " << no << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            Node<Course>* couCurr = currSem.Courses;
            int count = 0;
            while (couCurr) {
                count++;
                if (count == choice) {
                    menuCommandHeader();
                    couCurr->data.viewStudentsList();
                    system("pause");
                    courseManagementPage();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void chooseStudentToUpdateResult(Node<Course>* couCurr) {
    menuCommandHeader();
    couCurr->data.viewScoreboard();
    std::cout << "Enter the student you want to update result (between 1 and " << couCurr->data.courseSize << "): ";
    int studentIndex;
    while (true) {
        std::cin >> studentIndex;
        if (studentIndex < 1 || studentIndex > couCurr->data.courseSize) {
            std::cout << "Invalid student number. Please enter a valid integer between 1 and " << couCurr->data.courseSize << ".\n";
            continue;
        }
        break;
    }
    std::string scoreTypes[3] = { "Midterm", "Final", "Other" };
    bool updateMore = true;
    while (updateMore) {
        std::cout << "Select the score type to update:" << std::endl;
        for (int i = 0; i < 3; ++i) std::cout << i + 1 << ". " << scoreTypes[i] << std::endl;

        // Prompt for the user's choice
        int choice;
        // while (true)
        //     if (getChoice(3, "Enter the number corresponding to your choice: ", choice)) break;

        // Prompt for the new score
        double newScore;
        std::cout << "Enter the new score: ";
        std::cin >> newScore;

        // Update the selected score
        if (scoreTypes[choice - 1] == "Midterm") couCurr->data.score[studentIndex - 1].midTerm = newScore;
        else if (scoreTypes[choice - 1] == "Final") couCurr->data.score[studentIndex - 1].final = newScore;
        else if (scoreTypes[choice - 1] == "Other") couCurr->data.score[studentIndex - 1].other = newScore;

        std::cout << "Student's result updated successfully." << std::endl;
        std::cout << "Do you want to update more scores? (Y/N): ";
        char updateChoice;
        std::cin >> updateChoice;
        if (updateChoice == 'N' || updateChoice == 'n') {
            updateMore = false;
        }
        else {
            chooseStudentToUpdateResult(couCurr);
            return;
        }
    }
    system("pause");
    courseManagementPage();
    return;
}

void updateAStudentResultOfACourse() {
    menuCommandHeader();
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course number (between 1 and " << no << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            Node<Course>* couCurr = currSem.Courses;
            int count = 0;
            while (couCurr) {
                count++;
                if (count == choice) {
                    chooseStudentToUpdateResult(couCurr);
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void exportCSVStudentsOfACourse() {
    menuCommandHeader();
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course you want to view student (between 1 and " << no << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            Node<Course>* couCurr = currSem.Courses;
            int count = 0;
            while (couCurr) {
                count++;
                if (count == choice) {
                    std::string folderName;
                    while (true) {
                        std::cout << "Enter the path of folder you want to export CSV: ";
                        std::getline(std::cin >> std::ws, folderName);
                        if ((!std::filesystem::is_directory(folderName) && !std::filesystem::is_regular_file(folderName)) || folderName.empty()) {
                            std::cout << "Invalid path. Please enter a folder path." << std::endl;
                            folderName = ""; // Clear folderName to loop again
                            continue;
                        }
                        break;
                    }
                    std::string fileName = removeQuotesFromPath(folderName) + "/" + couCurr->data.ID + "_" + couCurr->data.className + ".csv";
                    std::ofstream outF(fileName);
                    if (!outF.is_open()) {
                        std::cout << "Error creating CSV file!" << std::endl;
                        return;
                    }
                    outF << "Student ID,Student Name,Midterm Mark,Final Mark,Other Mark,Total Mark\n";
                    StudentScore* scoreArr = couCurr->data.score;
                    for (int i = 0; i < couCurr->data.courseSize; i++) {
                        outF << scoreArr[i].studentID << ","
                            << scoreArr[i].studentName << ",";
                        if (scoreArr[i].midTerm > 0)
                            outF << scoreArr[i].midTerm;
                        outF << ",";
                        if (scoreArr[i].final > 0)
                            outF << scoreArr[i].final;
                        outF << ",";
                        if (scoreArr[i].other > 0)
                            outF << scoreArr[i].other;
                        outF << ",";
                        if (scoreArr[i].total > 0)
                            outF << scoreArr[i].total;
                        outF << "\n";
                    }
                    outF.close();
                    std::cout << "Exported successfully!" << std::endl;
                    system("pause");
                    courseManagementPage();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void importOutsideCSVStudentsInCourse(Node<Course>* couCurr, std::string fileName) {
    std::ifstream inF(fileName);
    if (!inF.is_open()) {
        std::cout << "Couldn't import " << fileName << std::endl;
        return;
    }
    std::string header;
    std::getline(inF, header);
    std::string line;
    int n = 0;
    while (std::getline(inF, line)) {
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        std::stringstream ss(line);
        std::string token;
        bool idRead = false;
        bool nameRead = false;
        while (std::getline(ss, token, ',')) {
            if (std::all_of(token.begin(), token.end(), ::isdigit)) {
                continue;
            }
            if (!idRead) {
                couCurr->data.score[n].studentID = token;
                idRead = true;
            }
            else if (!nameRead) {
                couCurr->data.score[n].studentName = token;
                nameRead = true;
                n++;
            }
            if (idRead && nameRead) {
                break;
            }
        }
    }
    couCurr->data.courseSize = n;
    inF.close();
}

void uploadCSVFileContainingAListOfStudentsOfACourse() {
    menuCommandHeader();
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course number: ";
    std::cout << "Enter the course number (between 1 and " << no << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            Node<Course>* couCurr = currSem.Courses;
            int count = 0;
            while (couCurr) {
                count++;
                if (count == choice) {
                    if (couCurr->data.score == nullptr) {
                        std::string fileName;
                        std::cout << "Enter the path of the CSV file (You can drag it into the program): ";
                        while (true) {
                            std::cin >> fileName;
                            if (std::filesystem::is_regular_file(fileName) && ends_with(fileName, ".csv")) {
                                break;
                            }
                            std::cout << "Invalid CSV file path." << std::endl;
                        }
                        importOutsideCSVStudentsInCourse(couCurr, fileName);
                        std::cout << "Imported successfully." << std::endl;
                    }
                    else {
                        std::cout << "This course already has students enrolled." << std::endl;
                    }
                    system("pause");
                    courseManagementPage();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void updateInformationOfACourse() {
    menuCommandHeader();
    std::cout << "[2]. Update information of a course\n";
    int no;
    currSem.viewCoursesList(no);
    std::cout << "Enter the course number (between 1 and " << no << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > no) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << no << ": ";
        }
        else {
            Node<Course>* couCurr = currSem.Courses;
            int count = 0;
            while (couCurr) {
                count++;
                if (count == choice) {
                    couCurr->data.updateInformation();
                    system("pause");
                    courseManagementPage();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}