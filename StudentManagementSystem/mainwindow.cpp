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

    ui->tableWidget->setStyleSheet(QString(ui->tableWidget->styleSheet() + "QTableWidget { font-family: %1;font-size: 14px;}"
                                      "QTableWidget QHeaderView::section {font-family: %1; font-size: 14px;}").arg(fontName));
    ui->table_scoreboard->setStyleSheet(QString(ui->table_scoreboard->styleSheet() + "QTableWidget { font-family: %1;font-size: 14px;}"
                                                                           "QTableWidget QHeaderView::section {font-family: %1; font-size: 14px;}").arg(fontName));

    ui->table_student->setStyleSheet(QString(ui->table_student->styleSheet() + "QTableWidget { font-family: %1; }"
                                                                             "QTableWidget QHeaderView::section { font-family: %1; font-size: 14px;}").arg(fontName));
    ui->tableWidget_2->setStyleSheet(QString(ui->tableWidget_2->styleSheet() + "QTableWidget { font-family: %1; }"
                                                                             "QTableWidget QHeaderView::section {font-family: %1; font-size: 14px;}").arg(fontName));
    ui->table_course->setStyleSheet(QString(ui->table_course->styleSheet() + "QTableWidget { font-family: %1; font-size: 14px;}"
                                                                               "QTableWidget QHeaderView::section {font-family: %1; font-size: 14px;}").arg(fontName));
    ui->table_student_2->setStyleSheet(QString(ui->table_student_2->styleSheet() + "QTableWidget { font-family: %1; font-size: 14px;}"
                                                                             "QTableWidget QHeaderView::section {font-family: %1; font-size: 14px;}").arg(fontName));

    ui->calendarWidget_3->setStyleSheet(QString(ui->calendarWidget_3->styleSheet() + "QMenu { font-family: %1;}"
                                                                                     "QWidget#qt_calendar_navigationbar {font-family: %1}"
                                                                                     "QCalendarWidget { font-family: %1;}").arg(fontName));
    ui->calendarWidget_2->setStyleSheet(QString(ui->calendarWidget_2->styleSheet() + "QMenu { font-family: %1;}"
                                                                                     "QWidget#qt_calendar_navigationbar {font-family: %1}"
                                                                                     "QCalendarWidget { font-family: %1;}").arg(fontName));
    ui->calendarWidget->setStyleSheet(QString(ui->calendarWidget->styleSheet() + "QMenu { font-family: %1;}"
                                                                                       "QWidget#qt_calendar_navigationbar {font-family: %1}"
                                                                                       "QCalendarWidget { font-family: %1;}").arg(fontName));


    minecraftFont.setPointSize(9);


    minecraftFont.setPointSize(12);
    ui->checkBox->setFont(minecraftFont);
    ui->checkBox_2->setFont(minecraftFont);
    ui->checkBox_3->setFont(minecraftFont);
    ui->button_currentDay->setFont(minecraftFont);
    ui->sem_select->setFont(minecraftFont);
    ui->sy_select->setFont(minecraftFont);


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
    ui->button_viewScore->setFont(minecraftFont);
    ui->button_back_5->setFont(minecraftFont);
    ui->lb_selectSY->setFont(minecraftFont);
    ui->lb_enterClassName->setFont(minecraftFont);
    ui->button_confirm_4->setFont(minecraftFont);
    ui->button_back_8->setFont(minecraftFont);
    ui->button_selectDate->setFont(minecraftFont);
    ui->button_confirm_6->setFont(minecraftFont);
    ui->button_cancel_2->setFont(minecraftFont);
    ui->button_confirm_5->setFont(minecraftFont);
    ui->button_cancel->setFont(minecraftFont);
    ui->button_addOne->setFont(minecraftFont);
    ui->button_back_10->setFont(minecraftFont);
    ui->button_ok_2->setFont(minecraftFont);
    ui->button_back_9->setFont(minecraftFont);
    ui->button_allClasses->setFont(minecraftFont);
    ui->button_createClass->setFont(minecraftFont);
    ui->button_addStudent->setFont(minecraftFont);
    ui->button_scoreOfClass->setFont(minecraftFont);
    ui->button_back_7->setFont(minecraftFont);
    ui->button_coursesList->setFont(minecraftFont);
    ui->button_viewStudent->setFont(minecraftFont);
    ui->button_removeFilter->setFont(minecraftFont);
    ui->button_back_11->setFont(minecraftFont);
    ui->button_create_sy->setFont(minecraftFont);
    ui->button_create_sem->setFont(minecraftFont);
    ui->button_course_manage->setFont(minecraftFont);
    ui->button_class_manage->setFont(minecraftFont);
    ui->button_setStartDate->setFont(minecraftFont);
    ui->button_setEndDate->setFont(minecraftFont);
    ui->button_confirm_3->setFont(minecraftFont);
    ui->button_back_6->setFont(minecraftFont);
    ui->button_currentDate->setFont(minecraftFont);
    ui->button_back_12->setFont(minecraftFont);
    ui->button_addCourse->setFont(minecraftFont);
    ui->button_removeCourse->setFont(minecraftFont);
    ui->button_addStudent_2->setFont(minecraftFont);
    ui->button_removeStudent->setFont(minecraftFont);
    ui->button_importScoreBoard->setFont(minecraftFont);
    ui->button_coursesList->setFont(minecraftFont);
    ui->button_exportTable->setFont(minecraftFont);
    ui->button_confirm_7->setFont(minecraftFont);
    ui->button_back_13->setFont(minecraftFont);
    ui->pushButton_3->setFont(minecraftFont);
    ui->pushButton_4->setFont(minecraftFont);

    minecraftFont.setPointSize(16);
    ui->slogan_1->setFont(minecraftFont);
    ui->slogan_2->setFont(minecraftFont);
    ui->slogan_3->setFont(minecraftFont);
    ui->button_ok->setFont(minecraftFont);
    ui->box_selectSY->setFont(minecraftFont);
    ui->lb_allClassesIn->setFont(minecraftFont);
    ui->lb_addStuID->setFont(minecraftFont);
    ui->lb_addGender->setFont(minecraftFont);
    ui->lb_addBirthday->setFont(minecraftFont);
    ui->lb_addName->setFont(minecraftFont);
    ui->lb_addSocialID->setFont(minecraftFont);
    ui->lb_selectClass->setFont(minecraftFont);
    ui->box_selectClass->setFont(minecraftFont);
    ui->lb_enterPath->setFont(minecraftFont);
    ui->box_year->setFont(minecraftFont);
    ui->box_semester->setFont(minecraftFont);
    ui->box_class->setFont(minecraftFont);
    ui->label->setFont(minecraftFont);
    ui->label_2->setFont(minecraftFont);
    ui->box_selectSY_2->setFont(minecraftFont);
    ui->box_selectSem->setFont(minecraftFont);

    ui->box_session->setFont(minecraftFont);
    ui->box_numCredits->setFont(minecraftFont);
    ui->box_dayOfWeek->setFont(minecraftFont);
    ui->tableWidget_2->setFont(minecraftFont);

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
    ui->txt_className->setFont(minecraftFont);

    ui->txt_addBirthday->setFont(minecraftFont);
    ui->txt_addID->setFont(minecraftFont);
    ui->txt_addName->setFont(minecraftFont);
    ui->txt_addSocialID->setFont(minecraftFont);
    ui->txt_path->setFont(minecraftFont);
    ui->txt_startDate->setFont(minecraftFont);
    ui->txt_endDate->setFont(minecraftFont);

    ui->txt_studentName->setFont(minecraftFont);
    ui->txt_studentID->setFont(minecraftFont);
    ui->txt_courseID->setFont(minecraftFont);
    ui->txt_courseName->setFont(minecraftFont);
    ui->txt_className_2->setFont(minecraftFont);
    ui->txt_teacherName->setFont(minecraftFont);
    ui->txt_maxStudents->setFont(minecraftFont);

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
    ui->lb_latestSem->setFont(minecraftFont);
    ui->lb_latestSY->setFont(minecraftFont);
    ui->lb_courseID->setFont(minecraftFont);
    ui->lb_courseName->setFont(minecraftFont);
    ui->lb_className->setFont(minecraftFont);
    ui->lb_teacherName->setFont(minecraftFont);
    ui->lb_maxStudents->setFont(minecraftFont);
    ui->lb_numCredits->setFont(minecraftFont);
    ui->lb_session->setFont(minecraftFont);
    ui->lb_studentID->setFont(minecraftFont);
    ui->lb_studentName->setFont(minecraftFont);
    minecraftFont.setBold(0); //End Bold Region


    minecraftFont.setPointSize(22);
    ui->box_addGender->setFont(minecraftFont);
    minecraftFont.setBold(1); // Bold Region
    ui->lb_username->setFont(minecraftFont);
    ui->lb_password->setFont(minecraftFont);
    ui->list_classes_2->setFont(minecraftFont);
    ui->list_classes->setFont(minecraftFont);
    ui->lb_curClass->setFont(minecraftFont);
    ui->lb_class->setFont(minecraftFont);
    ui->lb_latestSED->setFont(minecraftFont);
    ui->lb_scoreBoard->setFont(minecraftFont);
    ui->label_3->setFont(minecraftFont);
    ui->lb_addCourse->setFont(minecraftFont);
    ui->lb_courseData->setFont(minecraftFont);
    minecraftFont.setBold(0); //End Bold Region


    minecraftFont.setPointSize(36);
    minecraftFont.setBold(1); // Bold Region
    ui->lb_signin->setFont(minecraftFont);
    ui->lb_changePass->setFont(minecraftFont);
    ui->lb_MyProfile->setFont(minecraftFont);
    ui->lb_MyCourses->setFont(minecraftFont);
    ui->lb_changePass_2->setFont(minecraftFont);
    ui->lb_MyProfile_2->setFont(minecraftFont);
    ui->lb_allClasses->setFont(minecraftFont);
    ui->lb_createNewClass->setFont(minecraftFont);
    ui->lb_viewScoreboard->setFont(minecraftFont);
    ui->lb_addNewStudent->setFont(minecraftFont);
    ui->lb_addNewStudent->setFont(minecraftFont);
    ui->lb_classManage->setFont(minecraftFont);
    ui->lb_courseView->setFont(minecraftFont);
    ui->lb_createNewSemester->setFont(minecraftFont);
    minecraftFont.setBold(0); //End Bold Region

    minecraftFont.setPointSize(48);
    minecraftFont.setBold(1); // Bold region
    ui->lb_welcome->setFont(minecraftFont);
    ui->lb_welcome_2->setFont(minecraftFont);
    minecraftFont.setBold(0); // End Bold region

    QTextCharFormat weekendFormat;
    weekendFormat.setForeground(QColor("#7FFFD4"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::Saturday, weekendFormat);
    ui->calendarWidget->setWeekdayTextFormat(Qt::Sunday, weekendFormat);
    ui->calendarWidget_2->setWeekdayTextFormat(Qt::Saturday, weekendFormat);
    ui->calendarWidget_2->setWeekdayTextFormat(Qt::Sunday, weekendFormat);
    ui->calendarWidget_3->setWeekdayTextFormat(Qt::Saturday, weekendFormat);
    ui->calendarWidget_3->setWeekdayTextFormat(Qt::Sunday, weekendFormat);

    ui->table_student->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_student->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_student_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_student_2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_course->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_course->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_scoreboard->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->table_scoreboard->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MessageBox(std::string title, std::string text)
{
    int fontId = QFontDatabase::addApplicationFont(":/font/MinecraftRegular-Bmg3.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont minecraftFont(fontName);
    minecraftFont.setPointSize(15);

    QMessageBox reply;
    reply.setStandardButtons(QMessageBox::Ok);
    reply.setIcon(QMessageBox::Critical);
    reply.setFont(minecraftFont);
    reply.setWindowTitle(QString::fromStdString(title));
    reply.setText(QString::fromStdString(text));

    reply.exec();

    // reply = QMessageBox::critical(nullptr, QString::fromStdString(title), QString::fromStdString(text), QMessageBox::Ok);
}
void MessageBox_information(std::string title, std::string text)
{
    int fontId = QFontDatabase::addApplicationFont(":/font/MinecraftRegular-Bmg3.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont minecraftFont(fontName);
    minecraftFont.setPointSize(15);

    QMessageBox reply;
    reply.setStandardButtons(QMessageBox::Ok);
    reply.setIcon(QMessageBox::Information);
    reply.setFont(minecraftFont);
    reply.setWindowTitle(QString::fromStdString(title));
    reply.setText(QString::fromStdString(text));

    reply.exec();

    // reply = QMessageBox::critical(nullptr, QString::fromStdString(title), QString::fromStdString(text), QMessageBox::Ok);
}
int MessageBox_ok_cancel(std::string title, std::string text)
{
    int fontId = QFontDatabase::addApplicationFont(":/font/MinecraftRegular-Bmg3.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont minecraftFont(fontName);
    minecraftFont.setPointSize(15);

    QMessageBox msgBox;

    msgBox.setText(QString::fromStdString(text));
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setFont(minecraftFont);

    msgBox.setDefaultButton(QMessageBox::Cancel);
    msgBox.setWindowTitle(QString::fromStdString(title));
    msgBox.setIcon(QMessageBox::Information);

    return msgBox.exec();
}

void MainWindow::resizeTable(QTableWidget* tableWidget)
{
    tableWidget->resizeColumnsToContents();
    // Get the width of the table widget
    int tableWidth = tableWidget->viewport()->width();

    // Get the total width of all the columns
    int totalColumnWidth = 0;
    int columnCount = tableWidget->columnCount();
    for (int col = 0; col < columnCount; ++col) {
        totalColumnWidth += tableWidget->columnWidth(col);
    }

    // Check if the total width of columns is larger than the width of the table
    if (totalColumnWidth < tableWidth) {
        // Resize columns to fit their contents
        tableWidget->resizeColumnsToContents();

        // Get the total width of all the columns after resizing
        totalColumnWidth = 0;
        for (int col = 0; col < columnCount; ++col) {
            totalColumnWidth += tableWidget->columnWidth(col);
        }

        // Get the width of the vertical scroll bar
        int verticalScrollBarWidth = tableWidget->verticalScrollBar()->isVisible() ? tableWidget->verticalScrollBar()->width() : 0;

        // Calculate the available width (excluding the width of the vertical scroll bar)
        int availableWidth = tableWidth - verticalScrollBarWidth;

        // Calculate the remaining space to be distributed among columns
        int remainingSpace = availableWidth - totalColumnWidth;

        // Calculate the width to be added to each column
        int extraWidthPerColumn = remainingSpace / columnCount;

        // Distribute the remaining space evenly among columns
        for (int col = 0; col < columnCount; ++col) {
            int newWidth = tableWidget->columnWidth(col) + extraWidthPerColumn;
            tableWidget->setColumnWidth(col, newWidth);
        }
    }
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

    resizeTable(ui->tableWidget);
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

    resizeTable(ui->tableWidget);
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
    else ui->button_StuHome->setStyleSheet("color: white;");

    if (ui->stackedWidget_2->currentIndex() == 1) ui->button_StuMyProfile->setStyleSheet("color: lightgreen;");
    else ui->button_StuMyProfile->setStyleSheet("color: white;");

    if (ui->stackedWidget_2->currentIndex() == 2) ui->button_StuMyCourses->setStyleSheet("color: lightgreen;");
    else ui->button_StuMyCourses->setStyleSheet("color: white;");

    if (ui->stackedWidget_2->currentIndex() == 3) ui->button_StuChangePassword->setStyleSheet("color: lightgreen;");
    else ui->button_StuChangePassword->setStyleSheet("color: white;");
}

void MainWindow::on_stackedWidget_3_currentChanged(int arg1)
{
    if (ui->stackedWidget_3->currentIndex() == 0) ui->button_AdHome->setStyleSheet("color: lightgreen;");
    else ui->button_AdHome->setStyleSheet("color: white;");

    if (ui->stackedWidget_3->currentIndex() == 1) ui->button_AdMyProfile->setStyleSheet("color: lightgreen;");
    else ui->button_AdMyProfile->setStyleSheet("color: white;");

    if (ui->stackedWidget_3->currentIndex() == 2) ui->button_AdChangePassword->setStyleSheet("color: lightgreen;");
    else ui->button_AdChangePassword->setStyleSheet("color: white;");
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
    if (lastSemNumber < 3)
    {
        MessageBox("Error!", "Unable To Create New School Year, Semester Is Not Latest!");
    }
    else
    {
        // QMessageBox msgBox;

        std::string nextSY = getNextSchoolYear(latestSYear->data.year);
        // msgBox.setText(QString::fromStdString("The Next School Year Will Be " + nextSY + ", Do You Want To Continue?"));
        // msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

        // msgBox.setDefaultButton(QMessageBox::Cancel);
        // msgBox.setWindowTitle("Confirmation");
        // msgBox.setIcon(QMessageBox::Information);

        int ret = MessageBox_ok_cancel("Confirmation", "The Next School Year Will Be " + nextSY + ", Do You Want To Continue?");
        if (ret == QMessageBox::Ok)
        {
            //create new school year
            SchoolYear newYear;
            newYear.year = nextSY;
            Node<SchoolYear>* syHead = new Node<SchoolYear>(newYear, latestSYear);
            latestSYear = currSYear = syHead;
            lastSemNumber = currSemNumber = 0;

            MessageBox_information("Notification", "A New School Year Has Been Created!");

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
    ui->lb_latestSED->setText(QString::fromStdString("Latest Semester End Date: " + latestSem.endDate));
}


void MainWindow::on_button_currentDate_clicked()
{
    QDate currentDate = QDate::currentDate();

    ui->calendarWidget_2->setCurrentPage(currentDate.year(), currentDate.month());
    ui->calendarWidget_2->setSelectedDate(currentDate);
}


void MainWindow::on_button_setStartDate_clicked()
{
    QDate selectedDate = ui->calendarWidget_2->selectedDate();

    ui->txt_startDate->setText(selectedDate.toString("dd/MM/yyyy"));
}


void MainWindow::on_button_setEndDate_clicked()
{
    QDate selectedDate = ui->calendarWidget_2->selectedDate();

    ui->txt_endDate->setText(selectedDate.toString("dd/MM/yyyy"));
}


void MainWindow::on_button_back_6_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_button_confirm_3_clicked()
{
    if (lastSemNumber >= 3)
    {
        MessageBox("Error", "Current School Year Is Full Of Semesters!\n Let's Create A New School Year!");
        return;
    }

    std::string startDate = ui->txt_startDate->text().toStdString();
    std::string endDate = ui->txt_endDate->text().toStdString();

    int diff = daysBetweenDates(startDate, latestSem.endDate);
    if (diff < 1)
    {
        MessageBox("Error", "Start Date Must Be Later Than The End Date Of The Previous Semester!");
        ui->txt_startDate->setText("");
        ui->txt_endDate->setText("");
        return;
    }

    diff = daysBetweenDates(endDate, startDate);
    if (diff < 1)
    {
        MessageBox("Error", "End Date Must Be Later Than Start Date!");
        ui->txt_startDate->setText("");
        ui->txt_endDate->setText("");
        return;
    }

    diff = daysBetweenDates(endDate, startDate);
    if ((diff < 90) || (diff > 150))
    {
        MessageBox("Error", "The Duration Of A Semester Must Be Between 90 Days (~3 Months) And 150 Days (~5 Months)!");
        ui->txt_startDate->setText("");
        ui->txt_endDate->setText("");
        return;
    }

    latestSYear->data.semesters[lastSemNumber].isCreated = true;
    latestSYear->data.semesters[lastSemNumber].startDate = startDate;
    latestSYear->data.semesters[lastSemNumber].endDate = endDate;
    latestSem = currSem = latestSYear->data.semesters[lastSemNumber];
    lastSemNumber++;
    currSemNumber = lastSemNumber;
    QMessageBox::information(nullptr, "Notification", "Semester Created Successfully!");
    ui->lb_latestSY->setText(QString::fromStdString("Latest School Year: " + latestSYear->data.year));
    ui->lb_latestSem->setText(QString::fromStdString("Latest Semester: " + std::to_string(lastSemNumber)));
    ui->lb_latestSED->setText(QString::fromStdString("Latest Semester End Date: " + latestSem.endDate));

    ui->txt_startDate->setText("");
    ui->txt_endDate->setText("");
}


void MainWindow::on_button_class_manage_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}


void MainWindow::on_button_createClass_clicked()
{
    ui->box_selectSY->clear();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        ui->box_selectSY->addItem(QString::fromStdString(syCurr->data.year));
        syCurr = syCurr->next;
    }

    ui->stackedWidget_3->setCurrentIndex(5);
}


void MainWindow::on_box_selectSY_currentTextChanged(const QString &arg1)
{
    std::string sy = ui->box_selectSY->currentText().toStdString();

    ui->lb_allClassesIn->setText(QString::fromStdString("All Classes In " + sy));

    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        if (syCurr->data.year == sy)
        {
            currSYear = syCurr;
            break;
        }
        syCurr = syCurr->next;
    }

    ui->list_classes->clear();
    Node<Class>* claCurr = currSYear->data.classes;
    if (!claCurr)
    {
        QListWidgetItem* item = new QListWidgetItem("No Class");
        item->setTextAlignment(Qt::AlignHCenter);
        ui->list_classes->addItem(item);
    }
    else while (claCurr)
    {
        // std::cout << std::left << "\t| " << std::setw(8) << no << "| " << std::setw(19) << claCurr->data.className << "|\n";
        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(claCurr->data.className));
        item->setTextAlignment(Qt::AlignHCenter);
        ui->list_classes->addItem(item);
        claCurr = claCurr->next;
    }

    if (sy.size() > 0)
        ui->txt_className->setPlaceholderText(QString::fromStdString("Example: " + sy.substr(2, 2) + "CLC04, " + sy.substr(2, 2) + "APCS09, etc."));
}


void MainWindow::on_button_confirm_4_clicked()
{
    std::string className = ui->txt_className->text().toStdString();

    if (!isValidClassName(className, currSYear->data.year))
    {
        MessageBox("Error", "Invalid Class Name!");
        return;
    }
    if (isClassExisted(className))
    {
        MessageBox("Error", "Class Is Already In The System!");
        return;
    }

    Class newClass;
    newClass.className = className;
    newClass.schoolYear = currSYear->data.year;
    Node<Class>* claHead = new Node<Class>(newClass, currSYear->data.classes);
    currSYear->data.classes = claHead;

    QMessageBox::information(nullptr, "Notification", "A New Class Created Successfully!");
    MainWindow::on_box_selectSY_currentTextChanged("0");
}


void MainWindow::on_button_back_8_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}


void MainWindow::on_button_addStudent_clicked()
{
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr)
        {
            ui->box_selectClass->addItem(QString::fromStdString(claCurr->data.className));
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }

    ui->stackedWidget_3->setCurrentIndex(6);
    ui->stackedWidget_4->setCurrentIndex(0);
}



