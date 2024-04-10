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

    void init_sy_select();

    void on_sy_select_currentTextChanged(const QString &arg1);

    void on_button_viewScore_clicked();

    void show_tableWidget_list();

    void show_tableWidget_score();

    void on_button_ok_clicked();

    void on_button_back_5_clicked();

    void on_button_create_sy_clicked();

    void on_button_create_sem_clicked();

    void on_button_currentDate_clicked();

    void on_button_setStartDate_clicked();

    void on_button_setEndDate_clicked();

    void on_button_back_6_clicked();

    void on_button_confirm_3_clicked();

    void on_button_class_manage_clicked();

    void on_button_createClass_clicked();

    void on_box_selectSY_currentTextChanged(const QString &arg1);

    void on_button_confirm_4_clicked();

    void on_button_back_8_clicked();

    void on_button_addStudent_clicked();

    void on_button_back_9_clicked();

    void on_button_addOne_clicked();

    void on_button_import_clicked();

    void on_button_openCalendar_clicked();

    void on_button_selectDate_clicked();

    void on_box_selectClass_currentTextChanged(const QString &arg1);

    void on_button_confirm_5_clicked();

    void on_button_cancel_clicked();

    void on_button_cancel_2_clicked();

    void on_button_confirm_6_clicked();

    void importCSVStudentsOfAClass_2(Node<Class>* claCurr, std::string fileName);

    void on_button_back_7_clicked();

    void on_button_allClasses_clicked();

    void on_pushButton_clicked();

    void on_list_classes_2_itemClicked(QListWidgetItem *item);

    void on_button_scoreOfClass_clicked();

    void on_box_class_currentTextChanged(const QString &arg1);

    void on_box_year_currentTextChanged(const QString &arg1);

    void on_button_ok_2_clicked();

    Node<Class>* ChooseClass_2(std::string className);

    void on_box_semester_currentTextChanged(const QString &arg1);

    void on_sem_select_currentTextChanged(const QString &arg1);

    void on_button_courseSetting_clicked();

    void on_button_courseView_clicked();

    void on_button_removeFilter_clicked();

    void on_button_course_manage_clicked();

    void on_button_ok_3_clicked();

    void on_box_selectSY_2_currentTextChanged(const QString &arg1);

    void on_box_selectSem_currentTextChanged(const QString &arg1);

    void on_button_viewStudent_clicked();

    void on_button_coursesList_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
