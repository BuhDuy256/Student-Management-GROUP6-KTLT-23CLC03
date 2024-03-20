#include"Student.h"
void Student::viewProfile(){
 cout << "PROFILE: " << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
 cout << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 cout << "|" << setw(14) << "NAME " << setfill(' ') << "|" << setw(30) << name << setfill(' ') << "|" << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
 cout << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 cout << "|" << setw(14) << "ID " << setfill(' ') << "|" << setw(30) << ID << setfill(' ') << "|" << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
 cout << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 cout << "|" << setw(14) << "MAIN CLASS " << setfill(' ') << "|" << setw(30) << mainClass << setfill(' ') << "|" << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
 cout << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 cout << "|" << setw(14) << "BIRTHDAY " << setfill(' ') << "|" << setw(30) << birthday << setfill(' ') << "|" << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
 cout << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 cout << "|" << setw(14) << "SOCIAL ID " << setfill(' ') << "|" << setw(30) << socialID << setfill(' ') << "|" << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
 cout << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 cout << "|" << setw(14) << "GENDER " << setfill(' ') << "|" << setw(30) << gender << setfill(' ') << "|" << "\n";
 for(int i = 0; i < 35; i++) cout << " ";
 for(int i = 0; i < 46; i++) cout << "-";
}
