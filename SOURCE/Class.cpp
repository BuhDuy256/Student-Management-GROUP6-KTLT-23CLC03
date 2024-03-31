#include"Class.h"

void importAllClassesCSV() {
    std::ifstream inF("../CSV Files/AllClasses.csv");
    if (!inF.is_open()) {
        std::cout << "Could't import AllClasses.csv!";
        return;
    }
    Node<SchoolYear>* syHead = latestSYear;
    std::string header;
    std::getline(inF, header);
    std::string line;
    while (std::getline(inF, line)) {
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
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

std::string removeQuotesFromPath(const std::string& path) {
    std::string cleanedPath = path;
    if (cleanedPath.size() >= 2 && cleanedPath.front() == '"' && cleanedPath.back() == '"') {
        cleanedPath = cleanedPath.substr(1, cleanedPath.size() - 2);
    }
    return cleanedPath;
}

bool checkClassExist(std::string className) {
    Node<SchoolYear>* syCurr = currSYear;
    Node<Class>* claCurr = syCurr->data.classes;
    bool isExisted = false;
    while(claCurr) {
        if (claCurr->data.className == className) {
            isExisted = true;
            break;
        }
        claCurr = claCurr->next;
    }
    return isExisted;
}

bool isValidClassName(std::string className) {
    bool isValid = false;
    // Check format ddXXXXdd
    std::regex pattern("\\d{2}[A-Z]{1,4}\\d{2}");
    if (std::regex_match(className, pattern) && className.substr(0, 2) == currSYear->data.year.substr(2, 2) && checkClassExist(className)) {
        isValid = true;
    }
    return isValid;
}

void importCSVStudentsOfAClass_Public() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "[2]. Import CSV containing all students in a class (in current semester)" << std::endl;

    // TODO: Display a table of classes empty or not

    std::string className;
    std::cout << "Enter the class you want to import CSV: ";
    std::cin >> className;
    if (!isValidClassName(className)) {
        std::cout << "Class is not existed in current school year" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }

    std::string fileName;
    std::cout << "Enter the path of the CSV file (You can drag it into the program): ";
    std::getline(std::cin >> std::ws, fileName);
    fileName = removeQuotesFromPath(fileName);
    std::ifstream inF(fileName);
    if (!std::filesystem::exists(fileName)) {
        std::cout << "Error path!" << std::endl;
        system("pause");
        classManagementPage();
        return;
    }

    Node<SchoolYear>* syHead = latestSYear;
    std::string header;
    std::getline(inF, header);
    std::string line;
    Node<SchoolYear>* syCurr = syHead;
    Node<Class>* claCurr = nullptr;
    bool found = false;
    while (syCurr && !found) {
        claCurr = syCurr->data.classes;
        while (claCurr && !found) {
            if (claCurr->data.className == className) {
                found = true;
                break;
            }
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
    if (!found) {
        std::cout << "Class " << className << " couldn't be found. You should create new Class to import!" << std::endl;
    }
    else {
        if (!claCurr->data.students) {
            while (std::getline(inF, line)) {
                // Check if the line is empty or contains only whitespace
                if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
                    break; // Stop reading if the line is empty
                }
                Student newStu;
                std::stringstream ss(line);
                std::string NO;
                std::getline(ss, NO, ',');
                std::getline(ss, newStu.ID, ',');
                std::string firstName, lastName;
                std::getline(ss, firstName, ',');
                std::getline(ss, lastName, ',');
                newStu.name = lastName + (firstName.empty() ? "" : " " + firstName);
                std::getline(ss, newStu.gender, ',');
                std::getline(ss, newStu.birthday, ',');
                std::getline(ss, newStu.socialID, ',');
                newStu.mainClass = className;
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
            std::cout << "Import CSV successfully!" << std::endl;
        }
        else {
            std::cout << "You cannot import the CSV file because this class already has students. Let's import into a class that doesn't have students yet! " << std::endl << "If you make a mistake in doing the import process, delete the class and recreate it." << std::endl;
        }
    }
    inF.close();
}

void createANewClassInCurrentSYear() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
    std::cout << "[1]. Create a new class (in current school year)" << std::endl;
    Class newClass;
    bool isValid = false;
    while (!isValid) {
        std::cout << "\tEnter new class name: ";
        std::cin >> newClass.className;
        // Check format ddXXXXdd
        std::regex pattern("\\d{2}[A-Z]{1,4}\\d{2}");
        if (std::regex_match(newClass.className, pattern) && newClass.className.substr(0, 2) == currSYear->data.year.substr(2, 2)) {
            isValid = true;
        }
        else {
            std::cout << "Invalid class name format or does not match the current school year. Please enter again." << std::endl;
        }
    }
    // TODO: 23APCS03 should be added right behind 23APCS02
    if (checkClassExist(newClass.className)) {
        std::cout << "Class is existed in current school year" << std::endl;
        system("pause");
        classManagementPage();
    }
    newClass.schoolYear = currSYear->data.year;
    Node<Class>* claHead = new Node<Class>(newClass, currSYear->data.classes);
    currSYear->data.classes = claHead;
    std::cout << "Class was added successfully" << std::endl;
    system("pause");
    classManagementPage();
}

void viewListOfStudentsInAClass() {
	system("cls");
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
	std::cout << "[2]. Import CSV containing all students in a class (in current school year)" << std::endl;

	int no1 = 0;
	displayTableOfClassesInCurrentSemester(no1);

	int choice;
	std::cout << "Enter your choice (between 1 and " << no1 << "): ";
	while (true) {
		std::cin >> choice;
		if (choice < 1 || choice > no1) {
			std::cout << "Invalid input. Please enter a number between 1 and " << no1 << ": ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} else {
			int count = 0;
			Node<Class>* claCurr = currSYear->data.classes;
			std::cout << "\t+--------+------------+--------------------+--------+------------+----------------+\n";
			std::cout << "\t| No     | Student ID | Full Name          | Gender | Birthday   | Social ID      |\n";
			std::cout << "\t+--------+------------+--------------------+--------+------------+----------------+\n";
			while (claCurr) {
				count++;
				if (count == choice) {
					Node<Student>* currStu = claCurr->data.students;
					int no2 = 0;
					while(currStu) {
						no2++;
						std::cout << "\t| " << std::left << std::setw(7) << no2 << "| " << std::left << std::setw(11) << currStu->data.ID << "| " 
								<< std::left << std::setw(19) << currStu->data.name << "| " << std::left << std::setw(7) << currStu->data.gender << "| " 
								<< std::left << std::setw(11) << currStu->data.birthday << "| " << std::left << std::setw(15) << currStu->data.socialID << "|" << std::endl;
						currStu = currStu->next;
					}
					break;
				}
				claCurr = claCurr->next;
			}
			std::cout << "\t+--------+------------+--------------------+--------+------------+----------------+\n" << std::endl;
			break;
		}
	}
	system("pause");
	classManagementPage();
}

void viewListOfClassesInCurrentSemeter() {
	system("cls");
	std::cout << "[5]. View list of classes (in current school year)" << std::endl;
	int no = 0;
	displayTableOfClassesInCurrentSemester(no);
	system("pause");
	classManagementPage();
}

void displayTableOfClassesInCurrentSemester(int& no) {
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
