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

void viewStudentProfile()
{
    system("cls");
    Student a = currStudent->data;
    std::cout << "[1] Your Profile: " << "\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Student Name" << "| " << std::setw(31) << a.name << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Student ID" << "| " << std::setw(31) << a.ID << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Class" << "| " << std::setw(31) << a.mainClass << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Gender" << "| " << std::setw(31) << a.gender << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Birthday" << "| " << std::setw(31) << a.birthday << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Social ID" << "| " << std::setw(31) << a.socialID << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    system("pause");
    studentHomePage();
    return;
}

void viewStudentCourses()
{
    system("cls");
    std::cout << "[2]. Your couse in this semester: " << std::endl;

    Node<Course>* couCurr = latestSem.Courses;

    std::cout << "\t+---------+----------------+--------------------------------+----------------+------------------------+-------------+----------------+\n";
    std::cout << "\t| No      | Course ID      | Course Name                    | Class Name     | Teacher Name           | Day of Week | Session        |\n";
    std::cout << "\t+---------+----------------+--------------------------------+----------------+------------------------+-------------+----------------+\n";

    int no = 0;
    while (couCurr) {
        bool check = false;
        for (int i = 0; i < couCurr->data.courseSize; i++) {
            if (couCurr->data.score[i].studentID == currStudent->data.ID) {
                no++;
                check = true;
            }
        }
        if (check) {
            std::cout << "\t| " << std::left << std::setw(8) << no << "| " << std::left << std::setw(15) << couCurr->data.ID << "| " << std::left << std::setw(31) << couCurr->data.Name << "| "
                << std::left << std::setw(15) << couCurr->data.className << "| " << std::left << std::setw(23) << couCurr->data.teacherName << "| "
                << std::left << std::setw(12) << couCurr->data.dayOfWeek << "| " << std::left << std::setw(15) << couCurr->data.session << "|\n";
        }
        couCurr = couCurr->next;
    }

    std::cout << "\t+---------+----------------+--------------------------------+----------------+------------------------+-------------+----------------+\n";
    system("pause");
    studentHomePage();
    return;
}

void viewStudentScoresInCurrentSem()
{
    system("cls");
    std::cout << "[3]. Your scoreboard in this semester: " << std::endl;

    Node<Course>* couCurr = latestSem.Courses;
    if (!couCurr) {
        std::cout << "You don't have any course!" << std::endl;
        system("pause");
        studentHomePage();
        return;
    }

    std::cout << "\t+---------+----------------+--------------------------------+------------+------------+------------+------------+\n";
    std::cout << "\t| No      | Couse ID       | Course Name                    | Midterm    | Final      | Other      | Total      |\n";
    std::cout << "\t+---------+----------------+--------------------------------+------------+------------+------------+------------+\n";

    int no = 0;
    while (couCurr) {
        for (int i = 0; i < couCurr->data.courseSize; i++) {
            if (couCurr->data.score[i].studentID == currStudent->data.ID) {
                no++;
                std::cout << "\t| " << std::left << std::setw(8) << no << "| "
                    << std::left << std::setw(15) << couCurr->data.ID << "| "
                    << std::left << std::setw(31) << couCurr->data.Name << "| "
                    << std::left << std::setw(11) << std::fixed << std::setprecision(2) << couCurr->data.score[i].midTerm << "| "
                    << std::left << std::setw(11) << std::fixed << std::setprecision(2) << couCurr->data.score[i].final << "| "
                    << std::left << std::setw(11) << std::fixed << std::setprecision(2) << couCurr->data.score[i].other << "| "
                    << std::left << std::setw(11) << std::fixed << std::setprecision(2) << couCurr->data.score[i].total << "|\n";
            }
        }
        couCurr = couCurr->next;
    }

    std::cout << "\t+---------+----------------+--------------------------------+------------+------------+------------+------------+\n";
    system("pause");
    studentHomePage();
    return;
}

void changeStudentPassword() {
    system("cls");
    std::cout << "[4]. Change password:" << std::endl;
    std::string oldPassword, newPassword, confirmPassword;
    std::cout << "\tEnter your old password: ";
    std::cin >> oldPassword;

    std::cout << "\tEnter your new password: ";
    std::cin >> newPassword;

    std::cout << "\tConfirm your new password: ";
    std::cin >> confirmPassword;

    bool verifyPassword = false;
    if (oldPassword == currStudent->data.password) {
        verifyPassword = true;
    }

    if (!verifyPassword) {
        std::cout << "Your old password is incorrect!" << std::endl;
        system("pause");
        studentHomePage();
        return;
    }

    if (newPassword != confirmPassword) {
        std::cout << "Your new passwords do not match. Please try again!" << std::endl;
        system("pause");
        studentHomePage();
        return;
    }

    currStudent->data.password = newPassword;
    std::cout << "Password changed successfully." << std::endl;
    system("pause");
    studentHomePage();
    return;
}