void MainWindow::on_button_back_9_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}


void MainWindow::on_button_addOne_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_button_import_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(1);
}


void MainWindow::on_button_openCalendar_clicked()
{
    ui->stackedWidget_4->setCurrentIndex(2);
}


void MainWindow::on_button_selectDate_clicked()
{
    QDate selectedDate = ui->calendarWidget_3->selectedDate();

    ui->txt_addBirthday->setText(selectedDate.toString("dd/MM/yyyy"));

    ui->stackedWidget_4->setCurrentIndex(0);
}


void MainWindow::on_box_selectClass_currentTextChanged(const QString &arg1)
{
    ui->tableWidget_2->setRowCount(0);
    std::string className = ui->box_selectClass->currentText().toStdString();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr)
        {
            if (claCurr->data.className == className)
            {
                // displayTableOfStudentsInAClass(claCurr, no2);
                Node<Student>* currStu = claCurr->data.students;
                int no = 0;
                while (currStu)
                {
                    no++;
                    ui->tableWidget_2->setRowCount(no);
                    ui->tableWidget_2->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(currStu->data.ID)));
                    ui->tableWidget_2->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(currStu->data.name)));
                    ui->tableWidget_2->setItem(no - 1, 2, new QTableWidgetItem(QString::fromStdString(currStu->data.gender)));
                    ui->tableWidget_2->setItem(no - 1, 3, new QTableWidgetItem(QString::fromStdString(currStu->data.socialID)));

                    currStu = currStu->next;
                }
                break;
            }
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
    ui->tableWidget_2->resizeColumnsToContents();
}


