/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *lb_signin;
    QLabel *lb_username;
    QLineEdit *txtUsername;
    QFrame *line;
    QLabel *lb_password;
    QLineEdit *txtPassword;
    QFrame *line_2;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_signin;
    QPushButton *button_exit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QWidget *student_homepage;
    QGridLayout *gridLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *avatar;
    QLabel *name;
    QPushButton *button_StuHome;
    QPushButton *button_StuMyProfile;
    QPushButton *button_StuMyCourses;
    QPushButton *button_StuChangePassword;
    QPushButton *button_StuSignOut;
    QStackedWidget *stackedWidget_2;
    QWidget *StuHome;
    QGridLayout *gridLayout_9;
    QLabel *slogan_2;
    QLabel *slogan_1;
    QVBoxLayout *verticalLayout_4;
    QCalendarWidget *calendarWidget;
    QPushButton *button_currentDay;
    QLabel *slogan_3;
    QLabel *lb_welcome;
    QWidget *StuProfile;
    QGridLayout *gridLayout_6;
    QLineEdit *txt_StuGender;
    QLabel *lb_StuSocialID;
    QLabel *lb_StuBirthday;
    QLabel *lb_StuMainClass;
    QLabel *lb_StuGender;
    QLineEdit *txt_StuName;
    QPushButton *button_back_2;
    QLineEdit *txt_StuID;
    QLineEdit *txt_StuBirthday;
    QLabel *lb_StuName;
    QLabel *lb_StuID;
    QLineEdit *txt_StuSocialID;
    QLineEdit *txt_StuClass;
    QLabel *lb_MyProfile;
    QWidget *StuCourse;
    QVBoxLayout *verticalLayout_5;
    QLabel *lb_MyCourses;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_select_sy;
    QComboBox *sy_select;
    QSpacerItem *horizontalSpacer_3;
    QLabel *lb_select_sem;
    QComboBox *sem_select;
    QPushButton *button_ok;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_back_5;
    QPushButton *button_viewScore;
    QWidget *StuChangePassword;
    QGridLayout *gridLayout_5;
    QLabel *lb_confirmPass;
    QPushButton *button_back;
    QPushButton *button_confirm;
    QLineEdit *txtNewPass;
    QLabel *lb_changePass;
    QLabel *lb_curPass;
    QLabel *lb_newPass;
    QLineEdit *txtCurPass;
    QLineEdit *txtConfirmPass;
    QCheckBox *checkBox_2;
    QWidget *admin_homepage;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *lb_latestSY;
    QLabel *lb_latestSem;
    QLabel *avatar_2;
    QLabel *name_2;
    QPushButton *button_AdHome;
    QPushButton *button_AdMyProfile;
    QPushButton *button_AdChangePassword;
    QPushButton *button_AdSignOut;
    QStackedWidget *stackedWidget_3;
    QWidget *AdHome;
    QLabel *lb_welcome_2;
    QPushButton *button_create_sy;
    QPushButton *button_class_manage;
    QPushButton *button_create_sem;
    QPushButton *button_course_manage;
    QWidget *AdProfile;
    QGridLayout *gridLayout_8;
    QLabel *lb_AdID;
    QPushButton *button_back_4;
    QLineEdit *txt_AdID;
    QLabel *lb_AdName;
    QLabel *lb_MyProfile_2;
    QLineEdit *txt_AdName;
    QLabel *lb_AdGender;
    QLabel *lb_AdBirthday;
    QLabel *lb_AdSocialID;
    QLineEdit *txt_AdSocialID;
    QLineEdit *txt_AdBirthday;
    QLineEdit *txt_AdGender;
    QWidget *AdChangePass;
    QGridLayout *gridLayout_7;
    QLabel *lb_changePass_2;
    QLabel *lb_curPass_2;
    QLineEdit *txtCurPass_2;
    QLabel *lb_newPass_2;
    QLineEdit *txtNewPass_2;
    QLabel *lb_confirmPass_2;
    QLineEdit *txtConfirmPass_2;
    QCheckBox *checkBox_3;
    QPushButton *button_confirm_2;
    QPushButton *button_back_3;
    QWidget *AdCreateSemester;
    QLabel *lb_createNewSemester;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QCalendarWidget *calendarWidget_2;
    QPushButton *button_currentDate;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_10;
    QPushButton *button_setEndDate;
    QPushButton *button_confirm_3;
    QLineEdit *txt_endDate;
    QPushButton *button_back_6;
    QLineEdit *txt_startDate;
    QPushButton *button_setStartDate;
    QLabel *lb_latestSED;
    QWidget *AdClassManagement;
    QLabel *lb_classManage;
    QPushButton *button_scoreOfClass;
    QPushButton *button_allClasses;
    QPushButton *button_addStudent;
    QPushButton *button_createClass;
    QPushButton *button_back_7;
    QWidget *AdAddClass;
    QGridLayout *gridLayout_11;
    QVBoxLayout *verticalLayout_7;
    QLabel *lb_allClassesIn;
    QListWidget *list_classes;
    QLabel *lb_createNewClass;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_selectSY;
    QComboBox *box_selectSY;
    QSpacerItem *verticalSpacer_3;
    QLabel *lb_enterClassName;
    QLineEdit *txt_className;
    QSpacerItem *verticalSpacer_4;
    QPushButton *button_confirm_4;
    QPushButton *button_back_8;
    QWidget *AdAddStudent;
    QGridLayout *gridLayout_14;
    QLabel *lb_addNewStudent;
    QComboBox *box_selectClass;
    QStackedWidget *stackedWidget_4;
    QWidget *page_addOne;
    QGridLayout *gridLayout_12;
    QPushButton *button_confirm_5;
    QLabel *lb_addStuID;
    QLabel *lb_addName;
    QLabel *lb_addGender;
    QLabel *lb_addBirthday;
    QLineEdit *txt_addID;
    QLineEdit *txt_addName;
    QComboBox *box_addGender;
    QPushButton *button_cancel;
    QLineEdit *txt_addSocialID;
    QLabel *lb_addSocialID;
    QPushButton *button_openCalendar;
    QLineEdit *txt_addBirthday;
    QWidget *page_import;
    QGridLayout *gridLayout_13;
    QLineEdit *txt_path;
    QPushButton *button_confirm_6;
    QPushButton *button_cancel_2;
    QLabel *lb_enterPath;
    QWidget *page_calendar;
    QGridLayout *gridLayout_15;
    QCalendarWidget *calendarWidget_3;
    QPushButton *button_selectDate;
    QPushButton *button_back_9;
    QTableWidget *tableWidget_2;
    QPushButton *button_addOne;
    QPushButton *button_import;
    QLabel *lb_selectClass;
    QWidget *AdAllClasses;
    QLabel *lb_allClasses;
    QListWidget *list_classes_2;
    QTableWidget *table_student;
    QLabel *lb_curClass;
    QLabel *lb_class;
    QPushButton *button_back_12;
    QWidget *AdScoreboard;
    QLabel *lb_viewScoreboard;
    QComboBox *box_class;
    QComboBox *box_year;
    QComboBox *box_semester;
    QTableWidget *table_scoreboard;
    QPushButton *button_back_10;
    QPushButton *button_ok_2;
    QWidget *AdCourseView;
    QGridLayout *gridLayout_16;
    QLabel *lb_courseView;
    QStackedWidget *stackedWidget_5;
    QWidget *page_2;
    QPushButton *button_back_11;
    QComboBox *box_selectSY_2;
    QTableWidget *table_course;
    QLabel *label_2;
    QLabel *label;
    QComboBox *box_selectSem;
    QPushButton *button_viewStudent;
    QPushButton *button_removeFilter;
    QCheckBox *checkBox_edit;
    QPushButton *button_addCourse;
    QPushButton *button_removeCourse;
    QWidget *page_4;
    QTableWidget *table_student_2;
    QPushButton *button_coursesList;
    QLabel *lb_scoreBoard;
    QPushButton *button_addStudent_2;
    QPushButton *button_removeStudent;
    QPushButton *button_importScoreBoard;
    QCheckBox *checkBox_4;
    QPushButton *button_exportTable;
    QWidget *page_5;
    QLabel *lb_addCourse;
    QComboBox *box_numCredits;
    QComboBox *box_dayOfWeek;
    QComboBox *box_session;
    QLabel *lb_numCredits;
    QLabel *lb_session;
    QPushButton *button_confirm_7;
    QPushButton *button_back_13;
    QLabel *lb_teacherName;
    QLineEdit *txt_teacherName;
    QLabel *lb_className;
    QLineEdit *txt_className_2;
    QLineEdit *txt_courseName;
    QLabel *lb_courseName;
    QLineEdit *txt_courseID;
    QLabel *lb_courseID;
    QLineEdit *txt_maxStudents;
    QLabel *lb_maxStudents;
    QWidget *page_3;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1221, 723);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"        border-image: url(:/background/button.png);\n"
