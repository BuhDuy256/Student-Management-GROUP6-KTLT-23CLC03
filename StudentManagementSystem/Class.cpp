#include"Class.h"

void createANewClassInCurrentSYear() {
    menuCommandHeader();
    std::cout << "[1]. Create a new class of first-year students\n\n";
    if (!currSYear) {
        std::cout << "(X) There is no school year in the system." << std::endl;
    } else {
        int no;
        displayTableOfFirstYearClasses(no);
    }
    Class newClass;
    std::cout << "\n\t(?) Enter the class name (Format: dd/U[2,4]/dd. 'dd': two consecutive digits, 'U[2,4]': 2-4 uppercase letter): ";
    while (true) {
        std::cin >> newClass.className;
        if (isValidClassName(newClass.className, currSYear->data.year)) {
            break;
        }
        else {
            std::cout << "(X) Invalid input. Please enter again (Ex: 23APCS01): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (isClassExisted(newClass.className)) {
        std::cout << "\n\t(X) Class is existed in current school year" << std::endl;
        char confirm = getYesNo("\n\t(?) Do you want to try again? (Y/N): ");
        if (confirm == 'Y' || confirm == 'y') {
            createANewClassInCurrentSYear();
            return;
        }
        else {
            classManagementPage();
            return;
        }
    }

    char confirm = getYesNo("\t(?) Do you want to add this class? (Y/N): ");

    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\n(X) Cancelled creating a new class" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }
    newClass.schoolYear = currSYear->data.year;
    Node<Class>* claHead = new Node<Class>(newClass, currSYear->data.classes);
    currSYear->data.classes = claHead;
    std::cout << "\n\t(!) Class was added successfully" << std::endl;

    confirm = getYesNo("\n\t(?) Do you want to continue adding classes? (Y/N): ");
    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\n\t(!) You have finished adding classes" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }
    else if (confirm == 'Y' || confirm == 'y') {
        createANewClassInCurrentSYear();
        return;
    }
}

void displayTableOfFirstYearClasses(int& no) {
    // Use to call to another fucntion
    no = 0;
    Node<Class>* claCurr = currSYear->data.classes;
    std::cout << "\t+---------+--------------------+\n";
    std::cout << "\t| No      | Class              |\n";
    std::cout << "\t+---------+--------------------+\n";
    while (claCurr) {
        no++;
        std::cout << std::left << "\t| " << std::setw(8) << no << "| " << std::setw(19) << claCurr->data.className << "|\n";
        claCurr = claCurr->next;
    }
    std::cout << "\t+---------+--------------------+\n";
}



void add1stStudentsTo1stClass(Node<Class>* claCurr) {
    menuCommandHeader();
    std::cout << "[2]. Add new 1st year students to 1st-year class " << claCurr->data.className << "\n\n";
    int no;
    displayTableOfStudentsInAClass(claCurr, no);
    std::string newStudentID;
    std::string newStudentName;
    std::string newStudentGender;
    std::string newStudentBirthday;
    std::string newStudentSocialID;
    std::cout << "\n\t(?) Enter the student ID (8 digits): ";
    while (true) {
        std::cin >> newStudentID;
        if (isValidStudentID(newStudentID)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid student ID. Please try again: ";
        }
    }
    std::cout << "\t(?) Enter the student's full name: ";
    std::cin.ignore();
    while (true) {
        std::getline(std::cin, newStudentName);
        if (isValidCouOrStuName(newStudentName)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid student name. Please try again: ";
        }
    }
    formalize(newStudentName);

    int choice1;
    std::string gender[2] = { "Male", "Female" };
    std::cout << "\t(*) Select the student gender:\n";
    std::cout << "\t\t1. Male\n";
    std::cout << "\t\t2. Female\n";
    getChoiceInt(1, 2, "\t(?) Enter the number of the student gender (1-2): ", choice1);
    newStudentGender = gender[choice1 - 1];

    std::cout << "\t(?) Enter the student's birthday (Format: dd/mm/yyyy): ";
    while (true) {
        std::cin >> newStudentBirthday;
        if (isValidDateFormat(newStudentBirthday)) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid date. Please try again: ";
        }
    }

    std::cout << "\t(?) Enter the student's social ID (12 digits): ";
    while (true) {
        std::cin >> newStudentSocialID;
        if (newStudentSocialID.length() == 12) {
            break;
        }
        else {
            std::cout << "\t(X) Invalid social ID. Please try again: ";
        }
    }

    char confirm = getYesNo("\n\t(?) Do you want to add this student? (Y/N): ");
    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\n(X) Cancelled adding a new student" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }
    Student newStudent;
    newStudent.ID = newStudentID;
    newStudent.name = newStudentName;
    newStudent.gender = newStudentGender;
    newStudent.birthday = newStudentBirthday;
    newStudent.socialID = newStudentSocialID;
    newStudent.mainClass = claCurr->data.className;
    if (!claCurr->data.students) {
        claCurr->data.students = new Node<Student>(newStudent);
    }
    else {
        Node<Student>* stuCurr = claCurr->data.students;
        while (stuCurr->next)
            stuCurr = stuCurr->next;
        stuCurr->next = new Node<Student>(newStudent);
    }
    std::cout << "\n\t(!) Student was added successfully" << std::endl;
    char confirm2 = getYesNo("\n\t(?) Do you want to continue adding students? (Y/N): ");
    if (confirm2 == 'Y' || confirm2 == 'y') {
        add1stStudentsTo1stClass(claCurr);
        return;
    }
    system("pause");
    classManagementPage();
    return;
}

