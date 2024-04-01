#include"Course.h"

std::string doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string removeQuotesFromPath(const std::string& path) {
    std::string cleanedPath = path;
    if (cleanedPath.size() >= 2 && cleanedPath.front() == '"' && cleanedPath.back() == '"') {
        cleanedPath = cleanedPath.substr(1, cleanedPath.size() - 2);
    }
    return cleanedPath;
}

void importAllCoursesCSV() {
    std::ifstream inF("../CSV Files/AllCourses.csv");
    if (!inF.is_open()) {
        std::cout << "Couldn't import AllCourses.csv!" << std::endl;
        return;
    }
    std::string header;
    std::getline(inF, header);
    std::string line;
    while (std::getline(inF, line)) {
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        std::stringstream ss(line);
        Course newCourse;
        std::getline(ss, newCourse.ID, ',');
        std::getline(ss, newCourse.Name, ',');
        std::getline(ss, newCourse.className, ',');
        std::getline(ss, newCourse.teacherName, ',');
        std::string nCreditStr;
        std::getline(ss, nCreditStr, ',');
        std::stringstream(nCreditStr) >> newCourse.nCredits;
        std::getline(ss, newCourse.dayOfWeek, ',');
        std::getline(ss, newCourse.session, ',');
        std::string couSemTemp;
        std::getline(ss, newCourse.couSY, ',');
        std::getline(ss, couSemTemp, ',');
        std::stringstream(couSemTemp) >> newCourse.couSem;
        // std::cout << couSemTemp << " | " << couSY << "\n"; 
        Node<SchoolYear>* syCurr = latestSYear;
        bool found = false;
        while (syCurr && !found) {
            if (syCurr->data.year == newCourse.couSY) {
                if (newCourse.couSem > 0 && newCourse.couSem <= 3) {
                    found = true;
                    if (!syCurr->data.semesters[newCourse.couSem - 1].isCreated) {
                        std::cout << "Error: Semester not created for year " << newCourse.couSY << " and semester " << newCourse.couSem << std::endl;
                        break;
                    }
                    Node<Course>* couHead = syCurr->data.semesters[newCourse.couSem - 1].Courses;
                    if (!couHead) {
                        syCurr->data.semesters[newCourse.couSem - 1].Courses = new Node<Course>(newCourse);
                        syCurr->data.semesters[newCourse.couSem - 1].Courses->data.score = new StudentScore[100];
                    }
                    else {
                        Node<Course>* couCurr = couHead;
                        while (couCurr->next) {
                            couCurr = couCurr->next;
                        }
                        couCurr->next = new Node<Course>(newCourse);
                        couCurr->next->data.score = new StudentScore[100];
                    }
                }
                else {
                    std::cout << "Error: Invalid semester number for year " << newCourse.couSY << ": " << newCourse.couSem << std::endl;
                    break;
                }
            }
            syCurr = syCurr->next;
        }
        if (!found) {
            std::cout << "Error: Year not found: " << newCourse.couSY << std::endl;
        }
    }
    inF.close();
}

void importContainingStudentsEnrolledInCourse(Node<Course>* couCurr) {
    std::string fileName = "../CSV Files/List of Courses/" + couCurr->data.ID + "_" + couCurr->data.className + ".csv";
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
        std::getline(ss, token, ',');
        couCurr->data.score[n].studentID = token;
        std::getline(ss, token, ',');
        couCurr->data.score[n].studentName = token;
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr->data.score[n].midTerm = std::stod(token);
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr->data.score[n].final = std::stod(token);
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr->data.score[n].other = std::stod(token);
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr->data.score[n].total = std::stod(token);
        n++;
    }
    couCurr->data.courseSize = n;
    inF.close();
}

void importAllStudentsInAllCoursesCSV() {
    Node<SchoolYear>* syHead = latestSYear;
    while (syHead) {
        for (int i = 0; i < 3; i++) {
            if (syHead->data.semesters[i].isCreated) {
                Node<Course>* couCurr = syHead->data.semesters[i].Courses;
                while (couCurr) {
                    importContainingStudentsEnrolledInCourse(couCurr);
                    couCurr = couCurr->next;
                }
            }
        }
        syHead = syHead->next;
    }
}

