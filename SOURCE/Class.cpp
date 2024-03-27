#include"Class.h"
#include<fstream>
#include<sstream>

void importAllClassesCSV() {
	std::ifstream inF ("AllClasses.csv");
	if (!inF.is_open()) {
		std::cout << "Can't import AllClasses.csv!";
		return;
	}
	Node<SchoolYear>* syHead = currYear;
	std::string header;
	std::getline(inF, header);
	std::string line;
	while(std::getline(inF, line)) {
		Class newClass;
		std::stringstream ss (line);
		std::getline(ss, newClass.className, ',');
		std::getline(ss, newClass.schoolYear, ',');
		Node<SchoolYear>* syCurr = syHead;
		bool found = false;
		while(syCurr && !found) {
			if (syCurr -> data.year == newClass.schoolYear) {
				found = true;
				if (!syCurr -> data.classes) {
                    syCurr -> data.classes = new Node<Class>(newClass);
                } else {
                    Node<Class>* claCurr = syCurr->data.classes;
                    while (claCurr -> next) {
                        claCurr = claCurr -> next;
                    }
                    claCurr -> next = new Node<Class>(newClass);
                }
				break;
			}
			syCurr = syCurr -> next;
		}
		if (!found) {
			std::cout << "Couldn't find the school year corresponding to " << newClass.className << std::endl;
		}
	}
	inF.close();
}

void saveAllClassesData() {
    Node<SchoolYear>* syCurr = currYear;
    std::ofstream outF("AllClasses.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Class Name,School Year\n";
        while(syCurr) {
            Node<Class>* claCurr = syCurr -> data.classes;
            while(claCurr) {
                outF << claCurr -> data.className << "," << claCurr -> data.schoolYear << "\n";
                claCurr = claCurr -> next;
            }
            syCurr = syCurr -> next;
        } 
    } else {
        std::cout << "Could't open AllClasses.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllClassesData() {
    Node<SchoolYear>* syCurr = currYear;
    while(syCurr) {
        Node<Class>* claCurr = syCurr -> data.classes;
        while(claCurr) {
            Node<Class>* temp = claCurr;
            claCurr = claCurr -> next;
            delete temp;
        }
        syCurr = syCurr -> next;
    } 
}