void add1stStudentsTo1styearClassPage() {
    menuCommandHeader();
    std::cout << "[2]. Add new 1st year students to 1st-year classes\n" << std::endl;
    int no1;
    displayTableOfFirstYearClasses(no1);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the previous menu.\n";
    getChoiceInt(0, no1, "\t(?) Enter the class number (0-" + std::to_string(no1) + "): ", choice);
    if (choice == 0) {
        classManagementPage();
        return;
    }
    Node<Class>* claCurr = currSYear->data.classes;
    int count = 0;
    while (claCurr) {
        count++;
        if (count == choice) {
            add1stStudentsTo1stClass(claCurr);
            return;
        }
        claCurr = claCurr->next;
    }
}

void importCSVStudentsOfAClass(Node<Class>* claCurr) {
    std::string fileName;
    std::cin.ignore();
    while (true) {
        std::cout << "\t(?) Enter the path of the CSV file (You can drag it into the program): ";
        std::getline(std::cin >> std::ws, fileName);
        fileName = removeQuotesFromPath(fileName);
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
        std::cout << "\n(X) Cannot open the file. Please check the file path and try again." << std::endl;
        system("pause");
        classManagementPage();
        return;
    }

    if (!claCurr->data.students) {
        // Pass the header
        std::string header;
        std::getline(inF, header);

        std::string line;
        while (std::getline(inF, line)) {
            // Check if the line is empty or contains only whitespace
            if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
                break; // Stop reading if the line is empty
            }
            Student newStu;
            std::stringstream ss(line);
            std::string NO; std::getline(ss, NO, ','); // don't use
            std::getline(ss, newStu.ID, ',');
            std::string firstName, lastName;
            std::getline(ss, firstName, ',');
            std::getline(ss, lastName, ',');
            newStu.name = lastName + (firstName.empty() ? "" : " " + firstName);
            std::getline(ss, newStu.gender, ',');
            std::getline(ss, newStu.birthday, ',');
            std::getline(ss, newStu.socialID, ',');
            newStu.mainClass = claCurr->data.className;
            if (!claCurr->data.students) {
                claCurr->data.students = new Node<Student>(newStu);
            }
            else {
                Node<Student>* stuCurr = claCurr->data.students;
                while (stuCurr->next)
                    stuCurr = stuCurr->next;
                stuCurr->next = new Node<Student>(newStu);
            }
        }
        std::cout << "\n(!) Import CSV successfully!" << std::endl;
    }
    else {
        std::cout << "\n(X) You cannot import the CSV file because this class already has students. Let's import into a class that doesn't have students yet! " << std::endl << "(X) If you make a mistake in doing the import process, delete the class and recreate it." << std::endl;
    }
    inF.close();
    system("pause");
    classManagementPage();
    return;
}

