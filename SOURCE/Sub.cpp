#include"Sub.h"

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

bool getChoice(int numberOfChoices, std::string prompt, int &choice)
{
    std::cin.ignore();
    std::cout << prompt;
    std::string line;
    std::getline(std::cin, line);

    if (line.length() > 1 || !isdigit(line[0]) || line[0] < '1' || line[0] > numberOfChoices + '0')
    {
        std::cout << "Please choose valid choice between " << 1 << " and " << numberOfChoices << std::endl;
        return false;
    }
    
    choice = line[0] - '0';
    return true;
}

bool checkNameValid(std::string name)
{   
    for (char c : name) 
    {
        if (!std::isalpha(c) && !isspace(c))
        {
            std::cerr << "Please input properly name with no special characters or digits\n";
            return false;
        }
    }
    return true;
}

bool checkIDValid(std::string id)
{
    for (char c : id) 
    {
        if (!isdigit(c))
        {
            std::cerr << "Please input properly id with no characters other than digits\n";
            return false;
        }
    }
    return true;
}

void formalize(std::string &name)
{
    std::string formalizedName;
    bool lastWasSpace = true;
    for (char c : name) 
    {
        if (std::isspace(c)) 
        {
            if (!lastWasSpace) 
            {
                formalizedName += ' ';
                lastWasSpace = true;
            }
        } 
        else 
        {
            if (lastWasSpace) c = toupper(c);
            else c = tolower(c);

            formalizedName += c;
            lastWasSpace = false;
        }
    }
    name = formalizedName;
    if (*(name.end() - 1) == ' ') name.pop_back();
}

std::string doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

std::string removeQuotesFromPath(const std::string& path) {
    std::string cleanedPath = path;
    if (cleanedPath.size() >= 2 && cleanedPath.front() == '"' && cleanedPath.back() == '"') {
        cleanedPath = cleanedPath.substr(1, cleanedPath.size() - 2);
    }
    return cleanedPath;
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

bool checkClassExist(std::string className) {
    Node<SchoolYear>* syCurr = currSYear;
    Node<Class>* claCurr = syCurr->data.classes;
    bool isExisted = false;
    while (claCurr) {
        if (claCurr->data.className == className) {
            isExisted = true;
            break;
        }
        claCurr = claCurr->next;
    }
    return isExisted;
}

bool isValidClassName(std::string className) {
    bool isValid = false;
    // Check format ddXXXXdd
    std::regex pattern("\\d{2}[A-Z]{1,4}\\d{2}");
    if (std::regex_match(className, pattern) && className.substr(0, 2) == currSYear->data.year.substr(2, 2) && checkClassExist(className)) {
        isValid = true;
    }
    return isValid;
}

bool ends_with(const std::string& str, const std::string& suffix) {
    if (str.size() < suffix.size()) return false;
    return std::equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}

std::string getNextSchoolYear(const std::string& currentYear) {
	int startYear = std::stoi(currentYear.substr(0, 4));
	int endYear = std::stoi(currentYear.substr(5, 4));

	return std::to_string(startYear + 1) + "-" + std::to_string(endYear + 1);
}

void menuCommandHeader() {
    system("cls");
    std::cout << "Latest Semester - School Year in System: " << lastSemNumber << " + " << latestSYear->data.year << "\n";
    std::cout << "Current Semester - School Year in System: " << currSemNumber << " + " << currSYear->data.year << "\n";
}