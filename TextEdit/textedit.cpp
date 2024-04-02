#include "Course.h"
#include "textedit.h"
#include "./ui_textedit.h"


Course course;
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

void TextEdit::on_pushButton_clicked()
{
    course.addStudent(ui);
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    course.viewStudentsList(ui);
    qDebug() << "Student added";
}



void TextEdit::on_pushButton_2_clicked()
{
    course.deleteStudent(ui);
}

