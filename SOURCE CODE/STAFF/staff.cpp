#include "../SYSTEM/system.h"
#include "staff.h"
void SchoolYear::add1stStudentto1stClass(){
 //importCSVfile
}
void Course::ListofStudents(){
 //importCSVfile
}
void Semester::showCourse(){
 for(int i = 0; i < NumofSemCourse; i++) cout << i + 1 << ":" << courses[i].Name << "\n";
}
void Course::updateInfor(){
  string update; int choice,newupdate;
  while(1){
  cout << "Update: \n";
  cout << "0.Exit\n";
  cout << "1.Teacher Name\n";
  cout << "2.Num Of Credits\n";
  cout << "3.Session Day: \n";
  cout << "4.Session Time: \n";
  cout << "Choice: ";
  cin >> choice;
  if(choice == 0) break;
  else{
    if(choice == 1){
        cin >> update; //getline
        TeacherName = update;
    }
    if(choice == 2){
        cin >> newupdate;
        NumofCredits = newupdate;
    }
    if(choice == 3){
        cin >> update;
        SessionDay = update;
    }
    if(choice == 4){
        cin >> update;
        SessionTime = update;
    }
    //cannhacdungsystemclear
  }
}
}
void Course::addStudent(){
 Student *newstu = new Student;
 cout << "Enter No: ";
 cin >> newstu->No;
 cout << "Enter Student ID: ";
 cin >> newstu->StudentID;
 cout << "First Name: ";
 cin >> newstu->LastName;
 cout << "Last Name: ";
 cin >> newstu->LastName;
 cout << "Gender: ";
 cin >> newstu->Gender;
 cout << "Date Of Birth: ";
 cin >> newstu->DateofBirth;
 cout << "Social ID: ";
 cin >> newstu->SocialID;
 newstu->next = NULL;
 classes->Last->next = newstu;
 classes->Last = newstu;
}
void Course::removeStudent(){
 string ID;
 cout << "Enter Student ID: ";
 cin >> ID;
 Student *remov = classes->First;
 if(remov && remov->StudentID == ID){
    Student* temp = remov;
    classes->First = classes->First->next;
    delete temp;
    return;
 }
 while(remov){
    if(remov->next && remov->next->StudentID == ID){
        Student* temp = remov->next;
        remov->next = remov->next->next;
        delete temp;
    }
    remov = remov->next;
 }
}
void Semester::deleteCourse(){
 string n;
 showCourse();
 cout << "\nName of Course to Delete: ";
 cin >> n;
 for(int i = 0; i < NumofSemCourse; i++){
    if(courses[i].Name == n){ //maychangetoLinkedList
        for(int t = i;t < NumofSemCourse - 1; t++){
            courses[t] = courses[t + 1];
        }
     NumofSemCourse--;
     break;
    }
 }
}
void Semester::addCourse(){
 for(int i = 0; i < NumofSemCourse; i++){
    cout << "Course" << i + 1 << "." << "ID: ";
    cin >> courses[i].ID;
    cout << "Course" << i + 1 << "." << "Name: ";
    cin >> courses[i].Name; //getline
    cout << "Course" << i + 1 << "." << "Class Name: ";
    cin >> courses[i].ClassName; //manglop
    cout << "Course" << i + 1 << "." << "Teacher Name: ";
    cin >> courses[i].TeacherName; //getline
    cout << "Course" << i + 1 << "." << "Num of Credits: ";
    cin >> courses[i].NumofCredits;
    cout << "Course" << i + 1 << "." << "Session Day: ";
    cin >> courses[i].SessionDay;
    cout << "Course" << i + 1 << "." << "Session Time: ";
    cin >> courses[i].SessionTime;
 }
}

