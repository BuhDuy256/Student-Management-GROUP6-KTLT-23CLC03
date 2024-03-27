#include"Semester.h"
#include<fstream>
#include<sstream>

void importAllSemestersCSV() {
    std::ifstream inF("AllSemesters.csv");
    if (!inF.is_open()) {
        std::cout << "Can't import AllSemesters.csv!" << std::endl;
        return;
    }
    std::string header;
    std::getline(inF, header);
    std::string line;
    while (std::getline(inF, line)) {
        std::stringstream ss(line);
        std::string nSemTemp, syName, startDate, endDate;
        std::getline(ss, nSemTemp, ',');
        std::getline(ss, syName, ',');
        std::getline(ss, startDate, ',');
        std::getline(ss, endDate, ',');
        Node<SchoolYear>* syCurr = currYear;
        while (syCurr) {
            if (syCurr -> data.year == syName) {
                int nSem = 0;
                std::istringstream(nSemTemp) >> nSem;
                // std::cout << nSem;
                syCurr -> data.semesters[nSem - 1].isCreated = true;
                syCurr -> data.semesters[nSem - 1].startDate = startDate;
                syCurr -> data.semesters[nSem - 1].endDate = endDate;
                break;
            }
            syCurr = syCurr -> next;
        }
    }
    inF.close();
}

void saveAllSemestersData() {
    Node<SchoolYear>* syCurr = currYear;
    std::ofstream outF("AllSemesters.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Semester,School Year,Start Date,End Date\n";
        while(syCurr) {
            for(int i = 0; i < 3; i++) {
                if (syCurr -> data.semesters[i].isCreated) {
                    outF << i + 1 << "," 
                    << syCurr -> data.year << "," 
                    << syCurr -> data.semesters[i].startDate << "," 
                    << syCurr -> data.semesters[i].endDate << "\n"; 
                }
            }
            syCurr = syCurr -> next;
        } 
    } else {
        std::cout << "Could't open AllSemesters.csv to save Data." << std::endl;
    }
    outF.close();
}
