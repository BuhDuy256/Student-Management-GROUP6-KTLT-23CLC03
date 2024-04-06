#include"Class.h"

void createANewClassInCurrentSYear() {
    menuCommandHeader();
    std::cout << "[1]. Create a new class of first-year students" << std::endl;
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
    // FIXME: 23APCS03 should be added right behind 23APCS02
    if (isClassExisted(newClass.className)) {
        std::cout << "\n(X) Class is existed in current school year" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }
    char confirm;
    std::cout << "\n\t(?) Do you want to add this class? (Y/N): "; //consider_adding_do_you_want_to_create_more_class (Y/N)
    while(!(std::cin >> confirm) || (confirm != 'Y' && confirm != 'y' && confirm != 'N' && confirm != 'n')) {
        std::cout << "\t(X) Invalid input. Please enter again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (confirm == 'N' || confirm == 'n') {
        std::cout << "\n(X) Cancelled creating a new class" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }
    newClass.schoolYear = currSYear->data.year;
    Node<Class>* claHead = new Node<Class>(newClass, currSYear->data.classes);
    currSYear->data.classes = claHead;
    std::cout << "\n(!) Class was added successfully" << std::endl;
    system("pause");
    classManagementPage();
    return;
}

void importCSVStudentsOfAClass(Node<Class>* claCurr) {
    std::string fileName;
    std::cout << "\t(?) Enter the path of the CSV file (You can drag it into the program): ";
    std::getline(std::cin >> std::ws, fileName);
    fileName = removeQuotesFromPath(fileName);

    // Check if the file exists
    if (!std::filesystem::exists(fileName)) {
        std::cout << "(X) Error: File does not exist!" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }

    // Check if the file has a .csv extension
    if (fileName.substr(fileName.find_last_of(".") + 1) != "csv") {
        std::cout << "(X) Invalid file format. Please provide a .csv file." << std::endl;
        system("pause");
        classManagementPage();
        return;
    }

    // Open the file
    std::ifstream inF(fileName);

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
    system("pause");
    classManagementPage();
    return;
}

void importCSVStudentsOfAFirstYearClassPage() {
    menuCommandHeader();
    std::cout << "[2]. Import CSV file containing all students for a first-year class (in current school year)\n" << std::endl;

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

void viewListOfStudentsInAFirstYearClass() {
    menuCommandHeader();
    std::cout << "[3]. View list of students of first-year classes\n" << std::endl;

    int no1 = 0;
    displayTableOfFirstYearClasses(no1);

    int choice;
    std::cout << "\n\t(?) Enter the class (1-" << no1 << "): ";
    while (true) {
        std::cin >> choice;
        if (choice < 1 || choice > no1) {
            std::cout << "\t(X) Invalid input. Please enter again: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            int count = 0;
            Node<Class>* claCurr = currSYear->data.classes;
            menuCommandHeader();
            while (claCurr) {
                count++;
                if (count == choice) {
                    std::cout << "List of students of class " << claCurr->data.className << ":\n";
                    std::cout << "\n\t+--------+------------+------------------------------+--------+------------+----------------+\n";
                    std::cout << "\t| No     | Student ID | Full Name                    | Gender | Birthday   | Social ID      |\n";
                    std::cout << "\t+--------+------------+------------------------------+--------+------------+----------------+\n";
                    Node<Student>* currStu = claCurr->data.students;
                    int no2 = 0;
                    while (currStu) {
                        no2++;
                        std::cout << "\t| " << std::left << std::setw(7) << no2 << "| " << std::left << std::setw(11) << currStu->data.ID << "| "
                            << std::left << std::setw(29) << currStu->data.name << "| " << std::left << std::setw(7) << currStu->data.gender << "| "
                            << std::left << std::setw(11) << currStu->data.birthday << "| " << std::left << std::setw(15) << currStu->data.socialID << "|" << std::endl;
                        currStu = currStu->next;
                    }
                    std::cout << "\t+--------+------------+------------------------------+--------+------------+----------------+\n\n";
                    break;
                }
                claCurr = claCurr->next;
            }
            break;
        }
    }
    system("pause");
    classManagementPage();
    return;
}

void viewListOfFirstYearClasses() {
    menuCommandHeader();
    std::cout << "[4]. View list of first-year classes (in current school year)\n" << std::endl;
    int no = 0;
    displayTableOfFirstYearClasses(no);
    std::cout << std::endl;
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

void viewListOfClassesStudyingInCurrentSemester() {
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

void viewListOfClassesInSystem() {
    menuCommandHeader();
    std::cout << "[6]. View list of classes in system\n" << std::endl;
    int no = 0;
    displayTableOfClassesInSystem(no);
    std::cout << std::endl;
    system("pause");
    classManagementPage();
    return;
}
