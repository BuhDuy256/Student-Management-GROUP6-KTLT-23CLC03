#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "system.h"
#include <QApplication>
#include <QtWidgets>
#include <QFontDatabase>
#include <QFont>
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QCalendarWidget>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_checkBox_stateChanged(int arg1);

    void on_button_signin_clicked();

    void on_txtUsername_textEdited(const QString &arg1);

    void on_txtPassword_textEdited(const QString &arg1);

    void on_button_exit_clicked();

    void on_button_StuSignOut_clicked();

    void on_button_AdSignOut_clicked();

    void on_button_StuChangePassword_clicked();

    void on_button_StuHome_clicked();

    void on_button_back_clicked();

    void on_stackedWidget_2_currentChanged(int arg1);

    void on_button_confirm_clicked();

    void on_checkBox_2_stateChanged(int arg1);

    void on_button_StuMyProfile_clicked();

    void on_button_StuMyCourses_clicked();

    void on_button_back_2_clicked();

    void on_stackedWidget_3_currentChanged(int arg1);

    void on_button_AdMyProfile_clicked();

    void on_button_AdChangePassword_clicked();

    void on_button_AdHome_clicked();

    void on_button_confirm_2_clicked();

    void on_checkBox_3_stateChanged(int arg1);

    void on_button_back_3_clicked();

    void on_button_back_4_clicked();

    void on_button_currentDay_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
