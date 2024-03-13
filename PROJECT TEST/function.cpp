#include"struct.h"
#include<fstream>
#include<sstream>

void SY_Queue::enQueue(std::string line) {
    if (isEmpty()) {
        head = new SchoolYear(line);
        tail = head;
    } else {
        tail -> syNext = new SchoolYear(line);
        tail = tail -> syNext;
    }
}

void SY_Queue::deQueue() {
    if (!isEmpty()) {
        SchoolYear* dele = head;
        head = head -> syNext;
        delete dele;
    } else {
        tail = nullptr;
    }
}

bool SY_Queue::isEmpty() {
    return head == nullptr;
}

std::string SY_Queue::front() {
    if (isEmpty()) {
        std::cout << "There are no School Year Data";
        return "";
    } 
    return head -> AcademicYear;
}

void SY_Queue::display() {
    SchoolYear* curr = head;
    while(curr) {
        std::cout << curr -> AcademicYear << std::endl;
        curr = curr -> syNext;
    }   
}

void SY_Queue::remove() {
    while(head) {
        SchoolYear* dele = head;
        head = head -> syNext;
        delete dele;
    }
}

void Student::generatePasswordFromID() {
    if (StudentID.length() >= 4) {
        Password = "KHTN@" + StudentID.substr(StudentID.length() - 4);
    } else {
        Password = "KHTN@" + StudentID;
    }
}

void importCSVSchoolYear(SY_Queue &HCMUS) {
    std::ifstream inF ("SchoolYear.csv");
    if (!inF.is_open()) {
        std::cout << "Data School Year Error";
        return;
    }
    std::string line;
    while(std::getline(inF, line)) {
        HCMUS.enQueue(line);
    }
}

void importCSVClass(Class* &Classes) {
    std::ifstream inF ("ClassList.csv");
    if (!inF.is_open()) {
        std::cout << "Class List Data Error";
        return;
    }
    std::string line;
    while(std::getline(inF, line)) {
        std::stringstream ss (line);
        std::string ClassToken;
        std::getline(ss, ClassToken, ',');
        std::string ClassName = ClassToken;
        std::getline(ss, ClassToken, ',');
        std::string SchoolYear = ClassToken;
        Class* ClassTemp = Classes;
        if (!Classes) {
            Classes = new Class(ClassName, SchoolYear);
            ClassTemp = Classes;
        } else {
            ClassTemp -> ClaNext = new Class(ClassName, SchoolYear);
            ClassTemp = ClassTemp -> ClaNext;
        }
    }
}

void displayClass(Class* Classes) {
    while(Classes) {
        std::cout << Classes -> ClassName << " " << Classes -> SchoolYear << std::endl;
        Classes = Classes -> ClaNext;
    }
}

void removeClass(Class* &Classes) {
    while(Classes) {
        Class* dele = Classes;
        Classes = Classes -> ClaNext;
        delete dele;
    }
    if (!Classes) 
        std::cout << "Classes is Empty";
}

void AddStudentToClass(Student* &ListStudentOfClass, std::string StudentID, std::string StudentName, std::string Gender, std::string Birthday, std::string SocialID, std::string ClassOfStudent) {
    if (!ListStudentOfClass) {
        ListStudentOfClass = new Student(StudentID, StudentName, Gender, Birthday, SocialID, ClassOfStudent);
        return;
    }
    Student* Curr = ListStudentOfClass;
    while(Curr -> StuNext) 
        Curr = Curr -> StuNext;
    Curr -> StuNext = new Student(StudentID, StudentName, Gender, Birthday, SocialID, ClassOfStudent);
}

Class* FindClassWithClassName(Class* Classes, std::string ClassName) {
    Class* Curr = Classes;
    while(Curr && Curr -> ClassName != ClassName)
        Curr = Curr -> ClaNext;
    return Curr;
}

void importCSVStudent(Class* Classes) {
    std::ifstream inF ("StudentList.csv");
    if (!inF.is_open()) {
        std::cout << "Student Data Error";
        return;
    }
    std::string line;
    while(std::getline(inF, line)) {
        std::string StudentID, StudentName, Gender, Birthday, SocialID, ClassOfStudent;
        std::stringstream ss(line);
        std::string StudentToken;
        std::getline(ss, StudentToken, ',');
        StudentID = StudentToken;
        std::getline(ss, StudentToken, ',');
        StudentName = StudentToken;
        std::getline(ss, StudentToken, ',');
        Gender = StudentToken;
        std::getline(ss, StudentToken, ',');
        Birthday = StudentToken;
        std::getline(ss, StudentToken, ',');
        SocialID = StudentToken;
        std::getline(ss, StudentToken, ',');
        ClassOfStudent = StudentToken;
        Class* ClassF = FindClassWithClassName(Classes, ClassOfStudent);
        if (ClassF) {
            Student* ListStudentOfClass = ClassF -> Students;
            AddStudentToClass(ListStudentOfClass, StudentID, StudentName, Gender, Birthday, SocialID, ClassOfStudent);
            ClassF -> Students = ListStudentOfClass;
        } else {
            std::cout << "Class not found: " << ClassOfStudent << std::endl;
        }
    }
    inF.close();
}

void displayAllStudentOfClass(Class* Classes, std::string ClassName) {
    Class* ClassF = FindClassWithClassName(Classes, ClassName);
    Student* ListStudentOfClass = ClassF -> Students;
    while(ListStudentOfClass) {
        std::cout << ListStudentOfClass -> StudentID << ";" <<
        ListStudentOfClass -> StudentName << ";" << ListStudentOfClass -> ClassOfStudent << std::endl;
        ListStudentOfClass = ListStudentOfClass -> StuNext; 
    }
}   

void deleteAllStudent(Class* Classes) {
    Class* Curr = Classes;
    while(Curr) {
        Student* StuHead = Curr -> Students;
        while(StuHead) {
            Student* dele = StuHead;
            StuHead = StuHead -> StuNext;
            delete dele;
        }
        Curr -> Students = nullptr;
        Curr = Curr -> ClaNext;
    }
}



