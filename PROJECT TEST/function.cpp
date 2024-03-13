#include"struct.h"

template<class T>
void Queue<T>::enQueue(T x) {
    if (isEmpty()) {
        head = new Node<T>(x);
        tail = head;
    } else {
        tail -> next = new Node<T>(x);
        tail = tail -> next;
    }
}

template<class T>
void Queue<T>::deQueue(T x) {
    if (!isEmpty()) {
        Node<T>* temp = head;
        head = head -> next;
        detete temp;
        if (!head) 
            tail = nullptr;
    }
}

template<class T>
bool Queue<T>::isEmpty() {
    return head == nullptr;
}

template<class T>
T front() {
    if (!isEmpty()) 
        return head -> val;
    return T();
}

void Student::generatePasswordFromID() {
    if (StudentID.length() >= 4) {
        Password = "KHTN@" + StudentID.substr(StudentID.length() - 4);
    } else {           // Handle case where StudentID has less than 4 characters
        Password = "KHTN@" + StudentID;
    }
}

