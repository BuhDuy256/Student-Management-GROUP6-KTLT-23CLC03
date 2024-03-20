#include"SchoolYear.h"
void createASchoolYear(Node<SchoolYear>* &CurYear){
 string newyear;
 cout << "ENTER CURRENT YEAR: ";
 cin >> newyear;
 SchoolYear newy;
 newy.year = newyear;
 Node<SchoolYear>* NewYear = new Node<SchoolYear>(newy,CurYear);
 CurYear = NewYear;
}