void saveAllCoursesData() {
    Node<SchoolYear>* syCurr = latestSYear;
    std::ofstream outF("../CSV Files/AllCourses.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Course ID,Course Name,Class Name,Teacher Name,Number Of Credits,Day Of Week,Session,School Year,Semester\n";
        while (syCurr) {
            for (int i = 0; i < 3; i++) {
                if (syCurr->data.semesters[i].isCreated) {
                    Node<Course>* couCurr = syCurr->data.semesters[i].Courses;
                    while (couCurr) {
                        outF << couCurr->data.ID << ","
                            << couCurr->data.Name << ","
                            << couCurr->data.className << ","
                            << couCurr->data.teacherName << ","
                            << couCurr->data.nCredits << ","
                            << couCurr->data.dayOfWeek << ","
                            << couCurr->data.session << ","
                            << syCurr->data.year << "," // couSY
                            << i + 1 << "\n"; // couSem
                        couCurr = couCurr->next;
                    }
                }
            }
            syCurr = syCurr->next;
        }
    }
    else {
        std::cout << "Could't open AllCourses.csv to save Data." << std::endl;
    }
    outF.close();
}

void saveScoreboardOfACourse(Node<Course>* couCurr) {
    std::string fileName = "../CSV Files/List of Courses/" + couCurr->data.ID + "_" + couCurr->data.className + ".csv";
    std::ofstream outF(fileName, std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
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
    }
    else {
        std::cout << "Could't open " << fileName << " to save Data." << std::endl;
    }
    outF.close();
}

void saveAllScoreboardsData() {
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        for (int i = 0; i < 3; i++) {
            if (syCurr->data.semesters[i].isCreated) {
                Node<Course>* couCurr = syCurr->data.semesters[i].Courses;
                while (couCurr) {
                    saveScoreboardOfACourse(couCurr);
                    couCurr = couCurr->next;
                }
            }
        }
        syCurr = syCurr->next;
    }
}

void deleteAllScoreboardsData() {
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        for (int i = 0; i < 3; i++) {
            if (syCurr->data.semesters[i].isCreated) {
                Node<Course>* couCurr = syCurr->data.semesters[i].Courses;
                while (couCurr) {
                    couCurr->data.courseSize = 0;
                    delete[]couCurr->data.score;
                    couCurr = couCurr->next;
                }
            }
        }
        syCurr = syCurr->next;
    }
}

void deleteAllCourseData() {
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        for (int i = 0; i < 3; i++) {
            if (syCurr->data.semesters[i].isCreated) {
                Node<Course>* couCurr = syCurr->data.semesters[i].Courses;
                while (couCurr) {
                    Node<Course>* temp = couCurr;
                    couCurr = couCurr->next;
                    delete temp;
                }
            }
        }
        syCurr = syCurr->next;
    }
}

void displayTableListOfCoursesInCurrSem(int& no) {
    std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
    std::cout << "\t| No     | Course ID  | Course Name                  | Class Name | Teacher Name            | Credits | Size | Day | Session |\n";
    std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
    no = 0;
    Node<Course>* couCurr = currSem.Courses;
    while (couCurr) {
        no++;
        std::cout << "\t| " << std::left << std::setw(7) << no
            << "| " << std::left << std::setw(11) << couCurr->data.ID
            << "| " << std::left << std::setw(29) << couCurr->data.Name
            << "| " << std::left << std::setw(11) << couCurr->data.className
            << "| " << std::left << std::setw(24) << couCurr->data.teacherName
            << "| " << std::left << std::setw(8) << couCurr->data.nCredits
            << "| " << std::left << std::setw(5) << couCurr->data.courseSize
            << "| " << std::left << std::setw(4) << couCurr->data.dayOfWeek
            << "| " << std::left << std::setw(8) << couCurr->data.session
            << "|" << std::endl;
        couCurr = couCurr->next;
    }
    std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
}

void viewListOfCoursesInCurrSem() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "[8]. List of courses in current semester:\n";
    int no = 0;
    displayTableListOfCoursesInCurrSem(no);
    system("pause");
    courseManagementPage();
    return;
}

