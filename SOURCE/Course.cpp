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
    std::cout << "[5]. Remove student from a course\n\n";
    if (courseSize == 0) {
        std::cout << "\t(!) There is no student in this course. You cannot continue to delete students from a course\n\n";
        system("pause");
        courseManagementPage();
        return;
    }
    viewStudentsList();
    int index;
    getChoiceInt(1, courseSize, "\t(?) Enter the student number you want to delete: ", index);

    char confirm = getYesNo("\t(?) Are you sure you want to remove this student? (Y/N): ");
    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\t(!) Cancel deleting student.\n";
        system("pause");
        courseManagementPage();
        return;
    }
    else if (confirm == 'Y' || confirm == 'y') {
        for (int i = index - 1; i < courseSize - 1; i++) score[i] = score[i + 1];
        courseSize--;

        std::cout << "\n\t(!) Student is deleted sucessfully\n";
        char confirm = getYesNo("\t(?) Do you want to remove more students from course " + ID + " - " + Name + "? (Y/N): ");
        if (confirm == 'Y' || confirm == 'y') {
            deleteStudent();
            return;
        }
        else if (confirm == 'N' || confirm == 'n') {
            courseManagementPage();
            return;
        }
    }
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
}

void Course::addStudent()
{
    menuCommandHeader();
    std::cout << "[4]. Add student to a course\n\n";
    viewStudentsList();
    std::cout << std::endl;

    if (courseSize + 1 > maxStudents) {
        std::cout << "\t(X)  The number of students in the course exceeds the limit of " << maxStudents << ". You cannot add more students to this course.\n";
        system("pause");
        courseManagementPage();
        return;
    }

    StudentScore studentScore;
    std::cout << "\t(?) Enter the student's ID (8 digits): ";
    while (true) {
        std::cin >> studentScore.studentID;
        if (isValidStudentID(studentScore.studentID)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid student ID. Please try again: ";
        }
    }

    std::cout << "\t(?) Enter the student's name: ";
    std::cin.ignore();
    while (true) {
        std::getline(std::cin, studentScore.studentName);
        if (isValidCouOrStuName(studentScore.studentName)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid student name. Please try again: ";
        }
    }
    formalize(studentScore.studentName);
    bool isExist = false;
    for (int i = 0; i < courseSize; i++) {
        if (studentScore.studentID == score[i].studentID) {
            isExist = true;
            break;
        }
    }
    if (!isExist) {
        formalize(studentScore.studentName);
        score[courseSize] = studentScore;
        courseSize++;
        std::cout << "\n\t(!) Student is added sucessfully.\n";
    }
    else {
        std::cout << "\n\t(X) The student ID is already in the course.\n";
    }
    char confirm = getYesNo("\t(?) Do you want to add more students to course " + ID + " - " + Name + "? (Y/N): ");
    if (confirm == 'Y' || confirm == 'y') {
        addStudent();
        return;
    }
    else if (confirm == 'N' || confirm == 'n') {
        courseManagementPage();
        return;
    }
}