"        color: white;\n"
"}\n"
"QPushButton:hover { border-image: url(:/background/button_hover.png); \n"
"}\n"
"\n"
"\n"
"QLabel{\n"
"color: black;\n"
"}\n"
"\n"
"QLineEdit{\n"
"color: black;\n"
"}\n"
"\n"
"QCheckBox{\n"
"color: black;\n"
"}\n"
""));
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(7);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("#page{\n"
"        border-image: url(:/background/Minecraft HD world.jpg);\n"
"}\n"
"\n"
"#student_homepage{\n"
"        border-image: url(:/background/Lovely Minecraft Hd Wallpaper 1920x1080.jpg);\n"
"}"));
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        widget->setMaximumSize(QSize(571, 365));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"border-radius:40px;\n"
"        background-color: rgba(0, 0, 0, 175);\n"
"}\n"
"\n"
"#lb_username{\n"
"color: white;\n"
"}\n"
"\n"
"#lb_password{\n"
"color: white;\n"
"}\n"
"\n"
"#lb_signin {\n"
"color: white;\n"
"}\n"
"\n"
"#checkBox{\n"
"color: white;\n"
"}\n"
"\n"
"#txtUsername{\n"
"color: white;\n"
"}\n"
"\n"
"#txtPassword{\n"
"color: white;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 20, 15, 20);
        lb_signin = new QLabel(widget);
        lb_signin->setObjectName("lb_signin");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lb_signin->sizePolicy().hasHeightForWidth());
        lb_signin->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        font.setItalic(false);
        lb_signin->setFont(font);
        lb_signin->setStyleSheet(QString::fromUtf8("color: #FBFFF4"));
        lb_signin->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_signin);

        lb_username = new QLabel(widget);
        lb_username->setObjectName("lb_username");
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        lb_username->setFont(font1);
        lb_username->setStyleSheet(QString::fromUtf8("color: #FBFFF4"));

        verticalLayout->addWidget(lb_username);

        txtUsername = new QLineEdit(widget);
        txtUsername->setObjectName("txtUsername");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtUsername->sizePolicy().hasHeightForWidth());
        txtUsername->setSizePolicy(sizePolicy1);
        txtUsername->setMaximumSize(QSize(541, 38));
        QFont font2;
        font2.setPointSize(20);
        txtUsername->setFont(font2);
        txtUsername->setStyleSheet(QString::fromUtf8("#txtUsername{\n"
"        background-color: transparent;\n"
"}"));
        txtUsername->setFrame(false);
        txtUsername->setCursorPosition(0);

        verticalLayout->addWidget(txtUsername);

        line = new QFrame(widget);
        line->setObjectName("line");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy2);
        line->setMinimumSize(QSize(0, 5));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        lb_password = new QLabel(widget);
        lb_password->setObjectName("lb_password");
        lb_password->setFont(font1);
        lb_password->setStyleSheet(QString::fromUtf8("color: #FBFFF4"));

        verticalLayout->addWidget(lb_password);

        txtPassword = new QLineEdit(widget);
        txtPassword->setObjectName("txtPassword");
        sizePolicy1.setHeightForWidth(txtPassword->sizePolicy().hasHeightForWidth());
        txtPassword->setSizePolicy(sizePolicy1);
        txtPassword->setMaximumSize(QSize(541, 39));
        txtPassword->setFont(font2);
        txtPassword->setStyleSheet(QString::fromUtf8("\n"
"#txtPassword\n"
"{\n"
"background-color: transparent;\n"
"}"));
        txtPassword->setFrame(false);
        txtPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(txtPassword);

        line_2 = new QFrame(widget);
        line_2->setObjectName("line_2");
        sizePolicy2.setHeightForWidth(line_2->sizePolicy().hasHeightForWidth());
        line_2->setSizePolicy(sizePolicy2);
        line_2->setMinimumSize(QSize(0, 5));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");
        QFont font3;
        checkBox->setFont(font3);
        checkBox->setStyleSheet(QString::fromUtf8("font-size: 16px;\n"
"color: #FBFFF4"));

        verticalLayout->addWidget(checkBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        button_signin = new QPushButton(widget);
        button_signin->setObjectName("button_signin");
        button_signin->setEnabled(false);
        sizePolicy2.setHeightForWidth(button_signin->sizePolicy().hasHeightForWidth());
        button_signin->setSizePolicy(sizePolicy2);
        button_signin->setMinimumSize(QSize(258, 40));
        button_signin->setMaximumSize(QSize(289, 50));
        QFont font4;
        font4.setPointSize(14);
        button_signin->setFont(font4);
        button_signin->setCursor(QCursor(Qt::ArrowCursor));
        button_signin->setToolTipDuration(-1);

        horizontalLayout->addWidget(button_signin);

        button_exit = new QPushButton(widget);
        button_exit->setObjectName("button_exit");
        sizePolicy2.setHeightForWidth(button_exit->sizePolicy().hasHeightForWidth());
        button_exit->setSizePolicy(sizePolicy2);
        button_exit->setMinimumSize(QSize(257, 40));
        button_exit->setMaximumSize(QSize(288, 50));
        button_exit->setFont(font4);
        button_exit->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(button_exit);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addWidget(widget, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        gridLayout_2->setRowStretch(0, 2);
        gridLayout_2->setRowStretch(1, 7);
        gridLayout_2->setRowStretch(2, 2);
        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 5);
        gridLayout_2->setColumnStretch(2, 2);
        stackedWidget->addWidget(page);
        student_homepage = new QWidget();
        student_homepage->setObjectName("student_homepage");
        gridLayout_3 = new QGridLayout(student_homepage);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(15, 15, 15, 15);
        widget_2 = new QWidget(student_homepage);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2{\n"
"        background-color: rgba(0, 0, 0, 150);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 50, -1, 70);
        avatar = new QLabel(widget_2);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(140, 140));
        avatar->setMaximumSize(QSize(140, 140));
        avatar->setStyleSheet(QString::fromUtf8("#avatar{\n"
"        border-image: url(:/background/OIP.jpg)\n"
"}"));

        verticalLayout_2->addWidget(avatar, 0, Qt::AlignHCenter);

        name = new QLabel(widget_2);
        name->setObjectName("name");
        name->setMaximumSize(QSize(16777215, 34));
        QFont font5;
        font5.setPointSize(16);
        name->setFont(font5);
        name->setStyleSheet(QString::fromUtf8("#name{\n"
"        color: #FBFFF4;\n"
"}"));
        name->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name);

        button_StuHome = new QPushButton(widget_2);
        button_StuHome->setObjectName("button_StuHome");
        button_StuHome->setMinimumSize(QSize(218, 50));
        button_StuHome->setMaximumSize(QSize(251, 50));
        QFont font6;
        font6.setPointSize(12);
        button_StuHome->setFont(font6);

        verticalLayout_2->addWidget(button_StuHome, 0, Qt::AlignHCenter);

        button_StuMyProfile = new QPushButton(widget_2);
        button_StuMyProfile->setObjectName("button_StuMyProfile");
        button_StuMyProfile->setMinimumSize(QSize(218, 50));
        button_StuMyProfile->setMaximumSize(QSize(251, 50));
        button_StuMyProfile->setFont(font6);

        verticalLayout_2->addWidget(button_StuMyProfile, 0, Qt::AlignHCenter);

        button_StuMyCourses = new QPushButton(widget_2);
        button_StuMyCourses->setObjectName("button_StuMyCourses");
        button_StuMyCourses->setMinimumSize(QSize(218, 50));
        button_StuMyCourses->setMaximumSize(QSize(251, 50));
        button_StuMyCourses->setFont(font6);

        verticalLayout_2->addWidget(button_StuMyCourses, 0, Qt::AlignHCenter);

        button_StuChangePassword = new QPushButton(widget_2);
        button_StuChangePassword->setObjectName("button_StuChangePassword");
        button_StuChangePassword->setMinimumSize(QSize(218, 50));
        button_StuChangePassword->setMaximumSize(QSize(251, 50));
        button_StuChangePassword->setFont(font6);

        verticalLayout_2->addWidget(button_StuChangePassword, 0, Qt::AlignHCenter);

        button_StuSignOut = new QPushButton(widget_2);
        button_StuSignOut->setObjectName("button_StuSignOut");
        button_StuSignOut->setMinimumSize(QSize(218, 50));
        button_StuSignOut->setMaximumSize(QSize(251, 50));
        button_StuSignOut->setFont(font6);

        verticalLayout_2->addWidget(button_StuSignOut, 0, Qt::AlignHCenter);


        gridLayout_3->addWidget(widget_2, 0, 0, 1, 1);

        stackedWidget_2 = new QStackedWidget(student_homepage);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setStyleSheet(QString::fromUtf8("#StuHome{\n"
"        background-color: rgba(0, 0, 0, 80);\n"
"}\n"
"\n"
"#StuChangePassword{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#StuProfile{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#lb_StuID{\n"
"        color: white;\n"
"}\n"
"\n"
"#lb_StuName{\n"
"        color: white;\n"
"}\n"
"\n"
"#lb_StuGender{\n"
"        color: white;\n"
"}\n"
"\n"
"#lb_StuBirthday{\n"
"        color: white;\n"
"}\n"
"\n"
"#lb_StuMainClass{\n"
"        color: white;\n"
"}\n"
"\n"
"#lb_StuSocialID{\n"
"        color: white;\n"
"}\n"
"\n"
"#lb_MyProfile{\n"
"        color:rgb(151, 255, 168);\n"
"}\n"
"\n"
"#StuCourse{\n"
"background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#lb_MyCourses{\n"
"        color:rgb(151, 255, 168);\n"
"}\n"
"\n"
"#slogan_1{\n"
"	color: white;\n"
"}\n"
"#slogan_2{\n"
"	color: white;\n"
"}\n"
"#slogan_3{\n"
"	color: white;\n"
"}\n"
""));
        StuHome = new QWidget();
        StuHome->setObjectName("StuHome");
        gridLayout_9 = new QGridLayout(StuHome);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setContentsMargins(40, 11, 40, 80);
        slogan_2 = new QLabel(StuHome);
        slogan_2->setObjectName("slogan_2");
        slogan_2->setFont(font5);
        slogan_2->setWordWrap(true);

        gridLayout_9->addWidget(slogan_2, 2, 0, 1, 1);

        slogan_1 = new QLabel(StuHome);
        slogan_1->setObjectName("slogan_1");
        slogan_1->setFont(font5);
        slogan_1->setWordWrap(true);

        gridLayout_9->addWidget(slogan_1, 1, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        calendarWidget = new QCalendarWidget(StuHome);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setStyleSheet(QString::fromUtf8("QCalendarWidget QToolButton#qt_calendar_nextmonth{\n"
"	border-image: url(:/background/right_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"	icon-size: 0px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton#qt_calendar_prevmonth{\n"
"	border-image: url(:/background/left_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"	icon-size: 0px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    background-color: rgb(118, 118, 118);\n"
"    color: #F5F0F0;\n"
"    border: 2px solid #000000;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: rgba(158, 158, 158,200);\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:pressed {\n"
"    background-color: rgba(118, 118, 118,200);\n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: rgba(198, 198, 198,200);\n"
"    color: #292727;\n"
"	padding-left: 5px;\n"
"    border-style: none;\n"
"    border-bottom: 2px solid #000000;"
                        "\n"
"    border-right: 1px solid #000000;\n"
"    border-left: 1px solid #000000;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::up-button {\n"
"	border-image: url(:/background/up_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::down-button {\n"
"	border-image: url(:/background/down_arrow.png);	\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"}\n"
"\n"
"QCalendarWidget QWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	font-size: 14px;\n"
"	border: 1px solid black;\n"
"    gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QCalendarWidget QWidget::item:selected {\n"
"    background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QCalendarWidget QMenu {\n"
"	padding-left: 10px;\n"
"}\n"
"\n"
"#qt_calendar_monthbutton::menu-indicator"
                        "{\n"
"   width:0px;\n"
"}\n"
""));
        calendarWidget->setGridVisible(false);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        verticalLayout_4->addWidget(calendarWidget);

        button_currentDay = new QPushButton(StuHome);
        button_currentDay->setObjectName("button_currentDay");
        button_currentDay->setMinimumSize(QSize(201, 51));
        button_currentDay->setMaximumSize(QSize(201, 51));

        verticalLayout_4->addWidget(button_currentDay, 0, Qt::AlignHCenter);


        gridLayout_9->addLayout(verticalLayout_4, 1, 1, 3, 1);

        slogan_3 = new QLabel(StuHome);
        slogan_3->setObjectName("slogan_3");
        slogan_3->setFont(font5);
        slogan_3->setWordWrap(true);

        gridLayout_9->addWidget(slogan_3, 3, 0, 1, 1);

        lb_welcome = new QLabel(StuHome);
        lb_welcome->setObjectName("lb_welcome");
        QFont font7;
        font7.setPointSize(48);
        lb_welcome->setFont(font7);
        lb_welcome->setStyleSheet(QString::fromUtf8("#lb_welcome{\n"
"        color: #7FFFD4;\n"
"}"));
        lb_welcome->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(lb_welcome, 0, 0, 1, 2);

        gridLayout_9->setColumnStretch(0, 3);
        gridLayout_9->setColumnStretch(1, 4);
        stackedWidget_2->addWidget(StuHome);
        StuProfile = new QWidget();
        StuProfile->setObjectName("StuProfile");
        gridLayout_6 = new QGridLayout(StuProfile);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setHorizontalSpacing(20);
        gridLayout_6->setVerticalSpacing(15);
        gridLayout_6->setContentsMargins(65, -1, 65, 50);
        txt_StuGender = new QLineEdit(StuProfile);
        txt_StuGender->setObjectName("txt_StuGender");
        txt_StuGender->setMinimumSize(QSize(0, 50));
        txt_StuGender->setMaximumSize(QSize(10000, 50));
        QFont font8;
        font8.setPointSize(18);
        txt_StuGender->setFont(font8);
        txt_StuGender->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_StuGender->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuGender, 3, 1, 1, 1);

        lb_StuSocialID = new QLabel(StuProfile);
        lb_StuSocialID->setObjectName("lb_StuSocialID");
        lb_StuSocialID->setFont(font8);
        lb_StuSocialID->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuSocialID, 6, 0, 1, 1, Qt::AlignRight);

        lb_StuBirthday = new QLabel(StuProfile);
        lb_StuBirthday->setObjectName("lb_StuBirthday");
        lb_StuBirthday->setFont(font8);
        lb_StuBirthday->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuBirthday, 4, 0, 1, 1, Qt::AlignRight);

        lb_StuMainClass = new QLabel(StuProfile);
        lb_StuMainClass->setObjectName("lb_StuMainClass");
        lb_StuMainClass->setFont(font8);
        lb_StuMainClass->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuMainClass, 5, 0, 1, 1, Qt::AlignRight);

        lb_StuGender = new QLabel(StuProfile);
        lb_StuGender->setObjectName("lb_StuGender");
        lb_StuGender->setFont(font8);
        lb_StuGender->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuGender, 3, 0, 1, 1, Qt::AlignRight);

        txt_StuName = new QLineEdit(StuProfile);
        txt_StuName->setObjectName("txt_StuName");
        txt_StuName->setMinimumSize(QSize(0, 50));
        txt_StuName->setMaximumSize(QSize(10000, 50));
        txt_StuName->setFont(font8);
        txt_StuName->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_StuName->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuName, 2, 1, 1, 1);

        button_back_2 = new QPushButton(StuProfile);
        button_back_2->setObjectName("button_back_2");
        button_back_2->setMinimumSize(QSize(200, 65));
        button_back_2->setMaximumSize(QSize(200, 65));
        button_back_2->setFont(font4);

        gridLayout_6->addWidget(button_back_2, 7, 1, 1, 1, Qt::AlignRight);

        txt_StuID = new QLineEdit(StuProfile);
        txt_StuID->setObjectName("txt_StuID");
        txt_StuID->setMinimumSize(QSize(0, 50));
        txt_StuID->setMaximumSize(QSize(10000, 50));
        txt_StuID->setFont(font8);
        txt_StuID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);"));
        txt_StuID->setFrame(true);
        txt_StuID->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuID, 1, 1, 1, 1);

        txt_StuBirthday = new QLineEdit(StuProfile);
        txt_StuBirthday->setObjectName("txt_StuBirthday");
        txt_StuBirthday->setMinimumSize(QSize(0, 50));
        txt_StuBirthday->setMaximumSize(QSize(10000, 50));
        txt_StuBirthday->setFont(font8);
        txt_StuBirthday->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_StuBirthday->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuBirthday, 4, 1, 1, 1);

        lb_StuName = new QLabel(StuProfile);
        lb_StuName->setObjectName("lb_StuName");
        lb_StuName->setFont(font8);
        lb_StuName->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuName, 2, 0, 1, 1, Qt::AlignRight);

        lb_StuID = new QLabel(StuProfile);
        lb_StuID->setObjectName("lb_StuID");
        lb_StuID->setFont(font8);
        lb_StuID->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuID, 1, 0, 1, 1, Qt::AlignRight);

        txt_StuSocialID = new QLineEdit(StuProfile);
        txt_StuSocialID->setObjectName("txt_StuSocialID");
        txt_StuSocialID->setMinimumSize(QSize(0, 50));
        txt_StuSocialID->setMaximumSize(QSize(10000, 50));
        txt_StuSocialID->setFont(font8);
        txt_StuSocialID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_StuSocialID->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuSocialID, 6, 1, 1, 1);

        txt_StuClass = new QLineEdit(StuProfile);
        txt_StuClass->setObjectName("txt_StuClass");
        txt_StuClass->setMinimumSize(QSize(0, 50));
        txt_StuClass->setMaximumSize(QSize(10000, 50));
        txt_StuClass->setFont(font8);
        txt_StuClass->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_StuClass->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuClass, 5, 1, 1, 1);

        lb_MyProfile = new QLabel(StuProfile);
        lb_MyProfile->setObjectName("lb_MyProfile");
        QFont font9;
        font9.setPointSize(36);
        lb_MyProfile->setFont(font9);
        lb_MyProfile->setStyleSheet(QString::fromUtf8("color: #7FFFD4"));
        lb_MyProfile->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lb_MyProfile, 0, 0, 1, 2);

        stackedWidget_2->addWidget(StuProfile);
        StuCourse = new QWidget();
        StuCourse->setObjectName("StuCourse");
        verticalLayout_5 = new QVBoxLayout(StuCourse);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(40, 20, 40, 30);
        lb_MyCourses = new QLabel(StuCourse);
        lb_MyCourses->setObjectName("lb_MyCourses");
        lb_MyCourses->setMinimumSize(QSize(0, 130));
        lb_MyCourses->setFont(font9);
        lb_MyCourses->setStyleSheet(QString::fromUtf8("color: #7FFFD4"));
        lb_MyCourses->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lb_MyCourses);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lb_select_sy = new QLabel(StuCourse);
        lb_select_sy->setObjectName("lb_select_sy");
        QFont font10;
        font10.setBold(false);
        font10.setItalic(false);
        lb_select_sy->setFont(font10);
        lb_select_sy->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font: 20px;"));

        horizontalLayout_2->addWidget(lb_select_sy);

        sy_select = new QComboBox(StuCourse);
        sy_select->setObjectName("sy_select");
        sy_select->setMinimumSize(QSize(0, 28));
        sy_select->setMaximumSize(QSize(10000, 16777215));
        sy_select->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));

        horizontalLayout_2->addWidget(sy_select);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        lb_select_sem = new QLabel(StuCourse);
        lb_select_sem->setObjectName("lb_select_sem");
        lb_select_sem->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"font-size: 20px;"));

        horizontalLayout_2->addWidget(lb_select_sem);

        sem_select = new QComboBox(StuCourse);
        sem_select->addItem(QString());
        sem_select->addItem(QString());
        sem_select->addItem(QString());
        sem_select->setObjectName("sem_select");
        sem_select->setMinimumSize(QSize(0, 28));
        sem_select->setMaximumSize(QSize(10000, 16777215));
        sem_select->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));

        horizontalLayout_2->addWidget(sem_select);

        button_ok = new QPushButton(StuCourse);
        button_ok->setObjectName("button_ok");
        button_ok->setMinimumSize(QSize(70, 28));
        button_ok->setMaximumSize(QSize(100, 28));
        button_ok->setStyleSheet(QString::fromUtf8("font-size: 16px;"));

        horizontalLayout_2->addWidget(button_ok);


        verticalLayout_5->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(StuCourse);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QFont font11;
        font11.setBold(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font11);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font11);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font11);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font11);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font11);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font11);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font11);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font11);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget->setObjectName("tableWidget");
        QFont font12;
        font12.setPointSize(9);
        font12.setKerning(true);
        tableWidget->setFont(font12);
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	background-color: rgba(118, 118, 118,200);\n"
"	color: #F5F0F0;\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color: rgba(158, 158, 158,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"	padding: 4px;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QTableWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"        border: 2px solid black;\n"
"        background-color: rgb(118, 118, 118);\n"
"        height: 15px;\n"
"        margin: 0 22px 0 22px;\n"
"    }\n"
"    QScrollBar::handle:horizontal {\n"
"	   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"        border: 1px solid #adb0b6;\n"
" "
                        "       border-radius: 4px;\n"
