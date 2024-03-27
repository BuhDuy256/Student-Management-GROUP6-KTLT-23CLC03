#include"SchoolYear.h"
#include<fstream>
#include<sstream>

void importAllSchoolYearsCSV() {
	std::ifstream inF ("AllSchoolYears.csv");
	if (!inF.is_open()) {
		std::cout << "Can't import AllSchoolYear.csv!";
		return;
	}
	Node<SchoolYear>* syHead = nullptr;
	std::string header;
	std::getline(inF, header);
	std::string line;
	while(std::getline(inF, line)) {
		SchoolYear syNew;
		syNew.year = line;
		Node<SchoolYear>* syTemp = new Node<SchoolYear>(syNew, syHead);
		syHead = syTemp;
	}
	currYear = syHead;
	inF.close();
}

void reverseSchoolYearsList(Node<SchoolYear>* &syHead) {
    Node<SchoolYear>* syPrev = nullptr, *syNext = nullptr;
    Node<SchoolYear>* syCurr = syHead;
    while(syCurr) {
        syNext = syCurr -> next;
        syCurr -> next = syPrev;
        syPrev = syCurr;
        syCurr = syNext;
    }
    syHead = syPrev;
}

void saveAllSchoolYearsData() {
    reverseSchoolYearsList(currYear);
    Node<SchoolYear>* syCurr = currYear;
    std::ofstream outF("AllSchoolYears.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "School Year\n";
        while(syCurr) {
            outF << syCurr -> data.year << "\n";
            syCurr = syCurr -> next; 
        } 
    } else {
        std::cout << "Could't open AllSchoolYears.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllSchoolYearsData() {
    while(currYear) {
        Node<SchoolYear>* temp = currYear;
        currYear = currYear -> next;
        delete temp;
    }
}


