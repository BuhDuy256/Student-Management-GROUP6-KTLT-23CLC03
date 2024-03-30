#include"Student.h"

void importAllStudentsCSV() {
    std::ifstream inF("../CSV Files/AllStudents.csv");
    if (!inF.is_open()) {
        std::cout << "Could't import AllStudents.csv!";
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

std::string removeQuotesFromPath(const std::string& path) {
    std::string cleanedPath = path;
    if (cleanedPath.size() >= 2 && cleanedPath.front() == '"' && cleanedPath.back() == '"') {
        cleanedPath = cleanedPath.substr(1, cleanedPath.size() - 2);
    }
    return cleanedPath;
}

void importCSVStudentsOfAClass_Public() {
    std::string className;
    std::cout << "Enter the class you want to import CSV (Ex: 23CLC03): ";
    std::cin >> className;
    std::string fileName;
    std::cout << "Enter the path of the CSV file (You can drag it into the program): ";
    std::getline(std::cin >> std::ws, fileName);
    fileName = removeQuotesFromPath(fileName);
    std::ifstream inF(fileName);
    if (!inF.is_open()) {
        std::cout << "Error path!" << std::endl;
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

