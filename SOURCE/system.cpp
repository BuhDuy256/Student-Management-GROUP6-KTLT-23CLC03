#include"System.h"

void importData() {
	importAllSchoolYearsCSV();
	importAllClassesCSV();
	importAllStudentsCSV();
	importAllSemestersCSV();
	importAllCoursesCSV();
	importAllStudentsInAllCoursesCSV();
	importAllStaffsCSV();
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
		system("cls");
		signInPage();
	}
	else if (cmd == -1)
	{
		exit(0);
	}
	else
	{
		std::cout << "\n(!) Invalid input" << std::endl;
		system("pause");
		startPage();
	}
}

void signInPage() {
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
		startPage();
	}
	std::cout << "(!) Log in successfully." << std::endl;
	if (userType == 1) {
		// Handle user type 1
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
			executeCommand_StudentHomePage(choice);
		}
	}
}

void executeCommand_StudentHomePage(int choice) {
	switch (choice) {
	case 1:
		// Function 
		return;
	case 2:
		// Function
		return;
	case 3:
		// Function
		return;
	case 4:
		// Function
		return;
	case -1:
		exit(0);
		return;
	default:
		// Don't do anything
		return;
	}
}