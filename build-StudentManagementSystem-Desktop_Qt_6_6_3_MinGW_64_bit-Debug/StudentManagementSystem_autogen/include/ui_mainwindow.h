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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QStackedWidget *stackedWidget_2;
    QWidget *StuHome;
    QGridLayout *gridLayout_9;
    QLabel *slogan_3;
    QLabel *lb_welcome;
    QLabel *slogan_1;
    QVBoxLayout *verticalLayout_4;
    QCalendarWidget *calendarWidget;
    QPushButton *button_currentDay;
    QLabel *slogan_2;
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
    QLabel *lb_MyCourses;
    QTableWidget *tableWidget;
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
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lb_latestSY;
    QLabel *lb_curSY;
    QLabel *avatar;
    QLabel *name;
    QPushButton *button_StuHome;
    QPushButton *button_StuMyProfile;
    QPushButton *button_StuMyCourses;
    QPushButton *button_StuChangePassword;
    QPushButton *button_StuSignOut;
    QWidget *admin_homepage;
    QGridLayout *gridLayout_4;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *avatar_2;
    QLabel *name_2;
    QPushButton *button_AdHome;
    QPushButton *button_AdMyProfile;
    QPushButton *button_AdChangePassword;
    QPushButton *button_AdSignOut;
    QStackedWidget *stackedWidget_3;
    QWidget *AdHome;
    QLabel *lb_welcome_2;
    QWidget *AdProfile;
    QGridLayout *gridLayout_8;
    QLabel *lb_AdID;
    QLineEdit *txt_AdID;
    QLabel *lb_AdName;
    QLineEdit *txt_AdName;
    QLabel *lb_AdGender;
    QLineEdit *txt_AdGender;
    QLabel *lb_AdBirthday;
    QLineEdit *txt_AdBirthday;
    QLabel *lb_AdSocialID;
    QLineEdit *txt_AdSocialID;
    QPushButton *button_back_4;
    QLabel *lb_MyProfile_2;
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
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1190, 715);
        MainWindow->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border-image: url(:/background/button.png);\n"
