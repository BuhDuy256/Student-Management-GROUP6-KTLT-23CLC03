#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QObject>
#include <QDebug>
#include <QTableView>
#include <QStandardItemModel>

#include "textedit.h"

struct StudentScore {
    std::string studentID;
    std::string studentName;
    double midTerm = -1;
    double final = -1;
    double other = -1;
    double total = -1;
    double GPA = -1;
};

class Course : public QObject
{
private:
    QStandardItemModel *model;

public:
    std::string ID;
    std::string Name;
    std::string className;
    std::string teacherName;
    int courseSize = 0;
    std::string dayOfWeek;
    std::string session;
    StudentScore* score = nullptr;

    Course(QObject *parent = nullptr);
    ~Course();

    void updateInformation();

    void viewStudentsList(Ui::TextEdit *ui);

    void addStudent(Ui::TextEdit *ui);
    void deleteStudent(Ui::TextEdit *ui);

    void viewScoreboard();
    void updateStudentResult();
};

#endif // COURSE_H
