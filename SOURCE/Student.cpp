#include"Student.h"
#include<fstream>
#include<sstream>

void importAllStudentsCSV() {
	std::ifstream inF ("../CSV Files/AllStudents.csv");
	if (!inF.is_open()) {
		std::cout << "Can't import AllStudents.csv!";
		return;
	}
	Node<SchoolYear>* syHead = currYear;
	std::string header;
	std::getline(inF, header);
	std::string line;
	while(std::getline(inF, line)) {
		Student newStu;
		std::stringstream ss (line);
		std::getline(ss, newStu.ID, ',');
		std::getline(ss, newStu.name, ',');
		std::getline(ss, newStu.gender, ',');
		std::getline(ss, newStu.birthday, ',');
		std::getline(ss, newStu.socialID, ',');
		std::getline(ss, newStu.mainClass, ',');
		std::getline(ss, newStu.password, ',');
		Node<SchoolYear>* syCurr = syHead;
		bool found = false;
		while (syCurr && !found) {
			Node<Class>* claCurr = syCurr -> data.classes;
			while (claCurr && !found) {
				if (claCurr -> data.className == newStu.mainClass) {
					found = true; 
					if (!claCurr -> data.students) {
                        claCurr -> data.students = new Node<Student>(newStu);
                    } else {
                        Node<Student>* stuCurr = claCurr -> data.students;
                        while(stuCurr -> next) 
                            stuCurr = stuCurr -> next;
                        stuCurr -> next = new Node<Student>(newStu);
                    }
					break; 
				}
				claCurr = claCurr -> next;
			}
			syCurr = syCurr -> next;
		}
		if (!found) {
			std::cout << "Could not find class of student with ID " << newStu.ID << std::endl;
		}
	}	
	inF.close();
}

void saveAllStudentsData() {
    Node<SchoolYear>* syCurr = currYear;
    std::ofstream outF("../CSV Files/AllStudents.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Student ID,Student Name,Gender,Birthday,Social ID,Main Class,Password\n";
        while(syCurr) {
            Node<Class>* claCurr = syCurr -> data.classes;
            while(claCurr) {
                Node<Student>* stuCurr = claCurr -> data.students;
                while(stuCurr) {
                    outF << stuCurr -> data.ID << ","
                        << stuCurr -> data.name << ","
                        << stuCurr -> data.gender << ","
                        << stuCurr -> data.birthday << ","
                        << stuCurr -> data.socialID << ","
                        << stuCurr -> data.mainClass << ","
                        << stuCurr -> data.password << "\n";
                    stuCurr = stuCurr -> next;
                }
                claCurr = claCurr -> next;
            }
            syCurr = syCurr -> next;
        } 
    } else {
        std::cout << "Could't open AllStudents.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllStudentsData() {
    Node<SchoolYear>* syCurr = currYear;
    while(syCurr) {
        Node<Class>* claCurr = syCurr -> data.classes;
        while(claCurr) {
            Node<Student>* stuCurr = claCurr -> data.students;
            while(stuCurr) {
                Node<Student>* temp = stuCurr;
                stuCurr = stuCurr -> next;
                delete temp;
            }
            claCurr = claCurr -> next;
        }
        syCurr = syCurr -> next;
    }
}

