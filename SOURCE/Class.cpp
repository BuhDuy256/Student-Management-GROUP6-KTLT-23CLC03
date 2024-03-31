#include"Class.h"
#include<fstream>
#include<sstream>
#include<algorithm>

void importAllClassesCSV() {
	std::ifstream inF ("../CSV Files/AllClasses.csv");
	if (!inF.is_open()) {
		std::cout << "Could't import AllClasses.csv!";
		return;
	}
	Node<SchoolYear>* syHead = currYear;
	std::string header;
	std::getline(inF, header);
	std::string line;
	while(std::getline(inF, line)) {
        // Check if the line is empty or contains only whitespace
        if (line.empty() || std::all_of(line.begin(), line.end(), [](unsigned char c) { return std::isspace(c); })) {
            break; // Stop reading if the line is empty
        }
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
    std::ofstream outF("../CSV Files/AllClasses.csv", std::ofstream::out | std::ofstream::trunc);
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


//function declaration:
//system.h:
void deleteDuplicateTempCourses(Node<std::string>* TempCourses);	
int countUniqueTempCourses(Node<std::string>* TempCourses);
int countUniqueTempCourses2(Node<std::string>* TempCourses, bool* check);
bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind);
Node<std::string>* ClassCourse(Node<std::string>* TempCourses, bool* check);
Node<Class>* ChooseClass(std::string choice);
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass,Node<std::string>* StuUniqueCours);

//class.h:
void viewScoreBoardOfAClass();


//class.cpp
void viewScoreBoardOfAClass() {
    system("cls");
    viewAllClassesInSchool();
    std::string choice;
    std::cout << "ENTER ClASS: ";
    std::cin >> choice;

    Node<Class>* ChosenClass = ChooseClass(choice);
    if (ChosenClass == nullptr)
    {
        std::cout << "Invalid class!\n";
        system("pause");
        viewScoreBoardOfAClass();
        return;
    }
    Node<std::string>* TempCourses = nullptr;
    Node<Course>* SemCourse = currSem.Courses;
    while (SemCourse != nullptr)
    {
        std::string addTempCourse = SemCourse->data.Name;
        Node<std::string>* newTempCourse = new Node<std::string>(addTempCourse, TempCourses);
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
            if (!Exist(check, tmp, TempCourses, numofCourses, index))
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
    int NumofClassCourses = countUniqueTempCourses2(ClassCourses, check);
    Node<std::string>* print = ClassCourses;
    std::cout << "\n+----------+------------------------------+";
    std::cout << "\n| " << "CourseID |" << "         COURSE NAME          |" << "\n";
    std::cout << "+----------+------------------------------+";
    while (print != nullptr)
    {
        std::string courseID;
        Node<Course>* checkID = currSem.Courses;
        while (checkID != nullptr)
        {
            if (checkID->data.Name == print->data)
            {
                courseID = checkID->data.ID;
                break;
            }
            checkID = checkID->next;
        }
        std::cout << "\n|" << std::setfill(' ') << std::setw(10) << courseID << "|" << std::setfill(' ') << std::setw(30) << print->data << "|" << "\n"; //needfix
        std::cout << "+----------+------------------------------+";
        print = print->next;
    }
    std::cout << "\n\n";
    const int totalWidth = 30 + 11 + NumofClassCourses * 9  + 6 + 11; //fix
    std::cout << "+----------------------------+----------+"; //fix
    for (int i = 0; i < NumofClassCourses; i++) std::cout << "--------+"; //fix
    std::cout << "-----+----------+";
    std::cout << "\n|           NAME            |     ID   |"; //fix

    Node<std::string>* makeFirstRow = ClassCourses;
    while (makeFirstRow != nullptr) {
        std::string courseID;
        Node<Course>* checkID = currSem.Courses;
        while (checkID != nullptr)
        {
            if (checkID->data.Name == makeFirstRow->data)
            {
                courseID = checkID->data.ID;
                break;
            }
            checkID = checkID->next;
        }
        std::cout << std::setfill(' ') << std::setw(8) << courseID << "|"; //fix
        makeFirstRow = makeFirstRow->next;
    }
    std::cout << " GPA| " << "OVERALLGPA|";
    std::cout << "\n";
    std::cout << std::setfill('-') << std::setw(totalWidth) << "\n";
    

    Node<Student>* StuScore = ChosenClass->data.students;
    while (StuScore != nullptr)
    {
        Node<std::string>* StudentUniqueCourses = nullptr;
        double numofactivecourses = 0, gpa = 0;
        //fix
        std::cout << "|" << std::setfill(' ') << std::setw(28) << StuScore->data.name << "|" << std::setfill(' ') << std::setw(10) << StuScore->data.ID << "|";
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
                            std::string newStuCourses = check->data.Name;
                            Node<std::string>* newStuCours = new Node<std::string>(newStuCourses, StudentUniqueCourses);
                            StudentUniqueCourses = newStuCours;
                            if (check->data.score[i].total != (-1) * 1.0)
                            {
                                gpa += check->data.score[i].total;
                                numofactivecourses++;
                            }                                                              //fix
                            if (check->data.score[i].final != (-1) * 1.0) std::cout << std::setw(8) << check->data.score[i].final << std::setfill(' ') << "|";
                            else std::cout << std::setw(8) << std::setfill(' ') << "|";
                            score = true;
                            break;
                        }
                    }
                }
                if (score) break;
                check = check->next;
            }
            if (check == nullptr) std::cout << std::setw(8) << std::setfill(' ') << "|"; //fix
            tmp2 = tmp2->next;
        }
        if (numofactivecourses == 0 || gpa == 0) std::cout << std::setw(5) << std::setfill(' ') << "|"; //fix
        else std::cout << std::setw(10) << std::right << gpa / numofactivecourses << "|"; //fix
        double prevtotal = 0, prevnumofacticour = 0;
        previous(prevtotal, prevnumofacticour, StuScore, ChosenClass,StudentUniqueCourses);
        //fix
        std::cout << std::setw(10) << std::right << (prevtotal + gpa) / (prevnumofacticour + numofactivecourses) << "|\n";
        std::cout << std::setfill('-') << std::setw(totalWidth) << "\n";
        StuScore = StuScore->next;
    }
    delete[] check;
    Node<std::string>* deleteTempCourses = TempCourses;
    while (deleteTempCourses != nullptr)
    {
        Node<std::string>* temp = deleteTempCourses;
        deleteTempCourses = deleteTempCourses->next;
        delete temp;
    }
    Node<std::string>* deleteClassCourses = ClassCourses;
    while (deleteClassCourses != nullptr)
    {
        Node<std::string>* temp = deleteClassCourses;
        deleteClassCourses = deleteClassCourses->next;
        delete temp;
    }
    system("pause");
    //callpreviouspage
}




