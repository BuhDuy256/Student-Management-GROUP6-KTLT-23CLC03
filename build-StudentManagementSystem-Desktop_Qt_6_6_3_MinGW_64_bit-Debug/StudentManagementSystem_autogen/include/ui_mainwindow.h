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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QLabel *lb_welcome;
    QWidget *StuProfile;
    QWidget *StuCourse;
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
    QLabel *avatar_2;
    QLabel *name_2;
    QPushButton *button_AdHome;
    QPushButton *button_AdMyProfile;
    QPushButton *button_AdChangePassword;
    QPushButton *button_AdSignOut;
    QStackedWidget *stackedWidget_3;
    QWidget *page_5;
    QWidget *page_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1190, 713);
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
        widget_2 = new QWidget(student_homepage);
        widget_2->setObjectName("widget_2");
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2{\n"
"	background-color: rgba(0, 0, 0, 150);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, 50, -1, 70);
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
        QFont font5;
        font5.setPointSize(16);
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
        QFont font6;
        font6.setPointSize(12);
        button_StuHome->setFont(font6);

        verticalLayout_2->addWidget(button_StuHome);

        button_StuMyProfile = new QPushButton(widget_2);
        button_StuMyProfile->setObjectName("button_StuMyProfile");
        button_StuMyProfile->setMinimumSize(QSize(218, 50));
        button_StuMyProfile->setMaximumSize(QSize(251, 50));
        button_StuMyProfile->setFont(font6);

        verticalLayout_2->addWidget(button_StuMyProfile);

        button_StuMyCourses = new QPushButton(widget_2);
        button_StuMyCourses->setObjectName("button_StuMyCourses");
        button_StuMyCourses->setMinimumSize(QSize(218, 50));
        button_StuMyCourses->setMaximumSize(QSize(251, 50));
        button_StuMyCourses->setFont(font6);

        verticalLayout_2->addWidget(button_StuMyCourses);

        button_StuChangePassword = new QPushButton(widget_2);
        button_StuChangePassword->setObjectName("button_StuChangePassword");
        button_StuChangePassword->setMinimumSize(QSize(218, 50));
        button_StuChangePassword->setMaximumSize(QSize(251, 50));
        button_StuChangePassword->setFont(font6);

        verticalLayout_2->addWidget(button_StuChangePassword);

        button_StuSignOut = new QPushButton(widget_2);
        button_StuSignOut->setObjectName("button_StuSignOut");
        button_StuSignOut->setMinimumSize(QSize(218, 50));
        button_StuSignOut->setMaximumSize(QSize(251, 50));
        button_StuSignOut->setFont(font6);

        verticalLayout_2->addWidget(button_StuSignOut);


        gridLayout_3->addWidget(widget_2, 0, 0, 1, 1);

        stackedWidget_2 = new QStackedWidget(student_homepage);
        stackedWidget_2->setObjectName("stackedWidget_2");
        stackedWidget_2->setStyleSheet(QString::fromUtf8("#StuHome{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}\n"
"\n"
"#StuChangePassword{\n"
"	background-color: rgba(0, 0, 0, 96);\n"
"}"));
        StuHome = new QWidget();
        StuHome->setObjectName("StuHome");
        lb_welcome = new QLabel(StuHome);
        lb_welcome->setObjectName("lb_welcome");
        lb_welcome->setGeometry(QRect(190, 40, 511, 111));
        QFont font7;
        font7.setPointSize(48);
        lb_welcome->setFont(font7);
        lb_welcome->setStyleSheet(QString::fromUtf8("#lb_welcome{\n"
"	color:white;\n"
"}"));
        lb_welcome->setAlignment(Qt::AlignCenter);
        stackedWidget_2->addWidget(StuHome);
        StuProfile = new QWidget();
        StuProfile->setObjectName("StuProfile");
        stackedWidget_2->addWidget(StuProfile);
        StuCourse = new QWidget();
        StuCourse->setObjectName("StuCourse");
        stackedWidget_2->addWidget(StuCourse);
        StuChangePassword = new QWidget();
        StuChangePassword->setObjectName("StuChangePassword");
        gridLayout_5 = new QGridLayout(StuChangePassword);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(65, -1, 65, -1);
        lb_confirmPass = new QLabel(StuChangePassword);
        lb_confirmPass->setObjectName("lb_confirmPass");
        QFont font8;
        font8.setPointSize(18);
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
        QFont font9;
        font9.setPointSize(36);
        lb_changePass->setFont(font9);
        lb_changePass->setStyleSheet(QString::fromUtf8("#lb_changePass{\n"
"	color:white;\n"
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
        checkBox_2->setFont(font6);
        checkBox_2->setStyleSheet(QString::fromUtf8("#checkBox_2{\n"
"	color: white;\n"
"}"));

        gridLayout_5->addWidget(checkBox_2, 4, 2, 1, 1);

        stackedWidget_2->addWidget(StuChangePassword);

        gridLayout_3->addWidget(stackedWidget_2, 0, 1, 1, 1);

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
        button_AdHome->setFont(font6);

        verticalLayout_3->addWidget(button_AdHome);

        button_AdMyProfile = new QPushButton(widget_3);
        button_AdMyProfile->setObjectName("button_AdMyProfile");
        button_AdMyProfile->setMinimumSize(QSize(218, 50));
        button_AdMyProfile->setMaximumSize(QSize(251, 50));
        button_AdMyProfile->setFont(font6);

        verticalLayout_3->addWidget(button_AdMyProfile);

        button_AdChangePassword = new QPushButton(widget_3);
        button_AdChangePassword->setObjectName("button_AdChangePassword");
        button_AdChangePassword->setMinimumSize(QSize(218, 50));
        button_AdChangePassword->setMaximumSize(QSize(251, 50));
        button_AdChangePassword->setFont(font6);

        verticalLayout_3->addWidget(button_AdChangePassword);

        button_AdSignOut = new QPushButton(widget_3);
        button_AdSignOut->setObjectName("button_AdSignOut");
        button_AdSignOut->setMinimumSize(QSize(218, 50));
        button_AdSignOut->setMaximumSize(QSize(251, 50));
        button_AdSignOut->setFont(font6);

        verticalLayout_3->addWidget(button_AdSignOut);


        gridLayout_4->addWidget(widget_3, 0, 0, 1, 1);

        stackedWidget_3 = new QStackedWidget(admin_homepage);
        stackedWidget_3->setObjectName("stackedWidget_3");
        stackedWidget_3->setStyleSheet(QString::fromUtf8("#page_5{\n"
"	background-color: rgba(0, 0, 0, 0);\n"
"}"));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        stackedWidget_3->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget_3->addWidget(page_6);

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
        stackedWidget_2->setCurrentIndex(3);
        stackedWidget_3->setCurrentIndex(1);


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
        lb_welcome->setText(QCoreApplication::translate("MainWindow", "WELCOME", nullptr));
        lb_confirmPass->setText(QCoreApplication::translate("MainWindow", "Confirm Password:", nullptr));
        button_back->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        button_confirm->setText(QCoreApplication::translate("MainWindow", "CONFIRM", nullptr));
        lb_changePass->setText(QCoreApplication::translate("MainWindow", "Change Password", nullptr));
        lb_curPass->setText(QCoreApplication::translate("MainWindow", "Current Password:", nullptr));
        lb_newPass->setText(QCoreApplication::translate("MainWindow", "New Password:", nullptr));
        txtCurPass->setText(QString());
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Show Password", nullptr));
        avatar_2->setText(QString());
        name_2->setText(QCoreApplication::translate("MainWindow", "Hi, Admin", nullptr));
        button_AdHome->setText(QCoreApplication::translate("MainWindow", "HOME", nullptr));
        button_AdMyProfile->setText(QCoreApplication::translate("MainWindow", "MY PROFILE", nullptr));
        button_AdChangePassword->setText(QCoreApplication::translate("MainWindow", "CHANGE PASSWORD", nullptr));
        button_AdSignOut->setText(QCoreApplication::translate("MainWindow", "SIGN OUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
