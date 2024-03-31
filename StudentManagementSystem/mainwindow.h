#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtWidgets>
#include <QFontDatabase>
#include <QFont>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_checkBox_stateChanged(int arg1);

    void on_button_signin_clicked();

    void on_txtUsername_textEdited(const QString &arg1);

    void on_txtPassword_textEdited(const QString &arg1);

    void on_button_exit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