"        min-width: 20px;\n"
"    }\n"
"    QScrollBar::add-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: right;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: left;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical"
                        " {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setSortingEnabled(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);

        verticalLayout_5->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        button_back_5 = new QPushButton(StuCourse);
        button_back_5->setObjectName("button_back_5");
        button_back_5->setMinimumSize(QSize(200, 50));
        button_back_5->setMaximumSize(QSize(200, 50));
        button_back_5->setFont(font6);
        button_back_5->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(button_back_5);

        button_viewScore = new QPushButton(StuCourse);
        button_viewScore->setObjectName("button_viewScore");
        button_viewScore->setMinimumSize(QSize(200, 50));
        button_viewScore->setMaximumSize(QSize(200, 50));
        button_viewScore->setFont(font6);

        horizontalLayout_3->addWidget(button_viewScore);


        verticalLayout_5->addLayout(horizontalLayout_3);

        stackedWidget_2->addWidget(StuCourse);
        StuChangePassword = new QWidget();
        StuChangePassword->setObjectName("StuChangePassword");
        gridLayout_5 = new QGridLayout(StuChangePassword);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(65, -1, 65, -1);
        lb_confirmPass = new QLabel(StuChangePassword);
        lb_confirmPass->setObjectName("lb_confirmPass");
        lb_confirmPass->setFont(font8);
        lb_confirmPass->setStyleSheet(QString::fromUtf8("#lb_confirmPass{\n"
"        color: #FBFFF4;\n"
"}"));
        lb_confirmPass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lb_confirmPass, 3, 0, 1, 1);

        button_back = new QPushButton(StuChangePassword);
        button_back->setObjectName("button_back");
        button_back->setMinimumSize(QSize(200, 65));
        button_back->setMaximumSize(QSize(200, 65));
        button_back->setFont(font4);

        gridLayout_5->addWidget(button_back, 5, 2, 1, 1, Qt::AlignRight);

        button_confirm = new QPushButton(StuChangePassword);
        button_confirm->setObjectName("button_confirm");
        button_confirm->setMinimumSize(QSize(200, 65));
        button_confirm->setMaximumSize(QSize(200, 65));
        button_confirm->setFont(font4);

        gridLayout_5->addWidget(button_confirm, 5, 0, 1, 1);

        txtNewPass = new QLineEdit(StuChangePassword);
        txtNewPass->setObjectName("txtNewPass");
        txtNewPass->setMinimumSize(QSize(0, 50));
        txtNewPass->setMaximumSize(QSize(612, 50));
        txtNewPass->setFont(font2);
        txtNewPass->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding-left: 10px;"));
        txtNewPass->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(txtNewPass, 2, 2, 1, 1);

        lb_changePass = new QLabel(StuChangePassword);
        lb_changePass->setObjectName("lb_changePass");
        lb_changePass->setMaximumSize(QSize(16777215, 85));
        lb_changePass->setFont(font9);
        lb_changePass->setStyleSheet(QString::fromUtf8("#lb_changePass{\n"
"        color: #7FFFD4;\n"
"}"));
        lb_changePass->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_changePass, 0, 0, 1, 3);

        lb_curPass = new QLabel(StuChangePassword);
        lb_curPass->setObjectName("lb_curPass");
        lb_curPass->setFont(font8);
        lb_curPass->setStyleSheet(QString::fromUtf8("#lb_curPass{\n"
"        color: #FBFFF4;\n"
"}"));
        lb_curPass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lb_curPass, 1, 0, 1, 1);

        lb_newPass = new QLabel(StuChangePassword);
        lb_newPass->setObjectName("lb_newPass");
        lb_newPass->setFont(font8);
        lb_newPass->setStyleSheet(QString::fromUtf8("#lb_newPass{\n"
"        color: #FBFFF4;\n"
"}"));
        lb_newPass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lb_newPass, 2, 0, 1, 1);

        txtCurPass = new QLineEdit(StuChangePassword);
        txtCurPass->setObjectName("txtCurPass");
        txtCurPass->setMinimumSize(QSize(0, 50));
        txtCurPass->setMaximumSize(QSize(612, 50));
        txtCurPass->setFont(font2);
        txtCurPass->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding-left: 10px;"));
        txtCurPass->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(txtCurPass, 1, 2, 1, 1);

        txtConfirmPass = new QLineEdit(StuChangePassword);
        txtConfirmPass->setObjectName("txtConfirmPass");
        txtConfirmPass->setMinimumSize(QSize(0, 50));
        txtConfirmPass->setMaximumSize(QSize(612, 50));
        txtConfirmPass->setFont(font2);
        txtConfirmPass->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding-left: 10px;"));
        txtConfirmPass->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(txtConfirmPass, 3, 2, 1, 1);

        checkBox_2 = new QCheckBox(StuChangePassword);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setFont(font3);
        checkBox_2->setStyleSheet(QString::fromUtf8("#checkBox_2{\n"
"        color: #FBFFF4;\n"
"	font-size: 16px;\n"
"}"));

        gridLayout_5->addWidget(checkBox_2, 4, 2, 1, 1);

        stackedWidget_2->addWidget(StuChangePassword);

        gridLayout_3->addWidget(stackedWidget_2, 0, 1, 1, 2);

        gridLayout_3->setColumnStretch(0, 5);
        gridLayout_3->setColumnStretch(1, 19);
        stackedWidget->addWidget(student_homepage);
        admin_homepage = new QWidget();
        admin_homepage->setObjectName("admin_homepage");
        admin_homepage->setStyleSheet(QString::fromUtf8("#admin_homepage{\n"
"        border-image: url(:/background/Lovely Minecraft Hd Wallpaper 1920x1080.jpg);\n"
"}"));
        gridLayout_4 = new QGridLayout(admin_homepage);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(15, 15, 15, 15);
        widget_3 = new QWidget(admin_homepage);
        widget_3->setObjectName("widget_3");
        widget_3->setMaximumSize(QSize(100000, 100000));
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3{\n"
"        background-color: rgba(0, 0, 0, 150);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setSpacing(4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 0, -1, 70);
        lb_latestSY = new QLabel(widget_3);
        lb_latestSY->setObjectName("lb_latestSY");
        lb_latestSY->setMaximumSize(QSize(16777215, 23));
        lb_latestSY->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size: 16px;"));

        verticalLayout_3->addWidget(lb_latestSY, 0, Qt::AlignHCenter);

        lb_latestSem = new QLabel(widget_3);
        lb_latestSem->setObjectName("lb_latestSem");
        lb_latestSem->setMaximumSize(QSize(218, 23));
        lb_latestSem->setFont(font3);
        lb_latestSem->setStyleSheet(QString::fromUtf8("color:white;\n"
"font-size: 16px;"));

        verticalLayout_3->addWidget(lb_latestSem, 0, Qt::AlignHCenter);

        avatar_2 = new QLabel(widget_3);
        avatar_2->setObjectName("avatar_2");
        avatar_2->setMinimumSize(QSize(140, 140));
        avatar_2->setMaximumSize(QSize(140, 140));
        avatar_2->setStyleSheet(QString::fromUtf8("#avatar_2{\n"
"        border-image: url(:/background/OIP.jpg)\n"
"}"));

        verticalLayout_3->addWidget(avatar_2, 0, Qt::AlignHCenter);

        name_2 = new QLabel(widget_3);
        name_2->setObjectName("name_2");
        name_2->setMaximumSize(QSize(16777215, 34));
        name_2->setFont(font5);
        name_2->setStyleSheet(QString::fromUtf8("#name_2{\n"
"        color: #FBFFF4;\n"
"}"));
        name_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(name_2);

        button_AdHome = new QPushButton(widget_3);
        button_AdHome->setObjectName("button_AdHome");
        button_AdHome->setMinimumSize(QSize(218, 50));
        button_AdHome->setMaximumSize(QSize(251, 50));
        button_AdHome->setFont(font6);

        verticalLayout_3->addWidget(button_AdHome, 0, Qt::AlignHCenter);

        button_AdMyProfile = new QPushButton(widget_3);
        button_AdMyProfile->setObjectName("button_AdMyProfile");
        button_AdMyProfile->setMinimumSize(QSize(218, 50));
        button_AdMyProfile->setMaximumSize(QSize(251, 50));
        button_AdMyProfile->setFont(font6);

        verticalLayout_3->addWidget(button_AdMyProfile, 0, Qt::AlignHCenter);

        button_AdChangePassword = new QPushButton(widget_3);
        button_AdChangePassword->setObjectName("button_AdChangePassword");
        button_AdChangePassword->setMinimumSize(QSize(218, 50));
        button_AdChangePassword->setMaximumSize(QSize(251, 50));
        button_AdChangePassword->setFont(font6);

        verticalLayout_3->addWidget(button_AdChangePassword, 0, Qt::AlignHCenter);

        button_AdSignOut = new QPushButton(widget_3);
        button_AdSignOut->setObjectName("button_AdSignOut");
        button_AdSignOut->setMinimumSize(QSize(218, 50));
        button_AdSignOut->setMaximumSize(QSize(251, 50));
        button_AdSignOut->setFont(font6);

        verticalLayout_3->addWidget(button_AdSignOut, 0, Qt::AlignHCenter);


        gridLayout_4->addWidget(widget_3, 0, 0, 1, 1);

        stackedWidget_3 = new QStackedWidget(admin_homepage);
        stackedWidget_3->setObjectName("stackedWidget_3");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget_3->sizePolicy().hasHeightForWidth());
        stackedWidget_3->setSizePolicy(sizePolicy3);
        stackedWidget_3->setStyleSheet(QString::fromUtf8("#AdHome{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdProfile{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdChangePass{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdCreateSemester{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdClassManagement{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdAddClass{\n"
"	 background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdAddStudent{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdAddStudent_input{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdAddStudent_import{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdAllClasses{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdScoreboard{\n"
"        background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdCourseManagement{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdCourseSetting{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdCourseView{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
""
                        "\n"
"#lb_welcome_2{\n"
"        color:white;\n"
"}\n"
"#lb_changePass_2{\n"
"        color:rgb(151, 255, 168);\n"
"}\n"
"#lb_MyProfile_2{\n"
"        color:rgb(151, 255, 168);\n"
"}\n"
"\n"
"#lb_AdID{\n"
"        color: #FBFFF4;\n"
"}\n"
"\n"
"#lb_AdName{\n"
"        color: #FBFFF4;\n"
"}\n"
"\n"
"#lb_AdGender{\n"
"        color: #FBFFF4;\n"
"}\n"
"\n"
"#lb_AdBirthday{\n"
"        color: #FBFFF4;\n"
"}\n"
"\n"
"#lb_AdSocialID{\n"
"        color: #FBFFF4;\n"
"}\n"
""));
        AdHome = new QWidget();
        AdHome->setObjectName("AdHome");
        lb_welcome_2 = new QLabel(AdHome);
        lb_welcome_2->setObjectName("lb_welcome_2");
        lb_welcome_2->setGeometry(QRect(250, 0, 381, 141));
        lb_welcome_2->setFont(font7);
        lb_welcome_2->setStyleSheet(QString::fromUtf8("#lb_welcome_2{\n"
"	color: #7FFFD4;\n"
"}"));
        lb_welcome_2->setAlignment(Qt::AlignCenter);
        button_create_sy = new QPushButton(AdHome);
        button_create_sy->setObjectName("button_create_sy");
        button_create_sy->setGeometry(QRect(200, 200, 271, 41));
        button_class_manage = new QPushButton(AdHome);
        button_class_manage->setObjectName("button_class_manage");
        button_class_manage->setGeometry(QRect(200, 360, 261, 41));
        button_create_sem = new QPushButton(AdHome);
        button_create_sem->setObjectName("button_create_sem");
        button_create_sem->setGeometry(QRect(500, 200, 211, 41));
        button_course_manage = new QPushButton(AdHome);
        button_course_manage->setObjectName("button_course_manage");
        button_course_manage->setGeometry(QRect(510, 360, 201, 41));
        stackedWidget_3->addWidget(AdHome);
        AdProfile = new QWidget();
        AdProfile->setObjectName("AdProfile");
        gridLayout_8 = new QGridLayout(AdProfile);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setHorizontalSpacing(20);
        gridLayout_8->setVerticalSpacing(25);
        gridLayout_8->setContentsMargins(65, -1, 65, 50);
        lb_AdID = new QLabel(AdProfile);
        lb_AdID->setObjectName("lb_AdID");
        sizePolicy.setHeightForWidth(lb_AdID->sizePolicy().hasHeightForWidth());
        lb_AdID->setSizePolicy(sizePolicy);
        lb_AdID->setFont(font8);
        lb_AdID->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdID, 1, 0, 1, 1);

        button_back_4 = new QPushButton(AdProfile);
        button_back_4->setObjectName("button_back_4");
        button_back_4->setMinimumSize(QSize(200, 65));
        button_back_4->setMaximumSize(QSize(200, 65));
        button_back_4->setFont(font4);

        gridLayout_8->addWidget(button_back_4, 8, 2, 1, 1);

        txt_AdID = new QLineEdit(AdProfile);
        txt_AdID->setObjectName("txt_AdID");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(txt_AdID->sizePolicy().hasHeightForWidth());
        txt_AdID->setSizePolicy(sizePolicy4);
        txt_AdID->setMinimumSize(QSize(0, 50));
        txt_AdID->setMaximumSize(QSize(10000, 50));
        txt_AdID->setFont(font8);
        txt_AdID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_AdID->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdID, 1, 1, 1, 2);

        lb_AdName = new QLabel(AdProfile);
        lb_AdName->setObjectName("lb_AdName");
        lb_AdName->setFont(font8);
        lb_AdName->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdName, 2, 0, 1, 1);

        lb_MyProfile_2 = new QLabel(AdProfile);
        lb_MyProfile_2->setObjectName("lb_MyProfile_2");
        lb_MyProfile_2->setFont(font9);
        lb_MyProfile_2->setStyleSheet(QString::fromUtf8("color: #7FFFD4;"));
        lb_MyProfile_2->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(lb_MyProfile_2, 0, 0, 1, 3);

        txt_AdName = new QLineEdit(AdProfile);
        txt_AdName->setObjectName("txt_AdName");
        txt_AdName->setMinimumSize(QSize(0, 50));
        txt_AdName->setMaximumSize(QSize(10000, 50));
        txt_AdName->setFont(font8);
        txt_AdName->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_AdName->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdName, 2, 1, 1, 2);

        lb_AdGender = new QLabel(AdProfile);
        lb_AdGender->setObjectName("lb_AdGender");
        lb_AdGender->setFont(font8);
        lb_AdGender->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdGender, 3, 0, 1, 1);

        lb_AdBirthday = new QLabel(AdProfile);
        lb_AdBirthday->setObjectName("lb_AdBirthday");
        lb_AdBirthday->setFont(font8);
        lb_AdBirthday->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdBirthday, 4, 0, 1, 1);

        lb_AdSocialID = new QLabel(AdProfile);
        lb_AdSocialID->setObjectName("lb_AdSocialID");
        lb_AdSocialID->setMaximumSize(QSize(145, 50));
        lb_AdSocialID->setFont(font8);
        lb_AdSocialID->setStyleSheet(QString::fromUtf8("#label{\n"
"        color: #FBFFF4;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdSocialID, 5, 0, 1, 1);

        txt_AdSocialID = new QLineEdit(AdProfile);
        txt_AdSocialID->setObjectName("txt_AdSocialID");
        txt_AdSocialID->setMinimumSize(QSize(0, 50));
        txt_AdSocialID->setMaximumSize(QSize(10000, 50));
        txt_AdSocialID->setFont(font8);
        txt_AdSocialID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_AdSocialID->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdSocialID, 5, 1, 1, 2);

        txt_AdBirthday = new QLineEdit(AdProfile);
        txt_AdBirthday->setObjectName("txt_AdBirthday");
        txt_AdBirthday->setMinimumSize(QSize(0, 50));
        txt_AdBirthday->setMaximumSize(QSize(10000, 50));
        txt_AdBirthday->setFont(font8);
        txt_AdBirthday->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_AdBirthday->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdBirthday, 4, 1, 1, 2);

        txt_AdGender = new QLineEdit(AdProfile);
        txt_AdGender->setObjectName("txt_AdGender");
        txt_AdGender->setMinimumSize(QSize(0, 50));
        txt_AdGender->setMaximumSize(QSize(10000, 50));
        txt_AdGender->setFont(font8);
        txt_AdGender->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200)"));
        txt_AdGender->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdGender, 3, 1, 1, 2);

        stackedWidget_3->addWidget(AdProfile);
        AdChangePass = new QWidget();
        AdChangePass->setObjectName("AdChangePass");
        gridLayout_7 = new QGridLayout(AdChangePass);
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setContentsMargins(65, -1, 65, -1);
        lb_changePass_2 = new QLabel(AdChangePass);
        lb_changePass_2->setObjectName("lb_changePass_2");
        lb_changePass_2->setMaximumSize(QSize(16777215, 85));
        lb_changePass_2->setFont(font9);
        lb_changePass_2->setStyleSheet(QString::fromUtf8("#lb_changePass_2{\n"
"        color: #7FFFD4;\n"
"}"));
        lb_changePass_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lb_changePass_2, 0, 0, 1, 2);

        lb_curPass_2 = new QLabel(AdChangePass);
        lb_curPass_2->setObjectName("lb_curPass_2");
        lb_curPass_2->setFont(font8);
        lb_curPass_2->setStyleSheet(QString::fromUtf8("#lb_curPass_2{\n"
"        color: #FBFFF4;\n"
"}"));
        lb_curPass_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_curPass_2, 1, 0, 1, 1);

        txtCurPass_2 = new QLineEdit(AdChangePass);
        txtCurPass_2->setObjectName("txtCurPass_2");
        txtCurPass_2->setMinimumSize(QSize(0, 50));
        txtCurPass_2->setMaximumSize(QSize(612, 50));
        txtCurPass_2->setFont(font8);
        txtCurPass_2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding-left: 10px;"));
        txtCurPass_2->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(txtCurPass_2, 1, 1, 1, 1);

        lb_newPass_2 = new QLabel(AdChangePass);
        lb_newPass_2->setObjectName("lb_newPass_2");
        lb_newPass_2->setFont(font8);
        lb_newPass_2->setStyleSheet(QString::fromUtf8("#lb_newPass_2{\n"
"        color: #FBFFF4;\n"
"}"));
        lb_newPass_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_newPass_2, 2, 0, 1, 1);

        txtNewPass_2 = new QLineEdit(AdChangePass);
        txtNewPass_2->setObjectName("txtNewPass_2");
        txtNewPass_2->setMinimumSize(QSize(0, 50));
        txtNewPass_2->setMaximumSize(QSize(612, 50));
        txtNewPass_2->setFont(font8);
        txtNewPass_2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding-left: 10px"));
        txtNewPass_2->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(txtNewPass_2, 2, 1, 1, 1);

        lb_confirmPass_2 = new QLabel(AdChangePass);
        lb_confirmPass_2->setObjectName("lb_confirmPass_2");
        lb_confirmPass_2->setFont(font8);
        lb_confirmPass_2->setStyleSheet(QString::fromUtf8("#lb_confirmPass_2{\n"
"        color:#FBFFF4;\n"
"}"));
        lb_confirmPass_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_confirmPass_2, 3, 0, 1, 1);

        txtConfirmPass_2 = new QLineEdit(AdChangePass);
        txtConfirmPass_2->setObjectName("txtConfirmPass_2");
        txtConfirmPass_2->setMinimumSize(QSize(0, 50));
        txtConfirmPass_2->setMaximumSize(QSize(612, 50));
        txtConfirmPass_2->setFont(font8);
        txtConfirmPass_2->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding-left: 10px;"));
        txtConfirmPass_2->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(txtConfirmPass_2, 3, 1, 1, 1);

        checkBox_3 = new QCheckBox(AdChangePass);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setFont(font3);
        checkBox_3->setStyleSheet(QString::fromUtf8("#checkBox_3{\n"
"        color: #FBFFF4;\n"
"		font-size: 16px;\n"
"}"));

        gridLayout_7->addWidget(checkBox_3, 4, 1, 1, 1);

        button_confirm_2 = new QPushButton(AdChangePass);
        button_confirm_2->setObjectName("button_confirm_2");
        button_confirm_2->setMinimumSize(QSize(200, 65));
        button_confirm_2->setMaximumSize(QSize(200, 65));
        button_confirm_2->setFont(font4);

        gridLayout_7->addWidget(button_confirm_2, 5, 0, 1, 1);

        button_back_3 = new QPushButton(AdChangePass);
        button_back_3->setObjectName("button_back_3");
        button_back_3->setMinimumSize(QSize(200, 65));
        button_back_3->setMaximumSize(QSize(200, 65));
        button_back_3->setFont(font4);

        gridLayout_7->addWidget(button_back_3, 5, 1, 1, 1, Qt::AlignRight);

        stackedWidget_3->addWidget(AdChangePass);
        AdCreateSemester = new QWidget();
        AdCreateSemester->setObjectName("AdCreateSemester");
        lb_createNewSemester = new QLabel(AdCreateSemester);
        lb_createNewSemester->setObjectName("lb_createNewSemester");
        lb_createNewSemester->setGeometry(QRect(190, 10, 511, 61));
        lb_createNewSemester->setMaximumSize(QSize(16777215, 103));
        lb_createNewSemester->setFont(font9);
        lb_createNewSemester->setStyleSheet(QString::fromUtf8("color: #7FFFD4;\n"
""));
        layoutWidget = new QWidget(AdCreateSemester);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(410, 110, 435, 473));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        calendarWidget_2 = new QCalendarWidget(layoutWidget);
        calendarWidget_2->setObjectName("calendarWidget_2");
        sizePolicy3.setHeightForWidth(calendarWidget_2->sizePolicy().hasHeightForWidth());
        calendarWidget_2->setSizePolicy(sizePolicy3);
        calendarWidget_2->setStyleSheet(QString::fromUtf8("QCalendarWidget QToolButton#qt_calendar_nextmonth{\n"
"	border-image: url(:/background/right_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"	icon-size: 0px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton#qt_calendar_prevmonth{\n"
"	border-image: url(:/background/left_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"	icon-size: 0px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    background-color: rgb(118, 118, 118);\n"
"    color: #F5F0F0;\n"
"    border: 2px solid #000000;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: rgba(158, 158, 158,200);\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:pressed {\n"
"    background-color: rgba(118, 118, 118,200);\n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: rgba(198, 198, 198,200);\n"
"    color: #292727;\n"
"	padding-left: 5px;\n"
"    border-style: none;\n"
"    border-bottom: 2px solid #000000;"
                        "\n"
"    border-right: 1px solid #000000;\n"
"    border-left: 1px solid #000000;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::up-button {\n"
"	border-image: url(:/background/up_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::down-button {\n"
"	border-image: url(:/background/down_arrow.png);	\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"}\n"
"\n"
"QCalendarWidget QWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	font-size: 14px;\n"
"	border: 1px solid black;\n"
"    gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QCalendarWidget QWidget::item:selected {\n"
"    background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QCalendarWidget QMenu {\n"
"	padding-left: 10px;\n"
"}\n"
"\n"
"#qt_calendar_monthbutton::menu-indicator"
                        "{\n"
"   width:0px;\n"
"}\n"
""));
        calendarWidget_2->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        verticalLayout_6->addWidget(calendarWidget_2);

        button_currentDate = new QPushButton(layoutWidget);
        button_currentDate->setObjectName("button_currentDate");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(button_currentDate->sizePolicy().hasHeightForWidth());
        button_currentDate->setSizePolicy(sizePolicy5);
        button_currentDate->setMinimumSize(QSize(150, 40));
        button_currentDate->setMaximumSize(QSize(170, 16777215));

        verticalLayout_6->addWidget(button_currentDate, 0, Qt::AlignHCenter);

        gridLayoutWidget = new QWidget(AdCreateSemester);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 160, 439, 381));
        gridLayout_10 = new QGridLayout(gridLayoutWidget);
        gridLayout_10->setObjectName("gridLayout_10");
        gridLayout_10->setContentsMargins(0, 0, 0, 0);
        button_setEndDate = new QPushButton(gridLayoutWidget);
        button_setEndDate->setObjectName("button_setEndDate");
        sizePolicy5.setHeightForWidth(button_setEndDate->sizePolicy().hasHeightForWidth());
        button_setEndDate->setSizePolicy(sizePolicy5);
        button_setEndDate->setMinimumSize(QSize(150, 50));

        gridLayout_10->addWidget(button_setEndDate, 2, 1, 1, 1);

        button_confirm_3 = new QPushButton(gridLayoutWidget);
        button_confirm_3->setObjectName("button_confirm_3");
        sizePolicy5.setHeightForWidth(button_confirm_3->sizePolicy().hasHeightForWidth());
        button_confirm_3->setSizePolicy(sizePolicy5);
        button_confirm_3->setMinimumSize(QSize(200, 65));
        button_confirm_3->setMaximumSize(QSize(200, 65));
        button_confirm_3->setStyleSheet(QString::fromUtf8("margin: 5px;"));

        gridLayout_10->addWidget(button_confirm_3, 3, 0, 1, 1);

        txt_endDate = new QLineEdit(gridLayoutWidget);
        txt_endDate->setObjectName("txt_endDate");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(txt_endDate->sizePolicy().hasHeightForWidth());
        txt_endDate->setSizePolicy(sizePolicy6);
        txt_endDate->setMinimumSize(QSize(0, 50));
        txt_endDate->setMaximumSize(QSize(16777215, 50));
        txt_endDate->setFont(font5);
        txt_endDate->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));
        txt_endDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        txt_endDate->setReadOnly(true);

        gridLayout_10->addWidget(txt_endDate, 2, 0, 1, 1);

        button_back_6 = new QPushButton(gridLayoutWidget);
        button_back_6->setObjectName("button_back_6");
        sizePolicy5.setHeightForWidth(button_back_6->sizePolicy().hasHeightForWidth());
        button_back_6->setSizePolicy(sizePolicy5);
        button_back_6->setMinimumSize(QSize(200, 65));
        button_back_6->setMaximumSize(QSize(200, 65));
        button_back_6->setStyleSheet(QString::fromUtf8("margin: 5px;"));

        gridLayout_10->addWidget(button_back_6, 3, 1, 1, 1);

        txt_startDate = new QLineEdit(gridLayoutWidget);
        txt_startDate->setObjectName("txt_startDate");
        sizePolicy6.setHeightForWidth(txt_startDate->sizePolicy().hasHeightForWidth());
        txt_startDate->setSizePolicy(sizePolicy6);
        txt_startDate->setMinimumSize(QSize(0, 50));
        txt_startDate->setMaximumSize(QSize(16777215, 50));
        txt_startDate->setFont(font5);
        txt_startDate->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));
        txt_startDate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        txt_startDate->setReadOnly(true);

        gridLayout_10->addWidget(txt_startDate, 0, 0, 1, 1);

        button_setStartDate = new QPushButton(gridLayoutWidget);
        button_setStartDate->setObjectName("button_setStartDate");
        sizePolicy5.setHeightForWidth(button_setStartDate->sizePolicy().hasHeightForWidth());
        button_setStartDate->setSizePolicy(sizePolicy5);
        button_setStartDate->setMinimumSize(QSize(150, 50));

        gridLayout_10->addWidget(button_setStartDate, 0, 1, 1, 1);

        lb_latestSED = new QLabel(AdCreateSemester);
        lb_latestSED->setObjectName("lb_latestSED");
        lb_latestSED->setGeometry(QRect(10, 100, 399, 100));
        QSizePolicy sizePolicy7(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(10);
        sizePolicy7.setHeightForWidth(lb_latestSED->sizePolicy().hasHeightForWidth());
        lb_latestSED->setSizePolicy(sizePolicy7);
        lb_latestSED->setMaximumSize(QSize(399, 100));
        lb_latestSED->setSizeIncrement(QSize(1, 0));
        lb_latestSED->setFont(font2);
        lb_latestSED->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        lb_latestSED->setScaledContents(false);
        lb_latestSED->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lb_latestSED->setWordWrap(true);
        stackedWidget_3->addWidget(AdCreateSemester);
        AdClassManagement = new QWidget();
        AdClassManagement->setObjectName("AdClassManagement");
        lb_classManage = new QLabel(AdClassManagement);
        lb_classManage->setObjectName("lb_classManage");
        lb_classManage->setGeometry(QRect(120, 30, 621, 111));
        lb_classManage->setFont(font9);
        lb_classManage->setStyleSheet(QString::fromUtf8("color: #7FFFD4;\n"
""));
        lb_classManage->setAlignment(Qt::AlignCenter);
        button_scoreOfClass = new QPushButton(AdClassManagement);
        button_scoreOfClass->setObjectName("button_scoreOfClass");
        button_scoreOfClass->setGeometry(QRect(270, 490, 301, 61));
        button_allClasses = new QPushButton(AdClassManagement);
        button_allClasses->setObjectName("button_allClasses");
        button_allClasses->setGeometry(QRect(270, 390, 301, 61));
        button_addStudent = new QPushButton(AdClassManagement);
        button_addStudent->setObjectName("button_addStudent");
        button_addStudent->setGeometry(QRect(270, 290, 301, 61));
        button_createClass = new QPushButton(AdClassManagement);
        button_createClass->setObjectName("button_createClass");
        button_createClass->setGeometry(QRect(270, 190, 301, 61));
        button_back_7 = new QPushButton(AdClassManagement);
        button_back_7->setObjectName("button_back_7");
        button_back_7->setGeometry(QRect(620, 570, 200, 65));
        button_back_7->setMinimumSize(QSize(200, 65));
        button_back_7->setMaximumSize(QSize(200, 65));
        stackedWidget_3->addWidget(AdClassManagement);
        AdAddClass = new QWidget();
        AdAddClass->setObjectName("AdAddClass");
        gridLayout_11 = new QGridLayout(AdAddClass);
        gridLayout_11->setObjectName("gridLayout_11");
        gridLayout_11->setHorizontalSpacing(30);
        gridLayout_11->setVerticalSpacing(20);
        gridLayout_11->setContentsMargins(65, -1, 65, 11);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        lb_allClassesIn = new QLabel(AdAddClass);
        lb_allClassesIn->setObjectName("lb_allClassesIn");
        lb_allClassesIn->setFont(font4);
        lb_allClassesIn->setStyleSheet(QString::fromUtf8("color:white;\n"
""));
        lb_allClassesIn->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(lb_allClassesIn);

        list_classes = new QListWidget(AdAddClass);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(list_classes);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        list_classes->setObjectName("list_classes");
        QFont font13;
        font13.setPointSize(22);
        list_classes->setFont(font13);
        list_classes->setStyleSheet(QString::fromUtf8("QListWidget::item {\n"
"    background-color: rgba(118, 118, 118, 200);\n"
"    color: #F5F0F0;;\n"
"    border: 2px solid #000000;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: rgba(198, 198, 198, 200);\n"
"    color: #292727;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgba(198, 198, 198, 200);\n"
"    color: #292727;\n"
"    padding: 4px;\n"
"    border-style: none;\n"
"    border-bottom: 2px solid #000000;\n"
"    border-right: 1px solid #000000;\n"
"    border-left: 1px solid #000000;\n"
"    box-shadow: 0 2px 4px 0 rgba(0, 0, 0, 0.15);\n"
"}\n"
"\n"
"QListWidget {\n"
"    background-color: rgb(118, 118, 118);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    height: 15px;\n"
"    margin: 0 22px 0 22px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    bord"
                        "er-radius: 4px;\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    background: black;\n"
"    width: 20px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    background: black;\n"
"    width: 20px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: black;\n"
"    heig"
                        "ht: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        list_classes->setEditTriggers(QAbstractItemView::EditKeyPressed);
        list_classes->setViewMode(QListView::ListMode);
        list_classes->setItemAlignment(Qt::AlignCenter);
        list_classes->setSortingEnabled(true);

        verticalLayout_7->addWidget(list_classes);


        gridLayout_11->addLayout(verticalLayout_7, 1, 1, 2, 1);

        lb_createNewClass = new QLabel(AdAddClass);
        lb_createNewClass->setObjectName("lb_createNewClass");
        lb_createNewClass->setMaximumSize(QSize(16777215, 130));
        lb_createNewClass->setFont(font9);
        lb_createNewClass->setStyleSheet(QString::fromUtf8("color: #7FFFD4;\n"
""));
        lb_createNewClass->setAlignment(Qt::AlignCenter);

        gridLayout_11->addWidget(lb_createNewClass, 0, 0, 1, 2);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(7);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lb_selectSY = new QLabel(AdAddClass);
        lb_selectSY->setObjectName("lb_selectSY");
        lb_selectSY->setFont(font4);
        lb_selectSY->setStyleSheet(QString::fromUtf8("color: white;\n"
""));

        horizontalLayout_4->addWidget(lb_selectSY);

        box_selectSY = new QComboBox(AdAddClass);
        box_selectSY->addItem(QString());
        box_selectSY->setObjectName("box_selectSY");
        box_selectSY->setFont(font3);
        box_selectSY->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));

        horizontalLayout_4->addWidget(box_selectSY);


        verticalLayout_8->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_3);

        lb_enterClassName = new QLabel(AdAddClass);
        lb_enterClassName->setObjectName("lb_enterClassName");
        lb_enterClassName->setMaximumSize(QSize(16777215, 1000));
        lb_enterClassName->setFont(font4);
        lb_enterClassName->setStyleSheet(QString::fromUtf8("color:white;"));
        lb_enterClassName->setIndent(-1);

        verticalLayout_8->addWidget(lb_enterClassName);

        txt_className = new QLineEdit(AdAddClass);
        txt_className->setObjectName("txt_className");
        QSizePolicy sizePolicy8(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(txt_className->sizePolicy().hasHeightForWidth());
        txt_className->setSizePolicy(sizePolicy8);
        txt_className->setMinimumSize(QSize(0, 50));
        txt_className->setMaximumSize(QSize(16777215, 50));
        txt_className->setFont(font5);
        txt_className->setStyleSheet(QString::fromUtf8("color: #292727;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));

        verticalLayout_8->addWidget(txt_className);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_4);

        button_confirm_4 = new QPushButton(AdAddClass);
        button_confirm_4->setObjectName("button_confirm_4");
        QSizePolicy sizePolicy9(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(button_confirm_4->sizePolicy().hasHeightForWidth());
        button_confirm_4->setSizePolicy(sizePolicy9);
        button_confirm_4->setMinimumSize(QSize(150, 65));
        button_confirm_4->setMaximumSize(QSize(200, 65));
        button_confirm_4->setStyleSheet(QString::fromUtf8("margin: 5px;"));

        verticalLayout_8->addWidget(button_confirm_4, 0, Qt::AlignHCenter);

        button_back_8 = new QPushButton(AdAddClass);
        button_back_8->setObjectName("button_back_8");
        sizePolicy9.setHeightForWidth(button_back_8->sizePolicy().hasHeightForWidth());
        button_back_8->setSizePolicy(sizePolicy9);
        button_back_8->setMinimumSize(QSize(150, 65));
        button_back_8->setMaximumSize(QSize(200, 65));
        button_back_8->setStyleSheet(QString::fromUtf8("margin: 5px"));

        verticalLayout_8->addWidget(button_back_8, 0, Qt::AlignHCenter);


        gridLayout_11->addLayout(verticalLayout_8, 1, 0, 1, 1);

        stackedWidget_3->addWidget(AdAddClass);
        AdAddStudent = new QWidget();
        AdAddStudent->setObjectName("AdAddStudent");
        gridLayout_14 = new QGridLayout(AdAddStudent);
        gridLayout_14->setObjectName("gridLayout_14");
        gridLayout_14->setContentsMargins(65, 35, 65, 30);
        lb_addNewStudent = new QLabel(AdAddStudent);
        lb_addNewStudent->setObjectName("lb_addNewStudent");
        lb_addNewStudent->setFont(font9);
        lb_addNewStudent->setStyleSheet(QString::fromUtf8("color: #7FFFD4;"));
        lb_addNewStudent->setAlignment(Qt::AlignCenter);

        gridLayout_14->addWidget(lb_addNewStudent, 0, 0, 1, 7);

        box_selectClass = new QComboBox(AdAddStudent);
        box_selectClass->setObjectName("box_selectClass");
        sizePolicy9.setHeightForWidth(box_selectClass->sizePolicy().hasHeightForWidth());
        box_selectClass->setSizePolicy(sizePolicy9);
        box_selectClass->setFont(font3);
        box_selectClass->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 18px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));

        gridLayout_14->addWidget(box_selectClass, 9, 0, 1, 1);

        stackedWidget_4 = new QStackedWidget(AdAddStudent);
        stackedWidget_4->setObjectName("stackedWidget_4");
        stackedWidget_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color:white;\n"
"}"));
        page_addOne = new QWidget();
        page_addOne->setObjectName("page_addOne");
        gridLayout_12 = new QGridLayout(page_addOne);
        gridLayout_12->setSpacing(7);
        gridLayout_12->setObjectName("gridLayout_12");
        gridLayout_12->setContentsMargins(15, 5, 15, 0);
        button_confirm_5 = new QPushButton(page_addOne);
        button_confirm_5->setObjectName("button_confirm_5");
        button_confirm_5->setMinimumSize(QSize(120, 45));
        button_confirm_5->setMaximumSize(QSize(120, 16777215));

        gridLayout_12->addWidget(button_confirm_5, 6, 0, 1, 2);

        lb_addStuID = new QLabel(page_addOne);
        lb_addStuID->setObjectName("lb_addStuID");

        gridLayout_12->addWidget(lb_addStuID, 1, 0, 1, 1);

        lb_addName = new QLabel(page_addOne);
        lb_addName->setObjectName("lb_addName");

        gridLayout_12->addWidget(lb_addName, 2, 0, 1, 1);

        lb_addGender = new QLabel(page_addOne);
        lb_addGender->setObjectName("lb_addGender");

        gridLayout_12->addWidget(lb_addGender, 3, 0, 1, 1);

        lb_addBirthday = new QLabel(page_addOne);
        lb_addBirthday->setObjectName("lb_addBirthday");

        gridLayout_12->addWidget(lb_addBirthday, 4, 0, 1, 1);

        txt_addID = new QLineEdit(page_addOne);
        txt_addID->setObjectName("txt_addID");
        txt_addID->setMinimumSize(QSize(0, 40));
        txt_addID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));

        gridLayout_12->addWidget(txt_addID, 1, 1, 1, 3);

        txt_addName = new QLineEdit(page_addOne);
        txt_addName->setObjectName("txt_addName");
        txt_addName->setMinimumSize(QSize(0, 40));
        txt_addName->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));

        gridLayout_12->addWidget(txt_addName, 2, 1, 1, 3);

        box_addGender = new QComboBox(page_addOne);
        box_addGender->addItem(QString());
        box_addGender->addItem(QString());
        box_addGender->setObjectName("box_addGender");
        box_addGender->setMinimumSize(QSize(0, 40));
        box_addGender->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 14px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: white;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));

        gridLayout_12->addWidget(box_addGender, 3, 1, 1, 3);

        button_cancel = new QPushButton(page_addOne);
        button_cancel->setObjectName("button_cancel");
        button_cancel->setMinimumSize(QSize(120, 45));
        button_cancel->setMaximumSize(QSize(120, 16777215));

        gridLayout_12->addWidget(button_cancel, 6, 2, 1, 2, Qt::AlignRight);

        txt_addSocialID = new QLineEdit(page_addOne);
        txt_addSocialID->setObjectName("txt_addSocialID");
        txt_addSocialID->setMinimumSize(QSize(0, 40));
        txt_addSocialID->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));

        gridLayout_12->addWidget(txt_addSocialID, 5, 1, 1, 3);

        lb_addSocialID = new QLabel(page_addOne);
        lb_addSocialID->setObjectName("lb_addSocialID");

        gridLayout_12->addWidget(lb_addSocialID, 5, 0, 1, 1);

        button_openCalendar = new QPushButton(page_addOne);
        button_openCalendar->setObjectName("button_openCalendar");
        button_openCalendar->setMinimumSize(QSize(25, 25));
        button_openCalendar->setMaximumSize(QSize(25, 25));
        button_openCalendar->setStyleSheet(QString::fromUtf8("border-image: url(:/background/calendar.png)"));

        gridLayout_12->addWidget(button_openCalendar, 4, 3, 1, 1);

        txt_addBirthday = new QLineEdit(page_addOne);
        txt_addBirthday->setObjectName("txt_addBirthday");
        txt_addBirthday->setMinimumSize(QSize(0, 40));
        txt_addBirthday->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));
        txt_addBirthday->setReadOnly(true);

        gridLayout_12->addWidget(txt_addBirthday, 4, 1, 1, 2);

        stackedWidget_4->addWidget(page_addOne);
        page_import = new QWidget();
        page_import->setObjectName("page_import");
        gridLayout_13 = new QGridLayout(page_import);
        gridLayout_13->setObjectName("gridLayout_13");
        gridLayout_13->setHorizontalSpacing(77);
        gridLayout_13->setContentsMargins(11, 65, 11, 115);
        txt_path = new QLineEdit(page_import);
        txt_path->setObjectName("txt_path");
        txt_path->setMinimumSize(QSize(0, 45));
        txt_path->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"background-color: rgba(255,255,255,200);\n"