void addACourseInCurrSem() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "[1]. Add a course in current semester:\n";
    Course newCourse;
    std::cout << "Enter course ID: ";
    std::cin >> newCourse.ID;
    std::cout << "Enter course name: ";
    std::cin.ignore();
    std::getline(std::cin, newCourse.Name);
    std::cout << "Enter class name: ";
    std::cin >> newCourse.className;
    std::cout << "Enter teacher name: ";
    std::cin.ignore();
    std::getline(std::cin, newCourse.teacherName);
    std::cout << "Enter number of credits: ";
    while (!(std::cin >> newCourse.nCredits) || newCourse.nCredits < 2 || newCourse.nCredits > 4) {
        std::cout << "Invalid number of credits. The number of credits of a course should be between 2 and 4. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Enter course size: ";
    while (!(std::cin >> newCourse.courseSize) || newCourse.courseSize < 0 || newCourse.courseSize > 100) {
        std::cout << "Invalid course size. The course size should be between 0 and 100. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout << "Day of week:\n";
    std::cout << "\t1. MON\n";
    std::cout << "\t2. TUE\n";
    std::cout << "\t3. WED\n";
    std::cout << "\t4. THU\n";
    std::cout << "\t5. FRI\n";
    std::cout << "\t6. SAT\n";
    int day;
    std::cout << "Enter day of week (1-6): ";
    while (true) {
        std::cin >> day;
        if (day >= 1 && day <= 6) {
            if (day == 1) {
                newCourse.dayOfWeek = "MON";
            }
            else if (day == 2) {
                newCourse.dayOfWeek = "TUE";
            }
            else if (day == 3) {
                newCourse.dayOfWeek = "WED";
            }
            else if (day == 4) {
                newCourse.dayOfWeek = "THU";
            }
            else if (day == 5) {
                newCourse.dayOfWeek = "FRI";
            }
            else if (day == 6) {
                newCourse.dayOfWeek = "SAT";
            }
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter again (1-6): ";
        }
    }
    std::cout << "All sessions:\n";
    std::cout << "\t1. S1 (07:30)\n";
    std::cout << "\t2. S2 (09:30)\n";
    std::cout << "\t3. S3 (13:30)\n";
    std::cout << "\t4. S4 (15:30)\n";
    int session;
    std::cout << "Enter session (1-4): ";
    while (true) {
        std::cin >> session;
        if (session >= 1 && session <= 4) {
            if (session == 1) {
                newCourse.session = "07:30";
            }
            else if (session == 2) {
                newCourse.session = "09:30";
            }
            else if (session == 3) {
                newCourse.session = "13:30";
            }
            else if (session == 4) {
                newCourse.session = "15:30";
            }
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid choice. Please enter again (1-4): ";
        }
    }
    newCourse.couSY = currSYear->data.year;
    newCourse.couSem = currSemNumber;
    Node<Course>* newCourseNode = new Node<Course>(newCourse, currSem.Courses);
    currSem.Courses = newCourseNode;
    std::cout << "Course added successfully." << std::endl;
    system("pause");
    courseManagementPage();
    return;
}

void deleteACourseInCurrSem() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "List of courses in current semester:\n";
    int no = 0;
    displayTableListOfCoursesInCurrSem(no);
    std::cout << "Enter the course you want to delete (1 to " << no << "): ";
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
            Node<Course>* couPrev = nullptr;
            while (couCurr) {
                count++;
                if (count == choice) {
                    if (couPrev) {
                        couPrev->next = couCurr->next;
                    }
                    else {
                        currSem.Courses = couCurr->next;
                    }
                    delete couCurr;
                    std::cout << "Course deleted successfully." << std::endl;
                    break;
                }
                couPrev = couCurr;
                couCurr = couCurr->next;
            }
            break;
        }
    }
    system("pause");
    courseManagementPage();
    return;
}

void addStudentToACourse() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    int no;
    displayTableListOfCoursesInCurrSem(no);
    std::cout << "Enter the course you want to add students (1 to " << no << "): ";
    int choice;
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
                    StudentScore studentScore;
                    while (true) {
                        std::cout << "\tEnter the student's ID: ";
                        std::getline(std::cin, studentScore.studentID);
                        if (checkIDValid(studentScore.studentID)) break;
                    }
                    while (true) {
                        std::cout << "\tEnter the student's name: ";
                        std::getline(std::cin, studentScore.studentName);
                        if (checkNameValid(studentScore.studentName)) break;
                    }
                    formalize(studentScore.studentName);
                    couCurr->data.score[couCurr->data.courseSize] = studentScore;
                    couCurr->data.courseSize++;
                    break;
                }
                couCurr = couCurr->next;
            }
        }
    }
    system("pause");
    courseManagementPage();
    return;
}

