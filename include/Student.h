#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class Student {
private:
    string id;
    string name;
    string course;
    int age;
    
    // Marks
    float sub1, sub2, sub3, totalMarks;
    
    // Attendance
    int presentDays, totalDays;
    float attendancePercentage;

public:
    Student(string id, string name, string course, int age);
    
    // Getters
    string getId() const;
    string getName() const;
    string getCourse() const;
    int getAge() const;
    
    // Marks getters/setters
    void setMarks(float m1, float m2, float m3);
    float getSub1() const;
    float getSub2() const;
    float getSub3() const;
    float getTotalMarks() const;
    string getGrade() const;
    
    // Attendance getters/setters
    void setAttendance(int present, int total);
    int getPresentDays() const;
    int getTotalDays() const;
    float getAttendancePercentage() const;

    void display() const;
    void displayTableRow() const;
};

#endif
