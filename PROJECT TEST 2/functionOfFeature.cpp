#include"structProject.h"

void importCSVSchoolYear(Queue<SchoolYear> &HCMUS) {
    std::ifstream inF ("SchoolYear.csv");
    if (!inF.is_open()) {
        std::cout << "School Year Data Error!";
        return;
    }
    std::string line;
    while(std::getline(inF, line)) {
		SchoolYear temp;
		temp.yearRange = line;
        HCMUS.pushSchoolYear(temp);
    }
	inF.close();
}

void displayAllSchoolYears(Queue<SchoolYear> &HCMUS) {
	Node<SchoolYear>* temp = HCMUS.head;
	while(temp) {
		std::cout << (temp -> data).yearRange << std::endl;
		temp = temp -> next;
	}
}

void deleteAllSchoolYears(Queue<SchoolYear> &HCMUS) {
	while(HCMUS.head) {
		Node<SchoolYear>* temp = HCMUS.head;
		HCMUS.head = HCMUS.head -> next;
		delete temp;
	}
}

void importCSVClass(Queue<Class> &classes) {
    std::ifstream inF ("Class.csv");
    if (!inF.is_open()) {
        std::cout << "Class List Data Error!";
        return;
    }
    std::string line;
    while(std::getline(inF, line)) {
		Class temp;
		std::stringstream ss (line);
		std::getline(ss, temp.className, ',');
		std::getline(ss, temp.schoolYear, ',');
		classes.pushClass(temp);
    }
	inF.close();
}

void displayAllClasses(Queue<Class> &classes) {
	Node<Class>* temp = classes.head;
	while(temp) {
		std::cout << (temp -> data).className << " + " << (temp -> data).schoolYear << std::endl;
		temp = temp -> next;
	}
}

void deleteAllClasses(Queue<Class> &classes) {
	while(classes.head) {
		Node<Class>* temp = classes.head;
		classes.head = classes.head -> next;
	}	
}

void printFormattedTableHeader() {
	std::cout << "\t+" << std::setfill('-') << std::setw(9) << "+" 
			<< std::setfill('-') << std::setw(13) << "+" 
			<< std::setfill('-') << std::setw(21) << "+" 
			<< std::setfill('-') << std::setw(9) << "+" 
			<< std::setfill('-') << std::setw(13) << "+" 
			<< std::setfill('-') << std::setw(17) << "+" << std::endl;
	std::cout << std::left << std::setfill(' ');
	std::cout << "\t| " << std::setw(7) << "No" << "| " 
              << std::setw(11) << "Student ID" << "| "
              << std::setw(19) << "Full Name" << "| "
              << std::setw(7) << "Gender" << "| "
              << std::setw(11) << "Birthday" << "| "
              << std::setw(15) << "Social ID" << "|" << std::endl;
	std::cout << std::right;
	std::cout << "\t+" << std::setfill('-') << std::setw(9) << "+" 
			<< std::setfill('-') << std::setw(13) << "+" 
			<< std::setfill('-') << std::setw(21) << "+" 
			<< std::setfill('-') << std::setw(9) << "+" 
			<< std::setfill('-') << std::setw(13) << "+" 
			<< std::setfill('-') << std::setw(17) << "+" << std::endl; 
	std::cout << std::setfill(' ');
	// +--------+------------+--------------------+--------+------------+----------------+------------+
    // | No     | Student ID | Full Name          | Gender | Birthday   | Social ID      | Class      |
    // +--------+------------+--------------------+--------+------------+----------------+------------+
}

Node<Class>* findClass(Queue<Class> &classes, std::string className) {
    Node<Class>* curr = classes.head;
    while (curr) {
        if ((curr -> data).className == className) {
            return curr;
        }
        curr = curr -> next;
    }
    return nullptr;
}

void importCSVStudent(Queue<Class> &classes) {
	std::ifstream inF ("Student.csv");
    if (!inF.is_open()) {
        std::cout << "Student Data Error" << std::endl;
        return;
    }
	std::string line;
	while(std::getline(inF, line)) {
		Student temp;
		std::stringstream ss (line);
		std::getline(ss, temp.StudentID, ',');
		std::getline(ss, temp.StudentName, ',');
		std::getline(ss, temp.gender, ',');
		std::getline(ss, temp.birthday, ',');
		std::getline(ss, temp.socialID, ',');
		std::getline(ss, temp.classOfStudent, ',');
		Node<Class>* targetClass = findClass(classes, temp.classOfStudent);
		(targetClass -> data).students.pushStudent(temp);
	}
	inF.close();
}

void displayAllStudentOfSchool(Queue<Class> &classes) {
	Node<Class>* curr = classes.head;
	printFormattedTableHeader();
	int count = 1;
	while(curr) {
		Node<Student>* stuHead = ((curr -> data).students).head;
		while(stuHead) {
			std::cout << std::left << "\t| " << std::setw(7) << count++
			<< "| " << std::setw(11) << (stuHead -> data).StudentID 
			<< "| " << std::setw(19) << (stuHead -> data).StudentName 
			<< "| " << std::setw(7) << (stuHead -> data).gender
			<< "| " << std::setw(11) << (stuHead -> data).birthday
			<< "| " << std::setw(15) << (stuHead -> data).socialID << "|" << std::endl;
			stuHead = stuHead -> next;
		}
		curr = curr -> next;
	}
	std::cout << "\t+" << std::right << std::setfill('-') << std::setw(9) << "+" 
			<< std::setfill('-') << std::setw(13) << "+" 
			<< std::setfill('-') << std::setw(21) << "+" 
			<< std::setfill('-') << std::setw(9) << "+" 
			<< std::setfill('-') << std::setw(13) << "+" 
			<< std::setfill('-') << std::setw(17) << "+" << std::endl; 
	std::cout << std::setfill(' ');
}

void deleteAllStudents(Queue<Class> &classes) {
    Node<Class>* curr = classes.head;
    while (curr) {
        Node<Student>* stuHead = (curr -> data).students.head;
        while (stuHead) {
            Node<Student>* stuTemp = stuHead;
            stuHead = stuHead -> next;
            delete stuTemp;      
        }
        (curr -> data).students.head = nullptr; 
        curr = curr -> next;                 
    }
}