void MainWindow::on_button_confirm_5_clicked()
{
    std::string className = ui->box_selectClass->currentText().toStdString();
    Node<Class>* claCurr = latestSYear->data.classes;
    Node<SchoolYear>* tempYear = latestSYear;
    while(tempYear)
    {
        while (claCurr)
        {
            if (claCurr->data.className == className)
            {
                break;
            }
            claCurr = claCurr->next;
        }
        tempYear = tempYear->next;
    }

    std::string newStudentID = ui->txt_addID->text().toStdString();
    std::string newStudentName = ui->txt_addName->text().toStdString();
    std::string newStudentGender = ui->box_addGender->currentText().toStdString();
    std::string newStudentBirthday = ui->txt_addBirthday->text().toStdString();
    std::string newStudentSocialID = ui->txt_addSocialID->text().toStdString();
    if (!isValidStudentID(newStudentID))
    {
        MessageBox("Error", "Student ID Must Be A 8-Digit Number!");
        return;
    }
    
     Node<SchoolYear>* checkExist = latestSYear;
    while(checkExist)
    {
        Node<Class>* ClassesInSY = checkExist->data.classes;
        while(ClassesInSY)
        {
            Node<Student>* StuInClass = ClassesInSY->data.students;
            while(StuInClass)
            {
                if(StuInClass->data.ID == newStudentID || StuInClass->data.socialID == newStudentSocialID)
                {
                    MessageBox("Error", "Student already studies in class" + ClassesInSY->data.className);
                    return;
                }
                StuInClass = StuInClass->next;
            }
            ClassesInSY = ClassesInSY->next;
        }
        checkExist = checkExist->next;
    }

    if (!isValidCouOrStuName(newStudentName))
    {
        MessageBox("Error", "Invalid Name!");
        return;
    }
    formalize(newStudentName);
    
    if (newStudentSocialID.length() != 8)
    {
        MessageBox("Error", "Social ID Must Be A 8-Digit Number!");
        return;
    }
    
    Student newStudent;
    newStudent.ID = newStudentID;
    newStudent.name = newStudentName;
    newStudent.gender = newStudentGender;
    newStudent.birthday = newStudentBirthday;
    newStudent.socialID = newStudentSocialID;
    newStudent.mainClass = claCurr->data.className;
    if (!claCurr->data.students)
    {
        claCurr->data.students = new Node<Student>(newStudent);
    }
    else
    {
        Node<Student>* stuCurr = claCurr->data.students;
        while (stuCurr->next)
            stuCurr = stuCurr->next;
        stuCurr->next = new Node<Student>(newStudent);
    }

    ui->txt_addID->setText("");
    ui->txt_addName->setText("");
    ui->txt_addBirthday->setText("");
    ui->txt_addSocialID->setText("");

    QMessageBox::information(nullptr, "Notification", "A New Student Added Successfully!");
}


