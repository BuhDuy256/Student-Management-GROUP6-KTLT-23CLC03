#include"Class.h"
#include<fstream>
#include<sstream>

void importAllClassesCSV() {
	std::ifstream inF ("AllClasses.csv");
	if (!inF.is_open()) {
		std::cout << "Can't import AllClasses.csv!";
		return;
	}
	Node<SchoolYear>* syHead = currYear;
	std::string header;
	std::getline(inF, header);
	std::string line;
	while(std::getline(inF, line)) {
		Class newClass;
		std::stringstream ss (line);
		std::getline(ss, newClass.className, ',');
		std::getline(ss, newClass.schoolYear, ',');
		Node<SchoolYear>* syCurr = syHead;
		bool found = false;
		while(syCurr && !found) {
			if (syCurr -> data.year == newClass.schoolYear) {
				found = true;
				if (!syCurr -> data.classes) {
                    syCurr -> data.classes = new Node<Class>(newClass);
                } else {
                    Node<Class>* claCurr = syCurr->data.classes;
                    while (claCurr -> next) {
                        claCurr = claCurr -> next;
                    }
                    claCurr -> next = new Node<Class>(newClass);
                }
				break;
			}
			syCurr = syCurr -> next;
		}
		if (!found) {
			std::cout << "Couldn't find the school year corresponding to " << newClass.className << std::endl;
		}
	}
	inF.close();
}

void saveAllClassesData() {
    Node<SchoolYear>* syCurr = currYear;
    std::ofstream outF("AllClasses.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Class Name,School Year\n";
        while(syCurr) {
            Node<Class>* claCurr = syCurr -> data.classes;
            while(claCurr) {
                outF << claCurr -> data.className << "," << claCurr -> data.schoolYear << "\n";
                claCurr = claCurr -> next;
            }
            syCurr = syCurr -> next;
        } 
    } else {
        std::cout << "Could't open AllClasses.csv to save Data." << std::endl;
    }
    outF.close();
}

void deleteAllClassesData() {
    Node<SchoolYear>* syCurr = currYear;
    while(syCurr) {
        Node<Class>* claCurr = syCurr -> data.classes;
        while(claCurr) {
            Node<Class>* temp = claCurr;
            claCurr = claCurr -> next;
            delete temp;
        }
        syCurr = syCurr -> next;
    } 
}
Node<Class>* ChooseClass(std::string choice) {
    Node<SchoolYear>* tempcurrYear = currYear;
    while (tempcurrYear != nullptr)
    {
        Node<Class>* tempclass = tempcurrYear->data.classes;
        while (tempclass != nullptr)
        {
            if (tempclass->data.className == choice)
            {
                return tempclass;
            }
            tempclass = tempclass->next;
        }
        tempcurrYear = tempcurrYear->next;
    }
    return nullptr;
}
void deleteDuplicateTempCourses(Node<std::string>* TempCourses) {
    if (TempCourses == nullptr) return;
    else
    {
        Node<std::string>* deleteCourse = TempCourses;
        while (deleteCourse != nullptr)
        {
            if (deleteCourse->next != nullptr && deleteCourse->next->data == TempCourses->data)
            {
                Node<std::string>* temp2 = deleteCourse->next;
                deleteCourse->next = deleteCourse->next->next;
                delete temp2;
            }
            deleteCourse = deleteCourse->next;
        }
    }
    deleteDuplicateTempCourses(TempCourses->next);
}

