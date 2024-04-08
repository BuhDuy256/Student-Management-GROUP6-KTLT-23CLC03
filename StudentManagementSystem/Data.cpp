#include"Data.h"

void importAllClassesCSV() {
    // std::ifstream inF("../CSV Files/AllClasses.csv");
    // if (!inF.is_open()) {
    //     std::cout << "Could't import AllClasses.csv!";
    //     return;
    // }
    QFile file(":/prefix/CSV Files/AllClasses.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }
    QTextStream fin(&file);
    Node<SchoolYear>* syHead = latestSYear;
    QString header = fin.readLine();
    while (!fin.atEnd()) {
        QString Line = fin.readLine();
        std::string line = Line.toStdString();
        std::stringstream ss(line);
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        Class newClass;
        std::getline(ss, newClass.className, ',');
        std::getline(ss, newClass.schoolYear, ',');
        Node<SchoolYear>* syCurr = syHead;
        bool found = false;
        while (syCurr && !found) {
            if (syCurr->data.year == newClass.schoolYear) {
                found = true;
                if (!syCurr->data.classes) {
                    syCurr->data.classes = new Node<Class>(newClass);
                }
                else {
                    Node<Class>* claCurr = syCurr->data.classes;
                    while (claCurr->next) {
                        claCurr = claCurr->next;
                    }
                    claCurr->next = new Node<Class>(newClass);
                }
                break;
            }
            syCurr = syCurr->next;
        }
        if (!found) {
            std::cout << "Couldn't find the school year corresponding to " << newClass.className << std::endl;
        }
    }
    file.close();
}

void saveAllClassesData() {
    Node<SchoolYear>* syCurr = latestSYear;
    std::ofstream outF("../CSV Files/AllClasses.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Class Name,School Year\n";
        while (syCurr) {
            Node<Class>* claCurr = syCurr->data.classes;
            while (claCurr) {
                outF << claCurr->data.className << "," << claCurr->data.schoolYear << "\n";
                claCurr = claCurr->next;
            }
            syCurr = syCurr->next;
        }
    }
    else {
        std::cout << "Could't open AllClasses.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllClassesData() {
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr) {
            Node<Class>* temp = claCurr;
            claCurr = claCurr->next;
            delete temp;
        }
        syCurr = syCurr->next;
    }
}