void MainWindow::on_button_cancel_clicked()
{
    ui->txt_addID->setText("");
    ui->txt_addName->setText("");
    ui->txt_addBirthday->setText("");
    ui->txt_addSocialID->setText("");
}


void MainWindow::on_button_cancel_2_clicked()
{
    ui->txt_path->setText("");
}


void MainWindow::importCSVStudentsOfAClass_2(Node<Class>* claCurr, std::string fileName)
{
    QFile file(QString::fromStdString(fileName));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        MessageBox("Error", "Fail To Open File!");
        return;
    }
    QTextStream inF(&file);

    if (!claCurr->data.students)
    {
        // Pass the header
        QString header = inF.readLine();

        while (!inF.atEnd()) {
            QString Line = inF.readLine();
            std::string line = Line.toStdString();
            // Check if the line is empty or contains only whitespace
            if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
                break; // Stop reading if the line is empty
            }

            Student newStu;
            std::stringstream ss(line);
            std::string NO; std::getline(ss, NO, ','); // don't use
            std::getline(ss, newStu.ID, ',');
            std::string firstName, lastName;
            std::getline(ss, firstName, ',');
            std::getline(ss, lastName, ',');
            newStu.name = lastName + (firstName.empty() ? "" : " " + firstName);
            std::getline(ss, newStu.gender, ',');
            std::getline(ss, newStu.birthday, ',');
            std::getline(ss, newStu.socialID, ',');
            newStu.mainClass = claCurr->data.className;
            if (!claCurr->data.students) {
                claCurr->data.students = new Node<Student>(newStu);
            }
            else {
                Node<Student>* stuCurr = claCurr->data.students;
                while (stuCurr->next)
                    stuCurr = stuCurr->next;
                stuCurr->next = new Node<Student>(newStu);
            }
        }
        QMessageBox::information(nullptr, "Notification", "Import CSV Successfully!");

    }
    else {
        MessageBox("Error", "You Can Only Import CSV When The Class Has Had No Student Yet");
    }
    file.close();
}
void MainWindow::on_button_confirm_6_clicked()
{
    std::string path = ui->txt_path->text().toStdString();
    std::string className = ui->box_selectClass->currentText().toStdString();

    Node<SchoolYear>* syHead = currSYear;
    int count = 0;
    while (syHead) {
        Node<Class>* claHead = syHead->data.classes;
        while (claHead)
        {
            if (claHead->data.className == className)
            {
                importCSVStudentsOfAClass_2(claHead, path);
                return;
            }
            claHead = claHead->next;
        }
        syHead = syHead->next;
    }
}


