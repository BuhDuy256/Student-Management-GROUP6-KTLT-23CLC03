#include"Student.h"

void viewStudentProfile()
{
    menuCommandHeader();
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
    menuCommandHeader();
    std::cout << "[2]. Your couse in this semester: " << std::endl;

    Node<Course>* couCurr = currSem.Courses;

    std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
    std::cout << "\t| No     | Course ID  | Course Name                  | Class Name | Teacher Name            | Credits | Size | Day | Session |\n";
    std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";

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
            std::cout << "\t| " << std::left << std::setw(7) << no
            << "| " << std::left << std::setw(11) << couCurr->data.ID
            << "| " << std::left << std::setw(29) << couCurr->data.Name
            << "| " << std::left << std::setw(11) << couCurr->data.className
            << "| " << std::left << std::setw(24) << couCurr->data.teacherName
            << "| " << std::left << std::setw(8) << couCurr->data.nCredits
            << "| " << std::left << std::setw(5) << couCurr->data.courseSize
            << "| " << std::left << std::setw(4) << couCurr->data.dayOfWeek
            << "| " << std::left << std::setw(8) << couCurr->data.session
            << "|" << std::endl;
        }
        couCurr = couCurr->next;
    }

    std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
    system("pause");
    studentHomePage();
    return;
}

void viewStudentScoresInCurrentSem()
{
    menuCommandHeader();
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
