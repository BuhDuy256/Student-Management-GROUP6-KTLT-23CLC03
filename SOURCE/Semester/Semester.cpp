#include "Semester.h"

void Semester::viewCoursesList()
{
     std::cout << std::setw(10) << "ID" << std::setw(30) << "Name" << std::setw(20) << "Day" << std::setw(15) 
        << "Session" << std::setw(20) << "Class Name" << std::setw(20) << "Teacher Name" << std::endl;
    std::cout << std::setfill('-') << std::setw(115) << "-" << std::setfill(' ') << std::endl;

    Node<Course>* course = coursesList;
    while (course != nullptr) {
        std::cout << std::setw(10) << course->data.ID << std::setw(30) << course->data.name << std::setw(20) << course->data.dayOfWeek 
            << std::setw(15) << course->data.session << std::setw(20) << course->data.className << std::setw(20) << course->data.teacherName << "\n"; 
        course = course->next;
    }
}

void Semester::addCourse(Course course)
{
    Node<Course>* node = new Node<Course>(course);
    node->next = coursesList;
    coursesList = node;
}

bool Semester::deleteCourse(std::string ID)
{
    if (!coursesList) return false;
    else if (coursesList->data.ID == ID)
    {
        Node<Course>* deleteNode = coursesList;
        coursesList = coursesList->next;
        delete deleteNode;
        return true;
    }
    Node<Course>* node = coursesList;
    while (node->next && node->next->data.ID != ID)
        node = node->next;
    if (!node) return false;
    Node<Course>* deleteNode = node->next;
    node->next = node->next->next;
    delete deleteNode;
}