void MainWindow::on_button_back_7_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}


void MainWindow::on_button_allClasses_clicked()
{
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr)
        {
            QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(claCurr->data.className));
            item->setTextAlignment(Qt::AlignHCenter);
            ui->list_classes_2->addItem(item);
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }

    ui->stackedWidget_3->setCurrentIndex(7);
}


void MainWindow::on_button_back_12_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}


void MainWindow::on_list_classes_2_itemClicked(QListWidgetItem *item)
{
    ui->table_student->setRowCount(0);
    std::string className = item->text().toStdString();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr)
        {
            if (claCurr->data.className == className)
            {
                // displayTableOfStudentsInAClass(claCurr, no2);
                Node<Student>* currStu = claCurr->data.students;
                int no = 0;
                while (currStu)
                {
                    no++;
                    ui->table_student->setRowCount(no);
                    ui->table_student->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(currStu->data.ID)));
                    ui->table_student->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(currStu->data.name)));
                    ui->table_student->setItem(no - 1, 2, new QTableWidgetItem(QString::fromStdString(currStu->data.gender)));
                    ui->table_student->setItem(no - 1, 3, new QTableWidgetItem(QString::fromStdString(currStu->data.birthday)));
                    ui->table_student->setItem(no - 1, 4, new QTableWidgetItem(QString::fromStdString(currStu->data.socialID)));

                    currStu = currStu->next;
                }
                break;
            }
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }
    ui->table_student->resizeColumnsToContents();

    ui->lb_curClass->setText(QString::fromStdString(className));
}


void MainWindow::on_button_scoreOfClass_clicked()
{
    ui->box_class->clear();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        Node<Class>* claCurr = syCurr->data.classes;
        while (claCurr)
        {
            ui->box_class->addItem(QString::fromStdString(claCurr->data.className));
            claCurr = claCurr->next;
        }
        syCurr = syCurr->next;
    }

    ui->stackedWidget_3->setCurrentIndex(8);
}


void MainWindow::on_box_class_currentTextChanged(const QString &arg1)
{
    ui->box_year->clear();
    std::string className = ui->box_class->currentText().toStdString();
    Node<SchoolYear>* syCurr = latestSYear;

    bool ok = 1;
    while (syCurr && ok)
    {
        Node<Class>* claCurr = syCurr->data.classes;
        ui->box_year->addItem(QString::fromStdString(syCurr->data.year));
        while (claCurr)
        {
            if (claCurr->data.className == className) {ok = 0; break;}
            claCurr = claCurr->next;
        }
        if (ok) syCurr = syCurr->next;
    }
}


void MainWindow::on_box_year_currentTextChanged(const QString &arg1)
{
    if (ui->box_year->count() == 0) return;
    ui->box_semester->clear();
    std::string sy = ui->box_year->currentText().toStdString();
    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr)
    {
        if (syCurr->data.year == sy)
        {
            currSYear = syCurr;
            int no = 0;
            for (int i = 2; i >= 0; i--)
            {
                if (syCurr->data.semesters[i].isCreated)
                {
                    ui->box_semester->addItem(QString::number(++no));
                    ui->box_semester->setCurrentIndex(no - 1);
                }
            }
            if (no == 0)
            {
                ui->box_semester->addItem("No Semester");
                ui->box_semester->setDisabled(1);
            }
            else ui->box_semester->setDisabled(0);
            break;
        }
        syCurr = syCurr->next;
    }
}


void MainWindow::on_box_semester_currentTextChanged(const QString &arg1)
{
    if (ui->box_semester->count() == 0) return;

    int semester = ui->box_semester->currentText().toInt();
    currSem = currSYear->data.semesters[semester - 1];

    MainWindow::on_button_ok_2_clicked();
}

Node<Class>* MainWindow::ChooseClass_2(std::string className) {  //copyallfunc
    Node<SchoolYear>* tempcurrYear = latestSYear;
    while (tempcurrYear != nullptr)
    {
        Node<Class>* tempclass = tempcurrYear->data.classes;
        while (tempclass != nullptr)
        {
            if (tempclass->data.className == className)
            {
                return tempclass;
            }
            tempclass = tempclass->next;
        }
        tempcurrYear = tempcurrYear->next;
    }
    return nullptr;
}

void MainWindow::on_button_ok_2_clicked()
{
    if (ui->box_class->currentText() == "" || ui->box_year->currentText() == "" || ui->box_semester->currentText() == "") return;

    std::string className = ui->box_class->currentText().toStdString();

    Node<Class>* ChosenClass = ChooseClass_2(className);


    Node<std::string>* TempCourses = nullptr;
    Node<Course>* SemCourse = currSem.Courses;
    while (SemCourse != nullptr)
    {
        std::string addTempCourse = SemCourse->data.Name;
        Node<std::string>* newTempCourse = new Node<std::string>(addTempCourse, TempCourses);
        TempCourses = newTempCourse;
        SemCourse = SemCourse->next;
    }
    deleteDuplicateTempCourses(TempCourses);
    int numofCourses = countUniqueTempCourses(TempCourses);
    bool* check = new bool[numofCourses];
    for (int i = 0; i < numofCourses; i++) check[i] = false;
    Node<Student>* tempStu = ChosenClass->data.students;
    while (tempStu != nullptr)
    {
        Node<Course>* tmp = currSem.Courses;
        while (tmp != nullptr)
        {
            int index = 0;
            if (!Exist(check, tmp, TempCourses, numofCourses, index))
            {
                int numofStu = tmp->data.courseSize;
                for (int i = 0; i < numofStu; i++)
                {
                    if (tempStu->data.ID == tmp->data.score[i].studentID)
                    {
                        check[index] = true;
                    }
                }
            }
            tmp = tmp->next;
        }
        tempStu = tempStu->next;
    }

    Node<std::string>* ClassCourses = ClassCourse(TempCourses, check);
    int NumofClassCourses = countUniqueTempCourses(ClassCourses);

    ui->table_scoreboard->setColumnCount(4 + NumofClassCourses);
    QStringList horizontalHeaders;
    horizontalHeaders << "Student ID" << "Full Name";

    Node<std::string>* temp = ClassCourses;
    while (temp)
    {
        horizontalHeaders << QString::fromStdString(temp->data);
        temp = temp->next;
    }
    horizontalHeaders << "GPA" << "Overall GPA";
    ui->table_scoreboard->setHorizontalHeaderLabels(horizontalHeaders);



    ui->table_scoreboard->setRowCount(0);
    int no = 0;
    Node<Student>* StuScore = ChosenClass->data.students;
    while (StuScore != nullptr)
    {
        ui->table_scoreboard->setRowCount(++no);
        Node<std::string>* StudentUniqueCourses = nullptr;
        double numofactivecourses = 0, gpa = 0;

        ui->table_scoreboard->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(StuScore->data.ID)));
        ui->table_scoreboard->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(StuScore->data.name)));
        Node<std::string>* tmp2 = ClassCourses;
        int columnCount = 1;
        while (tmp2 != nullptr)
        {
            Node<Course>* check = currSem.Courses;
            while (check != nullptr)
            {
                bool score = false;
                if (tmp2->data == check->data.Name)
                {
                    int numofstudents = check->data.courseSize;
                    for (int i = 0; i < numofstudents; i++)
                    {
                        if (StuScore->data.ID == check->data.score[i].studentID)
                        {
                            std::string newStuCourses = check->data.Name;
                            Node<std::string>* newStuCours = new Node<std::string>(newStuCourses, StudentUniqueCourses);
                            StudentUniqueCourses = newStuCours;
                            if (check->data.score[i].total != (-1) * 1.0)
                            {
                                gpa += check->data.score[i].total;
                                numofactivecourses++;
                            }

                            // columnCount++;
                            if (check->data.score[i].final != (-1) * 1.0) ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::number(check->data.score[i].final)));
                            else ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::fromStdString("")));
                            score = true;
                            break;
                        }
                    }
                }
                if (score) break;
                check = check->next;
            }
            if (check == nullptr) ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::fromStdString("")));
            tmp2 = tmp2->next;
        }
        // columnCount++;
        if (numofactivecourses == 0 || gpa == 0) ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::fromStdString("")));
        else ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::number(gpa / numofactivecourses, 'f', 2)));
        double prevtotal = 0, prevnumofacticour = 0;
        // columnCount++;
        previous(prevtotal, prevnumofacticour, StuScore, ChosenClass, StudentUniqueCourses);
        if (prevnumofacticour == 0 || numofactivecourses == 0) ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::fromStdString("")));
        else ui->table_scoreboard->setItem(no - 1, ++columnCount, new QTableWidgetItem(QString::number((prevtotal + gpa) / (prevnumofacticour + numofactivecourses), 'f', 2)));

        StuScore = StuScore->next;
    }

    delete[] check;
    Node<std::string>* deleteTempCourses = TempCourses;
    while (deleteTempCourses != nullptr)
    {
        Node<std::string>* temp = deleteTempCourses;
        deleteTempCourses = deleteTempCourses->next;
        delete temp;
    }
    Node<std::string>* deleteClassCourses = ClassCourses;
    while (deleteClassCourses != nullptr)
    {
        Node<std::string>* temp = deleteClassCourses;
        deleteClassCourses = deleteClassCourses->next;
        delete temp;
    }

    ui->table_scoreboard->resizeColumnsToContents();
}


