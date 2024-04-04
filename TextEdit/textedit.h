#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class TextEdit;
}
QT_END_NAMESPACE

class TextEdit : public QWidget
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    ~TextEdit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_btn_addCourse_clicked();

    void on_btn_addStudent_clicked();

    void on_btn_deleteStudent_clicked();

private:
    Ui::TextEdit *ui;
};
#endif // TEXTEDIT_H
