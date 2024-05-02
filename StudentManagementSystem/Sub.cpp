#include"Sub.h"

void importData() {
    importAllSchoolYearsCSV();
    importAllClassesCSV();
    importAllStudentsCSV();
    importAllSemestersCSV();
    importAllCoursesCSV();
    importAllStudentsInAllCoursesCSV();
    importAllStaffsCSV();

    findCurrSem();
}

void saveData() {
    saveAllSchoolYearsData();
    saveAllClassesData();
    saveAllStudentsData();
    saveAllSemestersData();
    saveAllCoursesData();
    saveAllScoreboardsData();
    saveAllStaffsData();
}

void deleteData() {
    deleteAllStudentsData();
    deleteAllClassesData();
    deleteAllScoreboardsData();
    deleteAllCourseData();
    deleteAllStaffData();
}

void getChoiceInt(int startChoiceNum, int endChoiceNum, std::string prompt, int& choice)
{
    std::cout << prompt;
    choice = startChoiceNum - 1; // Initialize choice to an invalid value
    while (!(std::cin >> choice) || choice < startChoiceNum || choice > endChoiceNum) {
        std::cout << "\t(X) Invalid input. Please try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

bool isValidClassName(const std::string& className, const std::string& currentYear) {
    // if (className.size() < 6 || className.size() > 8) { // 23VP01 have 6 characters, 23CLC03 have 7 characters, 23APCS1 have 7 characters
    //     return false;
    // }
    if (className.size() < 6 || className.size() > 8) { // 23VP01 have 6 characters, 23CLC03 have 7 characters, 23APCS01 have 8 characters
        return false;
    }
    if (className.substr(0, 2) != currentYear.substr(2, 2)) { // 23VP01 must match with 2023-2024
        return false;
    }
    if (!isdigit(className[className.size() - 1])) { // check last character is digit or not
        return false;
    }
    int numUpper = 0;
    if (isupper(className[2])) {
        numUpper++;
    }
    else {
        return false;
    }
    bool isPrevUpper = false;
    for (int i = 2; i < className.size() - 2; ++i) {
        if (isupper(className[i])) {
            if (isPrevUpper) {
                numUpper++;
            }
            isPrevUpper = true;
        }
        else {
            isPrevUpper = false;
        }
    }
    // if (numUpper == 3 && className.size() == 7 && isupper(className[className.size() - 2])) {
    //     return true;
    // } // if class is 23APCS1
    if (numUpper == 4 && className.size() == 8 && isdigit(className[className.size() - 2])) {
        return true;
    } // if class is 23APCS01
    if (numUpper == 3 && className.size() == 7 && isdigit(className[className.size() - 2])) {
        return true;
    }
    if (numUpper == 2 && className.size() == 6 && isdigit(className[className.size() - 2])) {
        return true;
    }
    return false;
}

bool isValidClassName_smaller(const std::string& className, const std::string& currentYear) {
    // if (className.size() < 6 || className.size() > 8) { // 23VP01 have 6 characters, 23CLC03 have 7 characters, 23APCS1 have 7 characters
    //     return false;
    // }
    if (className.size() < 6 || className.size() > 8) { // 23VP01 have 6 characters, 23CLC03 have 7 characters, 23APCS01 have 8 characters
        return false;
    }
    if (className.substr(0, 2) > currentYear.substr(2, 2)) { // 23VP01 must match with 2023-2024
        return false;
    }
    if (!isdigit(className[className.size() - 1])) { // check last character is digit or not
        return false;
    }
    int numUpper = 0;
    if (isupper(className[2])) {
        numUpper++;
    }
    else {
        return false;
    }
    bool isPrevUpper = false;
    for (int i = 2; i < className.size() - 2; ++i) {
        if (isupper(className[i])) {
            if (isPrevUpper) {
                numUpper++;
            }
            isPrevUpper = true;
        }
        else {
            isPrevUpper = false;
        }
    }
    // if (numUpper == 3 && className.size() == 7 && isupper(className[className.size() - 2])) {
    //     return true;
    // } // if class is 23APCS1
    if (numUpper == 4 && className.size() == 8 && isdigit(className[className.size() - 2])) {
        return true;
    } // if class is 23APCS01
    if (numUpper == 3 && className.size() == 7 && isdigit(className[className.size() - 2])) {
        return true;
    }
    if (numUpper == 2 && className.size() == 6 && isdigit(className[className.size() - 2])) {
        return true;
    }
    return false;
}

bool isValidCouOrStuName(const std::string& name) {
    // Regular expression to match valid names
    std::regex pattern("^[A-Za-z]+(?:[ ][A-Za-z]+)*$");

    // Check if the name matches the pattern
    return std::regex_match(name, pattern);
}

bool isValidCourseID(const std::string& courseID) {
    for (char c : courseID) {
        if (c == ' ' || islower(c)) {
            return false; // Space found, invalid ID
        }
    }
    return true; // No space found, valid ID
}

bool isValidStudentID(std::string id) {
    if (id.size() != 8) {
        return false;
    }
    for (char c : id) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

bool notExistclassNameOfCourse(const std::string& courseID, const std::string& className, const std::string& currentYear) {
    // std::string year = getSYofCourse(courseID, className)->year;
    // if (year != currentYear) return 0;
    // Node<Course>* couCurr = currSem.Courses;
    // while (couCurr) {
    //     if (couCurr->data.ID == courseID && couCurr->data.className == className) {
    //         return false;
    //     }
    //     couCurr = couCurr->next;
    // }
    // return true;

    Course* tempCou = getCourse(courseID, className);
    if (tempCou == nullptr) return 1;
    return 0;
}

void formalize(std::string& name)
{
    std::string formalizedName;
    bool lastWasSpace = true;
    bool firstChar = true;
    for (char c : name) {
        if (std::isspace(c)) {
            if (!lastWasSpace) {
                formalizedName += ' ';
                lastWasSpace = true;
            }
        }
        else {
            if (lastWasSpace || firstChar) {
                c = toupper(c);
                firstChar = false;
            }
            else {
                c = tolower(c);
            }

            formalizedName += c;
            lastWasSpace = false;
        }
    }
    name = formalizedName;
    if (*(name.end() - 1) == ' ') name.pop_back();
}

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

int getUser(std::string userID, std::string userPassword) {
    int userType = -1;

    Node<Staff>* staffCurr = listStaff;
    while (staffCurr) {
        if (staffCurr->data.ID == userID && staffCurr->data.password == userPassword) {
            currStaff = staffCurr;
            userType = 1;
            break;
        }
        staffCurr = staffCurr->next;
    }

    if (userType == -1) {
        Node<SchoolYear>* syCurr = latestSYear;
        while (syCurr) {
            Node<Class>* classCurr = syCurr->data.classes;
            while (classCurr) {
                Node<Student>* studentCurr = classCurr->data.students;
                while (studentCurr) {
                    if (studentCurr->data.ID == userID && studentCurr->data.password == userPassword) {
                        currStudent = studentCurr;
                        userType = 2;
                        break;
                    }
                    studentCurr = studentCurr->next;
                }
                if (userType == 2)
                    break;
                classCurr = classCurr->next;
            }
            if (userType == 2)
                break;
            syCurr = syCurr->next;
        }
    }

    return userType;
}

void findCurrSem() {
    Node<SchoolYear>* syCurr = latestSYear;
    if (!latestSYear->data.semesters[0].isCreated && !latestSYear->data.semesters[1].isCreated && !latestSYear->data.semesters[2].isCreated) {
        lastSemNumber = currSemNumber = 0;
        // return;
    }
    bool found = false;
    while (syCurr && !found) {
        for (int i = 2; i >= 0; i--) {
            if (syCurr->data.semesters[i].isCreated) {
                found = true;
                latestSem = currSem = syCurr->data.semesters[i];
                if (lastSemNumber == 0) {
                    break;
                }
                lastSemNumber = currSemNumber = i + 1;
                break;
            }
        }
        syCurr = syCurr->next;
    }
}

bool isClassExisted(std::string className) {
    Node<SchoolYear>* syCurr = currSYear;
    Node<Class>* claCurr = syCurr->data.classes;
    bool isExisted = false;
    while (claCurr) {
        if (claCurr->data.className == className) {
            isExisted = true;
            break;
        }
        claCurr = claCurr->next;
    }
    return isExisted;
}

bool ends_with(const std::string& str, const std::string& suffix) {
    if (str.size() < suffix.size()) return false;
    return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}

std::string getNextSchoolYear(const std::string& currentYear) {
    std::istringstream ssStart(currentYear.substr(0, 4));
    int startYear;
    ssStart >> startYear;

    std::istringstream ssEnd(currentYear.substr(5, 4));
    int endYear;
    ssEnd >> endYear;

    return std::to_string(startYear + 1) + "-" + std::to_string(endYear + 1);
}

void menuCommandHeader() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
}

bool isValidDateFormat(const std::string& date) {
    if (date.size() != 10) // Check if the string has the correct length
        return false;

    for (int i = 0; i < 10; ++i) {
        if (i == 2 || i == 5) {
            if (date[i] != '/') // Check if slashes are at the correct positions
                return false;
        }
        else {
            if (!std::isdigit(date[i])) { // Check if other characters are digits
                std::cout << "\t(X) Invalid character in date: " << date[i] << std::endl;
                return false;
            }
        }
    }

    return true;
}

int dateToInt(std::string date) {
    // if (!isValidDateFormat(date)) {
    //     throw std::invalid_argument("Invalid date format");
    // }

    std::istringstream ss(date.substr(6, 4));
    int Y;
    ss >> Y;

    ss.clear();
    ss.str(date.substr(3, 2));
    int M;
    ss >> M;

    ss.clear();
    ss.str(date.substr(0, 2));
    int D;
    ss >> D;

    int dateRes = 0;
    for (int y = 1971; y < Y; ++y) dateRes += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < M; ++m) dateRes += daysInMonth(m, Y);
    return dateRes + D;
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int daysBetweenDates(const std::string& date1, const std::string& date2) {
    return -(dateToInt(date2) - dateToInt(date1));
}

char getYesNo(std::string prompt) {
    char confirm;
    std::cout << prompt;
    while (!(std::cin >> confirm) || (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n')) {
        std::cout << "\t(X) Invalid input. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return confirm;
}
bool checkMatchStudentIDAndName(std::string studentID, std::string studentName) {
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr) {
            Node<Student>* stuCurr = claCurr->data.students;
            while (stuCurr) {
                if (stuCurr->data.ID == studentID) {
                    if (stuCurr->data.name == studentName) {
                        return true;
                    }
                    else {
                        std::cout << "\t(X) Student ID " << studentID << " must match with student name " << stuCurr->data.name << ".\n";
                        return false;
                    }
                }
                stuCurr = stuCurr->next;
            }
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
    return false;
}

void copyResourceFileToWritableLocation(const QString& resourceFilePath, const QString& destinationFilePath) {
    QFile resourceFile(resourceFilePath);
    if (!resourceFile.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open resource file:" << resourceFile.errorString();
        return;
    }

    QFile destinationFile(destinationFilePath);
    if (!destinationFile.open(QIODevice::WriteOnly)) {
        qDebug() << "Failed to open destination file:" << destinationFile.errorString();
        return;
    }

    destinationFile.write(resourceFile.readAll());

    resourceFile.close();
    destinationFile.close();
}