void importCSVStudentsOfAFirstYearClassPage() {
    menuCommandHeader();
    std::cout << "[3]. Import CSV file containing all students for a first-year class (in current school year)\n" << std::endl;

    int no1 = 0;
    displayTableOfFirstYearClasses(no1);

    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the previous menu.\n"
                 "\t(?) Enter the class number (0-" << no1 << "): ";
    while (!(std::cin >> choice) || choice < 0 || choice > no1) {
        std::cout << "\t(X) Invalid input. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (choice == 0) {
        classManagementPage();
        return;
    }
    Node<SchoolYear>* syHead = currSYear;
    int count = 0;
    while (syHead) {
        Node<Class>* claHead = syHead->data.classes;
        while (claHead) {
            count++;
            if (count == choice) {
                importCSVStudentsOfAClass(claHead);
                return;
            }
            claHead = claHead->next;
        }
        syHead = syHead->next;
    }
}

void displayTableOfStudentsInAClass(Node<Class>* claCurr, int& no) {
    std::cout << "\t+--------+------------+------------------------------+--------+------------+----------------+\n";
    std::cout << "\t| No     | Student ID | Full Name                    | Gender | Birthday   | Social ID      |\n";
    std::cout << "\t+--------+------------+------------------------------+--------+------------+----------------+\n";
    Node<Student>* currStu = claCurr->data.students;
    no = 0;
    while (currStu) {
        no++;
        std::cout << "\t| " << std::left << std::setw(7) << no << "| " << std::left << std::setw(11) << currStu->data.ID << "| "
                  << std::left << std::setw(29) << currStu->data.name << "| " << std::left << std::setw(7) << currStu->data.gender << "| "
                  << std::left << std::setw(11) << currStu->data.birthday << "| " << std::left << std::setw(15) << currStu->data.socialID << "|" << std::endl;
        currStu = currStu->next;
    }
    std::cout << "\t+--------+------------+------------------------------+--------+------------+----------------+\n";
}

