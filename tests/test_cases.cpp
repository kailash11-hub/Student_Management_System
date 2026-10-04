#include <iostream>
#include <cassert>
#include "../include/Student.h"

using namespace std;

void testStudentCreation() {
    Student s("101", "Test Student", "CS", 20, 85.5);
    assert(s.getId() == "101");
    assert(s.getName() == "Test Student");
    assert(s.getCourse() == "CS");
    assert(s.getAge() == 20);
    assert(s.getMarks() == 85.5f);
    cout << "testStudentCreation passed!\n";
}

void testGradeCalculation() {
    Student s1("1", "A", "CS", 20, 95);
    assert(s1.getGrade() == "A+");

    Student s2("2", "B", "CS", 20, 85);
    assert(s2.getGrade() == "A");

    Student s3("3", "C", "CS", 20, 45);
    assert(s3.getGrade() == "F");
    
    cout << "testGradeCalculation passed!\n";
}

int main() {
    cout << "Running Tests...\n";
    testStudentCreation();
    testGradeCalculation();
    cout << "All tests passed successfully!\n";
    return 0;
}
