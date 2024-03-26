#include "Semester.h"

void Semester::viewCoursesList()
{
     std::cout << std::left 
        << std::setw(10) << "Index" << std::setw(10) << "ID" << std::setw(30) << "Name" << std::setw(20) << "Day" 
        << std::setw(15) << "Session" << std::setw(20) << "Class Name" << std::setw(20) << "Teacher Name" << std::endl;
    std::cout << std::setfill('-') << std::setw(125) << "-" << std::setfill(' ') << std::endl;

    Node<Course>* course = coursesList;
    int index = 1;
    while (course != nullptr) {
        std::cout << std::left 
            << std::setw(10) << index << std::setw(10) << course->data.ID << std::setw(30) << course->data.name << std::setw(20) << course->data.dayOfWeek 
            << std::setw(15) << course->data.session << std::setw(20) << course->data.className << std::setw(20) << course->data.teacherName << "\n"; 
        std::cout << std::setfill('-') << std::setw(125) << "-" << std::setfill(' ') << std::endl;
        course = course->next;
        index++;
    }
}

void Semester::addCourse(Course course)
{
    Node<Course>* node = new Node<Course>(course);
    node->next = coursesList;
    coursesList = node;
}

bool Semester::deleteCourse(int index)
{
    if (!coursesList) return false;
    else if (index == 1)
    {
        Node<Course>* deleteNode = coursesList;
        coursesList = coursesList->next;
        delete deleteNode;
        return true;
    }
    Node<Course>* node = coursesList;
    for (int i = 1; i < index - 1; i++)
    {
        if (!node) return false;
        node = node->next;
    }
    
    Node<Course>* deleteNode = node->next;
    node->next = node->next->next;
    delete deleteNode;
}