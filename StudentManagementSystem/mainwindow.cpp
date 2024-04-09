#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    ui->lb_latestSY->setText(QString::fromStdString("Latest School Year: " + latestSYear->data.year));
    ui->lb_latestSem->setText(QString::fromStdString("Latest Semester: " + std::to_string(lastSemNumber)));

    int fontId = QFontDatabase::addApplicationFont(":/font/MinecraftRegular-Bmg3.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont minecraftFont(fontName);


    minecraftFont.setPointSize(9);


    minecraftFont.setPointSize(12);
    ui->checkBox->setFont(minecraftFont);
    ui->checkBox_2->setFont(minecraftFont);
    ui->checkBox_3->setFont(minecraftFont);
    ui->button_currentDay->setFont(minecraftFont);
    ui->calendarWidget->setFont(minecraftFont);
    ui->sem_select->setFont(minecraftFont);
    ui->sy_select->setFont(minecraftFont);
    ui->tableWidget->horizontalHeader()->setFont(minecraftFont);
    ui->tableWidget->verticalHeader()->setFont(minecraftFont);


    minecraftFont.setPointSize(14);
    ui->button_signin->setFont(minecraftFont);
    ui->button_exit->setFont(minecraftFont);
    ui->button_StuHome->setFont(minecraftFont);
    ui->button_StuMyProfile->setFont(minecraftFont);
    ui->button_StuMyCourses->setFont(minecraftFont);
    ui->button_StuChangePassword->setFont(minecraftFont);
    ui->button_StuSignOut->setFont(minecraftFont);
    ui->button_AdHome->setFont(minecraftFont);
    ui->button_AdMyProfile->setFont(minecraftFont);
    ui->button_AdChangePassword->setFont(minecraftFont);
    ui->button_AdSignOut->setFont(minecraftFont);
    ui->button_confirm->setFont(minecraftFont);
    ui->button_confirm_2->setFont(minecraftFont);
    ui->button_back->setFont(minecraftFont);
    ui->button_back_2->setFont(minecraftFont);
    ui->button_back_3->setFont(minecraftFont);
    ui->button_back_4->setFont(minecraftFont);
    ui->lb_select_sy->setFont(minecraftFont);
    ui->lb_select_sem->setFont(minecraftFont);
    ui->tableWidget->setFont(minecraftFont);
    ui->button_viewScore->setFont(minecraftFont);
    ui->button_back_5->setFont(minecraftFont);


    minecraftFont.setPointSize(16);
    ui->slogan_1->setFont(minecraftFont);
    ui->slogan_2->setFont(minecraftFont);
    ui->slogan_3->setFont(minecraftFont);
    ui->button_ok->setFont(minecraftFont);

    minecraftFont.setPointSize(18);
    ui->txtPassword->setFont(minecraftFont);
    ui->txtUsername->setFont(minecraftFont);
    ui->txtCurPass->setFont(minecraftFont);
    ui->txtNewPass->setFont(minecraftFont);
    ui->txtConfirmPass->setFont(minecraftFont);
    ui->txt_StuID->setFont(minecraftFont);
    ui->txt_StuName->setFont(minecraftFont);
    ui->txt_StuGender->setFont(minecraftFont);
    ui->txt_StuBirthday->setFont(minecraftFont);
    ui->txt_StuClass->setFont(minecraftFont);
    ui->txt_StuSocialID->setFont(minecraftFont);
    ui->txtCurPass_2->setFont(minecraftFont);
    ui->txtNewPass_2->setFont(minecraftFont);
    ui->txtConfirmPass_2->setFont(minecraftFont);
    ui->txt_AdID->setFont(minecraftFont);
    ui->txt_AdName->setFont(minecraftFont);
    ui->txt_AdGender->setFont(minecraftFont);
    ui->txt_AdBirthday->setFont(minecraftFont);
    ui->txt_AdSocialID->setFont(minecraftFont);
    minecraftFont.setBold(1);  // Bold Region
    ui->name->setFont(minecraftFont);
    ui->name_2->setFont(minecraftFont);
    ui->lb_curPass->setFont(minecraftFont);
    ui->lb_newPass->setFont(minecraftFont);
    ui->lb_confirmPass->setFont(minecraftFont);
    ui->lb_StuID->setFont(minecraftFont);
    ui->lb_StuName->setFont(minecraftFont);
    ui->lb_StuGender->setFont(minecraftFont);
    ui->lb_StuBirthday->setFont(minecraftFont);
    ui->lb_StuMainClass->setFont(minecraftFont);
    ui->lb_StuSocialID->setFont(minecraftFont);
    ui->lb_curPass_2->setFont(minecraftFont);
    ui->lb_newPass_2->setFont(minecraftFont);
    ui->lb_confirmPass_2->setFont(minecraftFont);
    ui->lb_AdID->setFont(minecraftFont);
    ui->lb_AdName->setFont(minecraftFont);
    ui->lb_AdGender->setFont(minecraftFont);
    ui->lb_AdBirthday->setFont(minecraftFont);
    ui->lb_AdSocialID->setFont(minecraftFont);
    minecraftFont.setBold(0); //End Bold Region


    minecraftFont.setPointSize(22);
    minecraftFont.setBold(1); // Bold Region
    ui->lb_username->setFont(minecraftFont);
    ui->lb_password->setFont(minecraftFont);
    minecraftFont.setBold(0); //End Bold Region


    minecraftFont.setPointSize(36);
    minecraftFont.setBold(1); // Bold Region
    ui->lb_signin->setFont(minecraftFont);
    ui->lb_changePass->setFont(minecraftFont);
    ui->lb_MyProfile->setFont(minecraftFont);
    ui->lb_MyCourses->setFont(minecraftFont);
    ui->lb_changePass_2->setFont(minecraftFont);
    ui->lb_MyProfile_2->setFont(minecraftFont);
    minecraftFont.setBold(0); //End Bold Region

    minecraftFont.setPointSize(48);
    minecraftFont.setBold(1); // Bold region
    ui->lb_welcome->setFont(minecraftFont);
    ui->lb_welcome_2->setFont(minecraftFont);
    minecraftFont.setBold(0); // End Bold region

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MessageBox(std::string title, std::string text)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(nullptr, QString::fromStdString(title), QString::fromStdString(text), QMessageBox::Ok);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked()) ui->txtPassword->setEchoMode(QLineEdit::Normal);
    else ui->txtPassword->setEchoMode(QLineEdit::Password);
}


