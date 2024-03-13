#include"struct.h"
#include<fstream>

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
    // inF.close();  
    // HCMUS.display();
    // HCMUS.remove();
    // std::cout << HCMUS.isEmpty();
}