void viewScoreboardOfACourse() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "List of courses in current semester:\n";
    int no;
    displayTableListOfCoursesInCurrSem(no);
    std::cout << "Enter the course you want to view scoreboard (1 to " << no << "): ";
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
                    system("cls");
                    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
                    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
                    std::cout << "List of students in course " << couCurr->data.ID << " - " << couCurr->data.Name << " - " << couCurr->data.className << ":\n";
                    displayTableScoreboardOfACourse(couCurr);
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

void displayTableScoreboardOfACourse(Node<Course>* couCurr) {
    std::cout << "\t+--------+------------+------------------------------+----------+----------+----------+----------+" << std::endl;
    std::cout << "\t| NO     | Student ID | Student Name                 | Midterm  | Final    | Others   | Total    |" << std::endl;
    std::cout << "\t+--------+------------+------------------------------+----------+----------+----------+----------+" << std::endl;
    for (int i = 0; i < couCurr->data.courseSize; i++) {
        std::cout << "\t| " << std::setw(7) << std::left << i + 1
            << "| " << std::setw(11) << std::left << couCurr->data.score[i].studentID
            << "| " << std::setw(29) << std::left << couCurr->data.score[i].studentName
            << "| " << std::setw(9) << std::left << (couCurr->data.score[i].midTerm > 0 ? doubleToString(couCurr->data.score[i].midTerm) : "")
            << "| " << std::setw(9) << std::left << (couCurr->data.score[i].final > 0 ? doubleToString(couCurr->data.score[i].final) : "")
            << "| " << std::setw(9) << std::left << (couCurr->data.score[i].other > 0 ? doubleToString(couCurr->data.score[i].other) : "")
            << "| " << std::setw(9) << std::left << (couCurr->data.score[i].total > 0 ? doubleToString(couCurr->data.score[i].total) : "")
            << "|" << std::endl;
    }
    std::cout << "\t+--------+------------+------------------------------+----------+----------+----------+----------+" << std::endl;
    return;
}

void removeAStudentFromACoursePage() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "[5]. Remove student from a course\n";
    std::cout << "List of courses in current semester:" << std::endl;
    int no;
    displayTableListOfCoursesInCurrSem(no);
    std::cout << "Enter the course you want to remove students (1 to " << no << "): ";
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
                    removeAStudentFromACourse(couCurr);
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void displayTableStudentsInACourse(Node<Course>* couCurr) {
    std::cout << "\t+--------+------------+------------------------------+\n";
    std::cout << "\t| NO     | Student ID | Student Name                 |\n";
    std::cout << "\t+--------+------------+------------------------------+\n";

    for (int i = 0; i < couCurr->data.courseSize; i++) {
        std::cout << "\t| " << std::setw(7) << std::left << i + 1
            << "| " << std::setw(11) << std::left << couCurr->data.score[i].studentID
            << "| " << std::setw(29) << std::left << couCurr->data.score[i].studentName
            << "|\n";
    }
    std::cout << "\t+--------+------------+------------------------------+\n";
    return;
}

void removeAStudentFromACourse(Node<Course>* couCurr) {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "List of courses in current semester:" << std::endl;
    displayTableStudentsInACourse(couCurr);
    std::cout << "Enter the student you want to remove (between 1 and " << couCurr->data.courseSize << "): ";
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > couCurr->data.courseSize) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer between 1 and " << couCurr->data.courseSize << ": ";
        }
        else {
            for (int i = choice - 1; i < couCurr->data.courseSize - 1; i++) {
                couCurr->data.score[i] = couCurr->data.score[i + 1];
            }
            couCurr->data.courseSize--;
            std::cout << "Remove student successfully!\n";
            system("pause");
            courseManagementPage();
            return;
        }
    }
}