void MainWindow::on_button_signin_clicked()
{
    std::string username = ui->txtUsername->text().toStdString();
    std::string password = ui->txtPassword->text().toStdString();

    int id = getUser(username, password);
    if (id == -1)
    {
        MessageBox("Error", "Username Or Password Is Incorrect!!!");
        return;
    }
    if (id == 1)
    {
        std::stringstream name(currStaff->data.name);
        std::string firstName;
        while (getline(name, firstName, ' '));
        ui->name_2->setText(QString::fromStdString("Hi, " + firstName));

        ui->stackedWidget->setCurrentIndex(2);
        ui->stackedWidget_3->setCurrentIndex(0);
    }
    else if (id == 2)
    {
        std::stringstream name(currStudent->data.name);
        std::string firstName;
        while (getline(name, firstName, ' '));
        ui->name->setText(QString::fromStdString("Hi, " + firstName));

        ui->stackedWidget->setCurrentIndex(1);
        ui->stackedWidget_2->setCurrentIndex(0);
    }
}


void MainWindow::on_txtUsername_textEdited(const QString& arg1)
{
    if (ui->txtUsername->text() == "" || ui->txtPassword->text() == "") ui->button_signin->setDisabled(1);
    else ui->button_signin->setDisabled(0);
}


void MainWindow::on_txtPassword_textEdited(const QString& arg1)
{
    if (ui->txtUsername->text() == "" || ui->txtPassword->text() == "") ui->button_signin->setDisabled(1);
    else ui->button_signin->setDisabled(0);
}


void MainWindow::on_button_exit_clicked()
{
    MainWindow::close();
}

