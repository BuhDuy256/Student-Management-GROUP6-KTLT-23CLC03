#include"SchoolYear.h"

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
    latestSYear = syHead;
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
				currSem = syCurr->data.semesters[i];
				break;
			}
		}
		syCurr = syCurr->next;
	}
}


