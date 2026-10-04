#include "../include/StudentManager.h"
#include "../include/FileManager.h"
#include <iostream>
#include <algorithm>
#include <cctype>

// Helper for ID validation
bool isValidID(const std::string& id) {
    if (id.empty()) return false;
    for (char c : id) {
        if (!std::isdigit(c)) return false;
    }
    return true;
}

// Helper for Course validation
bool isAlphaOnly(const std::string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!std::isalpha(c) && c != ' ') return false;
    }
    return true;
}

StudentManager::StudentManager() {
    students = FileManager::loadAll();
}

void StudentManager::addStudent() {
    std::string id, name, course;
    int age;

    while (true) {
        std::cout << "Enter ID (numbers only): ";
        std::cin >> id;
        if (isValidID(id)) break;
        std::cout << "Invalid ID! Must contain only numbers.\n";
    }
    
    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getId() == id;
    });
    if (it != students.end()) {
        std::cout << "Student with ID " << id << " already exists!\n";
        return;
    }

    std::cin.ignore();
    
    while (true) {
        std::cout << "Enter Name (min 5 characters): ";
        std::getline(std::cin, name);
        if (name.length() >= 5) break;
        std::cout << "Invalid Name! Must be at least 5 characters long.\n";
    }

    while (true) {
        std::cout << "Enter Course (letters only): ";
        std::getline(std::cin, course);
        if (isAlphaOnly(course)) break;
        std::cout << "Invalid Course! Must contain only letters and spaces.\n";
    }
    
    while (true) {
        std::cout << "Enter Age (16 or above): ";
        if (std::cin >> age && age >= 16) {
            break;
        }
        std::cout << "Invalid age! Must be a number 16 or older.\n";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    students.emplace_back(id, name, course, age);
    FileManager::saveAll(students);
    std::cout << "Student added successfully!\n";
}

void StudentManager::viewStudents() const {
    if (students.empty()) {
        std::cout << "No students found.\n";
        return;
    }
    
    std::cout << "\n+-------+----------------+-----------+------+-------+-------------+\n";
    std::cout << "| ID    | Name           | Course    | Age  | Marks | Attendance% |\n";
    std::cout << "+-------+----------------+-----------+------+-------+-------------+\n";
    for (const auto& student : students) {
        student.displayTableRow();
    }
    std::cout << "+-------+----------------+-----------+------+-------+-------------+\n";
}

void StudentManager::searchStudent() const {
    std::string id;
    std::cout << "Enter ID to search: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getId() == id;
    });

    if (it != students.end()) {
        it->display();
    } else {
        std::cout << "Student not found.\n";
    }
}

void StudentManager::updateStudent() {
    std::string id;
    std::cout << "Enter ID to update: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getId() == id;
    });

    if (it != students.end()) {
        std::string name, course;
        int age;

        std::cin.ignore();
        
        while (true) {
            std::cout << "Enter new Name (min 5 characters): ";
            std::getline(std::cin, name);
            if (name.length() >= 5) break;
            std::cout << "Invalid Name! Must be at least 5 characters long.\n";
        }

        while (true) {
            std::cout << "Enter new Course (letters only): ";
            std::getline(std::cin, course);
            if (isAlphaOnly(course)) break;
            std::cout << "Invalid Course! Must contain only letters and spaces.\n";
        }
        
        while (true) {
            std::cout << "Enter new Age (16 or above): ";
            if (std::cin >> age && age >= 16) {
                break;
            }
            std::cout << "Invalid age! Must be a number 16 or older.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        // Keep marks and attendance from old record
        float m1 = it->getSub1();
        float m2 = it->getSub2();
        float m3 = it->getSub3();
        int p = it->getPresentDays();
        int t = it->getTotalDays();

        *it = Student(id, name, course, age);
        it->setMarks(m1, m2, m3);
        it->setAttendance(p, t);
        
        FileManager::saveAll(students);
        std::cout << "Student updated successfully!\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

void StudentManager::deleteStudent() {
    std::string id;
    std::cout << "Enter ID to delete: ";
    std::cin >> id;

    auto it = std::remove_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getId() == id;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        FileManager::saveAll(students);
        std::cout << "Student deleted successfully!\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

void StudentManager::enterMarks() {
    std::string id;
    std::cout << "Enter ID: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getId() == id;
    });

    if (it != students.end()) {
        float m1, m2, m3;
        while (true) {
            std::cout << "Enter Marks for Mathematics (0-100): ";
            if (std::cin >> m1 && m1 >= 0 && m1 <= 100) break;
            std::cout << "Invalid input! Marks must be between 0 and 100.\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        while (true) {
            std::cout << "Enter Marks for Physics (0-100): ";
            if (std::cin >> m2 && m2 >= 0 && m2 <= 100) break;
            std::cout << "Invalid input! Marks must be between 0 and 100.\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        while (true) {
            std::cout << "Enter Marks for Chemistry (0-100): ";
            if (std::cin >> m3 && m3 >= 0 && m3 <= 100) break;
            std::cout << "Invalid input! Marks must be between 0 and 100.\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        
        it->setMarks(m1, m2, m3);
        FileManager::saveAll(students);
        std::cout << "Marks updated successfully!\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

void StudentManager::markAttendance() {
    std::string id;
    std::cout << "Enter ID: ";
    std::cin >> id;

    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getId() == id;
    });

    if (it != students.end()) {
        int present, total;
        while (true) {
            std::cout << "Enter Total Classes: ";
            if (std::cin >> total && total > 0) break;
            std::cout << "Invalid input! Please enter a valid positive number.\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        while (true) {
            std::cout << "Enter Present Classes: ";
            if (std::cin >> present && present >= 0 && present <= total) break;
            std::cout << "Invalid input! Must be >= 0 and <= Total Classes.\n";
            std::cin.clear(); std::cin.ignore(10000, '\n');
        }
        
        it->setAttendance(present, total);
        FileManager::saveAll(students);
        std::cout << "Attendance updated successfully!\n";
    } else {
        std::cout << "Student not found.\n";
    }
}

const std::vector<Student>& StudentManager::getStudents() const {
    return students;
}