//scoreboard
void deleteDuplicateTempCourses(Node<std::string>* TempCourses) {
    if (TempCourses == nullptr) return;
    else
    {
        Node<std::string>* deleteCourse = TempCourses;
        while (deleteCourse != nullptr)
        {
            if (deleteCourse->next != nullptr && deleteCourse->next->data == TempCourses->data)
            {
                Node<string>* temp2 = deleteCourse->next;
                deleteCourse->next = deleteCourse->next->next;
                delete temp2;
            }
            deleteCourse = deleteCourse->next;
        }
    }
    deleteDuplicateTempCourses(TempCourses->next);
}
int countUniqueTempCourses(Node<std::string>* TempCourses) {
    int cnt = 0;
    Node<std::string>* count = TempCourses;
    while (count != nullptr)
    {
        cnt++;
        count = count->next;
    }
}
bool Exist(bool* check, Node<Course>* checkexist,Node<std::string>* TempCourse,int n,int &ind) {
    Node<std::string>* temp = TempCourse;
    int index = 0;
    while (temp != nullptr)
    {
        if (temp->data == checkexist->data.Name)
        {
            ind = index;
            return check[index];
        }
        index++;
    }
    return false;
}
Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check) {
    Node<std::string>* Cour = nullptr;
    int index = 0;
    while (TempCourses != nullptr)
    {
        if (check[index])
        {
            std::string newCour = TempCourses->data;
            Node<std::string>* NewCourse = new Node<std::string>(newCour, Cour);
            Cour = NewCourse;
        }
        index++;
        TempCourses = TempCourses->next;
    }
}
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore,Node<Class>* ChosenClass) {
    double prevsum = 0, preacticour = 0;
    Node<SchoolYear>* tempYear = currYear;
    if (tempYear == nullptr) return;
    tempYear = tempYear->next;
    while (tempYear != nullptr)
    {
        Node<Class>* checkClass = tempYear->data.classes;
        bool check = false;
        while (checkClass != nullptr)
        {
            if (checkClass->data.className == ChosenClass->data.className)
            {
                check = true;
                break;
            }
            checkClass = checkClass->next;
        }
        for (int i = 0; i < 3; i++)
        {
            Node<Course>* tempCour = tempYear->data.semesters[i].Courses;
            while (tempCour != nullptr)
            {
                for (int i = 0; i < tempCour->data.courseSize; i++)
                {
                    if (tempCour->data.score[i].studentID == StuScore->data.ID)
                    {
                        prevsum += tempCour->data.score[i].total;
                        preacticour++;
                        break;
                    }
                }
                tempCour = tempCour->next;
            }
        }
        if (check)
        {
            previousnumofacticour = preacticour;
            previoussum = prevsum;
            return;
        }
        tempYear = tempYear->next;
    }
}
void viewScoreBoardOfAClass() {
    viewAllClassesInSchool();
    string choice;
    std::cout << "ENTER ClASS: ";
    cin >> choice;

    Node<Class>* ChosenClass = ChooseClass(choice);
    if (ChosenClass == nullptr)
    {
        std::cout << "Invalid class!\n";
        //systemclear
        //displaymenu
    }
    Node<std::string>* TempCourses = nullptr;
    Node<Course>* SemCourse = currSem.Courses;
    while (SemCourse != nullptr)
    {
        std::string addTempCourse = SemCourse->data.Name;
        Node<std::string>* newTempCourse = new Node<string>(addTempCourse, TempCourses);
        TempCourses = newTempCourse;
        SemCourse = SemCourse->next;
    }
    deleteDuplicateTempCourses(TempCourses);
    int numofCourses = countUniqueTempCourses(TempCourses);
    bool* check = new bool[numofCourses];
    for (int i = 0; i < numofCourses; i++) check[i] = false;
    Node<Student>* tempStu = ChosenClass->data.students;
    while (tempStu != nullptr)
    {
        Node<Course>* tmp = currSem.Courses;
        while (tmp != nullptr)
        {
            int index = 0;
            if (!Exist(check, tmp, TempCourses, numofCourses,index))
            {
                int numofStu = tmp->data.courseSize;
                for (int i = 0; i < numofStu; i++)
                {
                    if (tempStu->data.ID == tmp->data.score[i].studentID)
                    {
                        check[index] = true;
                    }
                }
            }
            tmp = tmp->next;
        }
        tempStu = tempStu->next;
    }
    Node<std::string>* ClassCourses = ClassCourse(TempCourses, check);
    int NumofClassCourses = countUniqueTempCourses(ClassCourses);
    std::cout << setfill('-') << setw(NumofClassCourses * 20 + 42 + NumofClassCourses) << "\n";
    std::cout << "|" << setw(30) << "STUDENT FULL NAME      " << setfill(' ') << "|STUDENT ID|";
    Node<std::string>* makeFirstRow = ClassCourses;
    while (makeFirstRow != nullptr)
    {
        std::cout << setw(20) << makeFirstRow->data << setfill(' ') << "|";
        makeFirstRow = makeFirstRow->next;
    }
    std::cout << setw(4) << "GPA|" << "" << setw(11) << "OVERALLGPA|";
    std::cout << "\n" << setfill('-') << setw(NumofClassCourses * 20 + 42 + NumofClassCourses);
    Node<Student>* StuScore = ChosenClass->data.students;
    while (StuScore != nullptr)
    {
        double numofactivecourses = 0, gpa = 0;
        std::cout << "|" << setw(30) << StuScore->data.name << setfill(' ') << "|STUDENT ID|";
        Node<std::string>* tmp2 = ClassCourses;
        while (tmp2 != nullptr)
        {
            Node<Course>* check = currSem.Courses;
            while (check != nullptr)
            {
                bool score = false;
                if (tmp2->data == check->data.Name)
                {
                    int numofstudents = check->data.courseSize;
                    for (int i = 0; i < numofstudents; i++)
                    {
                        if (StuScore->data.ID == check->data.score[i].studentID)
                        {
                                gpa += check->data.score[i].total;
                                numofactivecourses++;

                            std::cout << setw(20) << check->data.score[i].final << setfill(' ') << "|";
                            score = true;
                            break;
                        }
                    }
                }
                if (score) break;
                check = check->next;
            }
            if(check == nullptr) std::cout << setw(20) << setfill(' ') << "|";
            tmp2 = tmp2->next;
        }
        if(numofactivecourses == 0 || gpa == 0) std::cout << setw(4) << setfill(' ') << "|";
        else std::cout << setw(4) << gpa / numofactivecourses << setfill(' ') << "|";
        double prevtotal = 0, prevnumofacticour = 0;
        previous(prevtotal, prevnumofacticour, StuScore, ChosenClass);
        std::cout << setw(10) << (gpa + prevtotal) / (numofactivecourses + prevnumofacticour) << setfill(' ') << "|";
        std::cout << "\n" << setfill('-') << setw(NumofClassCourses * 20 + 42 + NumofClassCourses);
        StuScore = StuScore->next;
    }
    //systemclear
    //displaymenu
}
//endofscoreboard
