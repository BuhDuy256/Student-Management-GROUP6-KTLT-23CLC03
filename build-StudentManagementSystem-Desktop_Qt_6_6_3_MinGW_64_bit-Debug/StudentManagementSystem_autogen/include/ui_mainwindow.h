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
#include <QtWidgets/QMenuBar>
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
    QWidget *widget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1189, 697);
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
"	background-color: rgb(223, 223, 223)\n"
"}"));
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
        button_signin->setToolTipDuration(-1);

        horizontalLayout->addWidget(button_signin);

        button_exit = new QPushButton(widget);
        button_exit->setObjectName("button_exit");
        sizePolicy2.setHeightForWidth(button_exit->sizePolicy().hasHeightForWidth());
        button_exit->setSizePolicy(sizePolicy2);
        button_exit->setMinimumSize(QSize(257, 40));
        button_exit->setMaximumSize(QSize(288, 50));
        button_exit->setFont(font4);

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
        widget_2 = new QWidget(student_homepage);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 1171, 81));
        widget_2->setStyleSheet(QString::fromUtf8("#widget_2{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        stackedWidget->addWidget(student_homepage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1189, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


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
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