"padding: 10px;"));

        gridLayout_13->addWidget(txt_path, 1, 0, 1, 2);

        button_confirm_6 = new QPushButton(page_import);
        button_confirm_6->setObjectName("button_confirm_6");
        button_confirm_6->setMinimumSize(QSize(120, 45));
        button_confirm_6->setMaximumSize(QSize(120, 45));

        gridLayout_13->addWidget(button_confirm_6, 2, 0, 1, 1, Qt::AlignLeft);

        button_cancel_2 = new QPushButton(page_import);
        button_cancel_2->setObjectName("button_cancel_2");
        button_cancel_2->setMinimumSize(QSize(120, 45));
        button_cancel_2->setMaximumSize(QSize(120, 45));

        gridLayout_13->addWidget(button_cancel_2, 2, 1, 1, 1, Qt::AlignRight);

        lb_enterPath = new QLabel(page_import);
        lb_enterPath->setObjectName("lb_enterPath");
        lb_enterPath->setMaximumSize(QSize(16777215, 45));
        lb_enterPath->setFont(font4);

        gridLayout_13->addWidget(lb_enterPath, 0, 0, 1, 2, Qt::AlignBottom);

        stackedWidget_4->addWidget(page_import);
        page_calendar = new QWidget();
        page_calendar->setObjectName("page_calendar");
        gridLayout_15 = new QGridLayout(page_calendar);
        gridLayout_15->setObjectName("gridLayout_15");
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        calendarWidget_3 = new QCalendarWidget(page_calendar);
        calendarWidget_3->setObjectName("calendarWidget_3");
        calendarWidget_3->setStyleSheet(QString::fromUtf8("QCalendarWidget QToolButton#qt_calendar_nextmonth{\n"
"	border-image: url(:/background/right_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"	icon-size: 0px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton#qt_calendar_prevmonth{\n"
"	border-image: url(:/background/left_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"	icon-size: 0px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    background-color: rgb(118, 118, 118);\n"
"    color: #F5F0F0;\n"
"    border: 2px solid #000000;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: rgba(158, 158, 158,200);\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:pressed {\n"
"    background-color: rgba(118, 118, 118,200);\n"
"}\n"
"\n"
"QCalendarWidget QWidget#qt_calendar_navigationbar {\n"
"    background-color: rgba(198, 198, 198,200);\n"
"    color: #292727;\n"
"	padding-left: 5px;\n"
"    border-style: none;\n"
"    border-bottom: 2px solid #000000;"
                        "\n"
"    border-right: 1px solid #000000;\n"
"    border-left: 1px solid #000000;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::up-button {\n"
"	border-image: url(:/background/up_arrow.png);\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox::down-button {\n"
"	border-image: url(:/background/down_arrow.png);	\n"
"	background-position: center;\n"
"	background-repeat: none;\n"
"}\n"
"\n"
"QCalendarWidget QWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	font-size: 14px;\n"
"	border: 1px solid black;\n"
"    gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QCalendarWidget QWidget::item:selected {\n"
"    background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QCalendarWidget QMenu {\n"
"	padding-left: 10px;\n"
"}\n"
"\n"
"#qt_calendar_monthbutton::menu-indicator"
                        "{\n"
"   width:0px;\n"
"}\n"
""));
        calendarWidget_3->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

        gridLayout_15->addWidget(calendarWidget_3, 0, 0, 1, 1);

        button_selectDate = new QPushButton(page_calendar);
        button_selectDate->setObjectName("button_selectDate");
        button_selectDate->setMinimumSize(QSize(0, 40));
        button_selectDate->setStyleSheet(QString::fromUtf8(""));

        gridLayout_15->addWidget(button_selectDate, 1, 0, 1, 1);

        stackedWidget_4->addWidget(page_calendar);

        gridLayout_14->addWidget(stackedWidget_4, 10, 0, 1, 5);

        button_back_9 = new QPushButton(AdAddStudent);
        button_back_9->setObjectName("button_back_9");
        button_back_9->setMinimumSize(QSize(200, 65));
        button_back_9->setMaximumSize(QSize(200, 65));
        button_back_9->setStyleSheet(QString::fromUtf8("margin: 5px"));

        gridLayout_14->addWidget(button_back_9, 11, 6, 1, 1, Qt::AlignRight);

        tableWidget_2 = new QTableWidget(AdAddStudent);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        tableWidget_2->setObjectName("tableWidget_2");
        tableWidget_2->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	background-color: rgba(118, 118, 118,200);\n"
