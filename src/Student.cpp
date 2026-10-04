#include "../include/Student.h"

Student::Student(string id, string name, string course, int age) 
    : id(id), name(name), course(course), age(age), 
      sub1(0), sub2(0), sub3(0), totalMarks(0),
      presentDays(0), totalDays(0), attendancePercentage(0.0f) {}

string Student::getId() const { return id; }
string Student::getName() const { return name; }
string Student::getCourse() const { return course; }
int Student::getAge() const { return age; }

void Student::setMarks(float m1, float m2, float m3) {
    sub1 = m1;
    sub2 = m2;
    sub3 = m3;
    totalMarks = m1 + m2 + m3;
}

float Student::getSub1() const { return sub1; }
float Student::getSub2() const { return sub2; }
float Student::getSub3() const { return sub3; }
float Student::getTotalMarks() const { return totalMarks; }

string Student::getGrade() const {
    float avg = totalMarks / 3.0f;
    if (avg >= 90) return "A+";
    else if (avg >= 80) return "A";
    else if (avg >= 70) return "B+";
    else if (avg >= 60) return "B";
    else if (avg >= 50) return "C";
    else return "F";
}

void Student::setAttendance(int present, int total) {
    presentDays = present;
    totalDays = total;
    if (total > 0) {
        attendancePercentage = ((float)present / total) * 100.0f;
    } else {
        attendancePercentage = 0;
    }
}

int Student::getPresentDays() const { return presentDays; }
int Student::getTotalDays() const { return totalDays; }
float Student::getAttendancePercentage() const { return attendancePercentage; }

#include <iomanip>

void Student::display() const {
    cout << "+---------------------------------------------------------+\n"
         << "| " << left << setw(15) << "ID:" << setw(40) << id << "|\n"
         << "| " << left << setw(15) << "Name:" << setw(40) << name << "|\n"
         << "| " << left << setw(15) << "Course:" << setw(40) << course << "|\n"
         << "| " << left << setw(15) << "Age:" << setw(40) << age << "|\n"
         << "+---------------------------------------------------------+\n"
         << "| Marks        | Math: " << setw(5) << sub1 << "Phy: " << setw(5) << sub2 << "Chem: " << setw(5) << sub3 << "Total: " << setw(6) << totalMarks << "|\n"
         << "| Attendance   | Present: " << setw(5) << presentDays << "Total: " << setw(5) << totalDays << "Perc: " << setw(5) << attendancePercentage << "% |\n"
         << "+---------------------------------------------------------+\n";
}

void Student::displayTableRow() const {
    cout << "| " << left << setw(6) << id 
         << "| " << setw(15) << name 
         << "| " << setw(10) << course 
         << "| " << setw(5) << age 
         << "| " << setw(6) << totalMarks 
         << "| " << setw(12) << attendancePercentage << "|\n";
}
