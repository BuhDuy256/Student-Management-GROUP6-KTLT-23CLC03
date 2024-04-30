#include"System.h"

void startPage()
{
	system("cls");
	std::cout << "\t1. Sign In\n\t-1. Exit\n\n(?) Input your command(1/-1): ";
	int cmd;

	while (!(std::cin >> cmd) || (cmd != 1 && cmd != -1)) {
		std::cout << "\n(X) Invalid input!. Please enter again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (cmd == 1) {
		signInPage();
	}
	else if (cmd == -1) {
		std::cout << "(!) Exiting..." << std::endl;
		saveData();
		deleteData();
		sleep(1);
		system("cls");
		exit(0);
	}
}

void signInPage() {
	system("cls");
	// 1: User is Staff
	// 2: User is Student
	int userType = -1;
	std::cout << "[1]. Sign in\n\n";
	std::string userID;
	std::cout << "\t(?) Username: ";
	std::cin >> userID;

	std::string userPassword;
	std::cout << "\t(?) Password: ";
	std::cin >> userPassword;

	userType = getUser(userID, userPassword);
	if (userType == -1) {
		std::cout << "\n(!) Username or Password is incorrect. Please try again." << std::endl;
		system("pause");
		startPage(); //signInpage();
	}
	std::cout << "\n(!) Log in successfully." << std::endl;
	userMode = userType;
	system("pause");
	if (userType == 1) {
		staffHomePage();
	}
	else if (userType == 2) {
		studentHomePage();
	}
}

void studentHomePage() {
	menuCommandHeader();
	std::cout << "Menu:\n\n";
	std::cout << "\t1. View profile\n"
		<< "\t2. View all courses in current semester\n"
		<< "\t3. View scoreboard in current semester\n"
		<< "\t4. Change semester\n"
		<< "\t5. Change password\n"
		<< "\t-1. Exit\n\n";
	int choice;
	std::cout << "(?) Enter your command (1/2/3/4/5/-1): ";

	while (!(std::cin >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != -1)) {
		std::cout << "(X) Invalid input. Please enter again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (choice == 1) {
		viewStudentProfile();
	}
	else if (choice == 2) {
		viewStudentCourses();
	}
	else if (choice == 3) {
		viewStudentScoresInCurrentSem();
	}
	else if (choice == 4) {
		changeCurrentSemesterSchoolYear();
	}
	else if (choice == 5) {
		changeStudentPassword();
	}
	else if (choice == -1) {
		std::cout << "(!) Exiting..." << std::endl;
		sleep(1);
		startPage();
		return;
	}
}

void staffHomePage() {
	system("cls");
	std::cout << "Menu:\n\n";
	std::cout << "\t1. View Profile\n"
		<< "\t2. Command Menu\n"
		<< "\t3. Change Password\n"
		<< "\t-1. Exit\n";
	int choice;
	std::cout << "\n(?) Enter your command (1/2/3/-1): ";

	while (!(std::cin >> choice) || (choice != 1 && choice != 2 && choice != 3 && choice != -1)) {
		std::cout << "(X) Invalid input. Please enter again: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	if (choice == 1) {
		viewStaffProfile();
	}
	else if (choice == 2) {
		staffCommandMenu();
	}
	else if (choice == 3) {
		changeStaffPassword();
	}
	else if (choice == -1) {
		std::cout << "(!) Exiting..." << std::endl;
		sleep(1);
		startPage();
		return;
	}
}

void staffCommandMenu() {
	menuCommandHeader();
	std::cout << "Menu:\n\n";
	std::cout << "\t1. Create a new School Year\n";
	std::cout << "\t2. Create a new Semester\n";
	std::cout << "\t3. Change current Semester - School Year\n";
	std::cout << "\t4. Class Management\n";
	std::cout << "\t5. Course Management\n";
	std::cout << "\t0. Back\n";
	int choice;
	std::cout << "\n(?) Enter your command (1/2/3/4/5/0): ";

	while (!(std::cin >> choice) || (choice < 0 || choice > 5)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "(X) Invalid input. Please enter again: ";
	}
	if (choice == 1) {
		createANewSchoolYear();
	}
	else if (choice == 2) {
		createANewSemester();
	}
	else if (choice == 3) {
		changeCurrentSemesterSchoolYear();
	}
	else if (choice == 4) {
		classManagementPage();
	}
	else if (choice == 5) {
		courseManagementPage();
	}
	else if (choice == 0) {
		staffHomePage();
		return;
	}
}