"	color: #F5F0F0;\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color: rgba(158, 158, 158,200);\n"
"	color: #292727;\n"
"	border: 1px solid #696969;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"	padding: 4px;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QTableWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"        border: 2px solid black;\n"
"        background-color: rgb(118, 118, 118);\n"
"        height: 15px;\n"
"        margin: 0 22px 0 22px;\n"
"    }\n"
"    QScrollBar::handle:horizontal {\n"
"	   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"        border: 1px solid #adb0b6;\n"
"    "
                        "    border-radius: 4px;\n"
"        min-width: 20px;\n"
"    }\n"
"    QScrollBar::add-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: right;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: left;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
""
                        "    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_2->setSortingEnabled(false);

        gridLayout_14->addWidget(tableWidget_2, 10, 5, 1, 2);

        button_addOne = new QPushButton(AdAddStudent);
        button_addOne->setObjectName("button_addOne");
        sizePolicy.setHeightForWidth(button_addOne->sizePolicy().hasHeightForWidth());
        button_addOne->setSizePolicy(sizePolicy);
        button_addOne->setMinimumSize(QSize(370, 65));
        button_addOne->setMaximumSize(QSize(370, 65));
        button_addOne->setStyleSheet(QString::fromUtf8("margin: 5px;"));

        gridLayout_14->addWidget(button_addOne, 11, 0, 1, 1);

        button_import = new QPushButton(AdAddStudent);
        button_import->setObjectName("button_import");
        sizePolicy.setHeightForWidth(button_import->sizePolicy().hasHeightForWidth());
        button_import->setSizePolicy(sizePolicy);
        button_import->setMinimumSize(QSize(0, 65));
        button_import->setStyleSheet(QString::fromUtf8("border-image: url(:/background/File.png);\n"
"margin: 5px;"));

        gridLayout_14->addWidget(button_import, 11, 1, 1, 2);

        lb_selectClass = new QLabel(AdAddStudent);
        lb_selectClass->setObjectName("lb_selectClass");
        lb_selectClass->setFont(font6);
        lb_selectClass->setStyleSheet(QString::fromUtf8("color: #F5F0F0;\n"
""));

        gridLayout_14->addWidget(lb_selectClass, 8, 0, 1, 1);

        gridLayout_14->setColumnStretch(0, 5);
        stackedWidget_3->addWidget(AdAddStudent);
        AdAllClasses = new QWidget();
        AdAllClasses->setObjectName("AdAllClasses");
        lb_allClasses = new QLabel(AdAllClasses);
        lb_allClasses->setObjectName("lb_allClasses");
        lb_allClasses->setGeometry(QRect(60, 10, 777, 80));
        lb_allClasses->setFont(font9);
        lb_allClasses->setStyleSheet(QString::fromUtf8("color: #7FFFD4;"));
        lb_allClasses->setAlignment(Qt::AlignCenter);
        list_classes_2 = new QListWidget(AdAllClasses);
        list_classes_2->setObjectName("list_classes_2");
        list_classes_2->setGeometry(QRect(20, 190, 201, 351));
        list_classes_2->setFont(font13);
        list_classes_2->setStyleSheet(QString::fromUtf8("QListWidget::item {\n"
"    background-color: rgba(118, 118, 118, 200);\n"
"    color: #F5F0F0;\n"
"    border: 2px solid #000000;\n"
"}\n"
"\n"
"QListWidget::item:selected {\n"
"    background-color: rgba(198, 198, 198, 200);\n"
"    color: #292727;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: rgba(198, 198, 198, 200);\n"
"    color: #292727;\n"
"    padding: 4px;\n"
"    border-style: none;\n"
"    border-bottom: 2px solid #000000;\n"
"    border-right: 1px solid #000000;\n"
"    border-left: 1px solid #000000;\n"
"    box-shadow: 0 2px 4px 0 rgba(0, 0, 0, 0.15);\n"
"}\n"
"\n"
"QListWidget {\n"
"    background-color: rgb(118, 118, 118);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    height: 15px;\n"
"    margin: 0 22px 0 22px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    borde"
                        "r-radius: 4px;\n"
"    min-width: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal {\n"
"    background: black;\n"
"    width: 20px;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"    background: black;\n"
"    width: 20px;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: black;\n"
"    heigh"
                        "t: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""));
        table_student = new QTableWidget(AdAllClasses);
        if (table_student->columnCount() < 5)
            table_student->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_student->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_student->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_student->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_student->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_student->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        table_student->setObjectName("table_student");
        table_student->setGeometry(QRect(240, 190, 591, 351));
        table_student->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	background-color: rgba(118, 118, 118,200);\n"
"	color: #F5F0F0;\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color: rgba(158, 158, 158,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"	padding: 4px;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QTableWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"        border: 2px solid black;\n"
"        background-color: rgb(118, 118, 118);\n"
"        height: 15px;\n"
"        margin: 0 22px 0 22px;\n"
"    }\n"
"    QScrollBar::handle:horizontal {\n"
"	   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"        border: 1px solid #adb0b6;\n"
" "
                        "       border-radius: 4px;\n"
"        min-width: 20px;\n"
"    }\n"
"    QScrollBar::add-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: right;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: left;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical"
                        " {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        table_student->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_student->setSortingEnabled(false);
        table_student->horizontalHeader()->setCascadingSectionResizes(false);
        table_student->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table_student->verticalHeader()->setCascadingSectionResizes(false);
        lb_curClass = new QLabel(AdAllClasses);
        lb_curClass->setObjectName("lb_curClass");
        lb_curClass->setGeometry(QRect(460, 140, 151, 41));
        lb_curClass->setFont(font13);
        lb_curClass->setStyleSheet(QString::fromUtf8("color: #F5F0F0;\n"
""));
        lb_class = new QLabel(AdAllClasses);
        lb_class->setObjectName("lb_class");
        lb_class->setGeometry(QRect(50, 140, 151, 41));
        lb_class->setFont(font13);
        lb_class->setStyleSheet(QString::fromUtf8("color: #F5F0F0;\n"
""));
        button_back_12 = new QPushButton(AdAllClasses);
        button_back_12->setObjectName("button_back_12");
        button_back_12->setGeometry(QRect(630, 550, 200, 65));
        button_back_12->setMinimumSize(QSize(200, 65));
        button_back_12->setMaximumSize(QSize(200, 65));
        stackedWidget_3->addWidget(AdAllClasses);
        AdScoreboard = new QWidget();
        AdScoreboard->setObjectName("AdScoreboard");
        lb_viewScoreboard = new QLabel(AdScoreboard);
        lb_viewScoreboard->setObjectName("lb_viewScoreboard");
        lb_viewScoreboard->setGeometry(QRect(70, 10, 777, 80));
        lb_viewScoreboard->setFont(font9);
        lb_viewScoreboard->setStyleSheet(QString::fromUtf8("color: #7FFFD4;"));
        lb_viewScoreboard->setAlignment(Qt::AlignCenter);
        box_class = new QComboBox(AdScoreboard);
        box_class->addItem(QString());
        box_class->setObjectName("box_class");
        box_class->setGeometry(QRect(50, 140, 131, 31));
        QSizePolicy sizePolicy10(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Fixed);
        sizePolicy10.setHorizontalStretch(0);
        sizePolicy10.setVerticalStretch(0);
        sizePolicy10.setHeightForWidth(box_class->sizePolicy().hasHeightForWidth());
        box_class->setSizePolicy(sizePolicy10);
        box_class->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));
        box_year = new QComboBox(AdScoreboard);
        box_year->addItem(QString());
        box_year->setObjectName("box_year");
        box_year->setGeometry(QRect(200, 140, 141, 31));
        box_year->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));
        box_semester = new QComboBox(AdScoreboard);
        box_semester->addItem(QString());
        box_semester->setObjectName("box_semester");
        box_semester->setGeometry(QRect(360, 140, 141, 31));
        box_semester->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));
        table_scoreboard = new QTableWidget(AdScoreboard);
        table_scoreboard->setObjectName("table_scoreboard");
        table_scoreboard->setGeometry(QRect(50, 180, 751, 331));
        table_scoreboard->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	background-color: rgba(118, 118, 118,200);\n"
