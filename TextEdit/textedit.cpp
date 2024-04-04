#include "Course.h"
#include "Semester.h"
#include "textedit.h"
#include "./ui_textedit.h"


Course course;
Semester semester;
TextEdit::TextEdit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TextEdit)
{
    ui->setupUi(this);
}

TextEdit::~TextEdit()
{
    delete ui;
}

void TextEdit::on_btn_addCourse_clicked()
{
    semester.addCourse(ui);

    ui->CourseID->setText("");
    ui->CourseName->setText("");
    qDebug() << "Course added";
}

void TextEdit::on_btn_addStudent_clicked()
{
    course.addStudent(ui);
    ui->studentID->setText("");
    ui->studentName->setText("");
    course.viewStudentsList(ui);
    qDebug() << "Student added";
}


void TextEdit::on_btn_deleteStudent_clicked()
{
    course.deleteStudent(ui);
}