void Course::updateInformation()
{
    menuCommandHeader();
    std::cout << "Update information of course " << ID << " - " << Name << std::endl;
    std::cout << "\n\t1. Class Name: " << className << std::endl;
    std::cout << "\t2. Teacher Name: " << teacherName << std::endl;
    std::cout << "\t3. Number of Credits: " << nCredits << std::endl;
    std::cout << "\t4. Maximum number of students: " << maxStudents << "\n";
    std::cout << "\t5. Day of Week: " << dayOfWeek << std::endl;
    std::cout << "\t6. Session: " << session << "\n\n";
    int choice;
    getChoiceInt(1, 6, "\t(?) Enter the number corresponding to the information you want to update: ", choice);
    // Prompt for the new value based on the user's choice
    std::string newClassName;
    std::string newTeacherName;
    int newNCredits;
    int newMaxStudents;
    std::string newDayOfWeek;
    std::string newSession;
    if (choice == 1) {
        std::cout << "\t\t(?) Enter the class name (Format: dd/U[2,4]/dd. 'dd': two consecutive digits, 'U[2,4]': 2-4 uppercase letter): ";
        while (true) {
            std::cin >> newClassName;
            if (newClassName == className) {
                break;
            }
            if (!isValidClassName(newClassName, currSYear->data.year)) {
                std::cout << "\t\t(X) Invalid class name. Please try again: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            if (!notExistclassNameOfCourse(ID, newClassName, currSYear->data.year)) {
                std::cout << "\t\t(X) The class name already exists. Please try again: ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            break;
        }
    }
    else if (choice == 2) {
        std::cout << "\t\t(?) Enter teacher name: ";
        std::cin.ignore();
        while (true) {
            std::getline(std::cin, newTeacherName);
            if (isValidCouOrStuName(newTeacherName)) {
                break;
            }
            else {
                std::cout << "\t\t(X) Invalid teacher name. Please try again: ";
            }
        }
    }
    else if (choice == 3) {
        std::cout << "\t\t(?) Enter number of credits (2-4): ";
        while (!(std::cin >> newNCredits) || newNCredits < 2 || newNCredits > 4) {
            std::cout << "\t\t(X) Invalid number of credits. Please enter again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    else if (choice == 4) {
        std::cout << "\t\t(?) Enter the maximum number of students in the course: ";
        while (!(std::cin >> newMaxStudents) || newMaxStudents < 1 || newMaxStudents < courseSize) {
            if (newMaxStudents < courseSize) {
                std::cout << "\t\t(X) The maximum number of students must be greater than or equal to the number of students in the course. Please enter again: ";
            }
            else if (newMaxStudents < 1) {
                std::cout << "\t\t(X) Invalid input. Please enter a positive integer: ";
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    else if (choice == 5) {
        std::string daysOfWeek[6] = { "MON", "TUE", "WED", "THU", "FRI", "SAT" };
        std::cout << "\t(*) Select the new day of week:\n";
        for (int i = 0; i < 6; ++i)
            std::cout << "\t\t" << i + 1 << ". " << daysOfWeek[i] << std::endl;
        int choice;
        getChoiceInt(1, 6, "\t\t(?) Enter the number of the new day of week: ", choice);
        newDayOfWeek = daysOfWeek[choice - 1];
    }
    else if (choice == 6) {
        std::string sessions[4] = { "07:30", "09:30", "13:30", "15:30" };
        std::cout << "\t(*) Select the new session:\n";
        for (int i = 0; i < 4; ++i)
            std::cout << "\t\t" << i + 1 << ". " << sessions[i] << std::endl;
        int choice;
        getChoiceInt(1, 4, "\t\t(?) Enter the number of the new session: ", choice);
        newSession = sessions[choice - 1];
    }
    char confirm = getYesNo("\t(?) Are you sure you want to update this information? (Y/N): ");
    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\t(!) Cancel updating course information.\n";
        system("pause");
        courseManagementPage();
        return;
    }
    else if (confirm == 'Y' || confirm == 'y') {
        if (choice == 1) {
            if (newClassName != className) {
                std::string fileName = "../CSV Files/List of Courses/" + ID + "_" + className + ".csv";
                std::ifstream fileStream(fileName);
                if (fileStream.is_open()) {
                    fileStream.close();
                    std::remove(fileName.c_str());
                }
                className = newClassName;
            }
        }
        else if (choice == 2) {
            formalize(newTeacherName);
            teacherName = newTeacherName;
        }
        else if (choice == 3) {
            nCredits = newNCredits;
        }
        else if (choice == 4) {
            if (newMaxStudents >= courseSize) {
                StudentScore* temp = new StudentScore[newMaxStudents];
                for (int i = 0; i < courseSize; i++) {
                    temp[i] = score[i];
                }
                delete[] score;
                score = temp;
                maxStudents = newMaxStudents;
            }
        }
        else if (choice == 5) {
            dayOfWeek = newDayOfWeek;
        }
        else if (choice == 6) {
            session = newSession;
        }
    }

    std::cout << "\t(!) Course information updated successfully." << std::endl;

    char confirm = getYesNo("\t(?) Do you want to continue updating course " + ID + " - " + Name + " information? (Y/N): ");
    if (confirm == 'Y' || confirm == 'y') {
        updateInformation();
        return;
    }
    else {
        courseManagementPage();
        return;
    }
}

void addACourseInCurrSem() {
    menuCommandHeader();
    std::cout << "[1]. Add a course in current semester:\n";
    Course newCourse;
    std::cout << "\n\t(?) Enter course ID: ";
    while (true) {
        std::cin >> newCourse.ID;
        if (isValidCourseID(newCourse.ID)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid course ID. Please try again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "\t(?) Enter course name: ";
    std::cin.ignore();
    while (true) {
        std::getline(std::cin, newCourse.Name);
        if (isValidCouOrStuName(newCourse.Name)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid course name. Please try again: ";
        }
    }
    formalize(newCourse.Name);
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
    std::cin.ignore();
    while (true) {
        std::getline(std::cin, newCourse.teacherName);
        if (isValidCouOrStuName(newCourse.teacherName)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid teacher name. Please try again: ";
        }
    }
    formalize(newCourse.teacherName);
    std::cout << "\t(?) Enter number of credits (2-4): ";
    while (!(std::cin >> newCourse.nCredits) || newCourse.nCredits < 2 || newCourse.nCredits > 4) {
        std::cout << "\t(X) Invalid number of credits. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char confirm = getYesNo("\t(?) The default maximum number of students in a course is 50. Do you want to change it? (Y/N): ");
    if (confirm == 'Y' || confirm == 'y') {
        std::cout << "\t(?) Enter the maximum number of students in the course: ";
        while (!(std::cin >> newCourse.maxStudents) || newCourse.maxStudents < 1) {
            std::cout << "\t(X) Invalid input. Please enter a positive integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    else {
        newCourse.maxStudents = 50;
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

    char confirm = getYesNo("\t(?) Are you sure you want to add this course? (Y/N): ");

    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\t(!) Cancel adding course.\n";
        system("pause");
        courseManagementPage();
        return;
    }
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        if (syCurr->data.year == currSYear->data.year) {
            Node<Course>* temp = syCurr->data.semesters[currSemNumber - 1].Courses;
            syCurr->data.semesters[currSemNumber - 1].Courses = new Node<Course>(newCourse, temp);
            syCurr->data.semesters[currSemNumber - 1].Courses->data.score = new StudentScore[100];
            currSem = syCurr->data.semesters[currSemNumber - 1];
            break;
        }
        syCurr = syCurr->next;
    }
    std::cout << "\t(!) Course added successfully." << std::endl;
    char confirm2 = getYesNo("\t(?) Do you want to continue adding courses to the current semester? (Y/N): ");
    if (confirm2 == 'Y' || confirm2 == 'y') {
        addACourseInCurrSem();
        return;
    }
    else if (confirm2 == 'N' || confirm2 == 'n') {
        courseManagementPage();
        return;
    }
}

void updateInformationOfACourse() {
    menuCommandHeader();
    std::cout << "[2]. Update information of a course\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\t(*) Enter '0' to return to the course management page\n";
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
    Node<Course>* couCurr = currSem.Courses;
    int count = 0;
    while (couCurr) {
        count++;
        if (count == choice) {
            couCurr->data.updateInformation();
            return;
        }
        couCurr = couCurr->next;
    }
}

void deleteACourseInCurrSem() {
    menuCommandHeader();
    std::cout << "[3]. Delete a course in current semester\n\n";
    if (currSem.Courses == nullptr) {
        std::cout << "\t(!) There is no course in this semester.\n";
        system("pause");
        courseManagementPage();
        return;
    }
    int no;
    currSem.viewCoursesList(no);
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    int choice;
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }

    char confirm = getYesNo("\t(?) If you delete it you will lose all course information. Are you sure you want to delete? (Y/N): ");

    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\t(!) Cancel deleting course.\n";
        system("pause");
        courseManagementPage();
        return;
    }
    Node<Course>* couCurr = currSem.Courses;
    Node<Course>* couPrev = nullptr;
    int count = 0;
    while (couCurr) {
        count++;
        if (count == choice) {
            std::string fileName = "../CSV Files/List of Courses/" + couCurr->data.ID + "_" + couCurr->data.className + ".csv";
            std::ifstream fileStream(fileName);
            if (fileStream.is_open()) {
                fileStream.close();
                std::remove(fileName.c_str());
            }
            if (couCurr == currSem.Courses) {
                Node<SchoolYear>* syCurr = latestSYear; // find the school year that contains the current semester
                while (syCurr) {
                    if (syCurr->data.year == currSYear->data.year) {
                        Node<Course>* temp = syCurr->data.semesters[currSemNumber - 1].Courses;
                        delete[] temp->data.score;
                        syCurr->data.semesters[currSemNumber - 1].Courses = temp->next;
                        delete temp;
                        currSem = syCurr->data.semesters[currSemNumber - 1];
                        break;
                    }
                    syCurr = syCurr->next;
                }
            }
            else {
                delete[] couCurr->data.score;
                couPrev->next = couCurr->next;
                delete couCurr;
            }
            break;
        }
        couPrev = couCurr;
        couCurr = couCurr->next;
    }
    std::cout << "\t(!) Course deleted successfully.\n";
    system("pause");
    courseManagementPage();
    return;
}

void addStudentToACourse() {
    menuCommandHeader();
    std::cout << "[4]. Add student to a course\n\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    std::cout << "\t(?) Enter the course number you want to add students (0-" << no << "): ";
    while (!(std::cin >> choice) || choice < 0 || choice > no) {
        std::cout << "\t(X) Invalid input. Please enter a again:";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (choice == 0) {
        courseManagementPage();
        return;
    }
    int count;
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        if (syCurr->data.year == currSYear->data.year) {
            Node<Course>* couCurr = syCurr->data.semesters[currSemNumber - 1].Courses;
            count = 0;
            while (couCurr) {
                count++;
                if (count == choice) {
                    couCurr->data.addStudent();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
        syCurr = syCurr->next;
    }
}

void removeAStudentFromACourse() {
    menuCommandHeader();
    std::cout << "[5]. Remove student from a course\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
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

void viewListOfCoursesInCurrSem() {
    menuCommandHeader();
    std::cout << "[8]. List of courses in current semester:\n\n";
    int no;
    currSem.viewCoursesList(no);
    std::cout << std::endl;
    system("pause");
    courseManagementPage();
    return;
}

void viewScoreboardOfACourse() {
    menuCommandHeader();
    std::cout << "[10]. View scoreboard of a course\n\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    getChoiceInt(0, no, "\t(?) Enter the course you want to view scoreboard (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
    int count = 0;
    Node<Course>* couCurr = currSem.Courses;
    while (couCurr) {
        count++;
        if (count == choice) {
            menuCommandHeader();
            std::cout << "[10]. Scoreboard of course " << couCurr->data.ID << " - " << couCurr->data.Name << " - " << couCurr->data.className << ":\n\n";
            couCurr->data.viewScoreboard();
            std::cout << std::endl;
            system("pause");
            courseManagementPage();
            return;
        }
        couCurr = couCurr->next;
    }
}

void viewListStudentInACourse() {
    menuCommandHeader();
    std::cout << "[9]. View list of students in a course\n\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
    Node<Course>* couCurr = currSem.Courses;
    int count = 0;
    while (couCurr) {
        count++;
        if (count == choice) {
            menuCommandHeader();
            std::cout << "[9] List of students in course " << couCurr->data.ID << " - " << couCurr->data.Name << " - " << couCurr->data.className << ":\n\n";
            couCurr->data.viewStudentsList();
            std::cout << "\n";
            system("pause");
            courseManagementPage();
            return;
            return;
        }
        couCurr = couCurr->next;
    }
}

void chooseStudentToUpdateResult(Node<Course>* couCurr) {
    menuCommandHeader();
    std::cout << "[11]. Update a student's result of course " << couCurr->data.ID << " - " << couCurr->data.Name << " - " << couCurr->data.className << "\n\n";
    couCurr->data.viewScoreboard();
    int studentIndex;
    getChoiceInt(1, couCurr->data.courseSize, "\n\t(?) Enter the student number you want to update: ", studentIndex);
    std::string scoreTypes[4] = { "Midterm", "Final", "Other", "Total" };
    std::cout << "\t(*) Select the score type to update:" << std::endl;
    for (int i = 0; i < 4; ++i) std::cout << "\t\t" << i + 1 << ". " << scoreTypes[i] << std::endl;
    int choice;
    getChoiceInt(1, 4, "\t(?) Enter the number of the score type you want to update (1/2/3/4): ", choice);
    double newScore;
    std::cout << "\t(?) Enter the new score: ";
    do {
        std::cin >> newScore;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\t(!) Please enter a valid number: ";
        }
        else if (newScore < 0 || newScore > 10) {
            std::cout << "\t(!) Score must be between 0 and 10. Please enter again: ";
        }
        else {
            break;
        }
    } while (true);
    char confirm = getYesNo("\t(?) Are you sure you want to update this score? (Y/N): ");
    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\t(!) Cancel updating score.\n";
        char confirm2 = getYesNo("\t(?) Do you want update again? (Y/N): ");
        if (confirm2 == 'N' || confirm2 == 'n') {
            system("pause");
            courseManagementPage();
            return;
        }
        else if (confirm2 == 'Y' || confirm2 == 'y') {
            chooseStudentToUpdateResult(couCurr);
            return;
        }
    }
    if (scoreTypes[choice - 1] == "Midterm") couCurr->data.score[studentIndex - 1].midTerm = newScore;
    else if (scoreTypes[choice - 1] == "Final") couCurr->data.score[studentIndex - 1].final = newScore;
    else if (scoreTypes[choice - 1] == "Other") couCurr->data.score[studentIndex - 1].other = newScore;
    else if (scoreTypes[choice - 1] == "Total") couCurr->data.score[studentIndex - 1].total = newScore;
    std::cout << "\n\t(!) Student's result updated successfully." << std::endl;
    char confirm2 = getYesNo("\t(?) Do you want to update more scores? (Y/N): ");
    if (confirm2 == 'N' || confirm2 == 'n') {
        courseManagementPage();
        return;
    }
    else if (confirm2 == 'Y' || confirm2 == 'y') {
        chooseStudentToUpdateResult(couCurr);
        return;
    }
}

void updateAStudentResultOfACourse() {
    menuCommandHeader();
    std::cout << "[11]. Update a student's result of a course\n\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
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

void exportCSVStudentsOfACourse() {
    menuCommandHeader();
    std::cout << "[7]. Export a CSV file containing a list of students of a course\n\n";
    int no;
    currSem.viewCoursesList(no);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the course management page\n";
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
    Node<Course>* couCurr = currSem.Courses;
    int count = 0;
    while (couCurr) {
        count++;
        if (count == choice) {
            std::string folderName;
            std::cin.ignore();
            while (true) {
                std::cout << "\t(?) Enter the path of folder (You can drag the folder in - Not drive \"C:\\\"): ";
                std::getline(std::cin >> std::ws, folderName);
                folderName = removeQuotesFromPath(folderName);
                if (!std::filesystem::is_directory(folderName) || folderName.empty()) {
                    char confirm = getYesNo("\t(X) Invalid path. Do you want to try again? (Y/N): ");
                    if (confirm == 'N' || confirm == 'n') {
                        courseManagementPage();
                        return;
                    }
                    folderName = ""; // Clear folderName to loop again
                    continue;
                }
                break;
            }
            std::string fileName;
            if (!folderName.empty() && folderName.back() == '\\') {
                fileName = removeQuotesFromPath(folderName) + couCurr->data.ID + "_" + couCurr->data.className + ".csv";
            }
            else {
                fileName = removeQuotesFromPath(folderName) + "\\" + couCurr->data.ID + "_" + couCurr->data.className + ".csv";
            }
            std::ofstream outF(fileName);
            if (!outF.is_open()) {
                std::cout << "\t(X) Cannot create CSV file!" << std::endl;
                system("pause");
                courseManagementPage();
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
            std::cout << "\t(!) Exported successfully!" << std::endl;
            system("pause");
            courseManagementPage();
            return;
        }
        couCurr = couCurr->next;
    }
}

void importOutsideCSVStudentsInCourse(Node<Course>* couCurr) {
    std::string fileName;
    std::cin.ignore();
    while (true) {
        std::cout << "\t(?) Enter the path of the CSV file (You can drag it into the program): ";
        std::getline(std::cin >> std::ws, fileName);
        if (std::filesystem::is_regular_file(fileName) && ends_with(fileName, ".csv")) {
            break;
        }
        std::cout << "\t(X) Invalid CSV file path." << std::endl;
        char confirm = getYesNo("\t(?) Do you want to try again? (Y/N): ");
        if (confirm == 'N' || confirm == 'n') {
            courseManagementPage();
            return;
        }
    }
    char confirm = getYesNo("\t(?) Are you sure you want to import this CSV file? (Y/N): ");
    if (confirm == 'N' || confirm == 'n') {
        courseManagementPage();
        return;
    }
    std::ifstream inF(fileName);
    if (!inF.is_open()) {
        std::cout << "\t(X) Couldn't import " << fileName << std::endl;
        system("pause");
        courseManagementPage();
        return;
    }
    std::string header;
    std::getline(inF, header);
    std::string line;
    int n = 0;
    bool success = true;
    while (std::getline(inF, line)) {
        if (n == couCurr->data.maxStudents) {
            std::cout << "\t(X) The number of students in the course exceeds the limit of " << couCurr->data.maxStudents << " students." << std::endl;
            success = false;
            break;
        }
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ',');
        std::getline(ss, token, ',');
        couCurr->data.score[n].studentID = token;
        std::getline(ss, token, ',');
        couCurr->data.score[n].studentName = token;
        n++;
    }
    if (!success) {
        delete[] couCurr->data.score;
        couCurr->data.score = nullptr;
        std::cout << "\t(X) Import failed. Imported students are removed. If you want to import more students, resize the course and try again." << std::endl;
    }
    else {
        couCurr->data.courseSize = n;
        inF.close();
        std::cout << "\t(X) Imported successfully." << std::endl;
    }
    inF.close();
}

void uploadCSVFileContainingAListOfStudentsOfACourse() {
    menuCommandHeader();
    std::cout << "[6]. Upload a CSV file containing a list of students of a course\n\n";
    int no;
    currSem.viewCoursesList(no);
    std::cout << "\n\t(*) Your CSV file must have the format:" << std::endl;
    std::cout << "\t\t1. The header line has the format: No,Student ID,Student Name" << std::endl;
    std::cout << "\t\t2. No is the serial number of each student, student ID must have 8 digits, student Name has no format." << std::endl;
    std::cout << "\t(*) Enter '0' to return to the course management page\n";
    int choice;
    getChoiceInt(0, no, "\t(?) Enter the course number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        courseManagementPage();
        return;
    }
    int count = 0;
    Node<Course>* couCurr = currSem.Courses;
    while (couCurr) {
        count++;
        if (count == choice) {
            if (couCurr->data.score == nullptr) {
                importOutsideCSVStudentsInCourse(couCurr);
            }
            else {
                std::cout << "\t(X) This course already has students enrolled." << std::endl;
            }
            system("pause");
            courseManagementPage();
            return;
        }
        couCurr = couCurr->next;
    }
}