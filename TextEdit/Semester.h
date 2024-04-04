#ifndef SEMESTER_H
#define SEMESTER_H

#include "Node.h"
#include "Course.h"
#include "textedit.h"

#include <string>
#include <iostream>
#include <iomanip>

class Semester : public QObject{

private:
    QStandardItemModel *model;

public:
    bool isCreated = false;
    std::string startDate;
    std::string endDate;
    Node<Course>* Courses = nullptr;

    Semester(QObject *parent = nullptr);
    ~Semester();

    void addCourse(Ui::TextEdit *ui);
    bool deleteCourse(int index);
    void viewCoursesList();
};

#endif // SEMESTER_H
