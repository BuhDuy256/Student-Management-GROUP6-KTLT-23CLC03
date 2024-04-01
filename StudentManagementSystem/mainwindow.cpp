#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    QFontDatabase::addApplicationFont(":/MinecraftRegular-Bmg3.ttf");
    QFont minecraftFont("Minecraft");

    minecraftFont.setPointSize(12);
    ui->checkBox->setFont(minecraftFont);
    ui->checkBox_2->setFont(minecraftFont);


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
    ui->button_back->setFont(minecraftFont);


    minecraftFont.setPointSize(18);
    ui->txtPassword->setFont(minecraftFont);
    ui->txtUsername->setFont(minecraftFont);
    ui->txtCurPass->setFont(minecraftFont);
    ui->txtNewPass->setFont(minecraftFont);
    ui->txtConfirmPass->setFont(minecraftFont);
    minecraftFont.setBold(1);
    ui->name->setFont(minecraftFont);
    ui->lb_curPass->setFont(minecraftFont);
    ui->lb_newPass->setFont(minecraftFont);
    ui->lb_confirmPass->setFont(minecraftFont);
    minecraftFont.setBold(0);


    minecraftFont.setPointSize(22);
    minecraftFont.setBold(1);
    ui->lb_username->setFont(minecraftFont);
    ui->lb_password->setFont(minecraftFont);
    minecraftFont.setBold(0);


    minecraftFont.setPointSize(36);
    minecraftFont.setBold(1);
    ui->lb_signin->setFont(minecraftFont);
    ui->lb_changePass->setFont(minecraftFont);
    minecraftFont.setBold(0);
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
    // if (ui->txtUsername->text() != "admin") MessageBox("Error", "Username Not Found!");
    // else
    // {
    //     if (ui->txtPassword->text() != "123456") MessageBox("Error", "Wrong Password!");
    //     else ui->stackedWidget->setCurrentIndex(1);
    // }
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


void MainWindow::on_txtUsername_textEdited(const QString &arg1)
{
    if (ui->txtUsername->text() == "" || ui->txtPassword->text() == "") ui->button_signin->setDisabled(1);
    else ui->button_signin->setDisabled(0);
}


void MainWindow::on_txtPassword_textEdited(const QString &arg1)
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
    // ui->txtPassword->setText(QString::fromStdString(""));
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_AdSignOut_clicked()
{
    // ui->txtUsername->setText(QString::fromStdString(""));
    // ui->txtPassword->setText(QString::fromStdString(""));
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_button_StuHome_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void MainWindow::on_button_StuMyProfile_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_button_StuMyCourses_clicked()
{
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