"	color: #000000;\n"
"	color: white;\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color: rgba(158, 158, 158,200);\n"
"	color: #292727;\n"
"	border: 1px solid #696969;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background-color: rgba(198, 198, 198,200);\n"
"	color: #000000;\n"
"	padding: 4px;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QTableWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"        border: 2px solid black;\n"
"        background-color: rgb(118, 118, 118);\n"
"        height: 15px;\n"
"        margin: 0 22px 0 22px;\n"
"    }\n"
"    QScrollBar::handle:horizontal {\n"
"	   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"        border: 1px soli"
                        "d #adb0b6;\n"
"        border-radius: 4px;\n"
"        min-width: 20px;\n"
"    }\n"
"    QScrollBar::add-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: right;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: left;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::s"
                        "ub-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        table_scoreboard->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_scoreboard->setSortingEnabled(false);
        table_scoreboard->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table_scoreboard->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        button_back_10 = new QPushButton(AdScoreboard);
        button_back_10->setObjectName("button_back_10");
        button_back_10->setGeometry(QRect(610, 530, 200, 65));
        button_back_10->setMinimumSize(QSize(200, 65));
        button_back_10->setMaximumSize(QSize(200, 65));
        button_ok_2 = new QPushButton(AdScoreboard);
        button_ok_2->setObjectName("button_ok_2");
        button_ok_2->setGeometry(QRect(640, 140, 161, 31));
        button_ok_2->setStyleSheet(QString::fromUtf8(""));
        stackedWidget_3->addWidget(AdScoreboard);
        AdCourseView = new QWidget();
        AdCourseView->setObjectName("AdCourseView");
        gridLayout_16 = new QGridLayout(AdCourseView);
        gridLayout_16->setObjectName("gridLayout_16");
        lb_courseView = new QLabel(AdCourseView);
        lb_courseView->setObjectName("lb_courseView");
        lb_courseView->setFont(font9);
        lb_courseView->setStyleSheet(QString::fromUtf8("color: #7FFFD4;"));
        lb_courseView->setAlignment(Qt::AlignCenter);

        gridLayout_16->addWidget(lb_courseView, 0, 0, 1, 1);

        stackedWidget_5 = new QStackedWidget(AdCourseView);
        stackedWidget_5->setObjectName("stackedWidget_5");
        sizePolicy3.setHeightForWidth(stackedWidget_5->sizePolicy().hasHeightForWidth());
        stackedWidget_5->setSizePolicy(sizePolicy3);
        stackedWidget_5->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        button_back_11 = new QPushButton(page_2);
        button_back_11->setObjectName("button_back_11");
        button_back_11->setGeometry(QRect(730, 500, 141, 41));
        sizePolicy10.setHeightForWidth(button_back_11->sizePolicy().hasHeightForWidth());
        button_back_11->setSizePolicy(sizePolicy10);
        button_back_11->setMinimumSize(QSize(0, 0));
        button_back_11->setStyleSheet(QString::fromUtf8(""));
        box_selectSY_2 = new QComboBox(page_2);
        box_selectSY_2->setObjectName("box_selectSY_2");
        box_selectSY_2->setGeometry(QRect(194, 12, 141, 31));
        sizePolicy4.setHeightForWidth(box_selectSY_2->sizePolicy().hasHeightForWidth());
        box_selectSY_2->setSizePolicy(sizePolicy4);
        box_selectSY_2->setFont(font3);
        box_selectSY_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));
        table_course = new QTableWidget(page_2);
        if (table_course->columnCount() < 9)
            table_course->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        table_course->setHorizontalHeaderItem(8, __qtablewidgetitem25);
        table_course->setObjectName("table_course");
        table_course->setGeometry(QRect(10, 50, 891, 441));
        sizePolicy5.setHeightForWidth(table_course->sizePolicy().hasHeightForWidth());
        table_course->setSizePolicy(sizePolicy5);
        table_course->setMinimumSize(QSize(831, 406));
        table_course->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	background-color: rgba(118, 118, 118,200);\n"
