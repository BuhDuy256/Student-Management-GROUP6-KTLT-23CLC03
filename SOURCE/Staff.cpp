#include"Staff.h"

void importAllStaffsCSV() {
    std::ifstream inF("../CSV Files/AllStaffs.csv");
    if (!inF.is_open()) {
        std::cout << "Couldn't import AllStaffs.csv!";
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
        Staff newStaff;
        std::getline(ss, newStaff.ID, ',');
        std::getline(ss, newStaff.name, ',');
        std::getline(ss, newStaff.gender, ',');
        std::getline(ss, newStaff.birthday, ',');
        std::getline(ss, newStaff.socialID, ',');
        std::getline(ss, newStaff.password, ',');

        Node<Staff>* staTemp = new Node<Staff>(newStaff);
        if (!listStaff) {
            listStaff = staTemp;
        }
        else {
            Node<Staff>* temp = listStaff;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = staTemp;
        }
    }
    inF.close();
}

void saveAllStaffsData() {
    Node<Staff>* staCurr = listStaff;
    std::ofstream outF("../CSV Files/AllStaffs.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Staff ID,Staff Name,Gender,Birthday,Social ID,Passowrd\n";
        while (staCurr) {
            outF << staCurr->data.ID << ","
                << staCurr->data.name << ","
                << staCurr->data.gender << ","
                << staCurr->data.birthday << ","
                << staCurr->data.socialID << ","
                << staCurr->data.password << "\n";
            staCurr = staCurr->next;
        }
    }
    else {
        std::cout << "Couldn't open AllStaffs.csv to save Data" << std::endl;
    }
    outF.close();
}

void deleteAllStaffData() {
    Node<Staff>* staCurr = listStaff;
    while (staCurr) {
        Node<Staff>* staTemp = staCurr;
        staCurr = staCurr->next;
        delete staTemp;
    }
    listStaff = nullptr;
}