#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H

#include "Student.h"
#include <vector>
#include <string>

class StudentManager {
private:
    std::vector<Student> students;

public:
    StudentManager();
    
    void addStudent();
    void viewStudents() const;
    void searchStudent() const;
    void updateStudent();
    void deleteStudent();
    
    void enterMarks();
    void markAttendance();
    
    const std::vector<Student>& getStudents() const;
};

#endif
