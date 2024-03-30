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

void viewStaffProfile() {
    system("cls");
    Staff a = currStaff->data;
    std::cout << "[1]. View your Profile" << std::endl;
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Staff Name" << "| " << std::setw(31) << a.name << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Staff ID" << "| " << std::setw(31) << a.ID << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Gender" << "| " << std::setw(31) << a.gender << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Birthday" << "| " << std::setw(31) << a.birthday << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Social ID" << "| " << std::setw(31) << a.socialID << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    system("pause");
    staffHomePage();
}

void changeStaffPassword() {
    system("cls");
    std::cout << "[4]. Change password:" << std::endl;
    std::string oldPassword, newPassword, confirmPassword;
    std::cout << "\tEnter your old password: ";
    std::cin >> oldPassword;

    std::cout << "\tEnter your new password: ";
    std::cin >> newPassword;

    std::cout << "\tConfirm your new password: ";
    std::cin >> confirmPassword;

    bool verifyPassword = false;
    if (oldPassword == currStaff->data.password) {
        verifyPassword = true;
    }

    if (!verifyPassword) {
        std::cout << "Your old password is incorrect!" << std::endl;
        system("pause");
        staffHomePage();
        return;
    }

    if (newPassword != confirmPassword) {
        std::cout << "Your new passwords do not match. Please try again!" << std::endl;
        system("pause");
        staffHomePage();
        return;
    }

    currStaff->data.password = newPassword;
    std::cout << "Password changed successfully." << std::endl;
    system("pause");
    staffHomePage();
}