void MainWindow::on_sem_select_currentTextChanged(const QString &arg1)
{
    if (ui->sem_select->count() == 0) return;
    on_button_ok_clicked();
}


void MainWindow::on_button_removeFilter_clicked()
{
    ui->box_selectSY_2->setCurrentIndex(-1);
    ui->box_selectSem->clear();

    ui->table_course->setRowCount(0);
    int no = 0;
    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        for (int i = 2; i >= 0; i--)
        {
            Node<Course>* couCurr = tempYear->data.semesters[i].Courses;
            while (couCurr)
            {
                ui->table_course->setRowCount(++no);
                ui->table_course->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(couCurr->data.ID)));
                ui->table_course->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(couCurr->data.Name)));
                ui->table_course->setItem(no - 1, 2, new QTableWidgetItem(QString::fromStdString(couCurr->data.className)));
                ui->table_course->setItem(no - 1, 3, new QTableWidgetItem(QString::fromStdString(couCurr->data.teacherName)));
                ui->table_course->setItem(no - 1, 4, new QTableWidgetItem(QString::number(couCurr->data.nCredits)));
                ui->table_course->setItem(no - 1, 5, new QTableWidgetItem(QString::number(couCurr->data.courseSize)));
                ui->table_course->setItem(no - 1, 6, new QTableWidgetItem(QString::number(couCurr->data.maxStudents)));
                ui->table_course->setItem(no - 1, 7, new QTableWidgetItem(QString::fromStdString(couCurr->data.dayOfWeek)));
                ui->table_course->setItem(no - 1, 8, new QTableWidgetItem(QString::fromStdString(couCurr->data.session)));
                couCurr = couCurr->next;

            }
        }
        tempYear = tempYear->next;
    }
    ui->table_course->resizeColumnsToContents();
}


void MainWindow::on_button_course_manage_clicked()
{
    MainWindow::on_button_removeFilter_clicked();
    ui->box_selectSY_2->clear();

    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        ui->box_selectSY_2->addItem(QString::fromStdString(tempYear->data.year));
        tempYear = tempYear->next;
    }

    ui->stackedWidget_3->setCurrentIndex(9);
    ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::button_ok_3_clicked()
{
    std::string year = ui->box_selectSY_2->currentText().toStdString();
    int sem = ui->box_selectSem->currentText().toInt();

    ui->table_course->setRowCount(0);
    int no = 0;
    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        if (tempYear->data.year == year)
        {
            Node<Course>* couCurr = tempYear->data.semesters[sem - 1].Courses;
            while (couCurr)
            {
                ui->table_course->setRowCount(++no);
                ui->table_course->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(couCurr->data.ID)));
                ui->table_course->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(couCurr->data.Name)));
                ui->table_course->setItem(no - 1, 2, new QTableWidgetItem(QString::fromStdString(couCurr->data.className)));
                ui->table_course->setItem(no - 1, 3, new QTableWidgetItem(QString::fromStdString(couCurr->data.teacherName)));
                ui->table_course->setItem(no - 1, 4, new QTableWidgetItem(QString::number(couCurr->data.nCredits)));
                ui->table_course->setItem(no - 1, 5, new QTableWidgetItem(QString::number(couCurr->data.courseSize)));
                ui->table_course->setItem(no - 1, 6, new QTableWidgetItem(QString::number(couCurr->data.maxStudents)));
                ui->table_course->setItem(no - 1, 7, new QTableWidgetItem(QString::fromStdString(couCurr->data.dayOfWeek)));
                ui->table_course->setItem(no - 1, 8, new QTableWidgetItem(QString::fromStdString(couCurr->data.session)));
                couCurr = couCurr->next;
            }
        }
        tempYear = tempYear->next;
    }
    ui->table_course->resizeColumnsToContents();
}


void MainWindow::on_box_selectSY_2_currentTextChanged(const QString &arg1)
{
    if (ui->box_selectSY_2->count() == 0 || ui->box_selectSY_2->currentIndex() == -1) return;
    ui->box_selectSem->clear();

    std::string year = ui->box_selectSY_2->currentText().toStdString();

    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        if (tempYear->data.year == year)
        {
            for (int i = 2; i >= 0; i--)
            {
                if (tempYear->data.semesters[i].isCreated) ui->box_selectSem->addItem(QString::number(i + 1));
            }
            break;
        }
        tempYear = tempYear->next;
    }

    MainWindow::button_ok_3_clicked();
}

void MainWindow::on_box_selectSem_currentTextChanged(const QString &arg1)
{
    if (ui->box_selectSem->count() == 0) return;

    MainWindow::button_ok_3_clicked();
}


