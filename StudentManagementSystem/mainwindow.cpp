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

    minecraftFont.setPointSize(14);
    ui->button_signin->setFont(minecraftFont);
    ui->button_exit->setFont(minecraftFont);

    minecraftFont.setPointSize(18);
    ui->txtPassword->setFont(minecraftFont);
    ui->txtUsername->setFont(minecraftFont);

    minecraftFont.setPointSize(22);
    minecraftFont.setBold(1);
    ui->lb_username->setFont(minecraftFont);
    ui->lb_password->setFont(minecraftFont);
    minecraftFont.setBold(0);

    minecraftFont.setPointSize(36);
    minecraftFont.setBold(1);
    ui->lb_signin->setFont(minecraftFont);
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
    if (ui->txtUsername->text() != "admin") MessageBox("Error", "Username Not Found!");
    else
    {
        if (ui->txtPassword->text() != "123456") MessageBox("Error", "Wrong Password!");
        else ui->stackedWidget->setCurrentIndex(1);
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

