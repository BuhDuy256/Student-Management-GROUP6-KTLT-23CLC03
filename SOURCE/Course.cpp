#include"Course.h"
#include<fstream>
#include<sstream>

void importAllCoursesCSV() {
    std::ifstream inF("AllCourses.csv");
    if (!inF.is_open()) {
        std::cout << "Can't import AllCourses.csv!" << std::endl;
        return;
    }
    std::string header;
    std::getline(inF, header); 
    std::string line;
    while (std::getline(inF, line)) {
        std::stringstream ss(line);
        Course newCourse;
        std::getline(ss, newCourse.ID, ',');
        std::getline(ss, newCourse.Name, ',');
        std::getline(ss, newCourse.className, ',');
        std::getline(ss, newCourse.teacherName, ',');
        std::getline(ss, newCourse.dayOfWeek, ',');
        std::getline(ss, newCourse.session, ',');
        std::string couSY, couSemTemp;
        std::getline(ss, couSY, ',');
        std::getline(ss, couSemTemp, ',');
        int couSem = 0;
        std::stringstream(couSemTemp) >> couSem;
        // std::cout << couSemTemp << " | " << couSY << "\n"; 
        Node<SchoolYear>* syCurr = currYear;
        bool found = false;
        while (syCurr && !found) {
            if (syCurr->data.year == couSY) {
                if (couSem > 0 && couSem <= 3) {
                    found = true;
                    if (!syCurr->data.semesters[couSem - 1].isCreated) {
                        std::cout << "Error: Semester not created for year " << couSY << " and semester " << couSem << std::endl;
                        break;
                    }
                    Node<Course>* couHead = syCurr->data.semesters[couSem - 1].Courses;
                    if (!couHead) {
                        syCurr->data.semesters[couSem - 1].Courses = new Node<Course>(newCourse);
                        syCurr->data.semesters[couSem - 1].Courses->data.score = new StudentScore[100];
                    } else {
                        Node<Course>* couCurr = couHead;
                        while (couCurr->next) {
                            couCurr = couCurr->next;
                        }
                        couCurr->next = new Node<Course>(newCourse);
                        couCurr->next->data.score = new StudentScore[100];
                    }
                } else {
                    std::cout << "Error: Invalid semester number for year " << couSY << ": " << couSem << std::endl;
                    break;
                }
            }
            syCurr = syCurr->next;
        }
        if (!found) {
            std::cout << "Error: Year not found: " << couSY << std::endl;
        }
    }
    inF.close(); 
}

void importContainingStudentsEnrolledInCourse(Node<Course>* couCurr) {
    std::string fileName = couCurr -> data.ID + "_" + couCurr -> data.className + ".csv";
    std::ifstream inF(fileName);
    if (!inF.is_open()) {
        std::cout << "Can't import " << fileName << std::endl;
        return;
    }
    std::string header;
    std::getline(inF, header);
    std::string line;
    int n = 0;
    while (std::getline(inF, line)) {
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ',');
        couCurr -> data.score[n].studentID = token;
        std::getline(ss, token, ',');
        couCurr -> data.score[n].studentName = token;
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr -> data.score[n].midTerm = std::stod(token);
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr -> data.score[n].final = std::stod(token);
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr -> data.score[n].other = std::stod(token);
        std::getline(ss, token, ',');
        if (!token.empty())
            couCurr -> data.score[n].total = std::stod(token);
        n++;
    }
    couCurr -> data.courseSize = n;
    inF.close();
}

void importAllStudentsInAllCoursesCSV() {
	Node<SchoolYear>* syHead = currYear;
	while(syHead) {
		for (int i = 0; i < 3; i++) {
			if (syHead -> data.semesters[i].isCreated) {
				Node<Course>* couCurr = syHead -> data.semesters[i].Courses;
				while(couCurr) {
					importContainingStudentsEnrolledInCourse(couCurr);
					couCurr = couCurr -> next;
				}
			}
		}
		syHead = syHead -> next;
	}
}