void MainWindow::on_button_viewStudent_clicked()
{
    if (ui->table_course->selectedItems().isEmpty())
    {
        MessageBox("Error", "Select A Course ID or Course Name To View!");
        return;
    }
    int row = ui->table_course->currentRow();

    std::string ID = ui->table_course->item(row, 0)->text().toStdString();
    std::string courseName = ui->table_course->item(row, 1)->text().toStdString();
    std::string className = ui->table_course->item(row, 2)->text().toStdString();

    ui->lb_scoreBoard->setText(QString::fromStdString(ID + " - " + courseName + " - " + className));

    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        for (int i = 2; i >= 0; i--)
        {
            Node<Course>* tempCou = tempYear->data.semesters[i].Courses;
            while(tempCou)
            {
                if (tempCou->data.ID == ID && tempCou->data.className == className)
                {
                    int no = 0;
                    for (int i = 0; i < tempCou->data.courseSize; i++)
                    {
                        ui->table_student_2->setRowCount(++no);
                        StudentScore curStu = tempCou->data.score[i];
                        ui->table_student_2->setItem(no - 1, 0, new QTableWidgetItem(QString::fromStdString(curStu.studentID)));
                        ui->table_student_2->setItem(no - 1, 1, new QTableWidgetItem(QString::fromStdString(curStu.studentName)));
                        ui->table_student_2->setItem(no - 1, 2, new QTableWidgetItem(QString::number(curStu.midTerm)));
                        ui->table_student_2->setItem(no - 1, 3, new QTableWidgetItem(QString::number(curStu.final)));
                        ui->table_student_2->setItem(no - 1, 4, new QTableWidgetItem(QString::number(curStu.other)));
                        ui->table_student_2->setItem(no - 1, 5, new QTableWidgetItem(QString::number(curStu.total)));
                    }
                    break;
                }
                tempCou = tempCou->next;
            }
        }
        tempYear = tempYear->next;
    }

    ui->table_student_2->resizeColumnsToContents();
    ui->stackedWidget_5->setCurrentIndex(1);
}


void MainWindow::on_button_coursesList_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::on_txt_className_textEdited(const QString &arg1)
{
    ui->txt_className->setText(arg1.toUpper());
}


void MainWindow::on_button_back_10_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(4);
}

void MainWindow::on_button_back_11_clicked()
{
    ui->stackedWidget_3->setCurrentIndex(0);
}

void MainWindow::on_table_course_itemDoubleClicked(QTableWidgetItem *item)
{
    if (ui->table_course->currentColumn() < 2 || ui->table_course->currentColumn() == 5)
    {
        MessageBox("Error", "Unable To Edit Course ID, Course Name and Course Size!");
        item->setFlags(item->flags() & ~Qt::ItemIsEditable);
        return;
    }
}


void MainWindow::on_button_removeCourse_clicked()
{
    if (ui->table_course->selectedItems().isEmpty())
    {
        MessageBox("Error", "Select A Course ID or Course Name To Remove!");
        return;
    }
    int row = ui->table_course->currentRow();

    std::string ID = ui->table_course->item(row, 0)->text().toStdString();
    std::string courseName = ui->table_course->item(row, 1)->text().toStdString();
    std::string className = ui->table_course->item(row, 2)->text().toStdString();
    std::string courseData = ID + " - " + courseName + " - " + className;

    int ret = MessageBox_ok_cancel("Confirmation", "Do You Want To Remove [" + courseData + "] Permanently?"
                                                    "\n\nYou Will Lose All Information Of This Course");
    if (ret == QMessageBox::Cancel) return;



    // Delete course
    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        for (int i = 2; i >= 0; i--)
        {
            Node<Course>* couCurr = tempYear->data.semesters[i].Courses;
            Node<Course>* couPrev = nullptr;

            if (couCurr && couCurr->data.ID == ID && couCurr->data.className == className)
            {
                delete[] couCurr->data.score;
                tempYear->data.semesters[i].Courses = couCurr->next;
                delete couCurr;
                break;
            }
            while(couCurr)
            {
                if (couCurr->data.ID == ID && couCurr->data.className == className) // found course
                {
                    delete[] couCurr->data.score;
                    couPrev->next = couCurr->next;
                    delete couCurr;
                    break;
                }
                couPrev = couCurr;
                couCurr = couCurr->next;
            }
        }
        tempYear = tempYear->next;
    }

    if (ui->box_selectSY_2->currentIndex() == -1) MainWindow::on_button_removeFilter_clicked();
    else {
        MainWindow::button_ok_3_clicked();
    }

    MessageBox_information("Notification", "Course Removed Successfully!");
}


void MainWindow::on_button_addCourse_clicked()
{
    if (ui->box_selectSY_2->currentIndex() == -1)
    {
        MessageBox("Notice", "Select School Year and Semester First!");
        return;
    }
    {
        ui->lb_addCourse->setText("ADD COURSE TO " + ui->box_selectSY_2->currentText() + ", SEMESTER " + ui->box_selectSem->currentText());
        ui->stackedWidget_5->setCurrentIndex(2);
    }
}


void MainWindow::on_button_confirm_7_clicked()
{
    Course newCourse;

    //get info
    newCourse.couSY = ui->box_selectSY_2->currentText().toStdString();
    newCourse.couSem = ui->box_selectSem->currentText().toInt();
    newCourse.ID = ui->txt_courseID->text().toStdString();
    newCourse.Name = ui->txt_courseName->text().toStdString();
    newCourse.teacherName = ui->txt_teacherName->text().toStdString();
    newCourse.className = ui->txt_className_2->text().toStdString();
    newCourse.nCredits = ui->box_numCredits->currentText().toInt();
    newCourse.dayOfWeek = ui->box_dayOfWeek->currentText().toStdString();
    newCourse.session = ui->box_session->currentText().toStdString();
    if (ui->txt_maxStudents->text() == "") newCourse.maxStudents = 50;
    else newCourse.maxStudents = ui->txt_maxStudents->text().toInt();


    // access current semester
    std::string year = ui->box_selectSY_2->currentText().toStdString();
    currSemNumber = ui->box_selectSem->currentText().toInt();

    currSYear = latestSYear;
    while (currSYear)
    {
        if (currSYear->data.year == year)
        {
            currSem = currSYear->data.semesters[currSemNumber - 1];
            break;
        }
        currSYear = currSYear->next;
    }


    // add course
    if (!isValidCourseID(newCourse.ID)) {
        MessageBox("Error", "Invalid Course ID!");
        return;
    }
    if (!isValidCouOrStuName(newCourse.Name)) {
        MessageBox("Error", "Invalid Course Name!");
        return;
    }
    formalize(newCourse.Name);

    if (!isValidClassName(newCourse.className, year)) {
        MessageBox("Error", "Invalid Class Name!");
        return;
    }
    if (!notExistclassNameOfCourse(newCourse.ID, newCourse.className, year)) {
        MessageBox("Error", "Class Name Has Already Existed!");
        return;
    }

    if (!isValidCouOrStuName(newCourse.teacherName)) {
        MessageBox("Error", "Invalid Teacher Name");
        return;
    }
    formalize(newCourse.teacherName);

    if (ui->box_numCredits->currentIndex() == -1){
        MessageBox("Error", "Choose Number of Credits");
        return;
    }
    if (ui->box_dayOfWeek->currentIndex() == -1 || ui->box_session->currentIndex() == -1){
        MessageBox("Error", "Choose Session");
        return;
    }

    int ret = MessageBox_ok_cancel("Confirmation", "Do You Want To Add This Course?");
    if (ret == QMessageBox::Cancel) return;

    Node<SchoolYear>* syCurr = latestSYear;
    while (syCurr) {
        if (syCurr->data.year == year) {
            Node<Course>* temp = syCurr->data.semesters[currSemNumber - 1].Courses;
            syCurr->data.semesters[currSemNumber - 1].Courses = new Node<Course>(newCourse, temp);
            syCurr->data.semesters[currSemNumber - 1].Courses->data.score = new StudentScore[newCourse.maxStudents];
            currSem = syCurr->data.semesters[currSemNumber - 1];
            break;
        }
        syCurr = syCurr->next;
    }

    MessageBox_information("Notification", "A New Course Has Been Added!");

    ui->txt_courseID->setText("");
    ui->txt_courseName->setText("");
    ui->txt_className_2->setText("");
    ui->txt_teacherName->setText("");
    ui->txt_maxStudents->setText("");
    ui->box_numCredits->setCurrentIndex(-1);
    ui->box_dayOfWeek->setCurrentIndex(-1);
    ui->box_session->setCurrentIndex(-1);
    MainWindow::button_ok_3_clicked();
}


