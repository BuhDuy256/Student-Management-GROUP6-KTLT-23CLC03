#include "Course.h"
#include "./ui_textedit.h"

struct Student {
    QString studentID;
    QString studentName;
};

class StudentListModel : public QAbstractListModel {
public:
    StudentListModel(const QList<Student> &students, QObject *parent = nullptr)
        : QAbstractListModel(parent), m_students(students) {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return m_students.count();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid())
            return QVariant();

        if (index.row() >= m_students.size() || index.row() < 0)
            return QVariant();

        if (role == Qt::DisplayRole) {
            const Student &student = m_students.at(index.row());
            if (index.column() == 0)
                return student.studentID;
            else if (index.column() == 1)
                return student.studentName;
            // Add more columns if needed
        }

        return QVariant();
    }

private:
    QList<Student> m_students;
};

void Course::viewStudentsList(Ui::TextEdit* ui) {
    if (score != nullptr) {
        QList<Student> students;
        for (int i = 0; i < courseSize; ++i) {
            Student student;
            student.studentID = QString::fromStdString(score[i].studentID);
            student.studentName = QString::fromStdString(score[i].studentName);
            students.append(student);
        }

        // Create model
        StudentListModel *model = new StudentListModel(students);

        // Create and set up the ListView

        ui->listView->setModel(model);
        ui->listView->setWindowTitle("Student List");
        ui->listView->show();
    } else {
        qDebug() << "No student in the course";
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

