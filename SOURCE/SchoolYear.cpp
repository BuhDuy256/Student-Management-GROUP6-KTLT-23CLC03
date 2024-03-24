#include"SchoolYear.h"
void createASchoolYear(Node<SchoolYear>*& CurYear) {
    string newyear;
    cout << "ENTER CURRENT YEAR: ";
    cin >> newyear;
    SchoolYear newy;
    newy.year = newyear;
    Node<SchoolYear>* NewYear = new Node<SchoolYear>(newy, CurYear);
    CurYear = NewYear;
}
void displayAllSchoolYears(Node<SchoolYear>* CurYear) {
    if (CurYear == nullptr) {
        cout << "NO SCHOOL YEAR" << "\n";
        return;
    }
    Node<SchoolYear>* temp = CurYear;
    for (int i = 0; i < 47; i++) cout << " ";
    for (int i = 0; i < 22; i++) cout << "-";
    cout << "\n";
    int i = 1;
    while (temp != nullptr) {
        for (int i = 0; i < 47; i++) cout << " ";
        cout << "|" << i << "|" << "     " << temp->data.year << setw(22 - 8 - temp->data.year.size()) << setfill(' ') << "|" << "\n";
        for (int i = 0; i < 47; i++) cout << " ";
        for (int i = 0; i < 22; i++) cout << "-";
        cout << "\n";
        temp = temp->next;
        i++;
    }
}