void MainWindow::on_button_StuSignOut_clicked()
{
    // ui->txtUsername->setText(QString::fromStdString(""));
    ui->txtPassword->setText(QString::fromStdString(""));
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_AdSignOut_clicked()
{
    // ui->txtUsername->setText(QString::fromStdString(""));
    ui->txtPassword->setText(QString::fromStdString(""));
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_StuHome_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_button_StuMyProfile_clicked()
{
    ui->txt_StuID->setText(QString::fromStdString("   " + currStudent->data.ID));
    ui->txt_StuName->setText(QString::fromStdString("   " + currStudent->data.name));
    ui->txt_StuGender->setText(QString::fromStdString("   " + currStudent->data.gender));
    ui->txt_StuBirthday->setText(QString::fromStdString("   " + currStudent->data.birthday));
    ui->txt_StuClass->setText(QString::fromStdString("   " + currStudent->data.mainClass));
    ui->txt_StuSocialID->setText(QString::fromStdString("   " + currStudent->data.socialID));
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::show_tableWidget_list()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    Node<Course>* couCurr = currSem.Courses;
    ui->tableWidget->setColumnCount(9);

    int no = 0;
    while (couCurr) {
        bool check = false;
        for (int i = 0; i < couCurr->data.courseSize; i++) {
            if (couCurr->data.score[i].studentID == currStudent->data.ID) {
                no++;
                check = true;
            }
        }
        if (check) {
            ui->tableWidget->setRowCount(no);
            ui->tableWidget->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(couCurr->data.ID)));
            ui->tableWidget->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(couCurr->data.Name)));
            ui->tableWidget->setItem(no - 1, 2, new QTableWidgetItem(QString::fromStdString(couCurr->data.className)));
            ui->tableWidget->setItem(no - 1, 3, new QTableWidgetItem(QString::fromStdString(couCurr->data.teacherName)));
            ui->tableWidget->setItem(no - 1, 4, new QTableWidgetItem(QString::number(couCurr->data.nCredits)));
            ui->tableWidget->setItem(no - 1, 5, new QTableWidgetItem(QString::number(couCurr->data.courseSize)));
            ui->tableWidget->setItem(no - 1, 6, new QTableWidgetItem(QString::number(couCurr->data.maxStudents)));
            ui->tableWidget->setItem(no - 1, 7, new QTableWidgetItem(QString::fromStdString(couCurr->data.dayOfWeek)));
            ui->tableWidget->setItem(no - 1, 8, new QTableWidgetItem(QString::fromStdString(couCurr->data.session)));
        }
        couCurr = couCurr->next;
    }
    ui->tableWidget->setHorizontalHeaderLabels({"Course ID", "Course Name", "Course Class", "Teacher Name", "Number of Credits", "Course Size","Max Students", "Day of Week", "Session"});
    ui->tableWidget->resizeColumnsToContents();
}
void MainWindow::show_tableWidget_score()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    Node<Course>* couCurr = currSem.Courses;
    ui->tableWidget->setColumnCount(6);

    int no = 0;
    while (couCurr) {
        for (int i = 0; i < couCurr->data.courseSize; i++) {
            if (couCurr->data.score[i].studentID == currStudent->data.ID) {
                no++;
                ui->tableWidget->setRowCount(no);
                ui->tableWidget->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(couCurr->data.ID)));
                ui->tableWidget->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(couCurr->data.Name)));
                if (couCurr->data.score[i].midTerm > 0) ui->tableWidget->setItem(no - 1, 2, new QTableWidgetItem(QString::number(couCurr->data.score[i].midTerm)));
                if (couCurr->data.score[i].final > 0) ui->tableWidget->setItem(no - 1, 3, new QTableWidgetItem(QString::number(couCurr->data.score[i].final)));
                if (couCurr->data.score[i].other > 0) ui->tableWidget->setItem(no - 1, 4, new QTableWidgetItem(QString::number(couCurr->data.score[i].other)));
                if (couCurr->data.score[i].total > 0) ui->tableWidget->setItem(no - 1, 5, new QTableWidgetItem(QString::number(couCurr->data.score[i].total)));
            }
        }
        couCurr = couCurr->next;
    }
    ui->tableWidget->setHorizontalHeaderLabels({"Course ID", "Course Name", "Mid Term", "Final", "Other", "Total"});
    ui->tableWidget->resizeColumnsToContents();
}
void MainWindow::on_button_StuMyCourses_clicked()
{
    init_sy_select();
    show_tableWidget_list();

    ui->stackedWidget_2->setCurrentIndex(2);
}


void MainWindow::on_button_StuChangePassword_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_button_back_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_stackedWidget_2_currentChanged(int arg1)
{
    if (ui->stackedWidget_2->currentIndex() == 0) ui->button_StuHome->setStyleSheet("color: lightgreen;");
    else ui->button_StuHome->setStyleSheet("color: white; :hover{color: black;}");

    if (ui->stackedWidget_2->currentIndex() == 1) ui->button_StuMyProfile->setStyleSheet("color: lightgreen;");
    else ui->button_StuMyProfile->setStyleSheet("color: white; :hover{color: black;}");

    if (ui->stackedWidget_2->currentIndex() == 2) ui->button_StuMyCourses->setStyleSheet("color: lightgreen;");
    else ui->button_StuMyCourses->setStyleSheet("color: white; :hover{color: black;}");

    if (ui->stackedWidget_2->currentIndex() == 3) ui->button_StuChangePassword->setStyleSheet("color: lightgreen;");
    else ui->button_StuChangePassword->setStyleSheet("color: white; :hover{color: black;}");
}

