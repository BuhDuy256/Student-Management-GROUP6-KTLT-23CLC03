#include"System.h"

void deleteDuplicateTempCourses(Node<std::string>* TempCourses);	
int countUniqueTempCourses(Node<std::string>* TempCourses);
int countUniqueTempCourses2(Node<std::string>* TempCourses, bool* check);
bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind);
Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check);
Node<Class>* ChooseClass(std::string choice);
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass,Node<std::string>* StuUniqueCours);
void viewScoreBoardOfAClass();

