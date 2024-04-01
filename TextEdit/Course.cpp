#include "Course.h"
#include "./ui_textedit.h"

void Course::viewStudentsList(Ui::TextEdit* ui) {
    if (score != nullptr) {
        // Create a standard item model
        QStandardItemModel *model = new QStandardItemModel();

        // Set column headers
        model->setHorizontalHeaderLabels(QStringList() << "Student ID" << "Student Name");

        // Populate the model
        for (int i = 0; i < courseSize; ++i) {
            QList<QStandardItem*> rowItems;

            // Create item for student ID
            QStandardItem *idItem = new QStandardItem(QString::fromStdString(score[i].studentID));
            rowItems.append(idItem);

            // Create item for student name
            QStandardItem *nameItem = new QStandardItem(QString::fromStdString(score[i].studentName));
            rowItems.append(nameItem);

            // Add the row to the model
            model->appendRow(rowItems);
        }

        // Create the TableView
        QTableView *tableView = new QTableView;

        // Set the model for the TableView
        ui->tableView->setModel(model);

        // Resize the columns to fit the content
        ui->tableView->resizeColumnsToContents();

        // Show the TableView
        ui->tableView->show();
    } else {
        qDebug() << "No students in the course";
    }
}


void Course::addStudent(Ui::TextEdit* ui)
{
    QString studentID = ui->lineEdit->text();
    QString studentName = ui->lineEdit_2->text();

    StudentScore* newScoreList = new StudentScore [courseSize + 1];
    for (int i = 0; i < courseSize; i++)
        newScoreList[i] = score[i];
    newScoreList[courseSize].studentID = studentID.toStdString();
    newScoreList[courseSize].studentName = studentName.toStdString();

    delete [] score;
    score = newScoreList;
    courseSize++;
}

