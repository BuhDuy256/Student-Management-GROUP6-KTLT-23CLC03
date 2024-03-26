#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

long long Rand(long long l, long long r)
{
    return 1LL * rand() * rand() % (r - l + 1) + 1LL * l;
}
int main()
{
    srand(time(0));

    ifstream fin("AllStudents.csv");

    string s;
    getline(fin, s);

    while (getline(fin, s))
    {
        stringstream Line(s);
        string ID, Name, Gender, Birthday, SocialID, MainClass, Password;
        getline(Line, ID, ',');
        getline(Line, Name, ',');
        getline(Line, Gender, ',');
        getline(Line, Birthday, ',');
        getline(Line, SocialID, ',');
        getline(Line, MainClass, ',');
        getline(Line, Password, ',');

        ofstream fout("CSC001_" + MainClass + ".csv", ios::app);
        fout << Name + "," + ID + "\n";
    }
}