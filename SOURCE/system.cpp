#include"System.h"

void importData() {
	importAllSchoolYearsCSV();
	importAllClassesCSV();
	importAllStudentsCSV();
	importAllSemestersCSV();
	importAllCoursesCSV();
	importAllStudentsInAllCoursesCSV();
	importAllStaffsCSV();

	findCurrSem();
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
		std::cout << "Exiting..." << std::endl;
		sleep(1);
		system("cls");
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
			if (choice == 1)
			{
				viewStudentProfile();
				system("pause");
				system("cls");
				studentHomePage();
			}
			else if (choice == 2)
			{
				viewStudentCourses();
				system("pause");
				system("cls");
				studentHomePage();
			}
			else if (choice == 3)
			{
				// viewScores(myID);
				// system("pause");
				// system("cls");
				// displayHomePage();
			}
			else if (choice == 4)
			{
				// changePasswordStudent();
				// system("pause");
				// system("cls");
				// displayHomePage();
			}
			else if (choice == -1)
			{
				std::cout << "Exiting..." << std::endl;
				sleep(1);
				system("cls");
				exit(0);
			}
		}
	}
}

void viewStudentCourses()
{
	std::cout << "[2]. Your couse in this semester: " << std::endl;
	std::cout << "+---------+----------------+--------------------------------+----------------+------------------------+-------------+----------------+\n";
	std::cout << "| No      | Course ID      | Course Name                    | Class Name     | Teacher Name           | Day of Week | Session        |\n";
	std::cout << "+---------+----------------+--------------------------------+----------------+------------------------+-------------+----------------+\n";

	Node<Course>* couCurr = currSem.Courses;
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
			std::cout << "| " << std::left << std::setw(8) << no << "| " << std::left << std::setw(15) << couCurr->data.ID << "| " << std::left << std::setw(31) << couCurr->data.Name << "| "
				<< std::left << std::setw(15) << couCurr->data.className << "| " << std::left << std::setw(23) << couCurr->data.teacherName << "| "
				<< std::left << std::setw(12) << couCurr->data.dayOfWeek << "| " << std::left << std::setw(15) << couCurr->data.session << "|\n";
		}
		couCurr = couCurr->next;
	}

	std::cout << "+---------+----------------+--------------------------------+----------------+------------------------+-------------+----------------+\n";
}