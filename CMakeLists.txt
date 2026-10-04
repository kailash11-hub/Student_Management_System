cmake_minimum_required(VERSION 3.10)
project(StudentManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(app 
    src/main.cpp 
    src/Student.cpp 
    src/StudentManager.cpp 
    src/FileManager.cpp 
    src/ReportManager.cpp
)