"	color: #F5F0F0;\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color: rgba(158, 158, 158,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"}\n"
"\n"
"\n"
"QHeaderView::section {\n"
"	background-color: rgba(198, 198, 198,200);\n"
"	color: #292727;\n"
"	padding: 4px;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QTableWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"        border: 2px solid black;\n"
"        background-color: rgb(118, 118, 118);\n"
"        height: 15px;\n"
"        margin: 0 22px 0 22px;\n"
"    }\n"
"    QScrollBar::handle:horizontal {\n"
"	   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"        border: 1px solid #adb0b6;\n"
""
                        "        border-radius: 4px;\n"
"        min-width: 20px;\n"
"    }\n"
"    QScrollBar::add-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: right;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: left;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertica"
                        "l {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        table_course->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_course->setSelectionMode(QAbstractItemView::SingleSelection);
        table_course->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        table_course->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(329, 0, 161, 47));
        sizePolicy9.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy9);
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setFont(font6);
        label_2->setStyleSheet(QString::fromUtf8("color:white;\n"
"padding: 10px"));
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 187, 47));
        sizePolicy10.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy10);
        label->setFont(font6);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"padding: 10px;\n"
""));
        box_selectSem = new QComboBox(page_2);
        box_selectSem->setObjectName("box_selectSem");
        box_selectSem->setGeometry(QRect(500, 10, 121, 31));
        sizePolicy10.setHeightForWidth(box_selectSem->sizePolicy().hasHeightForWidth());
        box_selectSem->setSizePolicy(sizePolicy10);
        box_selectSem->setFont(font3);
        box_selectSem->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	font-size: 16px;\n"
"	border-image: url(:/background/button.png);\n"
"	background-color: rgb(133, 133, 133);\n"
"	color: #F5F0F0;\n"
"}\n"
"\n"
"QComboBox::hover {\n"
" 	color: #292727\n"
"}"));
        button_viewStudent = new QPushButton(page_2);
        button_viewStudent->setObjectName("button_viewStudent");
        button_viewStudent->setGeometry(QRect(550, 500, 131, 40));
        sizePolicy5.setHeightForWidth(button_viewStudent->sizePolicy().hasHeightForWidth());
        button_viewStudent->setSizePolicy(sizePolicy5);
        button_viewStudent->setStyleSheet(QString::fromUtf8("padding: 10px"));
        button_removeFilter = new QPushButton(page_2);
        button_removeFilter->setObjectName("button_removeFilter");
        button_removeFilter->setGeometry(QRect(680, 0, 161, 40));
        sizePolicy10.setHeightForWidth(button_removeFilter->sizePolicy().hasHeightForWidth());
        button_removeFilter->setSizePolicy(sizePolicy10);
        button_removeFilter->setStyleSheet(QString::fromUtf8("padding: 10px;"));
        checkBox_edit = new QCheckBox(page_2);
        checkBox_edit->setObjectName("checkBox_edit");
        checkBox_edit->setGeometry(QRect(10, 510, 93, 26));
        QFont font14;
        font14.setPointSize(11);
        checkBox_edit->setFont(font14);
        checkBox_edit->setStyleSheet(QString::fromUtf8("color: white;"));
        button_addCourse = new QPushButton(page_2);
        button_addCourse->setObjectName("button_addCourse");
        button_addCourse->setGeometry(QRect(100, 500, 131, 41));
        button_removeCourse = new QPushButton(page_2);
        button_removeCourse->setObjectName("button_removeCourse");
        button_removeCourse->setGeometry(QRect(270, 500, 141, 41));
        stackedWidget_5->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        table_student_2 = new QTableWidget(page_4);
        if (table_student_2->columnCount() < 6)
            table_student_2->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        table_student_2->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        table_student_2->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        table_student_2->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        table_student_2->setHorizontalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        table_student_2->setHorizontalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        table_student_2->setHorizontalHeaderItem(5, __qtablewidgetitem31);
        table_student_2->setObjectName("table_student_2");
        table_student_2->setGeometry(QRect(10, 50, 891, 441));
        sizePolicy.setHeightForWidth(table_student_2->sizePolicy().hasHeightForWidth());
        table_student_2->setSizePolicy(sizePolicy);
        table_student_2->setStyleSheet(QString::fromUtf8("QTableWidget::item {\n"
"	background-color: rgba(118, 118, 118,200);\n"
"	color: #000000;\n"
"	color: white;\n"
"	border: 2px solid #000000;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"	background-color: rgba(158, 158, 158,200);\n"
"	color: #292727;\n"
"    border: 1px solid #696969;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"	background-color: rgba(198, 198, 198,200);\n"
"	color: #000000;\n"
"	padding: 4px;\n"
"	border-style: none;\n"
"	border-bottom: 2px solid #000000;\n"
"	border-right: 1px solid #000000;\n"
"	border-left: 1px solid #000000; \n"
"}\n"
"\n"
"QTableWidget {\n"
"	background-color: rgb(118, 118, 118);\n"
"	gridline-color: rgb(198, 198, 198);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"        border: 2px solid black;\n"
"        background-color: rgb(118, 118, 118);\n"
"        height: 15px;\n"
"        margin: 0 22px 0 22px;\n"
"    }\n"
"    QScrollBar::handle:horizontal {\n"
"	   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"        border: 1px s"
                        "olid #adb0b6;\n"
"        border-radius: 4px;\n"
"        min-width: 20px;\n"
"    }\n"
"    QScrollBar::add-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: right;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"    QScrollBar::sub-line:horizontal {\n"
"        background: black;\n"
"        width: 20px;\n"
"        subcontrol-position: left;\n"
"        subcontrol-origin: margin;\n"
"    }\n"
"\n"
"QScrollBar:vertical {\n"
"    border: 2px solid black;\n"
"    background-color: rgb(118, 118, 118);\n"
"    width: 15px;\n"
"    margin: 22px 0 22px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #D3D3D3, stop:1 #808080);\n"
"    border: 1px solid #adb0b6;\n"
"    border-radius: 4px;\n"
"    min-height: 20px;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"QScrollBar"
                        "::sub-line:vertical {\n"
"    background: black;\n"
"    height: 20px;\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"\n"
"\n"
""));
        table_student_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        table_student_2->setSelectionMode(QAbstractItemView::SingleSelection);
        button_coursesList = new QPushButton(page_4);
        button_coursesList->setObjectName("button_coursesList");
        button_coursesList->setGeometry(QRect(730, 510, 141, 40));
        button_coursesList->setStyleSheet(QString::fromUtf8("padding: 10px;"));
        lb_scoreBoard = new QLabel(page_4);
        lb_scoreBoard->setObjectName("lb_scoreBoard");
        lb_scoreBoard->setGeometry(QRect(70, 0, 582, 40));
        lb_scoreBoard->setMaximumSize(QSize(16777215, 41));
        lb_scoreBoard->setFont(font8);
        lb_scoreBoard->setStyleSheet(QString::fromUtf8("color:white;"));
        lb_scoreBoard->setAlignment(Qt::AlignCenter);
        button_addStudent_2 = new QPushButton(page_4);
        button_addStudent_2->setObjectName("button_addStudent_2");
        button_addStudent_2->setGeometry(QRect(90, 510, 161, 41));
        button_removeStudent = new QPushButton(page_4);
        button_removeStudent->setObjectName("button_removeStudent");
        button_removeStudent->setGeometry(QRect(280, 510, 171, 41));
        button_importScoreBoard = new QPushButton(page_4);
        button_importScoreBoard->setObjectName("button_importScoreBoard");
        button_importScoreBoard->setGeometry(QRect(490, 510, 171, 41));
        checkBox_4 = new QCheckBox(page_4);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(10, 510, 111, 31));
        checkBox_4->setFont(font14);
        checkBox_4->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        button_exportTable = new QPushButton(page_4);
        button_exportTable->setObjectName("button_exportTable");
        button_exportTable->setGeometry(QRect(700, 0, 151, 41));
        stackedWidget_5->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        lb_addCourse = new QLabel(page_5);
        lb_addCourse->setObjectName("lb_addCourse");
        lb_addCourse->setGeometry(QRect(40, 20, 861, 41));
        lb_addCourse->setFont(font8);
        lb_addCourse->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        lb_addCourse->setAlignment(Qt::AlignCenter);
        box_numCredits = new QComboBox(page_5);
        box_numCredits->addItem(QString());
        box_numCredits->addItem(QString());
        box_numCredits->addItem(QString());
        box_numCredits->setObjectName("box_numCredits");
        box_numCredits->setGeometry(QRect(260, 400, 71, 41));
        box_numCredits->setFont(font4);
        box_dayOfWeek = new QComboBox(page_5);
        box_dayOfWeek->addItem(QString());
        box_dayOfWeek->addItem(QString());
        box_dayOfWeek->addItem(QString());
        box_dayOfWeek->addItem(QString());
        box_dayOfWeek->addItem(QString());
        box_dayOfWeek->addItem(QString());
        box_dayOfWeek->setObjectName("box_dayOfWeek");
        box_dayOfWeek->setGeometry(QRect(460, 400, 131, 41));
        box_dayOfWeek->setFont(font4);
        box_session = new QComboBox(page_5);
        box_session->addItem(QString());
        box_session->addItem(QString());
        box_session->addItem(QString());
        box_session->addItem(QString());
        box_session->setObjectName("box_session");
        box_session->setGeometry(QRect(600, 400, 131, 41));
        box_session->setFont(font4);
        lb_numCredits = new QLabel(page_5);
        lb_numCredits->setObjectName("lb_numCredits");
        lb_numCredits->setGeometry(QRect(60, 400, 201, 41));
        lb_numCredits->setFont(font4);
        lb_numCredits->setStyleSheet(QString::fromUtf8("color: white;"));
        lb_session = new QLabel(page_5);
        lb_session->setObjectName("lb_session");
        lb_session->setGeometry(QRect(370, 400, 91, 41));
        lb_session->setFont(font4);
        lb_session->setStyleSheet(QString::fromUtf8("color: white;"));
        button_confirm_7 = new QPushButton(page_5);
        button_confirm_7->setObjectName("button_confirm_7");
        button_confirm_7->setGeometry(QRect(20, 470, 221, 61));
        button_back_13 = new QPushButton(page_5);
        button_back_13->setObjectName("button_back_13");
        button_back_13->setGeometry(QRect(650, 470, 231, 61));
        lb_teacherName = new QLabel(page_5);
        lb_teacherName->setObjectName("lb_teacherName");
        lb_teacherName->setGeometry(QRect(90, 280, 153, 31));
        lb_teacherName->setFont(font4);
        lb_teacherName->setStyleSheet(QString::fromUtf8("color: white;"));
        lb_teacherName->setAlignment(Qt::AlignCenter);
        txt_teacherName = new QLineEdit(page_5);
        txt_teacherName->setObjectName("txt_teacherName");
        txt_teacherName->setGeometry(QRect(260, 270, 471, 53));
        txt_teacherName->setMinimumSize(QSize(0, 53));
        txt_teacherName->setFont(font4);
        txt_teacherName->setStyleSheet(QString::fromUtf8(""));
        lb_className = new QLabel(page_5);
        lb_className->setObjectName("lb_className");
        lb_className->setGeometry(QRect(110, 220, 119, 31));
        lb_className->setFont(font4);
        lb_className->setStyleSheet(QString::fromUtf8("color: white;"));
        lb_className->setAlignment(Qt::AlignCenter);
        txt_className_2 = new QLineEdit(page_5);
        txt_className_2->setObjectName("txt_className_2");
        txt_className_2->setGeometry(QRect(260, 210, 471, 53));
        txt_className_2->setMinimumSize(QSize(0, 53));
        txt_className_2->setFont(font4);
        txt_className_2->setStyleSheet(QString::fromUtf8(""));
        txt_courseName = new QLineEdit(page_5);
        txt_courseName->setObjectName("txt_courseName");
        txt_courseName->setGeometry(QRect(260, 150, 471, 53));
        txt_courseName->setMinimumSize(QSize(0, 53));
        txt_courseName->setFont(font4);
        txt_courseName->setStyleSheet(QString::fromUtf8(""));
        lb_courseName = new QLabel(page_5);
        lb_courseName->setObjectName("lb_courseName");
        lb_courseName->setGeometry(QRect(100, 160, 137, 31));
        lb_courseName->setFont(font4);
        lb_courseName->setStyleSheet(QString::fromUtf8("color: white;"));
        lb_courseName->setAlignment(Qt::AlignCenter);
        txt_courseID = new QLineEdit(page_5);
        txt_courseID->setObjectName("txt_courseID");
        txt_courseID->setGeometry(QRect(260, 90, 471, 53));
        txt_courseID->setMinimumSize(QSize(0, 53));
        txt_courseID->setFont(font4);
        txt_courseID->setStyleSheet(QString::fromUtf8(""));
        lb_courseID = new QLabel(page_5);
        lb_courseID->setObjectName("lb_courseID");
        lb_courseID->setGeometry(QRect(130, 100, 98, 31));
        lb_courseID->setFont(font4);
        lb_courseID->setStyleSheet(QString::fromUtf8("color: white;"));
        lb_courseID->setAlignment(Qt::AlignCenter);
        txt_maxStudents = new QLineEdit(page_5);
        txt_maxStudents->setObjectName("txt_maxStudents");
        txt_maxStudents->setGeometry(QRect(260, 330, 471, 53));
        txt_maxStudents->setMinimumSize(QSize(0, 53));
        txt_maxStudents->setFont(font4);
        txt_maxStudents->setStyleSheet(QString::fromUtf8(""));
        lb_maxStudents = new QLabel(page_5);
        lb_maxStudents->setObjectName("lb_maxStudents");
        lb_maxStudents->setGeometry(QRect(90, 340, 153, 31));
        lb_maxStudents->setFont(font4);
        lb_maxStudents->setStyleSheet(QString::fromUtf8("color: white;"));
        lb_maxStudents->setAlignment(Qt::AlignCenter);
        stackedWidget_5->addWidget(page_5);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_3 = new QLabel(page_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(230, 0, 451, 51));
        label_3->setFont(font8);
        label_3->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget_5->addWidget(page_3);

        gridLayout_16->addWidget(stackedWidget_5, 1, 0, 1, 1);

        stackedWidget_3->addWidget(AdCourseView);

        gridLayout_4->addWidget(stackedWidget_3, 0, 1, 1, 1);

        gridLayout_4->setColumnStretch(0, 5);
        gridLayout_4->setColumnStretch(1, 19);
        stackedWidget->addWidget(admin_homepage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        stackedWidget_2->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(9);
        stackedWidget_4->setCurrentIndex(0);
        stackedWidget_5->setCurrentIndex(0);
        box_numCredits->setCurrentIndex(-1);
        box_dayOfWeek->setCurrentIndex(-1);
        box_session->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lb_signin->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        lb_username->setText(QCoreApplication::translate("MainWindow", "Username", nullptr));
        lb_password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        txtPassword->setText(QString());
        checkBox->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        button_signin->setText(QCoreApplication::translate("MainWindow", "Sign In", nullptr));
        button_exit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        avatar->setText(QString());
        name->setText(QCoreApplication::translate("MainWindow", "Hi, Student", nullptr));
        button_StuHome->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        button_StuMyProfile->setText(QCoreApplication::translate("MainWindow", "MY PROFILE", nullptr));
        button_StuMyCourses->setText(QCoreApplication::translate("MainWindow", "MY COURSES", nullptr));
        button_StuChangePassword->setText(QCoreApplication::translate("MainWindow", "CHANGE PASSWORD", nullptr));
        button_StuSignOut->setText(QCoreApplication::translate("MainWindow", "SIGN OUT", nullptr));
        slogan_2->setText(QCoreApplication::translate("MainWindow", "The only way to do great work is to love what you do", nullptr));
        slogan_1->setText(QCoreApplication::translate("MainWindow", "Take A Chance To Make A Change", nullptr));
        button_currentDay->setText(QCoreApplication::translate("MainWindow", "CURRENT DATE", nullptr));
        slogan_3->setText(QCoreApplication::translate("MainWindow", "Believe you can and you\342\200\231re halfway there", nullptr));
        lb_welcome->setText(QCoreApplication::translate("MainWindow", "WELCOME", nullptr));
        lb_StuSocialID->setText(QCoreApplication::translate("MainWindow", "Social ID:   ", nullptr));
        lb_StuBirthday->setText(QCoreApplication::translate("MainWindow", "Birthday:   ", nullptr));
        lb_StuMainClass->setText(QCoreApplication::translate("MainWindow", "Class:   ", nullptr));
        lb_StuGender->setText(QCoreApplication::translate("MainWindow", "Gender:   ", nullptr));
        button_back_2->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_StuName->setText(QCoreApplication::translate("MainWindow", "Name:   ", nullptr));
        lb_StuID->setText(QCoreApplication::translate("MainWindow", "Student ID:   ", nullptr));
        lb_MyProfile->setText(QCoreApplication::translate("MainWindow", "My Profile", nullptr));
        lb_MyCourses->setText(QCoreApplication::translate("MainWindow", "My Courses", nullptr));
        lb_select_sy->setText(QCoreApplication::translate("MainWindow", "Select School Year", nullptr));
        lb_select_sem->setText(QCoreApplication::translate("MainWindow", "Select Semester", nullptr));
        sem_select->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        sem_select->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        sem_select->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));

        button_ok->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Course ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Course Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Class Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Tearcher Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Number of Credits", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Course Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Day Of Week", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Session", nullptr));
        button_back_5->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        button_viewScore->setText(QCoreApplication::translate("MainWindow", "VIEW SCORES", nullptr));
        lb_confirmPass->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        button_back->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        button_confirm->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        lb_changePass->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        lb_curPass->setText(QCoreApplication::translate("MainWindow", "Current Password:", nullptr));
        lb_newPass->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        txtCurPass->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        lb_latestSY->setText(QCoreApplication::translate("MainWindow", "Latest School Year:", nullptr));
        lb_latestSem->setText(QCoreApplication::translate("MainWindow", "Latest Semester:", nullptr));
        avatar_2->setText(QString());
        name_2->setText(QCoreApplication::translate("MainWindow", "Hi, Admin", nullptr));
        button_AdHome->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        button_AdMyProfile->setText(QCoreApplication::translate("MainWindow", "MY PROFILE", nullptr));
        button_AdChangePassword->setText(QCoreApplication::translate("MainWindow", "CHANGE PASSWORD", nullptr));
        button_AdSignOut->setText(QCoreApplication::translate("MainWindow", "SIGN OUT", nullptr));
        lb_welcome_2->setText(QCoreApplication::translate("MainWindow", "WELCOME", nullptr));
        button_create_sy->setText(QCoreApplication::translate("MainWindow", "CREATE A NEW SCHOOL YEAR", nullptr));
        button_class_manage->setText(QCoreApplication::translate("MainWindow", "CLASS MANAGEMENT", nullptr));
        button_create_sem->setText(QCoreApplication::translate("MainWindow", "CREATE A NEW SEMESTER", nullptr));
        button_course_manage->setText(QCoreApplication::translate("MainWindow", "COURSE MANAGEMENT", nullptr));
        lb_AdID->setText(QCoreApplication::translate("MainWindow", "Staff ID:   ", nullptr));
        button_back_4->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_AdName->setText(QCoreApplication::translate("MainWindow", "Name:   ", nullptr));
        lb_MyProfile_2->setText(QCoreApplication::translate("MainWindow", "My Profile", nullptr));
        lb_AdGender->setText(QCoreApplication::translate("MainWindow", "Gender:   ", nullptr));
        lb_AdBirthday->setText(QCoreApplication::translate("MainWindow", "Birthday:   ", nullptr));
        lb_AdSocialID->setText(QCoreApplication::translate("MainWindow", "Social ID:   ", nullptr));
        lb_changePass_2->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        lb_curPass_2->setText(QCoreApplication::translate("MainWindow", "Current Password:", nullptr));
        txtCurPass_2->setText(QString());
        lb_newPass_2->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        lb_confirmPass_2->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        button_confirm_2->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        button_back_3->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_createNewSemester->setText(QCoreApplication::translate("MainWindow", "Create New Semester", nullptr));
        button_currentDate->setText(QCoreApplication::translate("MainWindow", "CURRENT DAY", nullptr));
        button_setEndDate->setText(QCoreApplication::translate("MainWindow", "Set End Date", nullptr));
        button_confirm_3->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        button_back_6->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        button_setStartDate->setText(QCoreApplication::translate("MainWindow", "Set Start Date", nullptr));
        lb_latestSED->setText(QCoreApplication::translate("MainWindow", "Latest Semester End Date:", nullptr));
        lb_classManage->setText(QCoreApplication::translate("MainWindow", "CLASS MANAGEMENT", nullptr));
        button_scoreOfClass->setText(QCoreApplication::translate("MainWindow", "VIEW SCOREBOARD OF CLASS", nullptr));
        button_allClasses->setText(QCoreApplication::translate("MainWindow", "ALL CLASSES", nullptr));
        button_addStudent->setText(QCoreApplication::translate("MainWindow", "ADD STUDENTS TO CLASS", nullptr));
        button_createClass->setText(QCoreApplication::translate("MainWindow", "CREATED NEW CLASS", nullptr));
        button_back_7->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_allClassesIn->setText(QCoreApplication::translate("MainWindow", "All Classes In", nullptr));

        const bool __sortingEnabled = list_classes->isSortingEnabled();
        list_classes->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list_classes->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "23CLC03", nullptr));
        list_classes->setSortingEnabled(__sortingEnabled);

        lb_createNewClass->setText(QCoreApplication::translate("MainWindow", "CREATE NEW CLASS", nullptr));
        lb_selectSY->setText(QCoreApplication::translate("MainWindow", "Select School Year:", nullptr));
        box_selectSY->setItemText(0, QCoreApplication::translate("MainWindow", "2023-2024", nullptr));

        lb_enterClassName->setText(QCoreApplication::translate("MainWindow", "Enter New Class Name:", nullptr));
        txt_className->setText(QString());
        button_confirm_4->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        button_back_8->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_addNewStudent->setText(QCoreApplication::translate("MainWindow", "ADD NEW STUDENT", nullptr));
        button_confirm_5->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        lb_addStuID->setText(QCoreApplication::translate("MainWindow", "Student ID", nullptr));
        lb_addName->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        lb_addGender->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        lb_addBirthday->setText(QCoreApplication::translate("MainWindow", "Birthday", nullptr));
        box_addGender->setItemText(0, QCoreApplication::translate("MainWindow", "Male", nullptr));
        box_addGender->setItemText(1, QCoreApplication::translate("MainWindow", "Female", nullptr));

        button_cancel->setText(QCoreApplication::translate("MainWindow", "CANCEL", nullptr));
        lb_addSocialID->setText(QCoreApplication::translate("MainWindow", "Social ID", nullptr));
        button_openCalendar->setText(QString());
        txt_addBirthday->setText(QString());
        txt_addBirthday->setPlaceholderText(QCoreApplication::translate("MainWindow", "Click the calendar icon", nullptr));
        button_confirm_6->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        button_cancel_2->setText(QCoreApplication::translate("MainWindow", "CANCEL", nullptr));
        lb_enterPath->setText(QCoreApplication::translate("MainWindow", "Enter Path To CSV File:", nullptr));
        button_selectDate->setText(QCoreApplication::translate("MainWindow", "Select Date", nullptr));
        button_back_9->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Student ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Social ID", nullptr));
        button_addOne->setText(QCoreApplication::translate("MainWindow", "ADD ONE STUDENT", nullptr));
