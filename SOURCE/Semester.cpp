#include"Semester.h"
void Semester::viewCourses()
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
