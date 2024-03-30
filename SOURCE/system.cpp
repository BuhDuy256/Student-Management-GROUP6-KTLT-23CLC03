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
		signInPage();
	}
	else if (cmd == -1)
	{
		std::cout << "Exiting..." << std::endl;
		saveData();
		deleteData();
		sleep(1);
		system("cls");
		exit(0);
	}
	else
	{
		std::cout << "\nInvalid input!" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("pause");
		startPage();
	}
}

void signInPage() {
	system("cls");
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
		startPage(); //signInpage();
	}
	std::cout << "(!) Log in successfully." << std::endl;
	if (userType == 1) {
		staffHomePage();
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
			}
			else if (choice == 2)
			{
				viewStudentCourses();
			}
			else if (choice == 3)
			{
				viewStudentScoresInCurrentSem();
			}
			else if (choice == 4)
			{
				changeStudentPassword();
			}
			else if (choice == -1)
			{
				std::cout << "Exiting..." << std::endl;
				sleep(1);
				startPage();
			}
		}
	}
}

void staffHomePage() {
	while (true) {
		system("cls");
		std::cout << "Menu:" << std::endl;
		std::cout << "\t1. View Profile\n"
			<< "\t2. Command Menu\n"
			<< "\t3. Change Password\n"
			<< "\t-1.Exit\n\n";
		int choice;
		std::cout << "Enter your command (1/2/3/4/-1): ";
		std::cin >> choice;

		if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != -1)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a valid integer (1/2/3/-1)." << std::endl;
			system("pause");
			continue;
		}
		else {
			if (choice == 1)
			{
				viewStaffProfile();
			}
			else if (choice == 2)
			{
				staffCommandMenu();
			}
			else if (choice == 3)
			{
				changeStaffPassword();
			}
			else if (choice == -1)
			{
				std::cout << "Exiting..." << std::endl;
				sleep(1);
				startPage();
			}
		}
	}
}

void staffCommandMenu() {
	while (true) {
		system("cls");
		std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
		std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
		std::cout << "Menu:" << std::endl;
		std::cout << "\t1.Create a newest School Year\n";
		std::cout << "\t2.Create a newest Semester\n";
		std::cout << "\t3.Change current Semester - School Year\n";
		std::cout << "\t4.Classes Management\n";
		std::cout << "\t5.Courses Management\n";
		std::cout << "\t6.Back\n";
		int choice;
		std::cout << "Enter your command (1/2/3/4/5/-1): ";
		std::cin >> choice;

		if (std::cin.fail() || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a valid integer (1/2/3/4/5/6)." << std::endl;
			system("pause");
			continue;
		}
		else {
			if (choice == 1)
			{
				createANewSchoolYear();
			}
			else if (choice == 2)
			{
				createANewSemester();
			}
			else if (choice == 3)
			{
				//...
			}
			else if (choice == 4)
			{
				//...
			}
			else if (choice == 5)
			{
				//...
			}
			else if (choice == 6)
			{
				staffHomePage();
			}
		}
	}
}

void createANewSemester() {
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	if (lastSemNumber >= 3) {
		std::cout << "You cannot create any more semesters during the school year"
			<< std::endl
			<< "Please let's create a new school year" << std::endl;
		system("pause");
		staffCommandMenu();
	}
	else {
		std::cout << "The newest semester you can create is " << lastSemNumber + 1 << " of school year " << latestSYear->data.year << std::endl;
		std::cout << "Are you sure you want to create a new school year (Y/N)? ";
		char choice;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y') {
			std::string startDate;
			std::cout << "\tEnter start date (Ex:01/05/2023): ";
			std::cin >> startDate;

			std::string endDate;
			std::cout << "\tEnter end date (Ex:02/05/2023): ";
			std::cin >> endDate;

			//TODO: Check valid

			latestSYear->data.semesters[lastSemNumber].isCreated = true;
			latestSYear->data.semesters[lastSemNumber].startDate = startDate;
			latestSYear->data.semesters[lastSemNumber].endDate = endDate;
			latestSem = currSem = latestSYear->data.semesters[lastSemNumber];
			lastSemNumber++;
			currSemNumber = lastSemNumber;
			system("pause");
			staffCommandMenu();
		}
		else if (choice == 'N' || choice == 'n') {
			std::cout << "Create a new semester failed.";
			system("pause");
			staffCommandMenu();
		}
		else {
			std::cout << "Invalid choice!" << std::endl;
			system("pause");
			staffCommandMenu();
		}
	}
}
