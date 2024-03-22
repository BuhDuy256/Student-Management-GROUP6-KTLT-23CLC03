#include "student.h"
#include "system.h"

extern string myID = "23127006";
extern string myPassword = "123456";

void pressEnterToContinue()
{
    cin.ignore();
    cout << "\nPress Enter To Continue...";
    cin.get();
}

void displayHeader()
{
    system("cls");
    cout << '\n'; for (int i = 0; i < 30; i++) cout << " "; cout << "+-------------------------------+";
    cout << '\n'; for (int i = 0; i < 30; i++) cout << " "; cout << "|   Student Management System   |";
    cout << '\n'; for (int i = 0; i < 30; i++) cout << " "; cout << "+-------------------------------+";
    cout << "\n\n\n\n\n";
}

void displayLoginConsole()
{
    displayHeader();
    cout << "What do you want to do?";
    cout << "\n1. Log In.\n-1. Exit.\n\n";

    cout << "Input Your Command: ";
    int cmd;
    cin >> cmd;

    if (cmd == -1) exit(0);
    if (cmd == 1) login();
}

void login()
{
    displayHeader();
    cout << "LOG IN\n\n";

    cout << "(Username: 23127006)\n(Default Password: 123456)\n\n";

    string username, password;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    if (username != myID)
    {
        cout << "\nUSERNAME NOT FOUND!!!\n";
        pressEnterToContinue();
        login();
        return;
    }
    if (password != myPassword)
    {
        cout << "\nWRONG PASSWORD!!!\n";
        pressEnterToContinue();
        login();
        return;
    }

    displayStudentMenu();
}

void displayStudentMenu()
{
    displayHeader();
    cout << "HOME\n\n";

    cout << "What do you want to do?";
    cout << "\n\n1. View Your Profile.\n2. View Your Courses.\n3. Change Your Password.\n4. Log Out.\n-1. Exit.\n\n";

    cout << "Input Your Command: ";
    int cmd;
    cin >> cmd;

    if (cmd == -1) exit(0);
    if (cmd == 1) displayStudentProfile();
    if (cmd == 2) displayCourses();
    if (cmd == 3) changePassword();
    if (cmd == 4) displayLoginConsole();
}
void displayStudentProfile()
{
    displayHeader();
    cout << "YOUR PROFILE:\n\n";

    cout << "StudentID: 23127006\n";
    cout << "Full Name: Tran Nguyen Khai Luan\n";
    cout << "Gender: Male\n";
    cout << "Luan dep trai vai lon\n";

    pressEnterToContinue();
    displayStudentMenu();
}

void displayCourses()
{
    displayHeader();
    cout << "YOUR COURSES:\n\n";

    cout << "Choose Your Course:\n";
    cout << "\n1. Programming Technique.\n2. Calculus 1.\n3. Physics 1.\n4. General Law.\n0. Back.\n-1. Exit.\n\n";

    cout << "Input Your Course: ";
    int cmd;
    cin >> cmd;
    if (cmd == 0) displayStudentMenu();
    if (cmd == -1) exit(0);

    cout << "\nCourse Not Found!!!\n";
    pressEnterToContinue();
    displayCourses();
}

void changePassword()
{
    displayHeader();
    cout << "CHANGE PASSWORD\n\n";

    string curPassword, newPassword, confirmPassword;

    cout << "Current Password: ";
    cin >> curPassword;
    if (curPassword != myPassword)
    {
        cout << "\nWRONG PASSWORD!!!\n";
        pressEnterToContinue();
        changePassword();
        return;
    }
    cout << "New Password: ";
    cin >> newPassword;
    cout << "Confirm New Password: ";
    cin >> confirmPassword;
    if (newPassword != confirmPassword)
    {
        cout << "\nNOT MATCH!!!\n";
        pressEnterToContinue();
        changePassword();
        return;
    }

    myPassword = newPassword;
    cout << "\nYour Password Has Been Changed!\n";

    pressEnterToContinue();
    displayStudentMenu();
}




void Student::viewProfile(){
 cout << "PROFILE: " << "\n";
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
 cout << setw(36) <<  setfill(' ');
 cout << " " << "|" << setw(14) << "NAME " << setfill(' ') << "|" << setw(28) << name << setfill(' ') << "|" << "\n";
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
 cout << setw(36) <<  setfill(' ');
 cout << " " << "|" << setw(14) << "ID " << setfill(' ') << "|" << setw(28) << ID << setfill(' ') << "|" << "\n";
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
 cout << " " << setw(36) <<  setfill(' ');
 cout << "|" << setw(14) << "MAIN CLASS " << setfill(' ') << "|" << setw(28) << mainClass << setfill(' ') << "|" << "\n";
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
 cout << " " << setw(36) <<  setfill(' ');
 cout << "|" << setw(14) << "BIRTHDAY " << setfill(' ') << "|" << setw(28) << birthday << setfill(' ') << "|" << "\n";
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
 cout << " " << setw(36) <<  setfill(' ');
 cout << "|" << setw(14) << "SOCIAL ID " << setfill(' ') << "|" << setw(28) << socialID << setfill(' ') << "|" << "\n";
 cout << setw(36) <<  setfill(' ');
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
  cout << " " << setw(36) <<  setfill(' ');
 cout << "|" << setw(14) << "GENDER " << setfill(' ') << "|" << setw(28) << gender << setfill(' ') << "|" << "\n";
 cout << setfill(' ') << setw(36) << "" << setw(46) << setfill('-');
 cout << "\n";
}
void Student::viewCourses(){
 Node<Node<Course>*>* show = addressCourses;
 if(show == nullptr)
 {
 cout << "Student has no course\n";
 return;
 }
 int i = 1;
 cout << setfill(' ') << setw(46) << "" << setw(37) << setfill('-') << "\n";
 while(show != nullptr){
    cout << setw(46) <<  setfill(' ');
    cout << " " << "|" << setw(3) << i << setfill(' ') << "|" << setw(31) << show->data->data.Name << setfill(' ') << "|" << "\n";
    cout << setfill(' ') << setw(46) << "" << setw(37) << setfill('-') << "\n";
    show = show->next;
    i++;
 }
}