//system.cpp
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
                continue;
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
    return cnt;
}
int countUniqueTempCourses2(Node<std::string>* TempCourses, bool* check) {
    int index = 0, cnt = 0;
    Node<std::string>* checkk = TempCourses;
    while (checkk != nullptr)
    {
        if (check[index]) cnt++;
        checkk = checkk->next;
        index++;
    }
    return cnt;
}
bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind) {
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
        temp = temp->next;
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
    return Cour;
}
Node<Class>* ChooseClass(std::string choice) {
    Node<SchoolYear>* tempcurrYear = latestSYear;
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
void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass,Node<std::string>* StuUniqueCours) {
    //previoussem
    double prevsum = 0, preacticour = 0;
    Node<SchoolYear>* tempYear = currSYear; //currSYear
    if (tempYear == nullptr) return;
    if (currSemNumber >= 2)
    {
        Node<Course>* tempCours = tempYear->data.semesters[0].Courses;
        while (tempCours != nullptr)
        {
            bool canCount = false;
            Node<std::string>* check = StuUniqueCours;
            while (check != nullptr)
            {
                if (check->data == tempCours->data.Name)
                {
                    canCount = true;
                    break;
                }
                check = check->next;
            }
            if (!canCount)
            {
                for (int i = 0; i < tempCours->data.courseSize; i++)
                {
                    if (tempCours->data.score[i].studentID == StuScore->data.ID)
                    {
                        std::string newCours = tempCours->data.Name;
                        Node<std::string>* newStuCour = new Node<std::string>(newCours, StuUniqueCours);
                        StuUniqueCours = newStuCour;
                        if (tempCours->data.score[i].total != (-1) * 1.0)
                        {
                            prevsum += tempCours->data.score[i].total;
                            preacticour++;
                        }
                        break;
                    }
                }
            }
            tempCours = tempCours->next;
        }
    }
    if (currSemNumber == 3)
    {
        Node<Course>* tempCours = tempYear->data.semesters[1].Courses;
        while (tempCours != nullptr)
        {
            Node<std::string>* check = StuUniqueCours;
            while (check != nullptr)
            {
                if (check->data == tempCours->data.Name) break;
                check = check->next;
            }
            for (int i = 0; i < tempCours->data.courseSize; i++)
            {
                if (tempCours->data.score[i].studentID == StuScore->data.ID)
                {
                    std::string newCours = tempCours->data.Name;
                    Node<std::string>* newStuCour = new Node<std::string>(newCours, StuUniqueCours);
                    StuUniqueCours = newStuCour;
                    if (tempCours->data.score[i].total != (-1) * 1.0)
                    {
                        prevsum += tempCours->data.score[i].total;
                        preacticour++;
                    }
                    break;
                }
            }
            tempCours = tempCours->next;
        }
    }
    tempYear = tempYear->next;
    while (tempYear != nullptr) 
    {
        Node<Class>* checkClass = tempYear->data.classes;
        bool checkloop = false;
        while (checkClass != nullptr)
        {
            if (checkClass->data.className == ChosenClass->data.className)
            {
                checkloop = true;
                break;
            }
            checkClass = checkClass->next;
        }
        for (int i = 0; i < 3; i++)
        {
            Node<Course>* tempCour = tempYear->data.semesters[i].Courses;
            while (tempCour != nullptr)
            {
                Node<std::string>* check = StuUniqueCours;
                while (check != nullptr)
                {
                    if (check->data == tempCour->data.Name) break;
                    check = check->next;
                }
                for (int i = 0; i < tempCour->data.courseSize; i++)
                {
                    if (tempCour->data.score[i].studentID == StuScore->data.ID)
                    {
                        std::string newCours = tempCour->data.Name;
                        Node<std::string>* newStuCour = new Node<std::string>(newCours, StuUniqueCours);
                        StuUniqueCours = newStuCour;
                        if (tempCour->data.score[i].total != (-1) * 1.0)
                        {
                            prevsum += tempCour->data.score[i].total;
                            preacticour++;
                        }
                        break;
                    }
                }
                tempCour = tempCour->next;
            }
        }
        if (checkloop)
        {
            previousnumofacticour = preacticour;
            previoussum = prevsum;
            return;
        }
        tempYear = tempYear->next;
    }
    Node<std::string>* deleteStuCours = StuUniqueCours;
    while (deleteStuCours != nullptr)
    {
        Node<std::string>* tempdelete = deleteStuCours;
        deleteStuCours = deleteStuCours->next;
        delete tempdelete;
    }
}