void saveAllCoursesData() {
    Node<SchoolYear>* syCurr = currYear;
    std::ofstream outF("AllCourses.csv", std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Course ID,Course Name,Class Name,Teacher Name,Day Of Week,Session,School Year,Semester\n";
        while(syCurr) {
            for(int i = 0; i < 3; i++) {
                if (syCurr -> data.semesters[i].isCreated) {
                    Node<Course>* couCurr = syCurr -> data.semesters[i].Courses;
                    while(couCurr) {
                        outF << couCurr -> data.ID << ","
                        << couCurr -> data.Name << ","
                        << couCurr -> data.className << ","
                        << couCurr -> data.teacherName << ","
                        << couCurr -> data.dayOfWeek << ","
                        << couCurr -> data.session << ","
                        << syCurr -> data.year << ","
                        << i + 1 << "\n";
                        couCurr = couCurr -> next;
                    }
                }
            }
            syCurr = syCurr -> next;
        } 
    } else {
        std::cout << "Could't open AllCourses.csv to save Data." << std::endl;
    }
    outF.close();
}

void saveScoreboardOfACourse(Node<Course>* couCurr) {
    std::string fileName = couCurr -> data.ID + "_" + couCurr -> data.className + ".csv";
    std::ofstream outF(fileName, std::ofstream::out | std::ofstream::trunc);
    if (outF.is_open()) {
        outF << "Student ID,Student Name,Midterm Mark,Final Mark,Other Mark,Total Mark\n";
        StudentScore* scoreArr = couCurr -> data.score;
        for(int i = 0; i < couCurr -> data.courseSize; i++) {
            outF << scoreArr[i].studentID << ","
            << scoreArr[i].studentName << ",";
            if (scoreArr[i].midTerm > 0)
                outF << scoreArr[i].midTerm;
            outF << ",";
            if (scoreArr[i].final > 0)
                outF << scoreArr[i].final;
            outF << ",";
            if (scoreArr[i].other > 0)
                outF << scoreArr[i].other;
            outF << ",";
            if (scoreArr[i].total > 0)
                outF << scoreArr[i].total;
            outF << "\n";  
        }
    } else {
        std::cout << "Could't open " << fileName << " to save Data." << std::endl;
    }
    outF.close();
}

void saveAllScoreboardsData() {
    Node<SchoolYear>* syCurr = currYear;
    while(syCurr) {
        for(int i = 0; i < 3; i++) {
            if (syCurr -> data.semesters[i].isCreated) {
                Node<Course>* couCurr = syCurr -> data.semesters[i].Courses;
                while(couCurr) {
                    saveScoreboardOfACourse(couCurr);
                    couCurr = couCurr -> next;
                }
            }
        }
        syCurr = syCurr -> next;
    } 
}

void deleteAllScoreboardsData() {
    Node<SchoolYear>* syCurr = currYear;
    while(syCurr) {
        for(int i = 0; i < 3; i++) {
            if (syCurr -> data.semesters[i].isCreated) {
                Node<Course>* couCurr = syCurr -> data.semesters[i].Courses;
                while(couCurr) {
                    couCurr -> data.courseSize = 0;
                    delete []couCurr -> data.score;
                    couCurr = couCurr -> next;
                }
            }
        }
        syCurr = syCurr -> next;
    } 
}

void deleteAllCourseData() {
    Node<SchoolYear>* syCurr = currYear;
    while(syCurr) {
        for(int i = 0; i < 3; i++) {
            if (syCurr -> data.semesters[i].isCreated) {
                Node<Course>* couCurr = syCurr -> data.semesters[i].Courses;
                while(couCurr) {
                    Node<Course>* temp = couCurr;
                    couCurr = couCurr -> next;
                    delete temp;
                }
            }
        }
        syCurr = syCurr -> next;
    }
}