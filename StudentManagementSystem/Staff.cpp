#include"Staff.h"

void importAllStaffsCSV() {
    QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System/AllStaffs.csv";
    if (!QFile::exists(path)) path = ":/prefix/CSV Files/AllStaffs.csv";
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return;
    }
    QTextStream fin(&file);

    QString header = fin.readLine();

    std::string line;
    while (!fin.atEnd()) {
        QString Line = fin.readLine();
        std::string line = Line.toStdString();
        std::stringstream ss(line);
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
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
    file.close();
}

void saveAllStaffsData() {
    QString directoryPath = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation) + "/Student Management System";
    QString filePath = directoryPath + "/AllStaffs.csv";

    // Check if the directory exists, create it if necessary
    QDir directory(directoryPath);
    if (!directory.exists()) {
        if (!directory.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directoryPath;
            return;
        }
    }

    Node<Staff>* staCurr = listStaff;
    QFile outFile(filePath);
    if (outFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream outStream(&outFile);
        outStream << "Staff ID,Staff Name,Gender,Birthday,Social ID,Password\n";
        while (staCurr) {
            outStream << QString::fromStdString(staCurr->data.ID) << ","
                      << QString::fromStdString(staCurr->data.name) << ","
                      << QString::fromStdString(staCurr->data.gender) << ","
                      << QString::fromStdString(staCurr->data.birthday) << ","
                      << QString::fromStdString(staCurr->data.socialID) << ","
                      << QString::fromStdString(staCurr->data.password) << "\n";
            staCurr = staCurr->next;
        }
    } else {
        qDebug() << "Couldn't open AllStaffs.csv to save Data " << outFile.errorString();
    }
    outFile.close();
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
    std::cout << "\n\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Staff Name" << "| " << std::setw(31) << a.name << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Staff ID" << "| " << std::setw(31) << a.ID << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Gender" << "| " << std::setw(31) << a.gender << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Birthday" << "| " << std::setw(31) << a.birthday << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n";
    std::cout << "\t| " << std::left << std::setw(19) << "Social ID" << "| " << std::setw(31) << a.socialID << "|\n";
    std::cout << "\t+--------------------+--------------------------------+\n\n";
    system("pause");
    staffHomePage();
    return;
}

void changeStaffPassword() {
    system("cls");
    std::cout << "[4]. Change password" << std::endl;
    std::string oldPassword, newPassword, confirmPassword;
    std::cout << "\n\t(?) Enter old password: ";
    std::cin >> oldPassword;

    std::cout << "\t(?) Enter new password: ";
    std::cin >> newPassword;

    std::cout << "\t(?) Enter again to confirm: ";
    std::cin >> confirmPassword;

    bool verifyPassword = false;
    if (oldPassword == currStaff->data.password) {
        verifyPassword = true;
    }

    if (!verifyPassword) {
        std::cout << "\n(X) Your old password is incorrect!" << std::endl;
        system("pause");
        staffHomePage();
        return;
    }

    if (newPassword != confirmPassword) {
        std::cout << "\n(X) Your new passwords do not match. Please try again!" << std::endl;
        system("pause");
        staffHomePage();
        return;
    }

    currStaff->data.password = newPassword;
    std::cout << "\n(!) Password changed successfully." << std::endl;
    system("pause");
    staffHomePage();
}
