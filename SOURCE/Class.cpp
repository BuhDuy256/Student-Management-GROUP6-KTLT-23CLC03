#include"Class.h"
void createANewClass(Node<Class>* &CurClass,string classname,Node<SchoolYear>* CurYear){
 Class newclass;
 newclass.className = classname;
 newclass.schoolYear = CurYear->data.year;
 Node<Class>* NewClass = new Node<Class>(newclass,CurClass);
 CurClass = NewClass;
}
void viewAllClassesInSchool(Node<Class>* CurClass){
 if(CurClass == nullptr) return;
 for(int i = 0; i < 11; i++) cout << "-";
 cout << "\n";
 Node<Class>* temp = CurClass;
 while(temp != nullptr){
    cout << "|" << setw(9) << temp->data.className << setfill(' ') << "|" << "\n";
    for(int i = 0; i < 11; i++) cout << "-";
    cout << "\n";
    temp = temp->next;
 }
}
void viewAllClassesInASchoolYear(Node<Class>* CurClass,Node<SchoolYear>* CurYear){
 if(CurClass == nullptr) return;
 displayAllSchoolYears(CurYear);
 int choice, i = 1;
 cout << "ENTER YOUR CHOICE: ";
 cin >> choice;
 if(choice == 0) return;
 cout << "\n";
 Node<SchoolYear>* temp2 = CurYear;
 while(i < choice){
    temp2 = temp2->next;
    i++;
 }
 string thatyear = temp2->data.year;
 for(int i = 0; i < 11; i++) cout << "-";
 Node<Class>* temp = CurClass;
 while(temp != nullptr){
    if(temp->data.schoolYear == thatyear)
    {
    cout << "|" << setw(9) << temp->data.className << setfill(' ') << "|" << "\n";
    for(int i = 0; i < 11; i++) cout << "-";
    cout << "\n";
    }
    temp = temp->next;
 }
}
