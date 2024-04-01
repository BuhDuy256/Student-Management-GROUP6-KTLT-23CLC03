#include"viewScoreboardClass.h"

void viewScoreBoardOfAClass() {
	system("cls");
	// viewAllClassesInSchool();
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
	const int totalWidth = 30 + 11 + NumofClassCourses * 9 + 6 + 11; //fix
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
		else std::cout << std::setw(5) << std::right << gpa / numofactivecourses << "|"; //fix
		double prevtotal = 0, prevnumofacticour = 0;
		previous(prevtotal, prevnumofacticour, StuScore, ChosenClass, StudentUniqueCourses);
		if (prevnumofacticour == 0 && numofactivecourses == 0) std::cout << std::setw(10) << std::setfill(' ') << "|\n";
		else std::cout << std::setw(10) << std::right << (prevtotal + gpa) / (prevnumofacticour + numofactivecourses) << "|\n";

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

void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass, Node<std::string>* StuUniqueCours) {
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