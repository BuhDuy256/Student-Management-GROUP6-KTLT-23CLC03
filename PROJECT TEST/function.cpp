#include"struct.h"

template <class T>
void Queue<T>::enQueue(T x) {
    T* newNode = new T(x); 
    if (tail == nullptr) { 
        head = tail = newNode; 
    } else {
        tail->syNext = newNode; 
        tail = newNode; 
    }
}

template <class T>
void Queue<T>::deQueue() {
    if (isEmpty()) {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }
    T* temp = head; 
    head = head -> syNext; 
    delete temp; 
    if (head == nullptr) { 
        tail = nullptr; 
    }
}

template <class T>
bool Queue<T>::isEmpty() {
    return head == nullptr; 
}

template <class T>
T Queue<T>::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty. No front element." << std::endl;
        return T(); 
    }
    return *head;
}

void Student::generatePasswordFromID() {
    if (StudentID.length() >= 4) {
        Password = "KHTN@" + StudentID.substr(StudentID.length() - 4);
    } else {
        Password = "KHTN@" + StudentID;
    }
}



