#include "Semester.h"
#include "ui_textedit.h"

Semester::Semester(QObject *parent) : QObject(parent) {
    model = new QStandardItemModel(this);
}

Semester::~Semester()
{
    delete model;
}

void Semester::addCourse(Ui::TextEdit *ui)
{
    QString courseID = ui->CourseID->text();
    QString courseName = ui->CourseName->text();

    Course* course = new Course;
    course->ID = courseID.toStdString();
    course->Name = courseName.toStdString();

    Node<Course>* node = new Node<Course>(course);
    node->next = Courses;
    Courses = node;
}
