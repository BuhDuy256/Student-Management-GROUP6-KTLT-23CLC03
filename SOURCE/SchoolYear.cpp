#include"SchoolYear.h"

void Semester::viewCoursesList(int& no) {
	std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
	std::cout << "\t| No     | Course ID  | Course Name                  | Class Name | Teacher Name            | Credits | Size | Day | Session |\n";
	std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
	no = 0;
	Node<Course>* couCurr = Courses;
	while (couCurr) {
		no++;
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
		couCurr = couCurr->next;
	}
	std::cout << "\t+--------+------------+------------------------------+------------+-------------------------+---------+------+-----+---------+\n";
}

bool Semester::deleteCourse(int index)
{
	if (!Courses) return false;
	else if (index == 1)
	{
		Node<Course>* deleteNode = Courses;
		Courses = Courses->next;
		delete deleteNode;
		return true;
	}
	Node<Course>* node = Courses;
	for (int i = 1; i < index - 1; i++)
	{
		if (!node) return false;
		node = node->next;
	}

	Node<Course>* deleteNode = node->next;
	node->next = node->next->next;
	delete deleteNode;
	return true;
}

void saveAllSemestersData() {
	Node<SchoolYear>* syCurr = latestSYear;
	std::ofstream outF("../CSV Files/AllSemesters.csv", std::ofstream::out | std::ofstream::trunc);
	if (outF.is_open()) {
		outF << "Semester,School Year,Start Date,End Date\n";
		while (syCurr) {
			for (int i = 0; i < 3; i++) {
				if (syCurr->data.semesters[i].isCreated) {
					outF << i + 1 << ","
						<< syCurr->data.year << ","
						<< syCurr->data.semesters[i].startDate << ","
						<< syCurr->data.semesters[i].endDate << "\n";
				}
			}
			syCurr = syCurr->next;
		}
	}
	else {
		std::cout << "Could't open AllSemesters.csv to save Data." << std::endl;
	}
	outF.close();
}

void createANewSchoolYear()
{
	menuCommandHeader();
	std::cout << "[1]. Create the new school year " << std::endl;
	if (lastSemNumber != 3) {
		std::cout << "\n(X) You cannot create a new school year as this is not the last semester of the latest school year on the system." << std::endl;
		system("pause");
		staffCommandMenu();
		return;
	}
	else {
		std::string nextSYear = getNextSchoolYear(latestSYear->data.year);
		std::cout << "\nThe new school year will be " << nextSYear << "." << std::endl;
		std::cout << "(?) Are you sure you want to create a new school year (Y/N)? ";

		char choice;
		do {
			std::cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				SchoolYear newYear;
				newYear.year = nextSYear;
				Node<SchoolYear>* syHead = new Node<SchoolYear>(newYear, latestSYear);
				latestSYear = currSYear = syHead;
				lastSemNumber = currSemNumber = 0;
				std::cout << "\n(!) Successfully created new School Year!" << std::endl
					<< "(*) Let's create a new first semester so you can execute commands." << std::endl;
				system("pause");
				staffCommandMenu();
				return;
			}
			else if (choice == 'N' || choice == 'n') {
				std::cout << "(X) Canceled creating new school year." << std::endl;
				system("pause");
				staffCommandMenu();
				return;
			}
			else {
				std::cout << "(X) Invalid choice. Please enter again: ";
			}
		} while (true);
	}
}

