#include "Accounts.h"
#include <fstream>

void displaySignInPage()
{
    std::cout << "[1] Sign In.\n[-1] Exit.\n\nInput Your Command: ";
    int cmd;
    std::cin >> cmd;

    if (cmd == 1)
    {
        signIn();
        return;
    }
    else if (cmd == -1)
    {
        exit(0);
    }
    else
    {
        std::cout << "\nInvalid Input!!!";
        displaySignInPage();
        return;
    }
}
void signIn()
{
    std::cout << "Username: ";
    std::cin >> myID;

    int idx = getStudent(myID);
    if (idx == -1)
    {
        std::cout << "\nUsername Not Found!!!";
        signIn();
        return;
    }

    std::string Pass;
    std::cout << "Password: ";
    std::cin >> Pass;
    if (Pass != students[idx].password)
    {
        std::cout << "\nWrong Password!!!";
        signIn();
        return;
    }

    displayHomePage();
}
void displayHomePage()
{
    std::cout << "Nothing here...";

    /*     upcoming features:
        - change password
        - view Course
        - log out
        ... */
}
void readStudentsInfo()
{
    numStudents = 0;

    std::ifstream fin;
    fin.open("../CSV Files/AllStudents.csv");

    std::string s;
    getline(fin, s);
    while (getline(fin, s))
    {
        std::stringstream Line(s);
        Student& x = students[numStudents];
        getline(fin, x.ID, ',');
        getline(fin, x.name, ',');
        getline(fin, x.gender, ',');
        getline(fin, x.birthday, ',');
        getline(fin, x.socialID, ',');
        getline(fin, x.mainClass, ',');
        getline(fin, x.password, ',');

        numStudents++;
    }
    fin.close();
}
void savePasswordData()
{
    std::ofstream fout;
    fout.open("../CSV Files/AllStudents.csv");

    fout << "StudentID, Name, Gender, Birthday, SocialID, Main Class\n";
    for (int i = 0; i < numStudents; i++)
    {
        Student& x = students[i];
        fout << x.ID << "," << x.name << "," << x.gender << "," << x.birthday << "," << x.socialID << "," << x.mainClass << "," << x.password << '\n';
    }

    fout.close();
}
int getStudent(std::string ID)
{
    for (int i = 0; i < numStudents; i++)
        if (students[i].ID == ID) return i;
    return -1;
}
void changePasswordStudent()
{
    int idx = getStudent(myID);

    std::string myPassword = students[idx].password;

    system("cls");

    std::string curPass, newPass, confirmPass;

    std::cout << "Current Password: ";
    std::cin >> curPass;
    if (curPass != myPassword)
    {
        std::cout << "\nWrong Password!!!";
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
        changePasswordStudent();
        return;
    }

    students[idx].password = newPass;

    std::cout << "Your Password Has Been Changed!!!";
    system("pause");
}