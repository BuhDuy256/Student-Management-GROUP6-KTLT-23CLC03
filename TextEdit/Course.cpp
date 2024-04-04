#include "Course.h"
#include "ui_textedit.h"

Course::Course(QObject *parent) : QObject(parent) {
    model = new QStandardItemModel(this);
}

Course::~Course()
{
    delete model;
}

void Course::viewStudentsList(Ui::TextEdit *ui) {
    if (score != nullptr) {
        // Set column headers
        model->setHorizontalHeaderLabels(QStringList() << "Student ID" << "Student Name");

        // Set the model for the TableView
        ui->studentTable->setModel(model);

        QObject::connect(model, &QStandardItemModel::dataChanged, [=](const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles) {
            if (topLeft == bottomRight && roles.contains(Qt::DisplayRole)) {

                // Only update data if the changed cell is the current selection
                QModelIndex currentIndex = ui->studentTable->selectionModel()->currentIndex();
                if (topLeft == currentIndex) {
                    QString studentID = model->item(topLeft.row(), 0)->text();
                    QString studentName = model->item(topLeft.row(), 1)->text();
                    // Update underlying data structure (score) for the selected row
                    score[topLeft.row()].studentID = studentID.toStdString();
                    score[topLeft.row()].studentName = studentName.toStdString();
                    ui->studentTable->resizeColumnToContents(topLeft.column());
                }
            }
        });
        // Resize the columns to fit the content
        ui->studentTable->resizeColumnsToContents();    

        // Show the TableView
        ui->studentTable->show();
    } else {
        qDebug() << "No students in the course";
    }
}

void Course::addStudent(Ui::TextEdit *ui)
{
    QString studentID = ui->studentID->text();
    QString studentName = ui->studentName->text();

    StudentScore* newScoreList = new StudentScore [courseSize + 1];
    for (int i = 0; i < courseSize; i++)
        newScoreList[i] = score[i];
    newScoreList[courseSize].studentID = studentID.toStdString();
    newScoreList[courseSize].studentName = studentName.toStdString();

    delete [] score;
    score = newScoreList;

    QList<QStandardItem*> rowItems;

    // Create item for student ID
    QStandardItem *idItem = new QStandardItem(QString::fromStdString(score[courseSize].studentID));
    rowItems.append(idItem);

    // Create item for student name
    QStandardItem *nameItem = new QStandardItem(QString::fromStdString(score[courseSize].studentName));
    rowItems.append(nameItem);

    // Add the row to the model
    model->appendRow(rowItems);

    courseSize++;
}

void Course::deleteStudent(Ui::TextEdit *ui)
{
    QModelIndexList selectedIndexes = ui->studentTable->selectionModel()->selectedIndexes();
    if (!selectedIndexes.isEmpty() && selectedIndexes.count() == 1)
    {
        int selectedRow = selectedIndexes.first().row();

        for (int i = selectedRow; i < courseSize - 1; i++) score[i] = score[i + 1];
        model->removeRow(selectedRow);
        courseSize--;
    }
}
