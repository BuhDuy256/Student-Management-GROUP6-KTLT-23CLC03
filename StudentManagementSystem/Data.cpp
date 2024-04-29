#include"Data.h"

void importAllClassesCSV() {
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/AllClasses.csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/AllClasses.csv";
    QFile file(path);
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
                    Node<Class>*& claCurr = syCurr->data.classes;
                    Node<Class>* tmp = new Node<Class>(newClass);
                    tmp->next = claCurr;
                    claCurr = tmp;
                    // while (claCurr->next) {
                    //     claCurr = claCurr->next;
                    // }
                    // claCurr->next = new Node<Class>(newClass);
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
    QString directoryPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System";
    QString filePath = directoryPath + "/AllClasses.csv";

    // Check if the directory exists, create it if necessary
    QDir directory(directoryPath);
    if (!directory.exists()) {
        if (!directory.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return;
        }
    }
    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outStream(&outFile);
        outStream << "Class Name,School Year\n";
        while (syCurr) {
            Node<Class>* claCurr = syCurr->data.classes;
            while (claCurr) {
                outStream << QString::fromStdString(claCurr->data.className) << "," << QString::fromStdString(claCurr->data.schoolYear) << "\n";
                claCurr = claCurr->next;
            }
            syCurr = syCurr->next;
        }
    } else {
        qDebug() << "Couldn't open AllClasses.csv to save Data.";
    }
    outFile.close();
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
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/AllCourses.csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/AllCourses.csv";
    QFile file(path);
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
                        // std::cout << "Error: Semester not created for year " << newCourse.couSY << " and semester " << newCourse.couSem << std::endl;
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
                    // std::cout << "Error: Invalid semester number for year " << newCourse.couSY << ": " << newCourse.couSem << std::endl;
                    break;
                }
            }
            syCurr = syCurr->next;
        }
        if (!found) {
            // std::cout << "Error: Year not found: " << newCourse.couSY << std::endl;
        }
    }
    file.close();
}

void importContainingStudentsEnrolledInCourse(Node<Course>* couCurr) {
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/List of Courses/" + QString::fromStdString(couCurr->data.ID) + "_" + QString::fromStdString(couCurr->data.className) + ".csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/List of Courses/" + QString::fromStdString(couCurr->data.ID) + "_" + QString::fromStdString(couCurr->data.className) + ".csv";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }

    QTextStream in(&file);

    QString header = in.readLine(); // Read the header line
    QString line;
    int n = 0;

    while (!in.atEnd()) {
        line = in.readLine();

        // Check if the line is empty or contains only whitespace
        if (line.trimmed().isEmpty()) {
            break; // Stop reading if the line is empty
        }

        QStringList tokens = line.split(',');

        // Assuming that tokens.size() is at least 3 (for student ID, name, and at least one score)
        couCurr->data.score[n].studentID = tokens.at(0).toStdString();
        couCurr->data.score[n].studentName = tokens.at(1).toStdString();

        if (tokens.size() > 2 && !tokens.at(2).isEmpty())
            couCurr->data.score[n].midTerm = tokens.at(2).toDouble();
        if (tokens.size() > 3 && !tokens.at(3).isEmpty())
            couCurr->data.score[n].final = tokens.at(3).toDouble();
        if (tokens.size() > 4 && !tokens.at(4).isEmpty())
            couCurr->data.score[n].other = tokens.at(4).toDouble();
        if (tokens.size() > 5 && !tokens.at(5).isEmpty())
            couCurr->data.score[n].total = tokens.at(5).toDouble();

        n++;
    }

    couCurr->data.courseSize = n;
    file.close();
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
    QString directoryPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System";
    QString filePath = directoryPath + "/AllCourses.csv";

    // Check if the directory exists, create it if necessary
    QDir directory(directoryPath);
    if (!directory.exists()) {
        if (!directory.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return;
        }
    }
    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outStream(&outFile);
        outStream << "Course ID,Course Name,Class Name,Teacher Name,Number Of Credits,Maximum Number Of Students,Day Of Week,Session,School Year,Semester\n";
        while (syCurr) {
            for (int i = 0; i < 3; i++) {
                if (syCurr->data.semesters[i].isCreated) {
                    Node<Course>* couCurr = syCurr->data.semesters[i].Courses;
                    while (couCurr) {
                        outStream << QString::fromStdString(couCurr->data.ID) << ","
                                  << QString::fromStdString(couCurr->data.Name) << ","
                                  << QString::fromStdString(couCurr->data.className) << ","
                                  << QString::fromStdString(couCurr->data.teacherName) << ","
                                  << QString::number(couCurr->data.nCredits) << ","
                                  << QString::number(couCurr->data.maxStudents) << ","
                                  << QString::fromStdString(couCurr->data.dayOfWeek) << ","
                                  << QString::fromStdString(couCurr->data.session) << ","
                                  << QString::fromStdString(syCurr->data.year) << "," // couSY
                                  << i + 1 << "\n"; // couSem
                        couCurr = couCurr->next;
                    }
                }
            }
            syCurr = syCurr->next;
        }
    } else {
        qDebug() << "Couldn't open AllCourses.csv to save Data.";
    }
    outFile.close();
}