void importAllCoursesCSV() {
    // std::ifstream inF("../CSV Files/AllCourses.csv");
    // if (!inF.is_open()) {
    //     std::cout << "Couldn't import AllCourses.csv!" << std::endl;
    //     return;
    // }
    QFile file(":/prefix/CSV Files/AllCourses.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }
    QTextStream fin(&file);
    QString header = fin.readLine();
    while (!fin.atEnd()) {
        QString Line = fin.readLine();
        std::string line = Line.toStdString();
        std::stringstream ss(line);
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        Course newCourse;
        std::getline(ss, newCourse.ID, ',');
        std::getline(ss, newCourse.Name, ',');
        std::getline(ss, newCourse.className, ',');
        std::getline(ss, newCourse.teacherName, ',');
        std::string nCreditStr;
        std::getline(ss, nCreditStr, ',');
        std::stringstream(nCreditStr) >> newCourse.nCredits;
        std::string maxStudentsStr;
        std::getline(ss, maxStudentsStr, ',');
        std::stringstream(maxStudentsStr) >> newCourse.maxStudents;
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
                        syCurr->data.semesters[newCourse.couSem - 1].Courses->data.score = new StudentScore[newCourse.maxStudents];
                    }
                    else {
                        Node<Course>* couCurr = couHead;
                        while (couCurr->next) {
                            couCurr = couCurr->next;
                        }
                        couCurr->next = new Node<Course>(newCourse);
                        couCurr->next->data.score = new StudentScore[newCourse.maxStudents];
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
    file.close();
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
        outF << "Course ID,Course Name,Class Name,Teacher Name,Number Of Credits,Maximum Number Of Students,Day Of Week,Session,School Year,Semester\n";
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
                             << couCurr->data.maxStudents << ","
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

void importAllSchoolYearsCSV() {
    // std::ifstream inF("../CSV Files/AllSchoolYears.csv");
    // if (!inF.is_open()) {
    //     std::cout << "Can't import AllSchoolYear.csv!";
    //     return;
    // }
    QFile file(":/prefix/CSV Files/AllSchoolYears.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }
    QTextStream fin(&file);
    Node<SchoolYear>* syHead = nullptr;
    QString header = fin.readLine();

    while (!fin.atEnd()) {
        QString Line = fin.readLine();
        std::string line = Line.toStdString();
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        SchoolYear syNew;
        syNew.year = line;
        Node<SchoolYear>* syTemp = new Node<SchoolYear>(syNew, syHead);
        syHead = syTemp;
    }
    latestSYear = currSYear = syHead;
    file.close();
}

void reverseSchoolYearsList(Node<SchoolYear>*& syHead) {
    Node<SchoolYear>* syPrev = nullptr, * syNext = nullptr;
    Node<SchoolYear>* syCurr = syHead;
    while (syCurr) {
        syNext = syCurr->next;
        syCurr->next = syPrev;
        syPrev = syCurr;
        syCurr = syNext;
    }
    syHead = syPrev;
}

void saveAllSchoolYearsData() {
    reverseSchoolYearsList(latestSYear);
    Node<SchoolYear>* syCurr = latestSYear;
    std::ofstream outF("../CSV Files/AllSchoolYears.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "School Year\n";
        while (syCurr) {
            outF << syCurr->data.year << "\n";
            syCurr = syCurr->next;
        }
    }
    else {
        std::cout << "Could't open AllSchoolYears.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllSchoolYearsData() {
    while (latestSYear) {
        Node<SchoolYear>* temp = latestSYear;
        latestSYear = latestSYear->next;
        delete temp;
    }
}

void importAllSemestersCSV() {
    // std::ifstream inF("../CSV Files/AllSemesters.csv");
    // if (!inF.is_open()) {
    //     std::cout << "Can't import AllSemesters.csv!" << std::endl;
    //     return;
    // }
    QFile file(":/prefix/CSV Files/AllSemesters.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }
    QTextStream fin(&file);
    QString header = fin.readLine();
    while (!fin.atEnd()) {
        QString Line = fin.readLine();
        std::string line = Line.toStdString();
        std::stringstream ss(line);
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        std::string nSemTemp, syName, startDate, endDate;
        std::getline(ss, nSemTemp, ',');
        std::getline(ss, syName, ',');
        std::getline(ss, startDate, ',');
        std::getline(ss, endDate, ',');
        Node<SchoolYear>* syCurr = latestSYear;
        while (syCurr) {
            if (syCurr->data.year == syName) {
                int nSem = 0;
                std::istringstream(nSemTemp) >> nSem;
                // std::cout << nSem;
                syCurr->data.semesters[nSem - 1].isCreated = true;
                syCurr->data.semesters[nSem - 1].startDate = startDate;
                syCurr->data.semesters[nSem - 1].endDate = endDate;
                break;
            }
            syCurr = syCurr->next;
        }
    }
    file.close();
}

void importAllStudentsCSV() {
    // std::ifstream inF("../CSV Files/AllStudents.csv");
    // if (!inF.is_open()) {
    //     std::cout << "Could't import AllStudents.csv!";
    //     return;
    // }
    QFile file(":/prefix/CSV Files/AllStudents.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }
    QTextStream fin(&file);
    Node<SchoolYear>* syHead = latestSYear;
    QString header = fin.readLine();
    while (!fin.atEnd()) {
        QString Line = fin.readLine();
        std::string line = Line.toStdString();
        std::stringstream ss(line);
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        Student newStu;
        std::getline(ss, newStu.ID, ',');
        std::getline(ss, newStu.name, ',');
        std::getline(ss, newStu.gender, ',');
        std::getline(ss, newStu.birthday, ',');
        std::getline(ss, newStu.socialID, ',');
        std::getline(ss, newStu.mainClass, ',');
        std::getline(ss, newStu.password, ',');
        Node<SchoolYear>* syCurr = syHead;
        bool found = false;
        while (syCurr && !found) {
            Node<Class>* claCurr = syCurr->data.classes;
            while (claCurr && !found) {
                if (claCurr->data.className == newStu.mainClass) {
                    found = true;
                    if (!claCurr->data.students) {
                        claCurr->data.students = new Node<Student>(newStu);
                    }
                    else {
                        Node<Student>* stuCurr = claCurr->data.students;
                        while (stuCurr->next)
                            stuCurr = stuCurr->next;
                        stuCurr->next = new Node<Student>(newStu);
                    }
                    break;
                }
                claCurr = claCurr->next;
            }
            syCurr = syCurr->next;
        }
        if (!found) {
            std::cout << "Could not find class of student with ID " << newStu.ID << std::endl;
        }
    }
    file.close();
}

void saveAllStudentsData() {
    Node<SchoolYear>* syCurr = latestSYear;
    std::ofstream outF("../CSV Files/AllStudents.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Student ID,Student Name,Gender,Birthday,Social ID,Main Class,Password\n";
        while (syCurr) {
            Node<Class>* claCurr = syCurr->data.classes;
            while (claCurr) {
                Node<Student>* stuCurr = claCurr->data.students;
                while (stuCurr) {
                    outF << stuCurr->data.ID << ","
                         << stuCurr->data.name << ","
                         << stuCurr->data.gender << ","
                         << stuCurr->data.birthday << ","
                         << stuCurr->data.socialID << ","
                         << stuCurr->data.mainClass << ","
                         << stuCurr->data.password << "\n";
                    stuCurr = stuCurr->next;
                }
                claCurr = claCurr->next;
            }
            syCurr = syCurr->next;
        }
    }
    else {
        std::cout << "Could't open AllStudents.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllStudentsData() {
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr) {
            Node<Student>* stuCurr = claCurr->data.students;
            while (stuCurr) {
                Node<Student>* temp = stuCurr;
                stuCurr = stuCurr->next;
                delete temp;
            }
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
}
