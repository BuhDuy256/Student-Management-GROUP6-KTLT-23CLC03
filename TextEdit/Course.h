#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QDebug>
#include <QAbstractListModel>
#include <QListView>
#include <QStringList>
#include <QStringListModel>

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

class Course
{
private:
    std::string ID;
    std::string Name;
    std::string className;
    std::string teacherName;
    int courseSize = 0;
    std::string dayOfWeek;
    std::string session;
    StudentScore* score = nullptr;

public:
    void updateInformation();

    void viewStudentsList(Ui::TextEdit *ui);

    void addStudent(Ui::TextEdit *ui);
    void deleteStudent();

    void viewScoreboard();
    void updateStudentResult();
};

#endif // COURSE_H
