#include"SchoolYear.h"

std::string formatSchoolYear(const std::string& inputYear) {
    std::string formattedInput = inputYear;
    formattedInput.erase(std::remove_if(formattedInput.begin(), formattedInput.end(), ::isspace), formattedInput.end());

    std::string formattedYear;

    if (formattedInput.length() == 9 && formattedInput[4] == '-') {
        formattedYear = formattedInput;
    }
    else if (formattedInput.length() == 9 && formattedInput[4] != '-') {
        formattedYear = formattedInput.substr(0, 4) + "-" + formattedInput.substr(4, 4);
    }
    return formattedYear;
}

void importAllSchoolYearsCSV() {
    std::ifstream inF("../CSV Files/AllSchoolYears.csv");
    if (!inF.is_open()) {
        std::cout << "Can't import AllSchoolYear.csv!";
        return;
    }
    Node<SchoolYear>* syHead = nullptr;
    std::string header;
    std::getline(inF, header);
    std::string line;
    while (std::getline(inF, line)) {
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        SchoolYear syNew;
        syNew.year = line;
        Node<SchoolYear>* syTemp = new Node<SchoolYear>(syNew, syHead);
        syHead = syTemp;
    }
    latestSYear = currSYear = syHead;
    inF.close();
}

void reverseSchoolYearsList(Node<SchoolYear>*& syHead) {
    Node<SchoolYear>* syPrev = nullptr, * syNext = nullptr;
    Node<SchoolYear>* syCurr = syHead;
    while (syCurr) {
        syNext = syCurr->next;
        syCurr->next = syPrev;
        syPrev = syCurr;
        syCurr = syNext;
    }
    syHead = syPrev;
}

void saveAllSchoolYearsData() {
    reverseSchoolYearsList(latestSYear);
    Node<SchoolYear>* syCurr = latestSYear;
    std::ofstream outF("../CSV Files/AllSchoolYears.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "School Year\n";
        while (syCurr) {
            outF << syCurr->data.year << "\n";
            syCurr = syCurr->next;
        }
    }
    else {
        std::cout << "Could't open AllSchoolYears.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllSchoolYearsData() {
    while (latestSYear) {
        Node<SchoolYear>* temp = latestSYear;
        latestSYear = latestSYear->next;
        delete temp;
    }
}

void importAllSemestersCSV() {
    std::ifstream inF("../CSV Files/AllSemesters.csv");
    if (!inF.is_open()) {
        std::cout << "Can't import AllSemesters.csv!" << std::endl;
        return;
    }
    std::string header;
    std::getline(inF, header);
    std::string line;
    while (std::getline(inF, line)) {
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
        std::stringstream ss(line);
        std::string nSemTemp, syName, startDate, endDate;
        std::getline(ss, nSemTemp, ',');
        std::getline(ss, syName, ',');
        std::getline(ss, startDate, ',');
        std::getline(ss, endDate, ',');
        Node<SchoolYear>* syCurr = latestSYear;
        while (syCurr) {
            if (syCurr->data.year == syName) {
                int nSem = 0;
                std::istringstream(nSemTemp) >> nSem;
                // std::cout << nSem;
                syCurr->data.semesters[nSem - 1].isCreated = true;
                syCurr->data.semesters[nSem - 1].startDate = startDate;
                syCurr->data.semesters[nSem - 1].endDate = endDate;
                break;
            }
            syCurr = syCurr->next;
        }
    }
    inF.close();
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

void findCurrSem() {
    Node<SchoolYear>* syCurr = latestSYear;
    bool found = false;
    while (syCurr && !found) {
        for (int i = 2; i >= 0; i--) {
            if (syCurr->data.semesters[i].isCreated) {
                found = true;
                latestSem = currSem = syCurr->data.semesters[i];
                lastSemNumber = currSemNumber = i + 1;
                break;
            }
        }
        syCurr = syCurr->next;
    }
}

std::string getNextSchoolYear(const std::string& currentYear) {
	int startYear = std::stoi(currentYear.substr(0, 4));
	int endYear = std::stoi(currentYear.substr(5, 4));

	return std::to_string(startYear + 1) + "-" + std::to_string(endYear + 1);
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
			std::cout << "Create a new school year failed.";
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
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	if (lastSemNumber >= 3) {
		std::cout << "You cannot create any more semesters during the school year"
			<< std::endl
			<< "Please let's create a new school year" << std::endl;
		system("pause");
		staffCommandMenu();
	} else {
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

void changeCurrentSemesterSchoolYear() {
	system("cls");
	std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
	std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
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
		} else {
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
}