void MainWindow::on_stackedWidget_3_currentChanged(int arg1)
{
    if (ui->stackedWidget_3->currentIndex() == 0) ui->button_AdHome->setStyleSheet("color: lightgreen;");
    else ui->button_AdHome->setStyleSheet("color: white; :hover{color: black;}");

    if (ui->stackedWidget_3->currentIndex() == 1) ui->button_AdMyProfile->setStyleSheet("color: lightgreen;");
    else ui->button_AdMyProfile->setStyleSheet("color: white; :hover{color: black;}");

    if (ui->stackedWidget_3->currentIndex() == 2) ui->button_AdChangePassword->setStyleSheet("color: lightgreen;");
    else ui->button_AdChangePassword->setStyleSheet("color: white; :hover{color: black;}");
}

void MainWindow::on_button_confirm_clicked()
{
    // changeStudentPassword();
    std::string oldPassword, newPassword, confirmPassword;

    oldPassword = ui->txtCurPass->text().toStdString();
    newPassword = ui->txtNewPass->text().toStdString();
    confirmPassword = ui->txtConfirmPass->text().toStdString();

    bool verifyPassword = false;
    if (oldPassword == currStudent->data.password) {
        verifyPassword = true;
    }

    if (!verifyPassword) {
        // std::cout << "Your old password is incorrect!" << std::endl;
        MessageBox("Fail", "Current Password Is Incorrect!");
        return;
    }

    if (newPassword != confirmPassword) {
        // std::cout << "Your new passwords do not match. Please try again!" << std::endl;
        MessageBox("Fail", "New Password Not Matched!");
        return;
    }

    if (newPassword == "")
    {
        MessageBox("Fail", "Password Can Not Be Empty!");
        return;
    }

    if (newPassword.size() < 6)
    {
        MessageBox("Fail", "Password Should Contain At Least 6 Characters!");
        return;
    }

    QMessageBox::information(nullptr, "Success", "Password Changed!", QMessageBox::Ok);
    ui->txtCurPass->setText("");
    ui->txtNewPass->setText("");
    ui->txtConfirmPass->setText("");

    currStudent->data.password = newPassword;
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if (ui->checkBox_2->isChecked())
    {
        ui->txtCurPass->setEchoMode(QLineEdit::Normal);
        ui->txtNewPass->setEchoMode(QLineEdit::Normal);
        ui->txtConfirmPass->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->txtCurPass->setEchoMode(QLineEdit::Password);
        ui->txtNewPass->setEchoMode(QLineEdit::Password);
        ui->txtConfirmPass->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_button_back_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_button_AdMyProfile_clicked()
{
    ui->txt_AdID->setText(QString::fromStdString("   " + currStaff->data.ID));
    ui->txt_AdName->setText(QString::fromStdString("   " + currStaff->data.name));
    ui->txt_AdGender->setText(QString::fromStdString("   " + currStaff->data.gender));
    ui->txt_AdBirthday->setText(QString::fromStdString("   " + currStaff->data.birthday));
    ui->txt_AdSocialID->setText(QString::fromStdString("   " + currStaff->data.socialID));
    ui->stackedWidget_3->setCurrentIndex(1);
}


void MainWindow::on_button_AdChangePassword_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(2);
}


void MainWindow::on_button_AdHome_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_button_confirm_2_clicked()
{
    // changeAdminPassword();
    std::string oldPassword, newPassword, confirmPassword;

    oldPassword = ui->txtCurPass_2->text().toStdString();
    newPassword = ui->txtNewPass_2->text().toStdString();
    confirmPassword = ui->txtConfirmPass_2->text().toStdString();

    bool verifyPassword = false;
    if (oldPassword == currStaff->data.password) {
        verifyPassword = true;
    }

    if (!verifyPassword) {
        // std::cout << "Your old password is incorrect!" << std::endl;
        QMessageBox::critical(nullptr, "Fail", "Current Password Is Incorrect!");
        return;
    }

    if (newPassword != confirmPassword) {
        // std::cout << "Your new passwords do not match. Please try again!" << std::endl;
        QMessageBox::critical(nullptr, "Fail", "New Password Not Matched!");
        return;
    }

    QMessageBox::information(nullptr, "Success", "Password Changed!", QMessageBox::Ok);
    ui->txtCurPass_2->setText("");
    ui->txtNewPass_2->setText("");
    ui->txtConfirmPass_2->setText("");

    currStaff->data.password = newPassword;
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    if (ui->checkBox_3->isChecked())
    {
        ui->txtCurPass_2->setEchoMode(QLineEdit::Normal);
        ui->txtNewPass_2->setEchoMode(QLineEdit::Normal);
        ui->txtConfirmPass_2->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->txtCurPass_2->setEchoMode(QLineEdit::Password);
        ui->txtNewPass_2->setEchoMode(QLineEdit::Password);
        ui->txtConfirmPass_2->setEchoMode(QLineEdit::Password);
    }
}


void MainWindow::on_button_back_3_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_button_back_4_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_button_currentDay_clicked()
{
    QDate currentDate = QDate::currentDate();

    ui->calendarWidget->setCurrentPage(currentDate.year(), currentDate.month());
    ui->calendarWidget->setSelectedDate(currentDate);
}

void MainWindow::init_sy_select()
{
    ui->sy_select->clear();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        ui->sy_select->addItem(QString::fromStdString(syCurr->data.year));
        syCurr = syCurr->next;
    }
}


