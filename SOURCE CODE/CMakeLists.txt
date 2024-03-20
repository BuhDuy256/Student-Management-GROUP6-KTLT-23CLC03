cmake_minimum_required(VERSION 3.0)
project(StudentManagement)

add_executable(MyExecutable SYSTEM/main.cpp)

target_include_directories(MyExecutable PRIVATE STUDENT)
# target_include_directories(MyExecutable PRIVATE STAFF)
target_sources(MyExecutable PRIVATE STUDENT/student.cpp)
# target_sources(MyExecutable PRIVATE STAFF/staff.cpp)