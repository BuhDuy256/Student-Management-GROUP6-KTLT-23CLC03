#include"Course.h"

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

void exportCSVStudentsOfACourse() {
    std::cout << "Enter the information of the course you want to export all students to CSV Files: " << std::endl;
    Course couEx;
    std::string couID, couClass, couSY;
    std::cout << "\tCourse ID: "; std::cin >> couID;
    std::cout << "\tClass Name (Ex: 23CLC03): "; std::cin >> couClass;
    std::cout << "\tSchool Year: "; std::cin >> couSY;
    couSY = formatSchoolYear(couSY);
    int couSem;
    std::cout << "\tSemester (1 -> 3): ";
    while (!(std::cin >> couSem) || couSem < 1 || couSem > 3) {
        std::cout << "Invalid age. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::string folderName;

    do {
        std::cout << "Enter the path of folder you want to export CSV: ";
        std::getline(std::cin >> std::ws, folderName);
        // Check if the folder exists
        if (!std::filesystem::is_directory(folderName)) {
            std::cout << "Invalid folder path. Please try again." << std::endl;
            folderName = ""; // Clear folderName to loop again
        }
    } while (folderName.empty());

    bool found = false;
    Node<SchoolYear>* syCurr = latestSYear;
    Node<Course>* couFind = nullptr;
    while (syCurr && !found) {
        if (syCurr->data.year == couSY) {
            if (syCurr->data.semesters[couSem - 1].isCreated) {
                if (!syCurr->data.semesters[couSem - 1].Courses) {
                    std::cout << "This semester don't have any course data!" << std::endl;
                    return;
                }
                else {
                    couFind = syCurr->data.semesters[couSem - 1].Courses;
                    while (couFind) {
                        if (couFind->data.ID == couID && couFind->data.className == couClass) {
                            std::string fileName = removeQuotesFromPath(folderName) + "/" + couID + "_" + couClass + ".csv";
                            std::ofstream outF(fileName);
                            if (!outF.is_open()) {
                                std::cout << "Error creating CSV file!" << std::endl;
                                return;
                            }
                            outF << "Student ID,Student Name,Midterm Mark,Final Mark,Other Mark,Total Mark\n";
                            StudentScore* scoreArr = couFind->data.score;
                            for (int i = 0; i < couFind->data.courseSize; i++) {
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
                            return;
                        }
                        if (!couFind) {
                            std::cout << "Couldn't find Course have ID: " << couID << " and class Name" << couClass << std::endl;
                            return;
                        }
                        couFind = couFind->next;
                    }
                }
            }
            else {
                std::cout << "Semester hasn't been created before!" << std::endl;
                return;
            }
        }
        syCurr = syCurr->next;
    }
    if (!syCurr) {
        std::cout << "School Year Information isn't true!" << std::endl;
        return;
    }
}