void viewListStudentInACourse() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "[9]. View list of student in a course\n";
    int no;
    displayTableListOfCoursesInCurrSem(no);
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
                    system("cls");
                    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
                    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
                    std::cout << "List of students in course: " << couCurr->data.ID << " - " << couCurr->data.Name << "\n";
                    displayTableStudentsInACourse(couCurr);
                    system("pause");
                    courseManagementPage();
                    return;
                }
                couCurr = couCurr->next;
            }
        }
    }
}

void updateAStudentResultOfACoursePage() {
	system("cls");
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
	std::cout << "[11]. Update a student's result of a course\n";
	int no;
	displayTableListOfCoursesInCurrSem(no);
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
					chooseStudentToUpateResult(couCurr);
					return;
				}
				couCurr = couCurr->next;
			}
		}
	}
}

void chooseStudentToUpateResult(Node<Course>* couCurr) {
	system("cls");
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
	std::cout << "List of students in course " << couCurr->data.ID << " - " << couCurr->data.Name << " - " << couCurr->data.className << ":\n";
	displayTableScoreboardOfACourse(couCurr);
	std::cout << "Enter the student you want to update result (between 1 and " << couCurr->data.courseSize << "): ";
	int choice;
	while (true) {
		std::cin >> choice;
		if (std::cin.fail() || choice < 1 || choice > couCurr->data.courseSize) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a valid integer between 1 and " << couCurr->data.courseSize << ": ";
		}
		else {
			updateStudentResult(couCurr, choice);
			return;
		}
	}
}

void updateStudentResult(Node<Course>* couCurr, int idx) {
	system("cls");
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
	currStuScore = &couCurr->data.score[idx - 1];
	std::cout << "Study Result of student " << currStuScore->studentID << " - " << currStuScore->studentName << " in course " << couCurr->data.Name << std::endl;
	std::cout << "\tMid-term: " << currStuScore->midTerm << std::endl;
	std::cout << "\tFinal: " << currStuScore->final << std::endl;
	std::cout << "\tOther: " << currStuScore->other << std::endl;
	std::cout << "\tTotal: " << currStuScore->total << std::endl;
	std::cout << "Enter the score you want to update: " << std::endl;
	std::cout << "\t1. Mid-term score" << std::endl;
	std::cout << "\t2. Final score" << std::endl;
	std::cout << "\t3. Other score" << std::endl;
	std::cout << "\t4. Total score" << std::endl;
	std::cout << "\t-1. Exit" << std::endl;
	int choice;
	std::cout << "Enter your command (1/2/3/4/-1): ";
	std::cin >> choice;
	if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a valid integer (1/2/3/4/-1)." << std::endl;
		system("pause");
		updateStudentResult(couCurr, idx);
	}
	else {
		if (choice == 1) {
			std::cout << "Enter new midterm score: ";
			while (true) {
				double newScore;
				std::cin >> newScore;
				if (std::cin.fail() || newScore < 0 || newScore > 10) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input. Please enter a valid double: " << std::endl;
				}
				else {
					currStuScore->midTerm = newScore;
					break;
				}
			}
		}
		else if (choice == 2) {
			std::cout << "Enter new final score: ";
			while (true) {
				double newScore;
				std::cin >> newScore;
				if (std::cin.fail() || newScore < 0 || newScore > 10) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input. Please enter a valid double: " << std::endl;
				}
				else {
					currStuScore->final = newScore;
					break;
				}
			}
		}
		else if (choice == 3) {
			std::cout << "Enter new others score: ";
			while (true) {
				double newScore;
				std::cin >> newScore;
				if (std::cin.fail() || newScore < 0 || newScore > 10) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input. Please enter a valid double: " << std::endl;
				}
				else {
					currStuScore->other = newScore;
					break;
				}
			}
		}
		else if (choice == 4) {
			std::cout << "Eneter new total score: ";
			while (true) {
				double newScore;
				std::cin >> newScore;
				if (std::cin.fail() || newScore < 0 || newScore > 4) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input. Please enter a valid double: " << std::endl;
				}
				else {
					currStuScore->total = newScore;
					break;
				}
			}
		}
		else if (choice == -1) {
			courseManagementPage();
			return;
		}
		std::cout << "Update successfully." << std::endl;
		system("pause");
		updateStudentResult(couCurr, idx);
	}
}