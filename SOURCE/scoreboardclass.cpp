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

void viewScoreboardOfAClass() {
	menuCommandHeader();
	
}