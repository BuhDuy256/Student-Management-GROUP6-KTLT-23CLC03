#include"SchoolYear.h"

void Semester::viewCoursesList(int &no) {
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
	system("cls");
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	std::cout << "[1]. Create the newest School Year " << std::endl;
	if (lastSemNumber != 3) {
		std::cout << "This is not the last semester of the latest school year created on the system, you cannot create a new school year!" << std::endl;
		system("pause");
		staffCommandMenu();
	}
	else {
		std::string nextSYear = getNextSchoolYear(latestSYear->data.year);
		std::cout << "The new school year is " << nextSYear << "." << std::endl;
		std::cout << "Are you sure you want to create a new school year (Y/N)? ";
		char choice;
		if (choice == 'Y' || choice == 'y') {
			SchoolYear newYear;
			newYear.year = nextSYear;
			Node<SchoolYear>* syHead = new Node<SchoolYear>(newYear, latestSYear);
			latestSYear = currSYear = syHead;
			lastSemNumber = currSemNumber = 0; 
			std::cout << "Created new School Year succesfully!" << std::endl
				<< "Let's create a new first semester so you can execute commands!" << std::endl;
			system("pause");
			staffCommandMenu();
		}
		else if (choice == 'N' || choice == 'n') {
			std::cout << "Create a new school year failed."; //No need
			system("pause");
			staffCommandMenu();
		}
		else {
			std::cout << "Invalid choice" << std::endl;
			system("pause");
			staffCommandMenu();
		}
	}
}

void createANewSemester() {
	menuCommandHeader();
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
			return;
		}
		else if (choice == 'N' || choice == 'n') {
			std::cout << "Create a new semester failed.";
			system("pause");
			staffCommandMenu();
			return;
		}
		else {
			std::cout << "Invalid choice!" << std::endl;
			system("pause");
			staffCommandMenu();
			return;
		}
	}
}

void changeCurrentSemesterSchoolYear() {
	menuCommandHeader();
	Node<SchoolYear>* syCurr = latestSYear;
	std::cout << "All semesters in the system:" << std::endl;
	// Display table Semester - School Year
	int no = 0;
	std::cout << "\t+---------+------------+--------------------+\n";
	std::cout << "\t|No       | Semester   | School Year        |\n";
	std::cout << "\t+---------+------------+--------------------+\n";
	while (syCurr)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (syCurr->data.semesters[i].isCreated)
			{
				no++;
				std::cout << "\t| " << std::setw(8) << std::left << no << "| " << std::setw(11) << i + 1 << "| " << std::setw(19) << syCurr->data.year << "|" << std::endl;
			}
		}
		syCurr = syCurr->next;
	}
	std::cout << "\t+---------+------------+--------------------+\n";

	std::cout << "Enter the sequence number corresponding to the semester you want to change (";
	for (int i = 1; i < no; i++) {
		std::cout << i << "/";
	}
	std::cout << no << "): ";

	int choice;
	while (true) {
		std::cin >> choice;
		if (choice < 1 || choice > no) {
			std::cout << "Invalid input. Please enter a number between 1 and " << no << ": ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			int count = 0;
			bool stopLoop = false;
			syCurr = latestSYear;
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
	staffCommandMenu();
	return;
}