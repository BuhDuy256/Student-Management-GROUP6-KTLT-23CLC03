#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>

template<class T>
struct Node
{
    T data;
    Node<T>* next;
    Node(T dataValue) : data(dataValue), next(nullptr) {}
    Node(T dataValue, Node<T>* nextNode) : data(dataValue), next(nextNode) {}
};
struct StudentScore
{
    std::string studentID;
    std::string studentName;
    double midTerm = -1;
    double final = -1;
    double other = -1;
    double total = -1;
};
struct Course
{
    std::string ID;
    std::string Name;
    std::string className;
    std::string teacherName;
    int courseSize = 50;
    std::string dayOfWeek;
    std::string session;
    StudentScore* score = new StudentScore[0];
    void updateInformation();
    void addStudent(std::string ID, std::string studentName);
    void updateStudentResult();
    void viewStudentsList();
    bool deleteStudent(int index);
    void viewScoreboard();
};
struct Student {
    std::string ID;
    std::string name;
    std::string gender;
    std::string birthday;
    std::string socialID;
    std::string mainClass;
    std::string password = "12345678";
};
struct Class {
    std::string className;
    std::string schoolYear;
    Node<Student>* students = nullptr; //
};
struct Semester {
    unsigned short number = 0;
    std::string startDate;
    std::string endDate;
    Node<Course>* Courses = nullptr;
    bool isCreated = false;
};
struct SchoolYear {
    std::string year;
    Semester semesters[3];
    Node<Class>* classes = nullptr;
};
struct Staff {
    std::string ID;
    std::string name;
    std::string gender;
    std::string birthday;
    std::string socialID;
    std::string password = "123445678";
};
std::string myID;
Semester currSem;
Node<SchoolYear>* currYear = nullptr;
Node<SchoolYear>* chosenYear = nullptr;
Node<Staff>* currStaff = nullptr;
Node<Course>* currCourse = nullptr;
bool getChoice(int numberofChoices, std::string prompt, int& choice);
Node<Student>* getStudent(std::string myID);
void viewAllClassesInASchoolYear(); //chosenyear (checkvalid)
void viewAllClassesInSchool(); //latestyear
void viewAllStudentsInAClass(); //while...toinput
void viewCourses(std::string myID);
void viewProfile(std::string myID);
void viewScores(std::string myID);
void displayStudentHomePage();
void saveAllClassesData();
void saveAllCoursesData();
void saveAllSchoolYearsData();
void saveAllScoreboardsData();
void saveAllSemestersData();
void saveAllStudentsData();
void saveScoreboardOfACourse();
void importAllClassesCSV();
void importAllCoursesCSV();
void importAllSchoolYearsCSV();
void importAllSemestersCSV();
void importAllStudentsCSV();
void importAllStudentsInAllCoursesCSV();
void importContainingStudentsEnrolledInCourse(Node<Course>* currCourse);
void deleteAllClassesData();
void deleteAllCourseData();
void deleteAllSchoolYearsData();
void deleteAllScoreboardsData();
void deleteAllStudentsData();
void deleteDuplicateTempCourses(Node<std::string>* TempCourses);
void reverseSchoolYearsList(Node<SchoolYear>*& syHead);
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass);
Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check);
bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind);
int countUniqueTempCourses2(Node<std::string>* TempCourses, bool* check);
int countUniqueTempCourses(Node<std::string>* TempCourses);
Node<Class>* ChooseClass(std::string choice);
void createANewClass(); //latestyear
void createASchoolYear(); //needchange,automatically_add,currSem = semesters[0] new year
void signIn();
void displaySignInPage();
void changePasswordStudent();
std::string shorterCourseName(std::string CourseName);
void viewScoreBoardOfAClass(); //i = 4,printboard
void printHorizontalLine(int totalWidth);
void displayStaffHomePage();
void SpecialStaffHomePage();
void CourseManagementPage();
void ClassManagementPage();
void deleteAllStaffData();
void saveAllStaffsData();
void importAllStaffsCSV();
Node<Staff>* getStaff(std::string ID);
void changePasswordStaff();
void chooseYear(); //checkvalid
void chooseSem(); //checkvalid
void chooseCourse(); //checkvalid
void displayAllSchoolYears();
void addSemester();
int main()
{
    importAllSchoolYearsCSV();
    importAllClassesCSV();
    importAllStudentsCSV();
    importAllSemestersCSV();
    importAllCoursesCSV();
    importAllStudentsInAllCoursesCSV();
    importAllStaffsCSV();
    currSem = currYear->data.semesters[0];
    displaySignInPage();
    return 0;
}
void addSemester(){

}
void chooseYear(){
    displayAllSchoolYears();
    int index;
    std::cout << "ENTER NUMBER (1 - N): ";
    std::cin >> index; //checkvalid
    Node<SchoolYear>* choose = currYear;
    while (choose && index > 1)
    {
        choose = choose->next;
        index--;
    }
    chosenYear = choose;
}
void chooseSem() {
    int index;
    std::cout << "ENTER SEMESTER NUMBER (1 - 3): ";
    std::cin >> index; //checkvalid
    currSem = chosenYear->data.semesters[index - 1];
}
void chooseCourse() {
    //displayallcoursesinasem
    int index;
    std::cout << "ENTER NUMBER (1 - N): ";
    std::cin >> index; //checkvalid
    Node<Course>* tempcourse = currSem.Courses;
    while (tempcourse != nullptr && index > 1)
    {
        tempcourse = tempcourse->next;
        index--;
    }
    currCourse = tempcourse;
}
void changePasswordStaff(){
    Node<Staff>* currStaff2 = getStaff(myID);
    if (currStaff2 == nullptr) return;
    std::string myPassword = currStaff2->data.password;

    system("cls");

    std::string curPass, newPass, confirmPass;

    std::cout << "Current Password: ";
    std::cin >> curPass;
    if (curPass != myPassword)
    {
        std::cout << "\nWrong Password!!!";
        system("pause");
        system("cls");
        changePasswordStaff();
        return;
    }

    std::cout << "New Password: ";
    std::cin >> newPass;
    std::cout << "Confirm New Password: ";
    std::cin >> confirmPass;
    if (newPass != confirmPass)
    {
        std::cout << "\nNot Match!!!";
        system("pause");
        system("cls");
        changePasswordStaff();
        return;
    }

    currStaff2->data.password = newPass;

    std::cout << "Your Password Has Been Changed!!!";
    system("pause");
    system("cls");
    displayStaffHomePage();
}
Node<Staff>* getStaff(std::string ID) {
    Node<Staff>* StaffCurr = currStaff;
    while (StaffCurr != nullptr)
    {
        if (StaffCurr->data.ID == ID) return StaffCurr;
        StaffCurr = StaffCurr->next;
    }
    return nullptr;
}
void CourseManagementPage() {
    std::cout << "1.Add a course to current semester\n";
    std::cout << "2.Upload a file CSV file containing a list of students enrolled in course\n";
    std::cout << "3.Update course information\n";
    std::cout << "4.Add a Student to the Course\n";
    std::cout << "5.Remove a student from the course\n";
    std::cout << "6.Delete a course\n";
    std::cout << "7.Export a list of students in a course to a CSV file\n";
    std::cout << "8.View scoreboard of a course\n";
    std::cout << "9.Update a student’s result of a course\n";
    std::cout << "10.Back\n";
    std::string choice;
    std::cin >> choice;
    if (choice == "1")
    {
        //addcourse
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "2")
    {
        //uploadCSVfile
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "3")
    {
        //showlistofcourse,makechoice
        //Course.updateinformation
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "4")
    {
        //showlistofstu,makechoice
        //Course.addStudent
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "5")
    {
        //showlistofstu,makechoice
        //Course.removestudent
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "6")
    {
        //showlistofcourses,makechoice
        //Sem.delete
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "7")
    {
        //export,choosefolder...
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "8")
    {
        //showlistofcourse,makechoice
        //Course.scoreboard
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "9")
    {
        //showlistofcourse->showlistofstu->makechoice
        //Course.updateresult
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else if (choice == "10")
    {
        system("pause");
        system("cls");
        CourseManagementPage();
    }
    else
    {

    }
}
void ClassManagementPage() {

}
void displayStaffHomePage() {
    std::string choice;
    std::cout << "1.View Profile\n"
        << "2.View list of classes\n"
        << "3.View list of courses\n"
        << "4.View list of students in a class\n"
        << "5.View list of students in a course\n"
        << "6.Choose School Year and Semester to execute command\n"
        << "7.Change Password\n"
        << "8.Back\n";
    std::cin >> choice;
    if (choice == "1")
    {
        viewProfile(myID);
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "2")
    {
        viewAllClassesInSchool();
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "3")
    {

        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "4")
    {
        viewAllStudentsInAClass();
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "5")
    {

        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "6")
    {
        SpecialStaffHomePage();
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "7")
    {
        changePasswordStaff();
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else if (choice == "8")
    {
        system("pause");
        system("cls");
        displaySignInPage();
    }
    else
    {
        std::cout << "Invalid choice!\n";
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
}
void SpecialStaffHomePage() {
    std::cout << "Latest Semester – School Year: " << currYear->data.year << "\n";
    std::cout << "Current School Year in System: " << chosenYear->data.year << "\n";
    std::cout << "Current Semester in System: " << currSem.number << "\n";
    std::cout << "1.Create a newest School Year\n";
    std::cout << "2.Change School Year\n";
    std::cout << "3.Create a newest Semester\n";
    std::cout << "4.Change Semester\n";
    std::cout << "5.Classes Management\n";
    std::cout << "6.Courses Management\n";
    std::cout << "7.Back\n";
    std::string choice;
    std::cout << "ENTER YOUR CHOICE: ";
    std::cin >> choice;
    if (choice == "1")
    {
        createASchoolYear();
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "2")
    {
        //chooseyearfunction
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "3")
    {
        //createSem
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "4")
    {
        //choosemfunction
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "5")
    {
        //Classmanagementpage
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "6")
    {
        //coursemanagementpage
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "7")
    {
        //changepass
        system("pause");
        system("cls");
        SpecialStaffHomePage();
    }
    else if (choice == "8")
    {
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else
    {
        std::cout << "Invalid choice!\n";
        //choiceagain
    }
}
void printHorizontalLine(int totalWidth) {
    std::cout << std::setfill('-') << std::setw(totalWidth) << "\n";
}
void importAllStaffsCSV() {
    std::ifstream inF("../CSV Files/AllStaffs.csv");
    if (!inF.is_open()) {
        std::cout << "Couldn't import AllStaffs.csv!";
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
        Staff newStaff;
        std::getline(ss, newStaff.ID, ',');
        std::getline(ss, newStaff.name, ',');
        std::getline(ss, newStaff.gender, ',');
        std::getline(ss, newStaff.birthday, ',');
        std::getline(ss, newStaff.socialID, ',');
        std::getline(ss, newStaff.password, ',');

        Node<Staff>* staTemp = new Node<Staff>(newStaff);
        if (!currStaff) {
            currStaff = staTemp;
        }
        else {
            Node<Staff>* temp = currStaff;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = staTemp;
        }
    }
    inF.close();
}

void saveAllStaffsData() {
    Node<Staff>* staCurr = currStaff;
    std::ofstream outF("../CSV Files/AllStaffs.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Staff ID,Staff Name,Gender,Birthday,Social ID,Passowrd\n";
        while (staCurr) {
            outF << staCurr->data.ID << ","
                << staCurr->data.name << ","
                << staCurr->data.gender << ","
                << staCurr->data.birthday << ","
                << staCurr->data.socialID << ","
                << staCurr->data.password << "\n";
            staCurr = staCurr->next;
        }
    }
    else {
        std::cout << "Couldn't open AllStaffs.csv to save Data" << std::endl;
    }
    outF.close();
}
void deleteAllStaffData() {
    Node<Staff>* staCurr = currStaff;
    while (staCurr) {
        Node<Staff>* staTemp = staCurr;
        staCurr = staCurr->next;
        delete staTemp;
    }
    currStaff = nullptr;
}
void viewScoreBoardOfAClass() {
    viewAllClassesInSchool();
    std::string choice;
    std::cout << "ENTER ClASS: ";
    std::cin >> choice;

    Node<Class>* ChosenClass = ChooseClass(choice);
    if (ChosenClass == nullptr)
    {
        std::cout << "Invalid class!\n";
        //systemclear
        //displaymenu
    }
    Node<std::string>* TempCourses = nullptr;
    Node<Course>* SemCourse = currSem.Courses;
    while (SemCourse != nullptr)
    {
        std::string addTempCourse = SemCourse->data.Name;
        Node<std::string>* newTempCourse = new Node<std::string>(addTempCourse, TempCourses);
        TempCourses = newTempCourse;
        SemCourse = SemCourse->next;
    }
    deleteDuplicateTempCourses(TempCourses);
    int numofCourses = countUniqueTempCourses(TempCourses);
    bool* check = new bool[numofCourses];
    for (int i = 0; i < numofCourses; i++) check[i] = false;
    Node<Student>* tempStu = ChosenClass->data.students;
    while (tempStu != nullptr)
    {
        Node<Course>* tmp = currSem.Courses;
        while (tmp != nullptr)
        {
            int index = 0;
            if (!Exist(check, tmp, TempCourses, numofCourses, index))
            {
                int numofStu = tmp->data.courseSize;
                for (int i = 0; i < numofStu; i++)
                {
                    if (tempStu->data.ID == tmp->data.score[i].studentID)
                    {
                        check[index] = true;
                    }
                }
            }
            tmp = tmp->next;
        }
        tempStu = tempStu->next;
    }
    Node<std::string>* ClassCourses = ClassCourse(TempCourses, check);
    int NumofClassCourses = countUniqueTempCourses2(ClassCourses, check);
    const int totalWidth = 30 + 12 + NumofClassCourses * 12 + 12 + 2 * NumofClassCourses + 1;
    printHorizontalLine(totalWidth);
    std::cout << "|" << std::setfill(' ') << std::setw(30) << "STUDENT FULL NAME" << "|STUDENT ID|";

    // Print course names
    Node<std::string>* makeFirstRow = ClassCourses;
    while (makeFirstRow != nullptr) {
        std::cout << std::setw(12) << std::right << makeFirstRow->data.substr(0, 11) << "|";
        makeFirstRow = makeFirstRow->next;
    }

    std::cout << std::setw(11) << std::setfill(' ') << "GPA|" << std::setw(11) << "OVERALL GPA|" << "\n";
    printHorizontalLine(totalWidth);

    // Your existing loop here for iterating through students and their scores
    Node<Student>* StuScore = ChosenClass->data.students;
    while (StuScore != nullptr)
    {
        double numofactivecourses = 0, gpa = 0;
        std::cout << "|" << std::setfill(' ') << std::setw(30) << StuScore->data.name << std::setfill(' ') << "|" << StuScore->data.ID;
        Node<std::string>* tmp2 = ClassCourses;
        while (tmp2 != nullptr)
        {
            Node<Course>* check = currSem.Courses;
            while (check != nullptr)
            {
                bool score = false;
                if (tmp2->data == check->data.Name)
                {
                    int numofstudents = check->data.courseSize;
                    for (int i = 0; i < numofstudents; i++)
                    {
                        if (StuScore->data.ID == check->data.score[i].studentID)
                        {
                            gpa += check->data.score[i].total;
                            numofactivecourses++;
                            if (check->data.score[i].final != -1) std::cout << std::setw(12) << check->data.score[i].final << std::setfill(' ') << "|";
                            else std::cout << std::setw(12) << std::setfill(' ') << "|";
                            score = true;
                            break;
                        }
                    }
                }
                if (score) break;
                check = check->next;
            }
            if (check == nullptr) std::cout << std::setw(12) << std::setfill(' ') << "|";
            tmp2 = tmp2->next;
        }
        if (numofactivecourses == 0 || gpa == 0) std::cout << std::setw(4) << std::setfill(' ') << "|";
        else std::cout << std::setw(12) << std::right << gpa / numofactivecourses << "|";
        double prevtotal = 0, prevnumofacticour = 0;
        previous(prevtotal, prevnumofacticour, StuScore, ChosenClass);
        std::cout << std::setw(11) << std::right << (prevtotal + gpa) / (prevnumofacticour + numofactivecourses) << "|\n";
        printHorizontalLine(totalWidth);
        StuScore = StuScore->next;
    }
    //systemclear
    //displaymenu
}
std::string shorterCourseName(std::string CourseName) {
    if (CourseName.size() > 12) {
        int i = 0;
        while (CourseName[i] != ' ') i++;
        std::string temp = "";
        temp += CourseName[0];
        temp += ".";
        temp += CourseName.substr(i, CourseName.size());
        return temp;
    }
    else return CourseName;
}
void displaySignInPage()
{
    std::cout << "[1] Sign In.\n[-1] Exit.\n\nInput Your Command: ";
    std::string cmd;
    std::cin >> cmd;

    if (cmd == "1")
    {
        signIn();
        system("pause");
        return;
    }
    else if (cmd == "-1")
    {
        exit(0);
    }
    else
    {
        std::cout << "\nInvalid Input!!!" << "\n";
        system("pause");
        system("cls");
        displaySignInPage();
        return;
    }
}

void displayStudentHomePage()
{
    std::string choice;
    std::cout << "1.View your profile" << "\n"
        << "2.View your courses in current semester" << "\n"
        << "3.View scoreboard" << "\n"
        << "4.Change password" << "\n"
        << "5.Exit\n"
        << "ENTER CHOICE: ";
    std::cin >> choice;
    if (choice == "1")
    {
        viewProfile(myID);
        system("pause");
        system("cls");
        displayStudentHomePage();
    }
    else if (choice == "2")
    {
        viewCourses(myID);
        system("pause");
        system("cls");
        displayStudentHomePage();
    }
    else if (choice == "3")
    {
        viewScores(myID);
        system("pause");
        system("cls");
        displayStudentHomePage();
    }
    else if (choice == "4")
    {
        changePasswordStudent();
        system("pause");
        system("cls");
        displayStudentHomePage();
    }
    else if (choice == "5")
    {
        system("pause");
        system("cls");
        displaySignInPage();
    }
    else
    {
        std::cout << "Invalid choice!\n";
        system("pause");
        system("cls");
        displayStudentHomePage();
    }
}
void signIn()
{
    std::cout << "Username: ";
    std::cin >> myID;

    if (getStudent(myID) == nullptr && getStaff(myID) == nullptr)
    {
        std::cout << "\nUsername Not Found!!!" << "\n";
        signIn();
        return;
    }

    std::string Pass;
    std::string check = myID.substr(0, 5);
    if (check == "admin")
    {
        Node<Staff>* currStaff2 = getStaff(myID);
        currStaff2 = getStaff(myID);
        std::cout << "Password: ";
        std::cin >> Pass;
        if (Pass != currStaff2->data.password)
        {
            std::cout << "\nWrong Password!!!";
            signIn();
            return;
        }
        system("pause");
        system("cls");
        displayStaffHomePage();
    }
    else
    {
        Node<Student>* currStu = getStudent(myID);
        std::cout << "Password: ";
        std::cin >> Pass;
        if (Pass != currStu->data.password)
        {
            std::cout << "\nWrong Password!!!";
            signIn();
            return;
        }
        system("pause");
        system("cls");
        displayStudentHomePage();
    }


}
void displayAllSchoolYears()
    {
        if (currYear == nullptr)
        {
            std::cout << "NO SCHOOL YEAR" << "\n";
            return;
        }
        Node<SchoolYear>* temp = currYear;
        std::cout << std::setfill(' ') << std::setw(47) << "" << std::setw(22) << std::setfill('-');
        std::cout << "\n";
        int i = 1;
        while (temp != nullptr)
        {
            std::cout << std::setw(47) << std::setfill(' ');
            std::cout << " " << "|" << i << "|" << "     " << temp->data.year << std::setw(22 - 9 - temp->data.year.size()) << std::setfill(' ') << "|" << "\n";
            std::cout << std::setfill(' ') << std::setw(47) << "" << std::setw(22) << std::setfill('-');
            std::cout << "\n";
            temp = temp->next;
            i++;
        }
    }
    /*void displayAllSemesters()
    {
        cout << setfill(' ') << setw(47) << "" << setw(17) << setfill('-');
        cout << "\n";
        cout << setw(50) << setfill(' ');
        cout << "|1|" << "     Fall   |" << "\n";
        cout << setfill(' ') << setw(47) << "" << setw(17) << setfill('-');
        cout << "\n";
        cout << setw(50) << setfill(' ');
        cout << "|2|" << "     Spring |" << "\n";
        cout << setfill(' ') << setw(47) << "" << setw(17) << setfill('-');
        cout << "\n";
        cout << setw(50) << setfill(' ');
        cout << "|3|" << "     Summer |" << "\n";
        cout << setfill(' ') << setw(47) << "" << setw(17) << setfill('-');
        cout << "\n";
    }
    */

void viewProfile(std::string ID)
    {
        Node<Student>* curStu = nullptr;
        Node<SchoolYear>* tempyear = currYear; // replace curr with latest
        while (tempyear != nullptr)
        {
            bool check2 = false;
            Node<Class>* tempclass = currYear->data.classes;
            while (tempclass != nullptr)
            {
                bool check = false;
                Node<Student>* tempstu = tempclass->data.students;
                while (tempstu != nullptr)
                {
                    if (tempstu->data.ID == ID)
                    {
                        check = true;
                        curStu = tempstu;
                        break;
                    }
                    tempstu = tempstu->next;
                }
                if (check)
                {
                    check2 = true;
                    break;
                }
                tempclass = tempclass->next;
            }
            if (check2) break;
            tempyear = tempyear->next;
        }
        Student a = curStu->data;
        std::cout << "PROFILE: " << "\n";
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
        std::cout << std::setw(36) << std::setfill(' ');
        std::cout << " " << "|" << std::setw(14) << "NAME " << std::setfill(' ') << "|" << std::setw(28) << a.name << std::setfill(' ') << "|" << "\n";
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
        std::cout << std::setw(36) << std::setfill(' ');
        std::cout << " " << "|" << std::setw(14) << "ID " << std::setfill(' ') << "|" << std::setw(28) << a.ID << std::setfill(' ') << "|" << "\n";
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
        std::cout << " " << std::setw(36) << std::setfill(' ');
        std::cout << "|" << std::setw(14) << "MAIN CLASS " << std::setfill(' ') << "|" << std::setw(28) << a.mainClass << std::setfill(' ') << "|" << "\n";
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
        std::cout << " " << std::setw(36) << std::setfill(' ');
        std::cout << "|" << std::setw(14) << "BIRTHDAY " << std::setfill(' ') << "|" << std::setw(28) << a.birthday << std::setfill(' ') << "|" << "\n";
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
        std::cout << " " << std::setw(36) << std::setfill(' ');
        std::cout << "|" << std::setw(14) << "SOCIAL ID " << std::setfill(' ') << "|" << std::setw(28) << a.socialID << std::setfill(' ') << "|" << "\n";
        std::cout << std::setw(36) << std::setfill(' ');
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
        std::cout << " " << std::setw(36) << std::setfill(' ');
        std::cout << "|" << std::setw(14) << "GENDER " << std::setfill(' ') << "|" << std::setw(28) << a.gender << std::setfill(' ') << "|" << "\n";
        std::cout << std::setfill(' ') << std::setw(36) << "" << std::setw(46) << std::setfill('-');
        std::cout << "\n";
    }

void viewAllClassesInSchool()
{
        if (currYear == nullptr) // replace curr year with latest year
        {
            std::cout << "No school year\n";
            return;
        }
        Node<SchoolYear>* showyear = currYear;
        std::cout << std::setfill(' ') << std::setw(46) << "" << std::setw(12) << std::setfill('-') << "\n";
        while (showyear != nullptr)
        {
            Node<Class>* Classes = showyear->data.classes;
            while (Classes != nullptr)
            {
                std::cout << std::setfill(' ') << std::setw(46);
                std::cout << " " << "|" << std::setw(9) << Classes->data.className << std::setfill(' ') << "|" << "\n";
                std::cout << std::setfill(' ') << std::setw(46) << "" << std::setw(12) << std::setfill('-') << "\n";
                Classes = Classes->next;
            }
            showyear = showyear->next;
        }
}
void viewAllClassesInASchoolYear()
{
        if (chosenYear == nullptr) //replacewithchosenyear
        {
            std::cout << "Please choose year!\n";
            return;
        }
        Node<Class>* temp = chosenYear->data.classes;
        if (temp == nullptr)
        {
            std::cout << "No class in this schoolyear\n";
            return;
        }
        std::cout << std::setfill(' ') << std::setw(46) << "" << std::setw(12) << std::setfill('-') << "\n";
        while (temp != nullptr)
        {
            std::cout << std::setfill(' ') << std::setw(46);
            std::cout << " " << "|" << std::setw(9) << temp->data.className << std::setfill(' ') << "|" << "\n";
            std::cout << std::setfill(' ') << std::setw(46) << "" << std::setw(12) << std::setfill('-') << "\n";
            temp = temp->next;
        }
        std::cout << "\n";
}
void viewAllStudentsInAClass()
{
        viewAllClassesInSchool();
        std::cout << "ENTER CLASS NAME: ";
        std::string choice;
        std::cin >> choice;
        Node<Class>* CurClass = nullptr;
        Node<SchoolYear>* tempcurrYear = currYear; // replace with latest year
        while (tempcurrYear != nullptr)
        {
            Node<Class>* tempclass = tempcurrYear->data.classes;
            while (tempclass != nullptr)
            {
                if (tempclass->data.className == choice)
                {
                    CurClass = tempclass;
                    break;
                }
                tempclass = tempclass->next;
            }
            tempcurrYear = tempcurrYear->next;
        }
        if(CurClass == nullptr)
        {
            std::cout << "Invalid class!\n";
            return;
        }
        Node<Student>* Stu = CurClass->data.students;
        if (Stu == nullptr)
        {
            std::cout << "No student in class\n";
            return;
        }
        int i = 1;
        std::cout << std::setfill(' ') << std::setw(47) << "" << std::setw(40) << std::setfill('-') << "\n";
        while (Stu != nullptr)
        {
            std::cout << std::setw(47) << std::setfill(' '); // make a table of info
            std::cout << " " << i << "     " << std::setw(30) << Stu->data.name << std::setfill(' ') << "\n";
            std::cout << std::setfill(' ') << std::setw(47) << "" << std::setw(40) << std::setfill('-');
            std::cout << "\n";
            i++;
            Stu = Stu->next;
        }
}

void viewCourses(std::string ID)
    {
        Node<Course>* show = currSem.Courses;
        if (show == nullptr)
        {
            std::cout << "Student has no course\n";
            return;
        }
        int i = 1;
        std::cout << std::setfill(' ') << std::setw(44) << "" << std::setw(36) << std::setfill('-') << "\n";
        while (show != nullptr)
        {
            int n = show->data.courseSize;
            for (int t = 0; t < n; t++)
            {
                if (show->data.score[t].studentID == ID)
                {
                    std::cout << std::setw(44) << std::setfill(' ');
                    std::cout << " " << std::setw(3) << i << std::setfill(' ') << std::setw(31) << show->data.Name << std::setfill(' ') << "\n";
                    std::cout << std::setw(44) << std::setfill(' ') << "" << std::setw(36) << std::setfill('-') << "\n";
                    i++;
                    break;
                }
            }
            show = show->next;
        }
    }

void viewScores(std::string ID)
{
        Node<Course>* showscore = currSem.Courses;
        if (showscore == nullptr)
        {
            std::cout << "No course\n";
            return;
        }
        std::cout << std::setw(44) << std::setfill(' ') << "" << std::setw(37) << std::setfill('-') << "\n";
        while (showscore != nullptr)
        {
            int n = showscore->data.courseSize;
            for (int t = 0; t < n; t++)
            {
                if (showscore->data.score[t].studentID == ID)
                {
                    std::cout << std::setw(44) << std::setfill(' ') << "" <<
                        "|" << std::setw(30) << showscore->data.Name << "|" << std::setw(4) << showscore->data.score[t].total << "|\n"
                        << std::setw(44) << std::setfill(' ') << "" << std::setw(37) << std::setfill('-') << "\n";
                    break;
                }
            }
            showscore = showscore->next;
        }
    }
void createASchoolYear() //noinput
    {
        SchoolYear newy;
        std::cout << "ENTER CURRENT YEAR: ";
        std::cin >> newy.year;
        // check valid
        Node<SchoolYear>* NewYear = new Node<SchoolYear>(newy, currYear);
        currYear = NewYear;
    }
void createANewClass()
{
        if (currYear == nullptr)
        {
            std::cout << "No schoolyear\n";
            return;
        }
        Class newclass; // consider checking valid
        std::cout << "Enter class name: ";
        std::cin >> newclass.className;
        newclass.schoolYear = currYear->data.year;
        Node<Class>* NewClass = new Node<Class>(newclass, currYear->data.classes);
        currYear->data.classes = NewClass;
}

Node<Class>* ChooseClass(std::string choice) {
        Node<SchoolYear>* tempcurrYear = currYear;
        while (tempcurrYear != nullptr)
        {
            Node<Class>* tempclass = tempcurrYear->data.classes;
            while (tempclass != nullptr)
            {
                if (tempclass->data.className == choice)
                {
                    return tempclass;
                }
                tempclass = tempclass->next;
            }
            tempcurrYear = tempcurrYear->next;
        }
        return nullptr;
    }
void deleteDuplicateTempCourses(Node<std::string>*TempCourses) {
        if (TempCourses == nullptr) return;
        else
        {
            Node<std::string>* deleteCourse = TempCourses;
            while (deleteCourse != nullptr)
            {
                if (deleteCourse->next != nullptr && deleteCourse->next->data == TempCourses->data)
                {
                    Node<std::string>* temp2 = deleteCourse->next;
                    deleteCourse->next = deleteCourse->next->next;
                    delete temp2;
                    continue;
                }
                deleteCourse = deleteCourse->next;
            }
        }
        deleteDuplicateTempCourses(TempCourses->next);
    }

int countUniqueTempCourses(Node<std::string>*TempCourses) {
        int cnt = 0;
        Node<std::string>* count = TempCourses;
        while (count != nullptr)
        {
            cnt++;
            count = count->next;
        }
        return cnt;
    }

int countUniqueTempCourses2(Node<std::string>*TempCourses, bool* check) {
        int index = 0, cnt = 0;
        Node<std::string>* checkk = TempCourses;
        while (checkk != nullptr)
        {
            if (check[index]) cnt++;
            checkk = checkk->next;
            index++;
        }
        return cnt;
    }

bool Exist(bool* check, Node<Course>*checkexist, Node<std::string>*TempCourse, int n, int& ind) {
        Node<std::string>* temp = TempCourse;
        int index = 0;
        while (temp != nullptr)
        {
            if (temp->data == checkexist->data.Name)
            {
                ind = index;
                return check[index];
            }
            index++;
            temp = temp->next;
        }
        return false;
    }

Node<std::string>* ClassCourse(Node<std::string>*TempCourses, bool* check) {
        Node<std::string>* Cour = nullptr;
        int index = 0;
        while (TempCourses != nullptr)
        {
            if (check[index])
            {
                std::string newCour = TempCourses->data;
                Node<std::string>* NewCourse = new Node<std::string>(newCour, Cour);
                Cour = NewCourse;
            }
            index++;
            TempCourses = TempCourses->next;
        }
        return Cour;
    }

void previous(double& previoussum, double& previousnumofacticour, Node<Student>*StuScore, Node<Class>*ChosenClass) {
        //previoussem
        double prevsum = 0, preacticour = 0;
        Node<SchoolYear>* tempYear = chosenYear; //chosenyear
        if (tempYear == nullptr) return;
        if (currSem.startDate == tempYear->data.semesters[1].startDate || currSem.startDate == tempYear->data.semesters[2].startDate)
        {
            Semester sem1 = tempYear->data.semesters[0];
            Node<Course>* tempCours = tempYear->data.semesters[0].Courses;
            while (tempCours != nullptr)
            {
                for (int i = 0; i < tempCours->data.courseSize; i++)
                {
                    if (tempCours->data.score[i].studentID == StuScore->data.ID)
                    {
                        if (tempCours->data.score[i].total != -1)
                        {
                            prevsum += tempCours->data.score[i].total;
                            preacticour++;
                        }
                        break;
                    }
                }
                tempCours = tempCours->next;
            }
        }
        if (currSem.startDate == tempYear->data.semesters[2].startDate)
        {
            Semester sem2 = tempYear->data.semesters[1];
            Node<Course>* tempCours = tempYear->data.semesters[1].Courses;
            while (tempCours != nullptr)
            {
                for (int i = 0; i < tempCours->data.courseSize; i++)
                {
                    if (tempCours->data.score[i].studentID == StuScore->data.ID)
                    {
                        if (tempCours->data.score[i].total != -1)
                        {
                            prevsum += tempCours->data.score[i].total;
                            preacticour++;
                        }
                        break;
                    }
                }
                tempCours = tempCours->next;
            }
        }
        tempYear = tempYear->next;
        while (tempYear != nullptr) //num != 4
        {
            Node<Class>* checkClass = tempYear->data.classes;
            bool check = false;
            while (checkClass != nullptr)
            {
                if (checkClass->data.className == ChosenClass->data.className)
                {
                    check = true;
                    break;
                }
                checkClass = checkClass->next;
            }
            for (int i = 0; i < 3; i++)
            {
                Node<Course>* tempCour = tempYear->data.semesters[i].Courses;
                while (tempCour != nullptr)
                {
                    for (int i = 0; i < tempCour->data.courseSize; i++)
                    {
                        if (tempCour->data.score[i].studentID == StuScore->data.ID)
                        {
                            if (tempCour->data.score[i].total != -1)
                            {
                                prevsum += tempCour->data.score[i].total;
                                preacticour++;
                            }
                            break;
                        }
                    }
                    tempCour = tempCour->next;
                }
            }
            if (check)
            {
                previousnumofacticour = preacticour;
                previoussum = prevsum;
                return;
            }
            tempYear = tempYear->next;
        }
    }

void importAllSchoolYearsCSV() {
        std::ifstream inF("AllSchoolYears.csv");
        if (!inF.is_open()) {
            std::cout << "Can't import AllSchoolYear.csv!";
            return;
        }
        Node<SchoolYear>* syHead = nullptr;
        std::string header;
        std::getline(inF, header);
        std::string line;
        while (std::getline(inF, line)) {
            SchoolYear syNew;
            syNew.year = line;
            Node<SchoolYear>* syTemp = new Node<SchoolYear>(syNew, syHead);
            syHead = syTemp;
        }
        currYear = syHead;
        inF.close();
    }

void importAllClassesCSV() {
        std::ifstream inF("AllClasses.csv");
        if (!inF.is_open()) {
            std::cout << "Can't import AllClasses.csv!";
            return;
        }
        Node<SchoolYear>* syHead = currYear;
        std::string header;
        std::getline(inF, header);
        std::string line;
        while (std::getline(inF, line)) {
            Class newClass;
            std::stringstream ss(line);
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
        inF.close();
    }
void importAllStudentsCSV() {
        std::ifstream inF("AllStudents.csv");
        if (!inF.is_open()) {
            std::cout << "Can't import AllStudents.csv!";
            return;
        }
        Node<SchoolYear>* syHead = currYear;
        std::string header;
        std::getline(inF, header);
        std::string line;
        while (std::getline(inF, line)) {
            Student newStu;
            std::stringstream ss(line);
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
        inF.close();
    }
void importAllSemestersCSV() {
        std::ifstream inF("AllSemesters.csv");
        if (!inF.is_open()) {
            std::cout << "Can't import AllSemesters.csv!" << std::endl;
            return;
        }
        std::string header;
        std::getline(inF, header);
        std::string line;
        while (std::getline(inF, line)) {
            std::stringstream ss(line);
            std::string nSemTemp, syName, startDate, endDate;
            std::getline(ss, nSemTemp, ',');
            std::getline(ss, syName, ',');
            std::getline(ss, startDate, ',');
            std::getline(ss, endDate, ',');
            Node<SchoolYear>* syCurr = currYear;
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
        inF.close();
    }
void importAllCoursesCSV() {
        std::ifstream inF("AllCourses.csv");
        if (!inF.is_open()) {
            std::cout << "Can't import AllCourses.csv!" << std::endl;
            return;
        }
        std::string header;
        std::getline(inF, header);
        std::string line;
        while (std::getline(inF, line)) {
            std::stringstream ss(line);
            Course newCourse;
            std::getline(ss, newCourse.ID, ',');
            std::getline(ss, newCourse.Name, ',');
            std::getline(ss, newCourse.className, ',');
            std::getline(ss, newCourse.teacherName, ',');
            std::getline(ss, newCourse.dayOfWeek, ',');
            std::getline(ss, newCourse.session, ',');
            std::string couSY, couSemTemp;
            std::getline(ss, couSY, ',');
            std::getline(ss, couSemTemp, ',');
            int couSem = 0;
            std::stringstream(couSemTemp) >> couSem;
            // std::cout << couSemTemp << " | " << couSY << "\n";
            Node<SchoolYear>* syCurr = currYear;
            bool found = false;
            while (syCurr && !found) {
                if (syCurr->data.year == couSY) {
                    if (couSem > 0 && couSem <= 3) {
                        found = true;
                        if (!syCurr->data.semesters[couSem - 1].isCreated) {
                            std::cout << "Error: Semester not created for year " << couSY << " and semester " << couSem << std::endl;
                            break;
                        }
                        Node<Course>* couHead = syCurr->data.semesters[couSem - 1].Courses;
                        if (!couHead) {
                            syCurr->data.semesters[couSem - 1].Courses = new Node<Course>(newCourse);
                            syCurr->data.semesters[couSem - 1].Courses->data.score = new StudentScore[100];
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
                        std::cout << "Error: Invalid semester number for year " << couSY << ": " << couSem << std::endl;
                        break;
                    }
                }
                syCurr = syCurr->next;
            }
            if (!found) {
                std::cout << "Error: Year not found: " << couSY << std::endl;
            }
        }
        inF.close();
    }
void importContainingStudentsEnrolledInCourse(Node<Course>*couCurr) {
        std::string fileName = couCurr->data.ID + "_" + couCurr->data.className + ".csv";
        std::ifstream inF(fileName);
        if (!inF.is_open()) {
            std::cout << "Can't import " << fileName << std::endl;
            return;
        }
        std::string header;
        std::getline(inF, header);
        std::string line;
        int n = 0;
        while (std::getline(inF, line)) {
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
        Node<SchoolYear>* syHead = currYear;
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

void reverseSchoolYearsList(Node<SchoolYear>*&syHead) {
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
        reverseSchoolYearsList(currYear);
        Node<SchoolYear>* syCurr = currYear;
        std::ofstream outF("AllSchoolYears.csv", std::ofstream::out | std::ofstream::trunc);
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

void saveAllClassesData() {
        Node<SchoolYear>* syCurr = currYear;
        std::ofstream outF("AllClasses.csv", std::ofstream::out | std::ofstream::trunc);
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

void saveAllStudentsData() {
        Node<SchoolYear>* syCurr = currYear;
        std::ofstream outF("AllStudents.csv", std::ofstream::out | std::ofstream::trunc);
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

void saveAllSemestersData() {
        Node<SchoolYear>* syCurr = currYear;
        std::ofstream outF("AllSemesters.csv", std::ofstream::out | std::ofstream::trunc);
        if (outF.is_open()) {
            outF << "Semester,School Year,Start Date,End Date\n";
            while (syCurr) {
                for (int i = 0; i < 3; i++) {
                    if (syCurr->data.semesters[i].isCreated) {
                        outF << i + 1 << ","
                            << syCurr->data.year << ","
                            << syCurr->data.semesters[i].startDate << ","
                            << syCurr->data.semesters[i].endDate << "\n";
                    }
                }
                syCurr = syCurr->next;
            }
        }
        else {
            std::cout << "Could't open AllSemesters.csv to save Data." << std::endl;
        }
        outF.close();
    }

void saveAllCoursesData() {
        Node<SchoolYear>* syCurr = currYear;
        std::ofstream outF("AllCourses.csv", std::ofstream::out | std::ofstream::trunc);
        if (outF.is_open()) {
            outF << "Course ID,Course Name,Class Name,Teacher Name,Day Of Week,Session,School Year,Semester\n";
            while (syCurr) {
                for (int i = 0; i < 3; i++) {
                    if (syCurr->data.semesters[i].isCreated) {
                        Node<Course>* couCurr = syCurr->data.semesters[i].Courses;
                        while (couCurr) {
                            outF << couCurr->data.ID << ","
                                << couCurr->data.Name << ","
                                << couCurr->data.className << ","
                                << couCurr->data.teacherName << ","
                                << couCurr->data.dayOfWeek << ","
                                << couCurr->data.session << ","
                                << syCurr->data.year << ","
                                << i + 1 << "\n";
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

void saveScoreboardOfACourse(Node<Course>*couCurr) {
        std::string fileName = couCurr->data.ID + "_" + couCurr->data.className + ".csv";
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
        Node<SchoolYear>* syCurr = currYear;
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

void deleteAllStudentsData() {
        Node<SchoolYear>* syCurr = currYear;
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

void deleteAllClassesData() {
        Node<SchoolYear>* syCurr = currYear;
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

void deleteAllScoreboardsData() {
        Node<SchoolYear>* syCurr = currYear;
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
        Node<SchoolYear>* syCurr = currYear;
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

void deleteAllSchoolYearsData() {
        while (currYear) {
            Node<SchoolYear>* temp = currYear;
            currYear = currYear->next;
            delete temp;
        }
    }
bool getChoice(int numberOfChoices, std::string prompt, int& choice)
    {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);

        if (line.length() > 1 || !isdigit(line[0]) || line[0] < '1' || line[0] > numberOfChoices + '0')
        {
            std::cout << "Please choose valid choice.\n";
            return false;
        }

        choice = line[0] - '0';
        return true;
    }
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
            std::string daysOfWeek[6] = { "MON", "TUE", "WED", "THU", "FRI", "SAT" };
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
            std::string sessions[4] = { "S1 (07:30)", "S2 (09:30)", "S3 (13:30)", "S4 (15:30)" };
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

void Course::addStudent(std::string studentID, std::string studentName)
    {
        StudentScore* newScoreList = new StudentScore[courseSize + 1];
        for (int i = 0; i < courseSize; i++)
            newScoreList[i] = score[i];
        newScoreList[courseSize].studentID = studentID;
        newScoreList[courseSize].studentName = studentName;

        delete[] score;
        score = newScoreList;
        courseSize++;
    }

bool Course::deleteStudent(int index)
    {
        if (index < 0 || index > courseSize) return false;
        for (int i = index - 1; i < courseSize - 1; i++) score[i] = score[i + 1];
        courseSize--;
        return true;
    }

void Course::viewScoreboard()
    {
        if (score != nullptr)
        {
            std::cout << std::left
                << std::setw(10) << "Index" << std::setw(15) << "Student ID" << std::setw(25) << "Student Name" << std::setw(10) << "Midterm"
                << std::setw(10) << "Final" << std::setw(10) << "Other" << std::setw(10) << "Total" << std::endl;
            std::cout << std::setfill('-') << std::setw(100) << "-" << std::setfill(' ') << std::endl;

            for (int i = 0; i < courseSize; ++i)
            {
                std::cout << std::left
                    << std::setw(10) << (i + 1) << std::setw(15) << score[i].studentID << std::setw(25) << score[i].studentName
                    << std::setw(10) << score[i].midTerm << std::setw(10) << score[i].final
                    << std::setw(10) << score[i].other << std::setw(10) << score[i].total
                    << std::endl;
                std::cout << std::setfill('-') << std::setw(100) << "-" << std::setfill(' ') << std::endl;
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
        std::string scoreTypes[3] = { "Midterm", "Final", "Other" };
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
Node<Student>* getStudent(std::string ID)
    {
        Node<SchoolYear>* temp = currYear;
        while (temp != nullptr)
        {
            Node<Class>* tempClass = currYear->data.classes;
            while (tempClass != nullptr)
            {
                Node<Student>* curStu = tempClass->data.students;
                while (curStu != nullptr)
                {
                    if (curStu->data.ID == ID) return curStu;
                    curStu = curStu->next;
                }
                tempClass = tempClass->next;
            }
            temp = temp->next;
        }
        return nullptr;
    }
void changePasswordStudent()
    {
        Node<Student>* curStu = getStudent(myID);

        std::string myPassword = curStu->data.password;

        system("cls");

        std::string curPass, newPass, confirmPass;

        std::cout << "Current Password: ";
        std::cin >> curPass;
        if (curPass != myPassword)
        {
            std::cout << "\nWrong Password!!!";
            system("pause");
            system("cls");
            changePasswordStudent();
            return;
        }

        std::cout << "New Password: ";
        std::cin >> newPass;
        std::cout << "Confirm New Password: ";
        std::cin >> confirmPass;
        if (newPass != confirmPass)
        {
            std::cout << "\nNot Match!!!";
            system("pause");
            system("cls");
            changePasswordStudent();
            return;
        }

        curStu->data.password = newPass;

        std::cout << "Your Password Has Been Changed!!!";
        system("pause");
        system("cls");
        displayStudentHomePage();
}