void saveScoreboardOfACourse(Node<Course>* couCurr) {
    QString directoryPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/List of Courses";
    QString filePath = directoryPath + "/" + QString::fromStdString(couCurr->data.ID) + "_" + QString::fromStdString(couCurr->data.className) + ".csv";

    // Check if the directory exists, create it if necessary
    QDir directory(directoryPath);
    if (!directory.exists()) {
        if (!directory.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return;
        }
    }
    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outStream(&outFile);
        outStream << "Student ID,Student Name,Midterm Mark,Final Mark,Other Mark,Total Mark\n";
        StudentScore* scoreArr = couCurr->data.score;
        for (int i = 0; i < couCurr->data.courseSize; i++) {
            outStream << QString::fromStdString(scoreArr[i].studentID) << ","
                      << QString::fromStdString(scoreArr[i].studentName) << ",";
            if (scoreArr[i].midTerm > 0)
                outStream << QString::number(scoreArr[i].midTerm);
            outStream << ",";
            if (scoreArr[i].final > 0)
                outStream << QString::number(scoreArr[i].final);
            outStream << ",";
            if (scoreArr[i].other > 0)
                outStream << QString::number(scoreArr[i].other);
            outStream << ",";
            if (scoreArr[i].total > 0)
                outStream << QString::number(scoreArr[i].total);
            outStream << "\n";
        }
    } else {
        qDebug() << "Couldn't open " << filePath << " to save Data.";
    }
    outFile.close();
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
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/AllSchoolYears.csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/AllSchoolYears.csv";
    QFile file(path);
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
    QString directoryPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System";
    QString filePath = directoryPath + "/AllSchoolYears.csv";

    // Check if the directory exists, create it if necessary
    QDir directory(directoryPath);
    if (!directory.exists()) {
        if (!directory.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return;
        }
    }
    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outStream(&outFile);
        outStream << "School Year\n";
        while (syCurr) {
            outStream << QString::fromStdString(syCurr->data.year) << "\n";
            syCurr = syCurr->next;
        }
    } else {
        qDebug() << "Failed to open file:" << outFile.errorString();
    }
    outFile.close();
}

void deleteAllSchoolYearsData() {
    while (latestSYear) {
        Node<SchoolYear>* temp = latestSYear;
        latestSYear = latestSYear->next;
        delete temp;
    }
}

void importAllSemestersCSV() {
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/AllSemesters.csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/AllSemesters.csv";
    QFile file(path);
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
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/AllStudents.csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/AllStudents.csv";
    QFile file(path);
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
    QString directoryPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System";
    QString filePath = directoryPath + "/AllStudents.csv";

    // Check if the directory exists, create it if necessary
    QDir directory(directoryPath);
    if (!directory.exists()) {
        if (!directory.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return;
        }
    }
    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outStream(&outFile);
        outStream << "Student ID,Student Name,Gender,Birthday,Social ID,Main Class,Password\n";
        while (syCurr) {
            Node<Class>* claCurr = syCurr->data.classes;
            while (claCurr) {
                Node<Student>* stuCurr = claCurr->data.students;
                while (stuCurr) {
                    outStream << QString::fromStdString(stuCurr->data.ID) << ","
                              << QString::fromStdString(stuCurr->data.name) << ","
                              << QString::fromStdString(stuCurr->data.gender) << ","
                              << QString::fromStdString(stuCurr->data.birthday) << ","
                              << QString::fromStdString(stuCurr->data.socialID) << ","
                              << QString::fromStdString(stuCurr->data.mainClass) << ","
                              << QString::fromStdString(stuCurr->data.password) << "\n";
                    stuCurr = stuCurr->next;
                }
                claCurr = claCurr->next;
            }
            syCurr = syCurr->next;
        }
    } else {
        qDebug() << "Couldn't open AllStudents.csv to save Data.";
    }
    outFile.close();
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