void createANewSemester() {
	menuCommandHeader();
	std::cout << "[2]. Create a new semester" << std::endl;
	if (lastSemNumber >= 3) {
		std::cout << "\n(X) You cannot create any more semesters during the school year"
			<< std::endl
			<< "(*) Please let's create a new school year" << std::endl;
		system("pause");
		staffCommandMenu();
	}
	else {
		int no;
		displayTableOfAllSemesters(no);

		std::cout << "\n(*) The newest semester you can create is " << lastSemNumber + 1 << " of school year "
			<< latestSYear->data.year << std::endl;
		char choice;
		bool validChoice = false;
		while (!validChoice) {
			std::cout << "(?) Are you sure you want to create a new school year (Y/N)? ";
			std::cin >> choice;
			if (choice == 'Y' || choice == 'y') {
				validChoice = true;
			}
			else if (choice == 'N' || choice == 'n') {
				std::cout << "(*) Creation of a new semester aborted." << std::endl;
				system("pause");
				staffCommandMenu();
				return;
			}
			else {
				std::cout << "(X) Invalid choice!" << std::endl;
				system("pause");
				staffCommandMenu();
				return;
			}
		}

		std::string startDate;
		bool validDate1 = false;

		std::cout << "\t(?) Enter start date (dd/mm/yyyy): ";
		while (!validDate1) {
			std::cin >> startDate;

			if (!isValidDateFormat(startDate)) {
				std::cout << "Invalid date format. Please enter in format dd/mm/yyyy.";
				continue;
			}
			int diff = daysBetweenDates(startDate, latestSem.endDate);
			if (diff < 1) {
				std::cout << "Start date cannot be greater than end date of latest semester. Please enter a valid start date: ";
				continue;
			}
			validDate1 = true;
		}

		std::string endDate;
		bool validDate2 = false;

		std::cout << "\t(?) Enter end date (dd/mm/yyyy): ";
		while (!validDate2) {
			std::cin >> endDate;
			if (!isValidDateFormat(endDate)) {
				std::cout << "(X) Invalid date format. Please enter in format dd/mm/yyyy: ";
				continue;
			};
			int diff = daysBetweenDates(endDate, startDate);
			if (diff < 1) {
				std::cout << "(X) End date cannot be greater than start date. Please enter a valid end date: ";
				continue;
			}
			validDate2 = true;
		}
		std::cout << std::endl;
		int diff = daysBetweenDates(startDate, endDate);

		if (diff < 90 || diff > 150) {
			std::cout << "(X) The duration of a semester must be between 90 (~3 monhs) and 150 days (~5 months)." << std::endl;
			system("pause");
			staffCommandMenu();
			return;
		}

		latestSYear->data.semesters[lastSemNumber].isCreated = true;
		latestSYear->data.semesters[lastSemNumber].startDate = startDate;
		latestSYear->data.semesters[lastSemNumber].endDate = endDate;
		latestSem = currSem = latestSYear->data.semesters[lastSemNumber];
		lastSemNumber++;
		currSemNumber = lastSemNumber;
		std::cout << "(*) Semester created successfully." << std::endl;
		system("pause");
		staffCommandMenu();
		return;
	}
}

void displayTableOfAllSemesters(int& no) {
	std::cout << "\n\t+---------+------------+--------------------+---------------+----------------+\n";
	std::cout << "\t|No       | Semester   | School Year        | Start Date    | End Date       |\n";
	std::cout << "\t+---------+------------+--------------------+---------------+----------------+\n";
	Node<SchoolYear>* syCurr = latestSYear;
	while (syCurr)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (syCurr->data.semesters[i].isCreated)
			{
				no++;
				std::cout << "\t| " << std::setw(8) << std::left << no << "| " << std::setw(11) << i + 1 << "| " << std::setw(19) << syCurr->data.year << "| " << std::setw(14) << syCurr->data.semesters[i].startDate << "| " << std::setw(15) << syCurr->data.semesters[i].endDate << "|\n";
			}
		}
		syCurr = syCurr->next;
	}
	std::cout << "\t+---------+------------+--------------------+---------------+----------------+\n";
}

void changeCurrentSemesterSchoolYear() {
	menuCommandHeader();
	std::cout << "[3]. All semesters in system:" << std::endl;
	// Display table Semester - School Year
	int no = 0;
	displayTableOfAllSemesters(no);

	std::cout << "\n(?) Enter the number of the semester you want to change (1-" << no << "): ";

	int choice;
	while (true) {
		std::cin >> choice;
		if (choice < 1 || choice > no) {
			std::cout << "(X) Invalid input. Please enter a number between 1 and " << no << ": ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			int count = 0;
			bool stopLoop = false;
			Node<SchoolYear>* syCurr = latestSYear;
			while (syCurr && !stopLoop) {
				for (int i = 2; i >= 0; i--) {
					if (syCurr->data.semesters[i].isCreated) {
						count++;
						if (count == choice) {
							currSemNumber = i + 1;
							currSem = syCurr->data.semesters[i];
							currSYear = syCurr;
							stopLoop = true;
							break;
						}
					}
				}
				syCurr = syCurr->next;
			}
			break;
		}
	}
	system("pause");
	if (userMode == 1) {
		staffCommandMenu();
	}
	else if (userMode == 2) {
		studentHomePage();
	}
}