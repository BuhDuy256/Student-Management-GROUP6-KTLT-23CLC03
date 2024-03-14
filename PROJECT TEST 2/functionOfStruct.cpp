#include"structProject.h"

template<class T>
bool Queue<T>::isEmpty() {
	return head == nullptr;
}

template<class T>
int Queue<T>::size() {
	int count = 0;
	Node<T>* curr = head;
	while (curr) {
		count++;
		curr = curr -> next;
	}
	return count;
}

template<class T>
T Queue<T>::front() {
	if (isEmpty()) {
		std::cout << "Data does not exist!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return head -> data;
}

template<class T>
T Queue<T>::back() {
	if (isEmpty()) {
		std::cout << "Data does not exist!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return tail -> data;
}

template<class T>
void Queue<T>::push(T value) {
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty()) {
		head = tail = newNode;
	} else {
		tail -> next = newNode;
		tail = newNode;
	}
}

template<>
void Queue<SchoolYear>::pushSchoolYear(SchoolYear value) {
    Node<SchoolYear>* newNode = new Node<SchoolYear>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<>
void Queue<Class>::pushClass(Class value) {
    Node<Class>* newNode = new Node<Class>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template<>
void Queue<Student>::pushStudent(Student value) {
    Node<Student>* newNode = new Node<Student>(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail -> next = newNode;
        tail = newNode;
    }
}

template<class T>
void Queue<T>::pop() {
	if (isEmpty()) {
		std::cout << "Queue is empty!" << std::endl;
		exit(EXIT_FAILURE);
	}
	Node<T>* temp = head;
	head = head -> next;
	delete temp;
	if (head == nullptr) {
		tail = nullptr;
	}
}

void Student::generatePasswordFromID() {
	std::string lastThreeDigits = StudentID.substr(StudentID.length() - 3);
    std::ostringstream oss;
    oss << "KHTN@" << lastThreeDigits;
    password = oss.str();
}

void SchoolYear::addSemester(unsigned short semesterNumber, std::string startDate, std::string endDate) {
	if (semesterNumber > 0 && semesterNumber <= 3) {
		semesters[semesterNumber - 1].semesterNumber = semesterNumber;
		semesters[semesterNumber - 1].startDate = startDate;
		semesters[semesterNumber - 1].endDate = endDate;
	} else {
		std::cout << "Invalid semester number!" << std::endl;
	}
}