void MainWindow::on_sy_select_currentTextChanged(const QString& arg1)
{
    ui->sem_select->clear();
    std::string sy = ui->sy_select->currentText().toStdString();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        if (syCurr->data.year == sy)
        {
            int no = 0;
            for (int i = 2; i >= 0; i--)
            {
                if (syCurr->data.semesters[i].isCreated)
                {
                    ui->sem_select->addItem(QString::number(++no));
                    ui->sem_select->setCurrentIndex(no - 1);
                }
            }
            if (no == 0)
            {
                ui->sem_select->addItem("No Semester");
                ui->sem_select->setDisabled(1);
            }
            else ui->sem_select->setDisabled(0);
        }
        syCurr = syCurr->next;
    }
}


void MainWindow::on_button_viewScore_clicked()
{
    MainWindow::on_button_ok_clicked();
    show_tableWidget_score();
}


void MainWindow::on_button_ok_clicked()
{
    // change current semester
    std::string sy = ui->sy_select->currentText().toStdString();
    currSemNumber = ui->sem_select->currentText().toInt();

    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        if (syCurr->data.year == sy)
        {
            currSYear = syCurr;
            currSem = syCurr->data.semesters[currSemNumber - 1];
            break;
        }
        syCurr = syCurr->next;
    }
    show_tableWidget_list();
}

void MainWindow::on_button_back_5_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}


void MainWindow::on_button_create_sy_clicked()
{
    if (lastSemNumber < 2)
    {
        MessageBox("Error!", "Unable To Create New School Year, Semester Is Not Latest!");
    }
    else
    {
        QMessageBox msgBox;

        std::string nextSY = getNextSchoolYear(latestSYear->data.year);
        msgBox.setText(QString::fromStdString("The Next School Year Will Be " + nextSY + ", Do You Want To Continue?"));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

        msgBox.setDefaultButton(QMessageBox::Cancel);
        msgBox.setWindowTitle("Confirmation");
        msgBox.setIcon(QMessageBox::Information);

        int ret = msgBox.exec();
        if (ret == QMessageBox::Ok)
        {
            //create new school year
            SchoolYear newYear;
            newYear.year = nextSY;
            Node<SchoolYear>* syHead = new Node<SchoolYear>(newYear, latestSYear);
            latestSYear = currSYear = syHead;
            lastSemNumber = currSemNumber = 0;

            QMessageBox::information(nullptr, "Notification", "A New School Year Has Been Created!");

            ui->lb_latestSY->setText(QString::fromStdString("Latest School Year: " + latestSYear->data.year));
            ui->lb_latestSem->setText(QString::fromStdString("Latest Semester: " + std::to_string(lastSemNumber)));
        }
        else if (ret == QMessageBox::Cancel)
        {
            return;
        }
    }
}


void MainWindow::on_button_create_sem_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(3);
}

