#include"System.h"

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

void formalize(std::string& name)
{
    std::string formalizedName;
    bool lastWasSpace = true;
    for (char c : name)
    {
        if (std::isspace(c))
        {
            if (!lastWasSpace)
            {
                formalizedName += ' ';
                lastWasSpace = true;
            }
        }
        else
        {
            if (lastWasSpace) c = toupper(c);
            else c = tolower(c);

            formalizedName += c;
            lastWasSpace = false;
        }
    }
    name = formalizedName;
    if (*(name.end() - 1) == ' ') name.pop_back();
}

bool checkNameValid(std::string name)
{
    for (char c : name)
    {
        if (!std::isalpha(c) && !isspace(c))
        {
            std::cerr << "Please input properly name with no special characters or digits\n";
            return false;
        }
    }
    return true;
}

bool checkIDValid(std::string id)
{
    for (char c : id)
    {
        if (!isdigit(c))
        {
            std::cerr << "Please input properly id with no characters other than digits\n";
            return false;
        }
    }
    return true;
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

void startPage()
{
    system("cls");
    std::cout << "[1] Sign In.\n[-1] Exit.\n\nInput your command: ";
    int cmd;
    std::cin >> cmd;

    if (cmd == 1)
    {
        signInPage();
    }
    else if (cmd == -1)
    {
        std::cout << "Exiting..." << std::endl;
        saveData();
        deleteData();
        sleep(1);
        system("cls");
        exit(0);
    }
    else
    {
        std::cout << "\nInvalid input!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        system("pause");
        startPage();
    }
}

void signInPage() {
    system("cls");
    // 1: User is Staff
    // 2: User is Student
    int userType = -1;
    std::cout << "[1] Sign in" << std::endl;
    std::string userID;
    std::cout << "Username: ";
    std::cin >> userID;

    std::string userPassword;
    std::cout << "Password: ";
    std::cin >> userPassword;

    userType = getUser(userID, userPassword);
    std::cout << std::endl;
    if (userType == -1) {
        std::cout << "(!) Username or Password is incorrect. Please try again." << std::endl;
        system("pause");
        startPage(); //signInpage();
    }
    std::cout << "(!) Log in successfully." << std::endl;
    system("pause");
    if (userType == 1) {
        staffHomePage();
    }
    else if (userType == 2) {
        studentHomePage();
    }
}

void studentHomePage() {
    while (true) {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "\t1. View your profile\n"
                  << "\t2. View your courses in current semester\n"
                  << "\t3. View scoreboard\n"
                  << "\t4. Change Password\n"
                  << "\t-1.Exit\n\n";
        int choice;
        std::cout << "Enter your command (1/2/3/4/-1): ";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer (1/2/3/4/-1)." << std::endl;
            system("pause");
            continue;
        }
        else {
            if (choice == 1)
            {
                viewStudentProfile();
            }
            else if (choice == 2)
            {
                viewStudentCourses();
            }
            else if (choice == 3)
            {
                viewStudentScoresInCurrentSem();
            }
            else if (choice == 4)
            {
                changeStudentPassword();
            }
            else if (choice == -1)
            {
                std::cout << "Exiting..." << std::endl;
                sleep(1);
                startPage();
                return;
            }
        }
    }
}

void staffHomePage() {
    while (true) {
        system("cls");
        std::cout << "Menu:" << std::endl;
        std::cout << "\t1. View Profile\n"
                  << "\t2. Command Menu\n"
                  << "\t3. Change Password\n"
                  << "\t-1.Exit\n\n";
        int choice;
        std::cout << "Enter your command (1/2/3/-1): ";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != -1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer (1/2/3/-1)." << std::endl;
            system("pause");
            continue;
        }
        else {
            if (choice == 1)
            {
                viewStaffProfile();
            }
            else if (choice == 2)
            {
                staffCommandMenu();
            }
            else if (choice == 3)
            {
                changeStaffPassword();
            }
            else if (choice == -1)
            {
                std::cout << "Exiting..." << std::endl;
                sleep(1);
                startPage();
                return;
            }
        }
    }
}

void staffCommandMenu() {
    while (true) {
        system("cls");
        std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
        std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
        std::cout << "Menu:\n";
        std::cout << "\t1.Create a newest School Year\n";
        std::cout << "\t2.Create a newest Semester\n";
        std::cout << "\t3.Change current Semester - School Year\n";
        std::cout << "\t4.Class Management\n";
        std::cout << "\t5.Course Management\n";
        std::cout << "\t6.Back\n";
        int choice;
        std::cout << "Enter your command (1/2/3/4/5/6): ";
        std::cin >> choice;

        if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer (1/2/3/4/5/6)." << std::endl;
            system("pause");
            continue;
        }
        else {
            if (choice == 1)
            {
                createANewSchoolYear();
            }
            else if (choice == 2)
            {
                createANewSemester();
            }
            else if (choice == 3)
            {
                changeCurrentSemesterSchoolYear();
            }
            else if (choice == 4)
            {
                classManagementPage();
            }
            else if (choice == 5)
            {
                courseManagementPage();
            }
            else if (choice == 6)
            {
                staffHomePage();
                return;
            }
        }
    }
}