"	color: white;\n"
"}\n"
"QPushButton:hover { color: black; }\n"
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
"	border-image: url(:/background/Minecraft HD world.jpg);\n"
"}\n"
"\n"
"#student_homepage{\n"
"	border-image: url(:/background/Lovely Minecraft Hd Wallpaper 1920x1080.jpg);\n"
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
"	background-color: rgba(0, 0, 0, 175);\n"
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
        lb_signin->setStyleSheet(QString::fromUtf8(""));
        lb_signin->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_signin);

        lb_username = new QLabel(widget);
        lb_username->setObjectName("lb_username");
        QFont font1;
        font1.setPointSize(22);
        font1.setBold(true);
        lb_username->setFont(font1);

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
"	background-color: transparent;\n"
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
        font3.setPointSize(11);
        checkBox->setFont(font3);
        checkBox->setStyleSheet(QString::fromUtf8(""));

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
        stackedWidget_2 = new QStackedWidget(student_homepage);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setStyleSheet(QString::fromUtf8("#StuHome{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"#StuChangePassword{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#StuProfile{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#StuHome{\n"
"	background-color: rgba(0, 0, 0, 80);\n"
"}\n"
"\n"
"#lb_StuID{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_StuName{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_StuGender{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_StuBirthday{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_StuMainClass{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_StuSocialID{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_MyProfile{\n"
"	color:rgb(151, 255, 168);\n"
"}\n"
"\n"
"#StuCourse{\n"
"background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#lb_MyCourses{\n"
"	color:rgb(151, 255, 168);\n"
"}\n"
"\n"
"#lb_welcome{\n"
"	color:rgb(151, 255, 168);\n"
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
"\n"
"#txt_StuID{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_"
                        "StuName{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_StuGender{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_StuBirthday{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_StuClass{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_StuSocialID{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txtCurPass{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txtNewPass{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txtConfirmPass{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}"));
        StuHome = new QWidget();
        StuHome->setObjectName("StuHome");
        gridLayout_9 = new QGridLayout(StuHome);
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setHorizontalSpacing(30);
        gridLayout_9->setVerticalSpacing(0);
        gridLayout_9->setContentsMargins(20, 15, 20, 60);
        slogan_3 = new QLabel(StuHome);
        slogan_3->setObjectName("slogan_3");
        QFont font5;
        font5.setPointSize(16);
        slogan_3->setFont(font5);

        gridLayout_9->addWidget(slogan_3, 4, 0, 1, 1);

        lb_welcome = new QLabel(StuHome);
        lb_welcome->setObjectName("lb_welcome");
        QFont font6;
        font6.setPointSize(48);
        lb_welcome->setFont(font6);
        lb_welcome->setStyleSheet(QString::fromUtf8(""));
        lb_welcome->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(lb_welcome, 0, 0, 1, 2);

        slogan_1 = new QLabel(StuHome);
        slogan_1->setObjectName("slogan_1");
        slogan_1->setFont(font5);

        gridLayout_9->addWidget(slogan_1, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        calendarWidget = new QCalendarWidget(StuHome);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setEnabled(true);
        calendarWidget->setMinimumSize(QSize(369, 302));
        calendarWidget->setFocusPolicy(Qt::NoFocus);
        calendarWidget->setStyleSheet(QString::fromUtf8(""));
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(false);

        verticalLayout_4->addWidget(calendarWidget);

        button_currentDay = new QPushButton(StuHome);
        button_currentDay->setObjectName("button_currentDay");
        button_currentDay->setMinimumSize(QSize(160, 40));
        button_currentDay->setMaximumSize(QSize(180, 50));
        QFont font7;
        font7.setPointSize(12);
        button_currentDay->setFont(font7);

        verticalLayout_4->addWidget(button_currentDay, 0, Qt::AlignHCenter);


        gridLayout_9->addLayout(verticalLayout_4, 2, 1, 3, 1);

        slogan_2 = new QLabel(StuHome);
        slogan_2->setObjectName("slogan_2");
        slogan_2->setFont(font5);

        gridLayout_9->addWidget(slogan_2, 3, 0, 1, 1);

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
        txt_StuGender->setMaximumSize(QSize(612, 50));
        QFont font8;
        font8.setPointSize(18);
        txt_StuGender->setFont(font8);
        txt_StuGender->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuGender, 3, 1, 1, 1);

        lb_StuSocialID = new QLabel(StuProfile);
        lb_StuSocialID->setObjectName("lb_StuSocialID");
        lb_StuSocialID->setFont(font8);
        lb_StuSocialID->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuSocialID, 6, 0, 1, 1, Qt::AlignRight);

        lb_StuBirthday = new QLabel(StuProfile);
        lb_StuBirthday->setObjectName("lb_StuBirthday");
        lb_StuBirthday->setFont(font8);
        lb_StuBirthday->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuBirthday, 4, 0, 1, 1, Qt::AlignRight);

        lb_StuMainClass = new QLabel(StuProfile);
        lb_StuMainClass->setObjectName("lb_StuMainClass");
        lb_StuMainClass->setFont(font8);
        lb_StuMainClass->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuMainClass, 5, 0, 1, 1, Qt::AlignRight);

        lb_StuGender = new QLabel(StuProfile);
        lb_StuGender->setObjectName("lb_StuGender");
        lb_StuGender->setFont(font8);
        lb_StuGender->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuGender, 3, 0, 1, 1, Qt::AlignRight);

        txt_StuName = new QLineEdit(StuProfile);
        txt_StuName->setObjectName("txt_StuName");
        txt_StuName->setMinimumSize(QSize(0, 50));
        txt_StuName->setMaximumSize(QSize(612, 50));
        txt_StuName->setFont(font8);
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
        txt_StuID->setMaximumSize(QSize(612, 50));
        txt_StuID->setFont(font8);
        txt_StuID->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuID, 1, 1, 1, 1);

        txt_StuBirthday = new QLineEdit(StuProfile);
        txt_StuBirthday->setObjectName("txt_StuBirthday");
        txt_StuBirthday->setMinimumSize(QSize(0, 50));
        txt_StuBirthday->setMaximumSize(QSize(612, 50));
        txt_StuBirthday->setFont(font8);
        txt_StuBirthday->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuBirthday, 4, 1, 1, 1);

        lb_StuName = new QLabel(StuProfile);
        lb_StuName->setObjectName("lb_StuName");
        lb_StuName->setFont(font8);
        lb_StuName->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuName, 2, 0, 1, 1, Qt::AlignRight);

        lb_StuID = new QLabel(StuProfile);
        lb_StuID->setObjectName("lb_StuID");
        lb_StuID->setFont(font8);
        lb_StuID->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_6->addWidget(lb_StuID, 1, 0, 1, 1, Qt::AlignRight);

        txt_StuSocialID = new QLineEdit(StuProfile);
        txt_StuSocialID->setObjectName("txt_StuSocialID");
        txt_StuSocialID->setMinimumSize(QSize(0, 50));
        txt_StuSocialID->setMaximumSize(QSize(612, 50));
        txt_StuSocialID->setFont(font8);
        txt_StuSocialID->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuSocialID, 6, 1, 1, 1);

        txt_StuClass = new QLineEdit(StuProfile);
        txt_StuClass->setObjectName("txt_StuClass");
        txt_StuClass->setMinimumSize(QSize(0, 50));
        txt_StuClass->setMaximumSize(QSize(612, 50));
        txt_StuClass->setFont(font8);
        txt_StuClass->setReadOnly(true);

        gridLayout_6->addWidget(txt_StuClass, 5, 1, 1, 1);

        lb_MyProfile = new QLabel(StuProfile);
        lb_MyProfile->setObjectName("lb_MyProfile");
        QFont font9;
        font9.setPointSize(36);
        lb_MyProfile->setFont(font9);
        lb_MyProfile->setStyleSheet(QString::fromUtf8(""));
        lb_MyProfile->setAlignment(Qt::AlignCenter);

        gridLayout_6->addWidget(lb_MyProfile, 0, 0, 1, 2);

        stackedWidget_2->addWidget(StuProfile);
        StuCourse = new QWidget();
        StuCourse->setObjectName("StuCourse");
        lb_MyCourses = new QLabel(StuCourse);
        lb_MyCourses->setObjectName("lb_MyCourses");
        lb_MyCourses->setGeometry(QRect(60, 10, 777, 129));
        lb_MyCourses->setFont(font9);
        lb_MyCourses->setStyleSheet(QString::fromUtf8(""));
        lb_MyCourses->setAlignment(Qt::AlignCenter);
        tableWidget = new QTableWidget(StuCourse);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(20, 200, 861, 371));
        QFont font10;
        font10.setPointSize(9);
        tableWidget->setFont(font10);
        tableWidget->setSortingEnabled(false);
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
"	color:white;\n"
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
        txtNewPass->setFont(font8);
        txtNewPass->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(txtNewPass, 2, 2, 1, 1);

        lb_changePass = new QLabel(StuChangePassword);
        lb_changePass->setObjectName("lb_changePass");
        lb_changePass->setMaximumSize(QSize(16777215, 85));
        lb_changePass->setFont(font9);
        lb_changePass->setStyleSheet(QString::fromUtf8("#lb_changePass{\n"
"	color:rgb(151, 255, 168);\n"
"}"));
        lb_changePass->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(lb_changePass, 0, 0, 1, 3);

        lb_curPass = new QLabel(StuChangePassword);
        lb_curPass->setObjectName("lb_curPass");
        lb_curPass->setFont(font8);
        lb_curPass->setStyleSheet(QString::fromUtf8("#lb_curPass{\n"
"	color:white;\n"
"}"));
        lb_curPass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lb_curPass, 1, 0, 1, 1);

        lb_newPass = new QLabel(StuChangePassword);
        lb_newPass->setObjectName("lb_newPass");
        lb_newPass->setFont(font8);
        lb_newPass->setStyleSheet(QString::fromUtf8("#lb_newPass{\n"
"	color:white;\n"
"}"));
        lb_newPass->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_5->addWidget(lb_newPass, 2, 0, 1, 1);

        txtCurPass = new QLineEdit(StuChangePassword);
        txtCurPass->setObjectName("txtCurPass");
        txtCurPass->setMinimumSize(QSize(0, 50));
        txtCurPass->setMaximumSize(QSize(612, 50));
        txtCurPass->setFont(font8);
        txtCurPass->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(txtCurPass, 1, 2, 1, 1);

        txtConfirmPass = new QLineEdit(StuChangePassword);
        txtConfirmPass->setObjectName("txtConfirmPass");
        txtConfirmPass->setMinimumSize(QSize(0, 50));
        txtConfirmPass->setMaximumSize(QSize(612, 50));
        txtConfirmPass->setFont(font8);
        txtConfirmPass->setEchoMode(QLineEdit::Password);

        gridLayout_5->addWidget(txtConfirmPass, 3, 2, 1, 1);

        checkBox_2 = new QCheckBox(StuChangePassword);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setFont(font7);
        checkBox_2->setStyleSheet(QString::fromUtf8("#checkBox_2{\n"
"	color: white;\n"
"}"));

        gridLayout_5->addWidget(checkBox_2, 4, 2, 1, 1);

        stackedWidget_2->addWidget(StuChangePassword);

        gridLayout_3->addWidget(stackedWidget_2, 0, 2, 1, 1);

        widget_2 = new QWidget(student_homepage);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2{\n"
"	background-color: rgba(0, 0, 0, 150);\n"
"}\n"
"\n"
"#lb_curSY{\n"
"	color:white;\n"
"}\n"
"#lb_latestSY{\n"
"	color:white;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, -1, -1, 33);
        lb_latestSY = new QLabel(widget_2);
        lb_latestSY->setObjectName("lb_latestSY");
        lb_latestSY->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(lb_latestSY);

        lb_curSY = new QLabel(widget_2);
        lb_curSY->setObjectName("lb_curSY");
        lb_curSY->setMaximumSize(QSize(16777215, 30));

        verticalLayout_2->addWidget(lb_curSY);

        avatar = new QLabel(widget_2);
        avatar->setObjectName("avatar");
        avatar->setMinimumSize(QSize(140, 140));
        avatar->setMaximumSize(QSize(140, 140));
        avatar->setStyleSheet(QString::fromUtf8("#avatar{\n"
"	border-image: url(:/background/OIP.jpg)\n"
"}"));

        verticalLayout_2->addWidget(avatar, 0, Qt::AlignHCenter);

        name = new QLabel(widget_2);
        name->setObjectName("name");
        name->setMaximumSize(QSize(16777215, 34));
        name->setFont(font5);
        name->setStyleSheet(QString::fromUtf8("#name{\n"
"	color: white;\n"
"}"));
        name->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(name);

        button_StuHome = new QPushButton(widget_2);
        button_StuHome->setObjectName("button_StuHome");
        button_StuHome->setMinimumSize(QSize(218, 50));
        button_StuHome->setMaximumSize(QSize(251, 50));
        button_StuHome->setFont(font7);

        verticalLayout_2->addWidget(button_StuHome);

        button_StuMyProfile = new QPushButton(widget_2);
        button_StuMyProfile->setObjectName("button_StuMyProfile");
        button_StuMyProfile->setMinimumSize(QSize(218, 50));
        button_StuMyProfile->setMaximumSize(QSize(251, 50));
        button_StuMyProfile->setFont(font7);

        verticalLayout_2->addWidget(button_StuMyProfile);

        button_StuMyCourses = new QPushButton(widget_2);
        button_StuMyCourses->setObjectName("button_StuMyCourses");
        button_StuMyCourses->setMinimumSize(QSize(218, 50));
        button_StuMyCourses->setMaximumSize(QSize(251, 50));
        button_StuMyCourses->setFont(font7);

        verticalLayout_2->addWidget(button_StuMyCourses);

        button_StuChangePassword = new QPushButton(widget_2);
        button_StuChangePassword->setObjectName("button_StuChangePassword");
        button_StuChangePassword->setMinimumSize(QSize(218, 50));
        button_StuChangePassword->setMaximumSize(QSize(251, 50));
        button_StuChangePassword->setFont(font7);

        verticalLayout_2->addWidget(button_StuChangePassword);

        button_StuSignOut = new QPushButton(widget_2);
        button_StuSignOut->setObjectName("button_StuSignOut");
        button_StuSignOut->setMinimumSize(QSize(218, 50));
        button_StuSignOut->setMaximumSize(QSize(251, 50));
        button_StuSignOut->setFont(font7);

        verticalLayout_2->addWidget(button_StuSignOut);


        gridLayout_3->addWidget(widget_2, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 5);
        gridLayout_3->setColumnStretch(1, 19);
        stackedWidget->addWidget(student_homepage);
        admin_homepage = new QWidget();
        admin_homepage->setObjectName("admin_homepage");
        admin_homepage->setStyleSheet(QString::fromUtf8("#admin_homepage{\n"
"	border-image: url(:/background/Lovely Minecraft Hd Wallpaper 1920x1080.jpg);\n"
"}"));
        gridLayout_4 = new QGridLayout(admin_homepage);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(15, 15, 15, 15);
        widget_3 = new QWidget(admin_homepage);
        widget_3->setObjectName("widget_3");
        widget_3->setStyleSheet(QString::fromUtf8("#widget_3{\n"
"	background-color: rgba(0, 0, 0, 150);\n"
"}"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(-1, 50, -1, 70);
        avatar_2 = new QLabel(widget_3);
        avatar_2->setObjectName("avatar_2");
        avatar_2->setMinimumSize(QSize(140, 140));
        avatar_2->setMaximumSize(QSize(140, 140));
        avatar_2->setStyleSheet(QString::fromUtf8("#avatar_2{\n"
"	border-image: url(:/background/OIP.jpg)\n"
"}"));

        verticalLayout_3->addWidget(avatar_2, 0, Qt::AlignHCenter);

        name_2 = new QLabel(widget_3);
        name_2->setObjectName("name_2");
        name_2->setMaximumSize(QSize(16777215, 34));
        name_2->setFont(font5);
        name_2->setStyleSheet(QString::fromUtf8("#name_2{\n"
"	color: white;\n"
"}"));
        name_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(name_2);

        button_AdHome = new QPushButton(widget_3);
        button_AdHome->setObjectName("button_AdHome");
        button_AdHome->setMinimumSize(QSize(218, 50));
        button_AdHome->setMaximumSize(QSize(251, 50));
        button_AdHome->setFont(font7);

        verticalLayout_3->addWidget(button_AdHome);

        button_AdMyProfile = new QPushButton(widget_3);
        button_AdMyProfile->setObjectName("button_AdMyProfile");
        button_AdMyProfile->setMinimumSize(QSize(218, 50));
        button_AdMyProfile->setMaximumSize(QSize(251, 50));
        button_AdMyProfile->setFont(font7);

        verticalLayout_3->addWidget(button_AdMyProfile);

        button_AdChangePassword = new QPushButton(widget_3);
        button_AdChangePassword->setObjectName("button_AdChangePassword");
        button_AdChangePassword->setMinimumSize(QSize(218, 50));
        button_AdChangePassword->setMaximumSize(QSize(251, 50));
        button_AdChangePassword->setFont(font7);

        verticalLayout_3->addWidget(button_AdChangePassword);

        button_AdSignOut = new QPushButton(widget_3);
        button_AdSignOut->setObjectName("button_AdSignOut");
        button_AdSignOut->setMinimumSize(QSize(218, 50));
        button_AdSignOut->setMaximumSize(QSize(251, 50));
        button_AdSignOut->setFont(font7);

        verticalLayout_3->addWidget(button_AdSignOut);


        gridLayout_4->addWidget(widget_3, 0, 0, 1, 1);

        stackedWidget_3 = new QStackedWidget(admin_homepage);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setStyleSheet(QString::fromUtf8("#AdHome{\n"
"	background-color: rgba(0, 0, 0, 80);\n"
"}\n"
"#AdProfile{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"#AdChangePass{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}\n"
"\n"
"#lb_welcome_2{\n"
"	color:rgb(151, 255, 168);\n"
"}\n"
"#lb_changePass_2{\n"
"	color:rgb(151, 255, 168);\n"
"}\n"
"#lb_MyProfile_2{\n"
"	color:rgb(151, 255, 168);\n"
"}\n"
"\n"
"#lb_AdID{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_AdName{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_AdGender{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_AdBirthday{\n"
"	color: white;\n"
"}\n"
"\n"
"#lb_AdSocialID{\n"
"	color: white;\n"
"}\n"
"\n"
"#txt_AdID{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_AdName{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_AdGender{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_AdBirthday{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txt_AdSocialID{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txtCurPass_2{\n"
"	background-color: rgba(2"
                        "55, 255, 255, 200);\n"
"}\n"
"#txtNewPass_2{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}\n"
"#txtConfirmPass_2{\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}"));
        AdHome = new QWidget();
        AdHome->setObjectName("AdHome");
        lb_welcome_2 = new QLabel(AdHome);
        lb_welcome_2->setObjectName("lb_welcome_2");
        lb_welcome_2->setGeometry(QRect(30, 10, 867, 146));
        lb_welcome_2->setFont(font6);
        lb_welcome_2->setStyleSheet(QString::fromUtf8(""));
        lb_welcome_2->setAlignment(Qt::AlignCenter);
        stackedWidget_3->addWidget(AdHome);
        AdProfile = new QWidget();
        AdProfile->setObjectName("AdProfile");
        gridLayout_8 = new QGridLayout(AdProfile);
        gridLayout_8->setObjectName("gridLayout_8");
        gridLayout_8->setHorizontalSpacing(20);
        gridLayout_8->setVerticalSpacing(26);
        gridLayout_8->setContentsMargins(65, -1, 65, 50);
        lb_AdID = new QLabel(AdProfile);
        lb_AdID->setObjectName("lb_AdID");
        lb_AdID->setFont(font8);
        lb_AdID->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdID, 1, 0, 1, 1, Qt::AlignRight);

        txt_AdID = new QLineEdit(AdProfile);
        txt_AdID->setObjectName("txt_AdID");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(txt_AdID->sizePolicy().hasHeightForWidth());
        txt_AdID->setSizePolicy(sizePolicy3);
        txt_AdID->setMinimumSize(QSize(586, 50));
        txt_AdID->setMaximumSize(QSize(612, 50));
        txt_AdID->setFont(font8);
        txt_AdID->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdID, 1, 1, 1, 2);

        lb_AdName = new QLabel(AdProfile);
        lb_AdName->setObjectName("lb_AdName");
        lb_AdName->setFont(font8);
        lb_AdName->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdName, 2, 0, 1, 1, Qt::AlignRight);

        txt_AdName = new QLineEdit(AdProfile);
        txt_AdName->setObjectName("txt_AdName");
        txt_AdName->setMinimumSize(QSize(0, 50));
        txt_AdName->setMaximumSize(QSize(612, 50));
        txt_AdName->setFont(font8);
        txt_AdName->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdName, 2, 1, 1, 2);

        lb_AdGender = new QLabel(AdProfile);
        lb_AdGender->setObjectName("lb_AdGender");
        lb_AdGender->setFont(font8);
        lb_AdGender->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdGender, 3, 0, 1, 1, Qt::AlignRight);

        txt_AdGender = new QLineEdit(AdProfile);
        txt_AdGender->setObjectName("txt_AdGender");
        txt_AdGender->setMinimumSize(QSize(0, 50));
        txt_AdGender->setMaximumSize(QSize(612, 50));
        txt_AdGender->setFont(font8);
        txt_AdGender->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdGender, 3, 1, 1, 2);

        lb_AdBirthday = new QLabel(AdProfile);
        lb_AdBirthday->setObjectName("lb_AdBirthday");
        lb_AdBirthday->setFont(font8);
        lb_AdBirthday->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdBirthday, 4, 0, 1, 1, Qt::AlignRight);

        txt_AdBirthday = new QLineEdit(AdProfile);
        txt_AdBirthday->setObjectName("txt_AdBirthday");
        txt_AdBirthday->setMinimumSize(QSize(0, 50));
        txt_AdBirthday->setMaximumSize(QSize(612, 50));
        txt_AdBirthday->setFont(font8);
        txt_AdBirthday->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdBirthday, 4, 1, 1, 2);

        lb_AdSocialID = new QLabel(AdProfile);
        lb_AdSocialID->setObjectName("lb_AdSocialID");
        lb_AdSocialID->setFont(font8);
        lb_AdSocialID->setStyleSheet(QString::fromUtf8("#label{\n"
"	color: white;\n"
"}\n"
""));

        gridLayout_8->addWidget(lb_AdSocialID, 5, 0, 1, 1, Qt::AlignRight);

        txt_AdSocialID = new QLineEdit(AdProfile);
        txt_AdSocialID->setObjectName("txt_AdSocialID");
        txt_AdSocialID->setMinimumSize(QSize(0, 50));
        txt_AdSocialID->setMaximumSize(QSize(612, 50));
        txt_AdSocialID->setFont(font8);
        txt_AdSocialID->setReadOnly(true);

        gridLayout_8->addWidget(txt_AdSocialID, 5, 1, 1, 2);

        button_back_4 = new QPushButton(AdProfile);
        button_back_4->setObjectName("button_back_4");
        button_back_4->setMinimumSize(QSize(200, 65));
        button_back_4->setMaximumSize(QSize(200, 65));
        button_back_4->setFont(font4);

        gridLayout_8->addWidget(button_back_4, 6, 2, 1, 1);

        lb_MyProfile_2 = new QLabel(AdProfile);
        lb_MyProfile_2->setObjectName("lb_MyProfile_2");
        lb_MyProfile_2->setFont(font9);
        lb_MyProfile_2->setStyleSheet(QString::fromUtf8(""));
        lb_MyProfile_2->setAlignment(Qt::AlignCenter);

        gridLayout_8->addWidget(lb_MyProfile_2, 0, 0, 1, 3);

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
"	color:rgb(151, 255, 168);\n"
"}"));
        lb_changePass_2->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(lb_changePass_2, 0, 0, 1, 2);

        lb_curPass_2 = new QLabel(AdChangePass);
        lb_curPass_2->setObjectName("lb_curPass_2");
        lb_curPass_2->setFont(font8);
        lb_curPass_2->setStyleSheet(QString::fromUtf8("#lb_curPass_2{\n"
"	color:white;\n"
"}"));
        lb_curPass_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_curPass_2, 1, 0, 1, 1);

        txtCurPass_2 = new QLineEdit(AdChangePass);
        txtCurPass_2->setObjectName("txtCurPass_2");
        txtCurPass_2->setMinimumSize(QSize(0, 50));
        txtCurPass_2->setMaximumSize(QSize(612, 50));
        txtCurPass_2->setFont(font8);
        txtCurPass_2->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(txtCurPass_2, 1, 1, 1, 1);

        lb_newPass_2 = new QLabel(AdChangePass);
        lb_newPass_2->setObjectName("lb_newPass_2");
        lb_newPass_2->setFont(font8);
        lb_newPass_2->setStyleSheet(QString::fromUtf8("#lb_newPass_2{\n"
"	color:white;\n"
"}"));
        lb_newPass_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_newPass_2, 2, 0, 1, 1);

        txtNewPass_2 = new QLineEdit(AdChangePass);
        txtNewPass_2->setObjectName("txtNewPass_2");
        txtNewPass_2->setMinimumSize(QSize(0, 50));
        txtNewPass_2->setMaximumSize(QSize(612, 50));
        txtNewPass_2->setFont(font8);
        txtNewPass_2->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(txtNewPass_2, 2, 1, 1, 1);

        lb_confirmPass_2 = new QLabel(AdChangePass);
        lb_confirmPass_2->setObjectName("lb_confirmPass_2");
        lb_confirmPass_2->setFont(font8);
        lb_confirmPass_2->setStyleSheet(QString::fromUtf8("#lb_confirmPass_2{\n"
"	color:white;\n"
"}"));
        lb_confirmPass_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(lb_confirmPass_2, 3, 0, 1, 1);

        txtConfirmPass_2 = new QLineEdit(AdChangePass);
        txtConfirmPass_2->setObjectName("txtConfirmPass_2");
        txtConfirmPass_2->setMinimumSize(QSize(0, 50));
        txtConfirmPass_2->setMaximumSize(QSize(612, 50));
        txtConfirmPass_2->setFont(font8);
        txtConfirmPass_2->setEchoMode(QLineEdit::Password);

        gridLayout_7->addWidget(txtConfirmPass_2, 3, 1, 1, 1);

        checkBox_3 = new QCheckBox(AdChangePass);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setFont(font7);
        checkBox_3->setStyleSheet(QString::fromUtf8("#checkBox_3{\n"
"	color: white;\n"
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

        stackedWidget->setCurrentIndex(1);
        stackedWidget_2->setCurrentIndex(0);
        stackedWidget_3->setCurrentIndex(0);


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
        slogan_3->setText(QCoreApplication::translate("MainWindow", "The More You Learn, The More You Earn", nullptr));
        lb_welcome->setText(QCoreApplication::translate("MainWindow", "WELCOME", nullptr));
        slogan_1->setText(QCoreApplication::translate("MainWindow", "Take A Chance To Make A Change", nullptr));
        button_currentDay->setText(QCoreApplication::translate("MainWindow", "CURRENT DAY", nullptr));
        slogan_2->setText(QCoreApplication::translate("MainWindow", "Be A Warrior, Not A Worrier", nullptr));
        lb_StuSocialID->setText(QCoreApplication::translate("MainWindow", "Social ID:   ", nullptr));
        lb_StuBirthday->setText(QCoreApplication::translate("MainWindow", "Birthday:   ", nullptr));
        lb_StuMainClass->setText(QCoreApplication::translate("MainWindow", "Class:   ", nullptr));
        lb_StuGender->setText(QCoreApplication::translate("MainWindow", "Gender:   ", nullptr));
        button_back_2->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_StuName->setText(QCoreApplication::translate("MainWindow", "Name:   ", nullptr));
        lb_StuID->setText(QCoreApplication::translate("MainWindow", "Student ID:   ", nullptr));
        lb_MyProfile->setText(QCoreApplication::translate("MainWindow", "My Profile", nullptr));
        lb_MyCourses->setText(QCoreApplication::translate("MainWindow", "My Courses", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "No", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Course ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Course Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Class Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Tearcher Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Day Of Week", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Session", nullptr));
        lb_confirmPass->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        button_back->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        button_confirm->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        lb_changePass->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        lb_curPass->setText(QCoreApplication::translate("MainWindow", "Current Password:", nullptr));
        lb_newPass->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        txtCurPass->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        lb_latestSY->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        lb_curSY->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        avatar->setText(QString());
        name->setText(QCoreApplication::translate("MainWindow", "Hi, Student", nullptr));
        button_StuHome->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        button_StuMyProfile->setText(QCoreApplication::translate("MainWindow", "MY PROFILE", nullptr));
        button_StuMyCourses->setText(QCoreApplication::translate("MainWindow", "MY COURSES", nullptr));
        button_StuChangePassword->setText(QCoreApplication::translate("MainWindow", "CHANGE PASSWORD", nullptr));
        button_StuSignOut->setText(QCoreApplication::translate("MainWindow", "SIGN OUT", nullptr));
        avatar_2->setText(QString());
        name_2->setText(QCoreApplication::translate("MainWindow", "Hi, Admin", nullptr));
        button_AdHome->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        button_AdMyProfile->setText(QCoreApplication::translate("MainWindow", "MY PROFILE", nullptr));
        button_AdChangePassword->setText(QCoreApplication::translate("MainWindow", "CHANGE PASSWORD", nullptr));
        button_AdSignOut->setText(QCoreApplication::translate("MainWindow", "SIGN OUT", nullptr));
        lb_welcome_2->setText(QCoreApplication::translate("MainWindow", "WELCOME", nullptr));
        lb_AdID->setText(QCoreApplication::translate("MainWindow", "Staff ID:   ", nullptr));
        lb_AdName->setText(QCoreApplication::translate("MainWindow", "Name:   ", nullptr));
        lb_AdGender->setText(QCoreApplication::translate("MainWindow", "Gender:   ", nullptr));
        lb_AdBirthday->setText(QCoreApplication::translate("MainWindow", "Birthday:   ", nullptr));
        lb_AdSocialID->setText(QCoreApplication::translate("MainWindow", "Social ID:   ", nullptr));
        button_back_4->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        lb_MyProfile_2->setText(QCoreApplication::translate("MainWindow", "My Profile", nullptr));
        lb_changePass_2->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        lb_curPass_2->setText(QCoreApplication::translate("MainWindow", "Current Password:", nullptr));
        txtCurPass_2->setText(QString());
        lb_newPass_2->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        lb_confirmPass_2->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        button_confirm_2->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        button_back_3->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