void classManagementPage() {
	menuCommandHeader();
	if (currSemNumber != 0) {
		std::cout << "[4]. Class Management:\n\n";
		std::cout << "\t1. Create a new class of first-year students (in current school year)\n";
		std::cout << "\t2. Add new 1st year students to 1st-year classes (in current school year).\n";
		std::cout << "\t3. Import CSV containing all students in a class (in current school year)\n";
		std::cout << "\t4. View list of students in a class (in system)\n";
		std::cout << "\t5. View list of classes studying (until current semester)\n";
		std::cout << "\t6. View list of classes (in system)\n";
		std::cout << "\t7. View scoreboard of a class (in current school year)\n";
		std::cout << "\t0. Back\n";
		int choice;
		std::cout << "\n(?) Enter your command (1/2/3/4/5/6/7/0): ";

		while (!(std::cin >> choice) || (choice < 0 || choice > 7)) {
			std::cout << "(X) Invalid input. Please enter again: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (choice == 1) {
			createANewClassInCurrentSYear();
		}
		else if (choice == 2) {
			add1stStudentsTo1styearClassPage();
		}
		else if (choice == 3) {
			importCSVStudentsOfAFirstYearClassPage();
		}
		else if (choice == 4) {
			viewListOfStudentsInAClassPage();
		}
		else if (choice == 5) {
			viewListOfClassesStudyingInCurrentSemesterPage();
		}
		else if (choice == 6) {
			viewListOfClassesInSystemPage();
		}
		else if (choice == 7) {
			viewScoreBoardOfAClass();
		}
		else if (choice == 0) {
			staffCommandMenu();
			return;
		}
	}
	else {
		std::cout << "\n(X) There are no semesters in the current school year, let's create a new semester so you can use the commands" << std::endl;
		system("pause");
		staffCommandMenu();
		return;
	}
}

void courseManagementPage() {
	menuCommandHeader();
	if (currSemNumber != 0) {
		std::cout << "[5]. Course Management:\n\n";
		std::cout << "\t1. Add a course to current semester\n";
		std::cout << "\t2. Update information of a course\n";
		std::cout << "\t3. Delete a course in current semester\n";
		std::cout << "\t4. Add a student to a course\n";
		std::cout << "\t5. Remove a student from a course\n";
		std::cout << "\t6. Upload a CSV file containing a list of students enrolled in a course\n";
		std::cout << "\t7. Export a list of students in a course to a CSV file\n";
		std::cout << "\t8. Import a scoreboard of a course (in curremt semester)\n";
		std::cout << "\t9. View list of courses (in current semester)\n";
		std::cout << "\t10. View list of students in a course (in current semester)\n";
		std::cout << "\t11. View scoreboard of a course\n";
		std::cout << "\t12. Update a student's result of a course\n";
		std::cout << "\t0. Back\n";
		int choice;
		std::cout << "\n(?) Enter your command (1/2/3/4/5/6/7/8/9/10/11/12/0): ";

		while (!(std::cin >> choice) || (choice < 0 || choice > 12)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "(X) Invalid input. Please enter again: ";
		}
		if (choice == 1) {
			addACourseInCurrSem();
		}
		else if (choice == 2) {
			updateInformationOfACourse();
		}
		else if (choice == 3) {
			deleteACourseInCurrSem();
		}
		else if (choice == 4) {
			addStudentToACourse();
		}
		else if (choice == 5) {
			removeAStudentFromACourse();
		}
		else if (choice == 6) {
			uploadCSVFileContainingAListOfStudentsOfACourse();
		}
		else if (choice == 7) {
			exportCSVStudentsOfACourse();
		}
		else if (choice == 8) {
			importScoreboardOfACourse();
		}
		else if (choice == 9) {
			viewListOfCoursesInCurrSem();
		}
		else if (choice == 10) {
			viewListStudentInACourse();
		}
		else if (choice == 11) {
			viewScoreboardOfACourse();
		}
		else if (choice == 12) {
			updateAStudentResultOfACourse();
		}
		else if (choice == 0) {
			staffCommandMenu();
			return;
		}
	}
	else {
		std::cout << "\n(X) There are no semesters in the current school year. Let's create a new semester so you can use the commands." << std::endl;
		system("pause");
		staffCommandMenu();
		return;
	}
}