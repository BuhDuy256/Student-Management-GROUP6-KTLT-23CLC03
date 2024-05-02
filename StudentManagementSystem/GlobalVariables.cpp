#include "GlobalVariables.h"

Node<Student>* currStudent = nullptr;
Node<SchoolYear>* latestSYear = nullptr;
Semester latestSem;
int lastSemNumber = -1;
Node<SchoolYear>* currSYear = nullptr;
Semester currSem;
int currSemNumber = -1;
Node<Staff>* listStaff = nullptr;
Node<Staff>* currStaff = nullptr;
Node<Course>* currCourse = nullptr;
StudentScore* currStuScore = nullptr;
unsigned short userMode;