void viewListOfStudentsInAClassPage() {
    menuCommandHeader();
    std::cout << "[4]. View list of students of first-year classes\n" << std::endl;

    int no1 = 0;
    displayTableOfClassesInSystem(no1);
    int choice;
    std::cout << "\n\t(*) Enter '0' to return to the previous menu.\n";
    getChoiceInt(0, no1, "\t(?) Enter the class number (0-" + std::to_string(no1) + "): ", choice);
    if (choice == 0) {
        classManagementPage();
        return;
    }
    int count = 0;
    Node<SchoolYear>* syCurr = latestSYear;
    bool found = false;
    while (syCurr && !found) {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr) {
            count++;
            if (count == choice) {
                int no2 = 0;
                found = false;
                menuCommandHeader();
                std::cout << "[4]. List of students of class " << claCurr->data.className << ":\n\n";
                displayTableOfStudentsInAClass(claCurr, no2);
                std::cout << std::endl;
                break;
            }
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
    system("pause");
    classManagementPage();
    return;
}

void displayTableOfClassesStudyingInCurrentSemester(int& no) {
    // Use to call to another fucntion
    Node<SchoolYear>* syCurrr = currSYear;
    int limits = 0;
    no = 0;
    std::cout << "\t+---------+--------------------+\n";
    std::cout << "\t| No      | Class              |\n";
    std::cout << "\t+---------+--------------------+\n";
    while (syCurrr != nullptr && limits != 4) {
        Node<Class>* claCurr = syCurrr->data.classes;
        while (claCurr) {
            no++;
            std::cout << std::left << "\t| " << std::setw(8) << no << "| " << std::setw(19) << claCurr->data.className << "|\n";
            claCurr = claCurr->next;
        }
        syCurrr = syCurrr->next;
        limits++;
    }
    std::cout << "\t+---------+--------------------+\n";
}

void viewListOfClassesStudyingInCurrentSemesterPage() {
    menuCommandHeader();
    std::cout << "[5]. View list of classes studying in current semester\n" << std::endl;
    int no = 0;
    displayTableOfClassesStudyingInCurrentSemester(no);
    std::cout << std::endl;
    system("pause");
    classManagementPage();
    return;
}

void displayTableOfClassesInSystem(int& no) {
    std::cout << "\t+---------+--------------------+--------------------+\n";
    std::cout << "\t| No      | Class              | School Year        |\n";
    std::cout << "\t+---------+--------------------+--------------------+\n";
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr) {
            no++;
            std::cout << "\t| " << std::left << std::setw(8) << no << "| " << std::left << std::setw(19) << claCurr->data.className << "| " << std::left << std::setw(19) << claCurr->data.schoolYear << "|" << std::endl;
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
    std::cout << "\t+---------+--------------------+--------------------+\n";
}

void viewListOfClassesInSystemPage() {
    menuCommandHeader();
    std::cout << "[6]. View list of classes in system\n" << std::endl;
    int no = 0;
    displayTableOfClassesInSystem(no);
    std::cout << std::endl;
    system("pause");
    classManagementPage();
    return;
}
void viewScoreBoardOfAClass() {
    menuCommandHeader();
    std::cout << "[7]. View scoreboard of a class\n";
    int no;
    displayTableOfClassesStudyingInCurrentSemester(no);
    std::cout << "\n\t(*) Enter '0' to return\n";
    int choice;
    getChoiceInt(0, no, "\t(?) Enter the class number (0-" + std::to_string(no) + "): ", choice);
    if (choice == 0) {
        classManagementPage();
        return;
    }
    Node<Class>* ChosenClass = ChooseClass(choice);
    if (ChosenClass == nullptr)
    {
        std::cout << "\t(X) Invalid choice!\n";
        system("pause");
        viewScoreBoardOfAClass();
        return;
    }
    Node<std::string>* TempCourses = nullptr;
    Node<Course>* SemCourse = currSem.Courses;
    while (SemCourse != nullptr)
    {
        std::string addTempCourse = SemCourse->data.ID;
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

    menuCommandHeader();
    std::cout << "[7]. Scoreboard of class " << ChosenClass->data.className << " in semester " << currSemNumber << " of school year " << currSYear->data.year << std::endl;
    Node<std::string>* ClassCourses = ClassCourse(TempCourses, check);
    int NumofClassCourses = countUniqueTempCourses(ClassCourses);
    Node<std::string>* print = ClassCourses;
    std::cout << "\n\t+----------+--------------------------------------------------+";
    std::cout << std::left << "\n\t|" << std::setfill(' ') << std::setw(10) << "CourseID" << "|" << std::setfill(' ') << std::setw(50) << "Course Name" << "|" << "\n";
    std::cout << "\t+----------+--------------------------------------------------+" << "\n";
    while (print != nullptr)
    {
        std::string courseName;
        Node<Course>* checkName = currSem.Courses;
        while (checkName != nullptr)
        {
            if (checkName->data.ID == print->data)
            {
                courseName = checkName->data.Name;
                break;
            }
            checkName = checkName->next;
        }
        std::cout << std::left << "\t|" << std::setfill(' ') << std::setw(10) << print->data << "|" << std::setfill(' ') << std::setw(50) << courseName << "|" << "\n";
        print = print->next;
    }
    std::cout << "\t+----------+--------------------------------------------------+";
    std::cout << "\n\n";

    std::cout << "\t+-----+-------------+------------------------------+";
    for (int i = 0; i < NumofClassCourses; i++) std::cout << "---------+";
    std::cout << "-----+-------------+";
    std::cout << std::left << "\n\t|" << " " << std::setfill(' ') << std::setw(4) << "NO" << "|" << " " << std::setfill(' ') << std::setw(12) << "Student ID " << "|" << " " << std::setfill(' ') << std::setw(29) << "Student Name" << "|";

    Node<std::string>* makeFirstRow = ClassCourses;
    while (makeFirstRow != nullptr) {
        std::cout << std::left << " " << std::setfill(' ') << std::setw(8) << makeFirstRow->data << "|";
        makeFirstRow = makeFirstRow->next;
    }
    std::cout << " GPA |" << " Overall GPA |";
    std::cout << "\n";
    std::cout << "\t+-----+-------------+------------------------------+";
    for (int i = 0; i < NumofClassCourses; i++) std::cout << "---------+";
    std::cout << "-----+-------------+" << "\n";
    Node<Student>* StuScore = ChosenClass->data.students;
    int index = 1;
    while (StuScore != nullptr)
    {
        Node<std::string>* StudentUniqueCourses = nullptr;
        double numofactivecourses = 0, gpa = 0;
        std::cout << std::left << "\t| " << std::setfill(' ') << std::setw(4) << index << "| " << std::setfill(' ') << std::setw(12) << StuScore->data.ID << "| " << std::setfill(' ') << std::setw(29) << StuScore->data.name << "|";
        Node<std::string>* tmp2 = ClassCourses;
        while (tmp2 != nullptr)
        {
            Node<Course>* check = currSem.Courses;
            while (check != nullptr)
            {
                bool score = false;
                if (tmp2->data == check->data.ID)
                {
                    int numofstudents = check->data.courseSize;
                    for (int i = 0; i < numofstudents; i++)
                    {
                        if (StuScore->data.ID == check->data.score[i].studentID)
                        {
                            std::string newStuCourses = check->data.ID;
                            Node<std::string>* newStuCours = new Node<std::string>(newStuCourses, StudentUniqueCourses);
                            StudentUniqueCourses = newStuCours;
                            if (check->data.score[i].total != (-1) * 1.0)
                            {
                                gpa += check->data.score[i].total;
                                numofactivecourses++;
                            }

                            if (check->data.score[i].final != (-1) * 1.0) std::cout << std::left << " " << std::setfill(' ') << std::setw(8) << check->data.score[i].final << "|";
                            else std::cout << std::setw(9) << " " << "|";
                            score = true;
                            break;
                        }
                    }
                }
                if (score) break;
                check = check->next;
            }
            if (check == nullptr) std::cout << std::setw(9) << " " << "|";
            tmp2 = tmp2->next;
        }
        if (numofactivecourses == 0 || gpa == 0) std::cout << std::setw(5) << " " << "|";
        else std::cout << std::left << " " << std::setfill(' ') << std::setw(4) << std::fixed << std::setprecision(1) << gpa / numofactivecourses << "|";
        double prevtotal = 0, prevnumofacticour = 0;
        previous(prevtotal, prevnumofacticour, StuScore, ChosenClass, StudentUniqueCourses);
        if (prevnumofacticour == 0 && numofactivecourses == 0) std::cout << std::setw(13) << " " << "|\n";
        else std::cout << std::left << " " << std::setfill(' ') << std::setw(12) << std::fixed << std::setprecision(1) << (prevtotal + gpa) / (prevnumofacticour + numofactivecourses) << "|\n";

        StuScore = StuScore->next;
        index++;
    }
    std::cout << "\t+-----+-------------+------------------------------+";
    for (int i = 0; i < NumofClassCourses; i++) std::cout << "---------+";
    std::cout << "-----+-------------+" << "\n";

    delete[] check;
    Node<std::string>* deleteTempCourses = TempCourses;
    while (deleteTempCourses != nullptr)
    {
        Node<std::string>* temp = deleteTempCourses;
        deleteTempCourses = deleteTempCourses->next;
        delete temp;
    }
    Node<std::string>* deleteClassCourses = ClassCourses;
    while (deleteClassCourses != nullptr)
    {
        Node<std::string>* temp = deleteClassCourses;
        deleteClassCourses = deleteClassCourses->next;
        delete temp;
    }
    std::cout << "\n";
    system("pause");
    classManagementPage();
    return;
}

void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass, Node<std::string>* StuUniqueCours) {
    double prevsum = 0, preacticour = 0;
    Node<SchoolYear>* tempYear = currSYear;
    if (tempYear == nullptr) return;

    if (currSemNumber >= 2)
    {
        Node<Course>* tempCours = tempYear->data.semesters[0].Courses;
        while (tempCours != nullptr)
        {
            bool canCount = false;
            Node<std::string>* check = StuUniqueCours;
            while (check != nullptr)
            {
                if (check->data == tempCours->data.Name)
                {
                    canCount = true;
                    break;
                }
                check = check->next;
            }
            if (!canCount)
            {
                for (int i = 0; i < tempCours->data.courseSize; i++)
                {
                    if (tempCours->data.score[i].studentID == StuScore->data.ID)
                    {
                        std::string newCours = tempCours->data.Name;
                        Node<std::string>* newStuCour = new Node<std::string>(newCours, StuUniqueCours);
                        StuUniqueCours = newStuCour;
                        if (tempCours->data.score[i].total != (-1) * 1.0)
                        {
                            prevsum += tempCours->data.score[i].total;
                            preacticour++;
                        }
                        break;
                    }
                }
            }
            tempCours = tempCours->next;
        }
    }
    if (currSemNumber == 3)
    {
        Node<Course>* tempCours = tempYear->data.semesters[1].Courses;
        while (tempCours != nullptr)
        {
            bool canCount = false;
            Node<std::string>* check = StuUniqueCours;
            while (check != nullptr)
            {
                if (check->data == tempCours->data.Name)
                {
                    canCount = true;
                    break;
                }
                check = check->next;
            }
            if (!canCount)
            {
                for (int i = 0; i < tempCours->data.courseSize; i++)
                {
                    if (tempCours->data.score[i].studentID == StuScore->data.ID)
                    {
                        std::string newCours = tempCours->data.Name;
                        Node<std::string>* newStuCour = new Node<std::string>(newCours, StuUniqueCours);
                        StuUniqueCours = newStuCour;
                        if (tempCours->data.score[i].total != (-1) * 1.0)
                        {
                            prevsum += tempCours->data.score[i].total;
                            preacticour++;
                        }
                        break;
                    }
                }
            }
            tempCours = tempCours->next;
        }
    }

    tempYear = tempYear->next;
    while (tempYear != nullptr)
    {
        Node<Class>* checkClass = tempYear->data.classes;
        bool checkloop = false;
        while (checkClass != nullptr)
        {
            if (checkClass->data.className == ChosenClass->data.className)
            {
                checkloop = true;
                break;
            }
            checkClass = checkClass->next;
        }
        for (int z = 0; z < 3; z++)
        {
            Node<Course>* tempCour = tempYear->data.semesters[z].Courses;
            while (tempCour != nullptr)
            {
                bool canCount = false;
                Node<std::string>* check = StuUniqueCours;
                while (check != nullptr)
                {
                    if (check->data == tempCour->data.Name)
                    {
                        canCount = true;
                        break;
                    }
                    check = check->next;
                }
                if (!canCount) {
                    for (int i = 0; i < tempCour->data.courseSize; i++)
                    {
                        if (tempCour->data.score[i].studentID == StuScore->data.ID)
                        {
                            std::string newCours = tempCour->data.Name;
                            Node<std::string>* newStuCour = new Node<std::string>(newCours, StuUniqueCours);
                            StuUniqueCours = newStuCour;
                            if (tempCour->data.score[i].total != (-1) * 1.0)
                            {
                                prevsum += tempCour->data.score[i].total;
                                preacticour++;
                            }
                            break;
                        }
                    }
                }
                tempCour = tempCour->next;
            }
        }
        if (checkloop)
        {
            previousnumofacticour = preacticour;
            previoussum = prevsum;
            break;
        }
        tempYear = tempYear->next;
    }

    if (tempYear == nullptr)
    {
        previousnumofacticour = preacticour;
        previoussum = prevsum;
    }

    Node<std::string>* deleteStuCours = StuUniqueCours;
    while (deleteStuCours != nullptr)
    {
        Node<std::string>* tempdelete = deleteStuCours;
        deleteStuCours = deleteStuCours->next;
        delete tempdelete;
    }
}

void deleteDuplicateTempCourses(Node<std::string>* TempCourses) {
    Node<std::string>* temp = TempCourses;
    while (temp != nullptr) {
        Node<std::string>* deleteCourse = temp;
        while (deleteCourse != nullptr)
        {
            if (deleteCourse->next != nullptr && deleteCourse->next->data == temp->data)
            {
                Node<std::string>* temp = deleteCourse->next;
                deleteCourse->next = deleteCourse->next->next;
                delete temp;
                continue;
            }
            deleteCourse = deleteCourse->next;
        }
        temp = temp->next;
    }
}

int countUniqueTempCourses(Node<std::string>* TempCourses) {
    int cnt = 0;
    Node<std::string>* count = TempCourses;
    while (count != nullptr)
    {
        cnt++;
        count = count->next;
    }
    return cnt;
}

bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind) {
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

Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check) {
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

Node<Class>* ChooseClass(int choice) {  //copyallfunc
    Node<SchoolYear>* tempcurrYear = currSYear;
    int index = 1;
    while (tempcurrYear != nullptr)
    {
        Node<Class>* tempclass = tempcurrYear->data.classes;
        while (tempclass != nullptr)
        {
            if (index == choice)
            {
                return tempclass;
            }
            index++;
            tempclass = tempclass->next;
        }
        tempcurrYear = tempcurrYear->next;
    }
    return nullptr;
}