void classManagementPage() {
    while (true) {
        system("cls");
        std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
        std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
        if (currSemNumber != 0) {
            std::cout << "Menu command of Class Management:\n";
            std::cout << "\t1.Create a new class (in current school year)\n";
            std::cout << "\t2.Import CSV containing all students in a class (in current semester)\n";
            std::cout << "\t3.View list of students in a class (in current school year)\n";
            std::cout << "\t4.View scoreboard of a class (in current school year)\n";
            std::cout << "\t5.View list of classes (in current school year)\n";
            std::cout << "\t6.View list of classes in system\n";
            std::cout << "\t7.Back\n";
            int choice;
            std::cout << "Enter your command (1/2/3/4/5/6/7): ";
            std::cin >> choice;

            if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer (1/2/3/4/5/6/7)." << std::endl;
                system("pause");
                continue;
            }
            else {
                if (choice == 1)
                {
                    createANewClassInCurrentSYear();
                }
                else if (choice == 2)
                {
                    importCSVStudentsOfAClass_Public();
                }
                else if (choice == 3)
                {
                    viewListOfStudentsInAClass();
                }
                else if (choice == 4)
                {
                    // TODO:
                    // 4.View scoreboard of a class
                }
                else if (choice == 5)
                {
                    viewListOfClassesInCurrentSemeter();
                }
                else if (choice == 6)
                {
                    viewListOfClassesInSystem();
                }
                else if (choice == 7)
                {
                    staffCommandMenu();
                    return;
                }
            }
        }
        else
        {
            std::cout << "There are no semesters in the current school year, let's create a new semester so you can use the commands" << std::endl;
            system("pause");
            staffCommandMenu();
            return;
        }
    }
}

void courseManagementPage() {
    while (true) {
        system("cls");
        std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
        std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
        if (currSemNumber != 0) {
            std::cout << "Menu command of Course Management:\n";
            std::cout << "\t1.Add a course to current semester\n";
            std::cout << "\t2.Update information of a course (Don't Use, need to fix more)\n";
            std::cout << "\t3.Delete a course in current semester\n";
            std::cout << "\t4.Add a student to a course\n";
            std::cout << "\t5.Remove a student from a course\n";
            std::cout << "\t6.Upload a CSV file containing a list of students enrolled in a course\n";
            std::cout << "\t7.Export a list of students in a course to a CSV file\n";
            std::cout << "\t8.View list of courses (in current semester)\n";
            std::cout << "\t9.View list of students in a course (in current semester)\n";
            std::cout << "\t10.View scoreboard of a course\n";
            std::cout << "\t11.Update a student's result of a course\n";
            std::cout << "\t12.Back\n";
            int choice;
            std::cout << "Enter your command (1/2/3/4/5/6/7/8/9/10/11/12): ";
            std::cin >> choice;

            if (std::cin.fail() || (choice < 1 || choice > 12)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer between 1 and 12." << std::endl;
                system("pause");
                continue;
            }
            else {
                if (choice == 1)
                {
                    addACourseInCurrSem();
                }
                else if (choice == 2)
                {
                    // updateInformationOfACoursePage();
                }
                else if (choice == 3)
                {
                    deleteACourseInCurrSem();
                }
                else if (choice == 4)
                {
                    addStudentToACourse();
                }
                else if (choice == 5)
                {
                    // Remove a student from a course
                }
                else if (choice == 6)
                {
                    // Upload a CSV file containing a list of students enrolled in a course
                }
                else if (choice == 7)
                {
                    exportCSVStudentsOfACourse();
                }
                else if (choice == 8)
                {
                    viewListOfCoursesInCurrSem();
                }
                else if (choice == 9)
                {
                    // View list Student in a course
                }
                else if (choice == 10)
                {
                    viewScoreboardOfACourse();
                }
                else if (choice == 11) {
                    // Update a student's result of a course
                }
                else if (choice == 12)
                {
                    staffCommandMenu();
                    return;
                }
            }
        }
        else {
            std::cout << "There are no semesters in the current school year. Let's create a new semester so you can use the commands." << std::endl;
            system("pause");
            staffCommandMenu();
            return;
        }
    }
}