void MainWindow::on_button_back_13_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::on_txt_className_2_textEdited(const QString &arg1)
{
    ui->txt_className_2->setText(arg1.toUpper());
}


void MainWindow::on_txt_courseID_textEdited(const QString &arg1)
{
    ui->txt_courseID->setText(arg1.toUpper());
}

void MainWindow::on_button_removeStudent_clicked()
{
    if (ui->table_student_2->selectedItems().isEmpty())
    {
        MessageBox("Error", "Select A Student To Remove!");
        return;
    }

    int ROW = ui->table_course->currentRow();
    std::string courseID = ui->table_course->item(ROW, 0)->text().toStdString();
    std::string className = ui->table_course->item(ROW, 2)->text().toStdString();
    // int courseSize = ui->table_course->item(ROW, 5)->text().toInt();

    int row = ui->table_student_2->currentRow();
    std::string studentID = ui->table_student_2->item(row, 0)->text().toStdString();
    // std::string studentName = ui->table_student_2->item(row, 1)->text().toStdString();


    // delete student
    int ret = MessageBox_ok_cancel("Confirmation", "Do You Want To Remove [" + studentID + "] From [" + courseID + "] Pernamently?");
    if (ret == QMessageBox::Cancel) return;

    Node<SchoolYear>* tempYear = latestSYear;
    while (tempYear)
    {
        for (int i = 2; i >= 0; i--)
        {
            Node<Course>* couCurr = tempYear->data.semesters[i].Courses;
            while(couCurr)
            {
                if (couCurr->data.ID == courseID && couCurr->data.className == className) // found course
                {
                    int index;
                    for (int i = 0; i < couCurr->data.courseSize; i++) if (couCurr->data.score[i].studentID == studentID) index = i;
                    for (int i = index; i < couCurr->data.courseSize - 1; i++) couCurr->data.score[i] = couCurr->data.score[i + 1];
                    couCurr->data.courseSize--;
                    break;
                }
                couCurr = couCurr->next;
            }
        }
        tempYear = tempYear->next;
    }

    MainWindow::on_button_viewStudent_clicked();
    MessageBox_information("Notification", "Student Removed Successfully!");
}

void MainWindow::on_button_addStudent_2_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(3);

    int row = ui->table_course->currentRow();

    std::string ID = ui->table_course->item(row, 0)->text().toStdString();
    std::string courseName = ui->table_course->item(row, 1)->text().toStdString();
    std::string className = ui->table_course->item(row, 2)->text().toStdString();
    int courseSize = ui->table_course->item(row, 5)->text().toInt();
    int maxStudents = ui->table_course->item(row, 6)->text().toInt();
    std::string courseData = ID + " - " + courseName + " - " + className;

    if (courseSize + 1 > maxStudents) {
        MessageBox("Error", "The Number Of Students In This Course Reached Maximum!");
        return;
    }

    ui->lb_courseData->setText(QString::fromStdString(courseData));
}

void MainWindow::on_button_back_15_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(1);
}


void MainWindow::on_button_confirm_9_clicked()
{
    std::string studentID = ui->txt_studentID->text().toStdString();
    std::string studentName = ui->txt_studentName->text().toStdString();

    int row = ui->table_course->currentRow();
    std::string courseID = ui->table_course->item(row, 0)->text().toStdString();
    std::string className = ui->table_course->item(row, 2)->text().toStdString();

    StudentScore studentScore;
    studentScore.studentID = studentID;
    studentScore.studentName = studentName;

    if (!isValidStudentID(studentScore.studentID)) {
        MessageBox("Error", "Invalid Student ID!");
        return;
    }
    if (!isValidCouOrStuName(studentScore.studentName)) {
        MessageBox("Error", "Invalid Student Name!");
        return;
    }

    int ret = MessageBox_ok_cancel("Confirmation", "Do You Want To Add [" + studentID + "] To [" + courseID + "] ?");
    if (ret == QMessageBox::Cancel) return;

    // search course
    Node<SchoolYear>* tempYear = latestSYear;
    Node<Course>* couCurr = nullptr;
    while (tempYear)
    {
        for (int i = 2; i >= 0; i--)
        {
            Node<Course>* tempCou = tempYear->data.semesters[i].Courses;
            while(tempCou)
            {
                if (tempCou->data.ID == courseID && tempCou->data.className == className)
                {
                    couCurr = tempCou;
                    break;
                }
                tempCou = tempCou->next;
            }
        }
        tempYear = tempYear->next;
    }

    if (checkMatchStudentIDAndName(studentScore.studentID, studentScore.studentName)) {
        formalize(studentScore.studentName);
        bool isExist = false;
        for (int i = 0; i < couCurr->data.courseSize; i++) {
            if (studentScore.studentID == couCurr->data.score[i].studentID) {
                isExist = true;
                break;
            }
        }
        if (!isExist) {
            formalize(studentScore.studentName);
            couCurr->data.score[couCurr->data.courseSize] = studentScore;
            couCurr->data.courseSize++;
            MessageBox_information("Notification", "Student Added Successfully!");
        }
        else {
            MessageBox_information("Notification", "Student Has Been Already In The Course!");
        }
    }
    else {
        MessageBox("Error", "Student ID and Student Name Do Not Match!");
    }
}


void MainWindow::on_button_edit_clicked()
{
    if (ui->table_course->selectedItems().isEmpty())
    {
        MessageBox("Error", "Select A Course To Edit!");
        return;
    }

    ui->stackedWidget_5->setCurrentIndex(4);

    int row = ui->table_course->currentRow();

    ui->txt_courseID_edit->setText(ui->table_course->item(row, 0)->text());
    ui->txt_courseName_edit->setText(ui->table_course->item(row, 1)->text());
    ui->txt_className_edit->setText(ui->table_course->item(row, 2)->text());
    ui->txt_teacherName_edit->setText(ui->table_course->item(row, 3)->text());
    ui->txt_maxStudents_edit->setText(ui->table_course->item(row, 6)->text());
    ui->box_numCredits_edit->setCurrentText(ui->table_course->item(row, 4)->text());
    ui->box_dayOfWeek_edit->setCurrentText(ui->table_course->item(row, 7)->text());
    ui->box_session_edit->setCurrentText(ui->table_course->item(row, 8)->text());
}


void MainWindow::on_button_back_14_clicked()
{
    ui->stackedWidget_5->setCurrentIndex(0);
}


void MainWindow::on_button_confirm_8_clicked()
{
    // Course couCurr;
    // couCurr.ID = ui->table_course->item(row, 0)->text().toStdString();
    // couCurr.Name = ui->table_course->item(row, 1)->text().toStdString();
    // couCurr.className = ui->table_course->item(row, 2)->text().toStdString();
    // couCurr.teacherName = ui->table_course->item(row, 3)->text().toStdString();
    // couCurr.nCredits = ui->table_course->item(row, 4)->text().toInt();
    // couCurr.courseSize = ui->table_course->item(row, 5)->text().toInt();
    // couCurr.maxStudents = ui->table_course->item(row, 6)->text().toInt();
    // couCurr.dayOfWeek = ui->table_course->item(row, 7)->text().toStdString();
    // couCurr.session = ui->table_course->item(row, 8)->text().toStdString();
}