#if QT_CONFIG(tooltip)
        button_import->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        button_import->setText(QString());
        lb_selectClass->setText(QCoreApplication::translate("MainWindow", "Select Class:", nullptr));
        lb_allClasses->setText(QCoreApplication::translate("MainWindow", "ALL CLASSES / STUDENTS", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = table_student->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Student ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = table_student->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = table_student->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Gender", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = table_student->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Birthday", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = table_student->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Social ID", nullptr));
        lb_curClass->setText(QCoreApplication::translate("MainWindow", "23CLC03", nullptr));
        lb_class->setText(QCoreApplication::translate("MainWindow", "CLASSES", nullptr));
        button_back_12->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_viewScoreboard->setText(QCoreApplication::translate("MainWindow", "VIEW SCOREBOARD", nullptr));
        box_class->setItemText(0, QCoreApplication::translate("MainWindow", "class", nullptr));

        box_year->setItemText(0, QCoreApplication::translate("MainWindow", "year", nullptr));

        box_semester->setItemText(0, QCoreApplication::translate("MainWindow", "semester", nullptr));

        button_back_10->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        button_ok_2->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        lb_courseView->setText(QCoreApplication::translate("MainWindow", "COURSE MANAGEMENT", nullptr));
        button_back_11->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = table_course->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Course ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = table_course->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Course Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = table_course->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Class Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = table_course->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Teacher Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = table_course->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Credits", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = table_course->horizontalHeaderItem(5);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = table_course->horizontalHeaderItem(6);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Max Size", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = table_course->horizontalHeaderItem(7);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = table_course->horizontalHeaderItem(8);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Session", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select Semester", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Select School Year", nullptr));
        button_viewStudent->setText(QCoreApplication::translate("MainWindow", "DETAIL", nullptr));
        button_removeFilter->setText(QCoreApplication::translate("MainWindow", "REMOVE FILTER", nullptr));
        checkBox_edit->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        button_addCourse->setText(QCoreApplication::translate("MainWindow", "ADD COURSE", nullptr));
        button_removeCourse->setText(QCoreApplication::translate("MainWindow", "REMOVE COURSE", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = table_student_2->horizontalHeaderItem(0);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Student ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = table_student_2->horizontalHeaderItem(1);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Full Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = table_student_2->horizontalHeaderItem(2);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Mid Term", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = table_student_2->horizontalHeaderItem(3);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Final", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = table_student_2->horizontalHeaderItem(4);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Other", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = table_student_2->horizontalHeaderItem(5);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        button_coursesList->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_scoreBoard->setText(QCoreApplication::translate("MainWindow", "COURSE ID - COURSE NAME - CLASS NAME", nullptr));
        button_addStudent_2->setText(QCoreApplication::translate("MainWindow", "ADD STUDENT", nullptr));
        button_removeStudent->setText(QCoreApplication::translate("MainWindow", "REMOVE STUDENT", nullptr));
        button_importScoreBoard->setText(QCoreApplication::translate("MainWindow", "IMPORT SCOREBOARD", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        button_exportTable->setText(QCoreApplication::translate("MainWindow", "EXPORT TABLE", nullptr));
        lb_addCourse->setText(QCoreApplication::translate("MainWindow", "ADD COURSE", nullptr));
        box_numCredits->setItemText(0, QCoreApplication::translate("MainWindow", "2", nullptr));
        box_numCredits->setItemText(1, QCoreApplication::translate("MainWindow", "3", nullptr));
        box_numCredits->setItemText(2, QCoreApplication::translate("MainWindow", "4", nullptr));

        box_dayOfWeek->setItemText(0, QCoreApplication::translate("MainWindow", "MON", nullptr));
        box_dayOfWeek->setItemText(1, QCoreApplication::translate("MainWindow", "TUE", nullptr));
        box_dayOfWeek->setItemText(2, QCoreApplication::translate("MainWindow", "WED", nullptr));
        box_dayOfWeek->setItemText(3, QCoreApplication::translate("MainWindow", "THU", nullptr));
        box_dayOfWeek->setItemText(4, QCoreApplication::translate("MainWindow", "FRI", nullptr));
        box_dayOfWeek->setItemText(5, QCoreApplication::translate("MainWindow", "SAT", nullptr));

        box_session->setItemText(0, QCoreApplication::translate("MainWindow", "07:30", nullptr));
        box_session->setItemText(1, QCoreApplication::translate("MainWindow", "09:30", nullptr));
        box_session->setItemText(2, QCoreApplication::translate("MainWindow", "13:30", nullptr));
        box_session->setItemText(3, QCoreApplication::translate("MainWindow", "15:30", nullptr));

        lb_numCredits->setText(QCoreApplication::translate("MainWindow", "Number of Credits", nullptr));
        lb_session->setText(QCoreApplication::translate("MainWindow", "Session", nullptr));
        button_confirm_7->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        button_back_13->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_teacherName->setText(QCoreApplication::translate("MainWindow", "Tearcher Name", nullptr));
        lb_className->setText(QCoreApplication::translate("MainWindow", "Class Name", nullptr));
        lb_courseName->setText(QCoreApplication::translate("MainWindow", "Course Name", nullptr));
        lb_courseID->setText(QCoreApplication::translate("MainWindow", "Course ID", nullptr));
        txt_maxStudents->setPlaceholderText(QCoreApplication::translate("MainWindow", "Default 50", nullptr));
        lb_maxStudents->setText(QCoreApplication::translate("MainWindow", "Max Students", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "ADD STUDENT TO COURSE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
