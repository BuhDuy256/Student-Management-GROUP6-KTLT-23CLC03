#include"scoreboardClass.h"

void viewScoreBoardOfAClass() {
	menuCommandHeader();
	std::cout << "[7]. View scoreboard of a class\n";
	int no;
	displayTableOfClassesStudyingInCurrentSemester(no);
	std::cout << "\n\t(*) Enter '0' to return\n";
	int choice;
	getChoiceInt(0, no, "\t(?) Enter the class number (0-" + std::to_string(no) + "): ", choice);
	if (choice == 0) {
		classManagementPage();
		return;
	}
	Node<Class>* ChosenClass = ChooseClass(choice);
	if (ChosenClass == nullptr)
	{
		std::cout << "\t(X) Invalid choice!\n";
		system("pause");
		viewScoreBoardOfAClass();
		return;
	}
	Node<std::string>* TempCourses = nullptr;
	Node<Course>* SemCourse = currSem.Courses;
	while (SemCourse != nullptr)
	{
		std::string addTempCourse = SemCourse->data.ID;
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

	menuCommandHeader();
	std::cout << "[7]. Scoreboard of class " << ChosenClass->data.className << " in semester " << currSemNumber << " of school year " << currSYear->data.year << std::endl;
	Node<std::string>* ClassCourses = ClassCourse(TempCourses, check);
	int NumofClassCourses = countUniqueTempCourses(ClassCourses);
	Node<std::string>* print = ClassCourses;
	std::cout << "\n\t+----------+--------------------------------------------------+";
	std::cout << std::left << "\n\t|" << std::setfill(' ') << std::setw(10) << "CourseID" << "|" << std::setfill(' ') << std::setw(50) << "Course Name" << "|" << "\n";
	std::cout << "\t+----------+--------------------------------------------------+" << "\n";
	while (print != nullptr)
	{
		std::string courseName;
		Node<Course>* checkName = currSem.Courses;
		while (checkName != nullptr)
		{
			if (checkName->data.ID == print->data)
			{
				courseName = checkName->data.Name;
				break;
			}
			checkName = checkName->next;
		}
		std::cout << std::left << "\t|" << std::setfill(' ') << std::setw(10) << print->data << "|" << std::setfill(' ') << std::setw(50) << courseName << "|" << "\n";
		print = print->next;
	}
	std::cout << "\t+----------+--------------------------------------------------+";
	std::cout << "\n\n";

	std::cout << "\t+-----+-------------+------------------------------+";
	for (int i = 0; i < NumofClassCourses; i++) std::cout << "---------+";
	std::cout << "-----+-------------+";
	std::cout << std::left << "\n\t|" << " " << std::setfill(' ') << std::setw(4) << "NO" << "|" << " " << std::setfill(' ') << std::setw(12) << "Student ID " << "|" << " " << std::setfill(' ') << std::setw(29) << "Student Name" << "|";

	Node<std::string>* makeFirstRow = ClassCourses;
	while (makeFirstRow != nullptr) {
		std::cout << std::left << " " << std::setfill(' ') << std::setw(8) << makeFirstRow->data << "|";
		makeFirstRow = makeFirstRow->next;
	}
	std::cout << " GPA |" << " Overall GPA |";
	std::cout << "\n";
	std::cout << "\t+-----+-------------+------------------------------+";
	for (int i = 0; i < NumofClassCourses; i++) std::cout << "---------+";
	std::cout << "-----+-------------+" << "\n";
	Node<Student>* StuScore = ChosenClass->data.students;
	int index = 1;
	while (StuScore != nullptr)
	{
		Node<std::string>* StudentUniqueCourses = nullptr;
		double numofactivecourses = 0, gpa = 0;
		std::cout << std::left << "\t| " << std::setfill(' ') << std::setw(4) << index << "| " << std::setfill(' ') << std::setw(12) << StuScore->data.ID << "| " << std::setfill(' ') << std::setw(29) << StuScore->data.name << "|";
		Node<std::string>* tmp2 = ClassCourses;
		while (tmp2 != nullptr)
		{
			Node<Course>* check = currSem.Courses;
			while (check != nullptr)
			{
				bool score = false;
				if (tmp2->data == check->data.ID)
				{
					int numofstudents = check->data.courseSize;
					for (int i = 0; i < numofstudents; i++)
					{
						if (StuScore->data.ID == check->data.score[i].studentID)
						{
							std::string newStuCourses = check->data.ID;
							Node<std::string>* newStuCours = new Node<std::string>(newStuCourses, StudentUniqueCourses);
							StudentUniqueCourses = newStuCours;
							if (check->data.score[i].total != (-1) * 1.0)
							{
								gpa += check->data.score[i].total;
								numofactivecourses++;
							}

							if (check->data.score[i].final != (-1) * 1.0) std::cout << std::left << " " << std::setfill(' ') << std::setw(8) << check->data.score[i].final << "|";
							else std::cout << std::setw(9) << " " << "|";
							score = true;
							break;
						}
					}
				}
				if (score) break;
				check = check->next;
			}
			if (check == nullptr) std::cout << std::setw(9) << " " << "|";
			tmp2 = tmp2->next;
		}
		if (numofactivecourses == 0 || gpa == 0) std::cout << std::setw(5) << " " << "|";
		else std::cout << std::left << " " << std::setfill(' ') << std::setw(4) << std::fixed << std::setprecision(1) << gpa / numofactivecourses << "|";
		double prevtotal = 0, prevnumofacticour = 0;
		previous(prevtotal, prevnumofacticour, StuScore, ChosenClass, StudentUniqueCourses);
		if (prevnumofacticour == 0 && numofactivecourses == 0) std::cout << std::setw(13) << " " << "|\n";
		else std::cout << std::left << " " << std::setfill(' ') << std::setw(12) << std::fixed << std::setprecision(1) << (prevtotal + gpa) / (prevnumofacticour + numofactivecourses) << "|\n";

		StuScore = StuScore->next;
		index++;
	}
	std::cout << "\t+-----+-------------+------------------------------+";
	for (int i = 0; i < NumofClassCourses; i++) std::cout << "---------+";
	std::cout << "-----+-------------+" << "\n";

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
	std::cout << "\n";
	system("pause");
	classManagementPage();
	return;
}

void previous(double& previoussum, double& previousnumofacticour, Node<Student>* StuScore, Node<Class>* ChosenClass, Node<std::string>* StuUniqueCours) {
	double prevsum = 0, preacticour = 0;
	Node<SchoolYear>* tempYear = currSYear;
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
				if (check->data == tempCours->data.ID)
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
						std::string newCours = tempCours->data.ID;
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
			bool canCount = false;
			Node<std::string>* check = StuUniqueCours;
			while (check != nullptr)
			{
				if (check->data == tempCours->data.ID)
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
						std::string newCours = tempCours->data.ID;
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
		for (int z = 0; z < 3; z++)
		{
			Node<Course>* tempCour = tempYear->data.semesters[z].Courses;
			while (tempCour != nullptr)
			{
				bool canCount = false;
				Node<std::string>* check = StuUniqueCours;
				while (check != nullptr)
				{
					if (check->data == tempCour->data.ID)
					{
						canCount = true;
						break;
					}
					check = check->next;
				}
				if (!canCount) {
					for (int i = 0; i < tempCour->data.courseSize; i++)
					{
						if (tempCour->data.score[i].studentID == StuScore->data.ID)
						{
							std::string newCours = tempCour->data.ID;
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
				}
				tempCour = tempCour->next;
			}
		}
		if (checkloop)
		{
			previousnumofacticour = preacticour;
			previoussum = prevsum;
			break;
		}
		tempYear = tempYear->next;
	}

	if (tempYear == nullptr)
	{
		previousnumofacticour = preacticour;
		previoussum = prevsum;
	}

	Node<std::string>* deleteStuCours = StuUniqueCours;
	while (deleteStuCours != nullptr)
	{
		Node<std::string>* tempdelete = deleteStuCours;
		deleteStuCours = deleteStuCours->next;
		delete tempdelete;
	}
}

void deleteDuplicateTempCourses(Node<std::string>* TempCourses) {
	Node<std::string>* temp = TempCourses;
	while (temp != nullptr) {
		Node<std::string>* deleteCourse = temp;
		while (deleteCourse != nullptr)
		{
			if (deleteCourse->next != nullptr && deleteCourse->next->data == temp->data)
			{
				Node<std::string>* temp = deleteCourse->next;
				deleteCourse->next = deleteCourse->next->next;
				delete temp;
				continue;
			}
			deleteCourse = deleteCourse->next;
		}
		temp = temp->next;
	}
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

bool Exist(bool* check, Node<Course>* checkexist, Node<std::string>* TempCourse, int n, int& ind) {
	Node<std::string>* temp = TempCourse;
	int index = 0;
	while (temp != nullptr)
	{
		if (temp->data == checkexist->data.ID)
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

Node<Class>* ChooseClass(int choice) {  //copyallfunc
	Node<SchoolYear>* tempcurrYear = currSYear;
	int index = 1;
	while (tempcurrYear != nullptr)
	{
		Node<Class>* tempclass = tempcurrYear->data.classes;
		while (tempclass != nullptr)
		{
			if (index == choice)
			{
				return tempclass;
			}
			index++;
			tempclass = tempclass->next;
		}
		tempcurrYear = tempcurrYear->next;
	}
	return nullptr;
}