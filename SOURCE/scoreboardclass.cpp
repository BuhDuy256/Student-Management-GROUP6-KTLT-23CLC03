#include"scoreboardclass.h"

bool findStudentAndAddCourse(std::string studentID, Node<Course>*& courseAddress) {
	bool found = false;
	Node<SchoolYear>* syCurr = latestSYear;
	while (syCurr && !found) {
		Node<Class>* claCurr = syCurr->data.classes;
		while (claCurr && !found) {
			Node<Student>* stuCurr = claCurr->data.students;
			while (stuCurr) {
				if (stuCurr->data.ID == studentID) {
					found = true;
					Node<Node<Course>*>* scoreCurr = stuCurr->data.courseScores;
					stuCurr->data.courseScores = new Node<Node<Course>*>(courseAddress, scoreCurr);
					return found;
				}
				stuCurr = stuCurr->next;
			}
			claCurr = claCurr->next;
		}
		syCurr = syCurr->next;
	}
	return found;
}

void deleteCourseAddressOfAStudent(std::string studentID, Node<Course>*& courseAddress) {
	bool found = false;
	Node<SchoolYear>* syCurr = latestSYear;
	while (syCurr && !found) {
		Node<Class>* claCurr = syCurr->data.classes;
		while (claCurr && !found) {
			Node<Student>* stuCurr = claCurr->data.students;
			while (stuCurr) {
				if (stuCurr->data.ID == studentID) {
					Node<Node<Course>*>* scoreCurr = stuCurr->data.courseScores;
					Node<Node<Course>*>* prev = nullptr;
					while (scoreCurr) {
						if (scoreCurr->data == courseAddress) {
							if (prev) {
								prev->next = scoreCurr->next;
							}
							else {
								stuCurr->data.courseScores = scoreCurr->next;
							}
							delete scoreCurr;
							return;
						}
						prev = scoreCurr;
						scoreCurr = scoreCurr->next;
					}
				}
				stuCurr = stuCurr->next;
			}
			claCurr = claCurr->next;
		}
		syCurr = syCurr->next;
	}
}

void removeDuplicateCourseAddress(Node<CourseAddress>*& list) {
	if (!list) {
		return;
	}
	Node<CourseAddress>* temp = list;
	while (temp) {
		Node<Node<Course>*>* tempAdd = temp->data.address;

		while (tempAdd->next) {
			Node<Node<Course>*>* tempAdd2 = tempAdd;
			while (tempAdd2->next) {
				if (tempAdd->data == tempAdd2->next->data && !tempAdd->next->next) {
					Node<Node<Course>*>* del = tempAdd2->next;
					tempAdd2->next = nullptr;
					delete del;
				}
				else if (tempAdd->data == tempAdd2->next->data && tempAdd->next->next) {
					Node<Node<Course>*>* del = tempAdd2->next;
					tempAdd2->next = tempAdd2->next->next;
					delete del;
				}
				if (tempAdd2->next->data == tempAdd->data)
					continue;
				tempAdd2 = tempAdd2->next;
			}
			if (!tempAdd->next)
				break;
			tempAdd = tempAdd->next;
		}

		temp = temp->next;
	}
}

void displayTableScoreboardOfAClass(Node<Class>*& claCurr) {
	menuCommandHeader();
	std::cout << "[7]. Scoreboard of class " << claCurr->data.className << std::endl;

	Node<CourseAddress>* list = nullptr;

	Node<Student>* stuCurr = claCurr->data.students;
	while (stuCurr) {
		Node<Node<Course>*>* addTemp = stuCurr->data.courseScores;
		while (addTemp) {
			Node<Course>* couTemp = addTemp->data;
			if (couTemp->data.couSem == currSemNumber && couTemp->data.couSY == currSYear->data.year) {
				if (!list) {
					CourseAddress newCourseAddList;
					newCourseAddList.courseID = couTemp->data.ID;
					newCourseAddList.address = new Node<Node<Course>*>(couTemp, nullptr);
					list = new Node<CourseAddress>(newCourseAddList, nullptr);
				}
				else {
					Node<CourseAddress>* temp = list;
					while (temp) {
						if (temp->data.courseID == couTemp->data.ID) {
							Node<Node<Course>*>* tempAdd = temp->data.address;
							while (tempAdd->next) {
								tempAdd = tempAdd->next;
							}
							tempAdd->next = new Node<Node<Course>*>(couTemp, nullptr);
							break;
						}
						if (!temp->next) {
							CourseAddress newCourseAddList;
							newCourseAddList.courseID = couTemp->data.ID;
							newCourseAddList.address = new Node<Node<Course>*>(couTemp, nullptr);
							temp->next = new Node<CourseAddress>(newCourseAddList, nullptr);
							break;
						}
						temp = temp->next;
					}
				}
			}
			addTemp = addTemp;
		}
		stuCurr = stuCurr->next;
	}
	int numberCourse = 0;
	Node<CourseAddress>* temp = list;
	while (temp) {
		numberCourse++;
		temp = temp->next;
	}
	int numberStudent = 0;
	std::string linePlus = "----------+";
	std::cout << "+--------+------------+------------------------------+";
	for (int i = 0; i < numberCourse; i++) {
		std::cout << linePlus;
	}
	std::cout << std::endl;
	std::cout << "| No     | Student ID | Full Name                    |";
	temp = list;
	while (temp) {
		std::cout << " " << temp->data.courseID << "    |";
		temp = temp->next;
	}
	std::cout << std::endl;
	std::cout << "+--------+------------+------------------------------+";
	for (int i = 0; i < numberCourse; i++) {
		std::cout << linePlus;
	}
	std::cout << std::endl;

	//...
	
	std::cout << "+--------+------------+------------------------------+";
	for (int i = 0; i < numberCourse; i++) {
		std::cout << linePlus;
	}
	std::cout << std::endl;
}

void viewScoreboardOfAClass() {
	menuCommandHeader();
	std::cout << "[7]. View scoreboard of a class" << std::endl;
	int no;
	displayTableOfClassesStudyingInCurrentSemester(no);
	std::cout << "(*) Enter '0' to return" << std::endl;
	int choice;
	getChoiceInt(0, no, "Enter the class number (1-" + std::to_string(no) + ")", choice);
	if (choice == 0) {
		classManagementPage();
		return;
	}
	int limits = 4;
	int count = 0;
	Node<SchoolYear>* syCurr = latestSYear;
	while (syCurr != nullptr && limits != 4) {
		Node<Class>* claCurr = syCurr->data.classes;
		while (claCurr) {
			count++;
			if (count == no) {
				displayTableScoreboardOfAClass(claCurr);
				return;
			}
			claCurr = claCurr->next;
		}
		limits++;
		syCurr = syCurr->next;
	}
}