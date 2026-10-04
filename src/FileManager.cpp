#include "../include/FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>

void FileManager::saveAll(const std::vector<Student>& students) {
    // Save students.txt
    std::ofstream fStudents("data/students.txt");
    std::ofstream fMarks("data/marks.txt");
    std::ofstream fAttendance("data/attendance.txt");

    if (!fStudents || !fMarks || !fAttendance) {
        std::cerr << "Error opening data files for writing.\n";
        return;
    }

    // Write headers
    fStudents << "ID,Name,Course,Age\n";
    fMarks << "ID,Sub1,Sub2,Sub3,Total\n";
    fAttendance << "ID,Present,Total,%\n";

    for (const auto& s : students) {
        fStudents << s.getId() << "," << s.getName() << "," << s.getCourse() << "," << s.getAge() << "\n";
        fMarks << s.getId() << "," << s.getSub1() << "," << s.getSub2() << "," << s.getSub3() << "," << s.getTotalMarks() << "\n";
        fAttendance << s.getId() << "," << s.getPresentDays() << "," << s.getTotalDays() << "," << s.getAttendancePercentage() << "\n";
    }
}

std::vector<Student> FileManager::loadAll() {
    std::vector<Student> students;
    std::map<std::string, Student> studentMap;

    // Load students.txt
    std::ifstream fStudents("data/students.txt");
    std::string line;
    if (fStudents.is_open()) {
        std::getline(fStudents, line); // Skip header
        while (std::getline(fStudents, line)) {
            std::stringstream ss(line);
            std::string id, name, course, ageStr;
            if (std::getline(ss, id, ',') && std::getline(ss, name, ',') && std::getline(ss, course, ',') && std::getline(ss, ageStr, ',')) {
                try {
                    studentMap.emplace(id, Student(id, name, course, std::stoi(ageStr)));
                } catch (...) {}
            }
        }
    }

    // Load marks.txt
    std::ifstream fMarks("data/marks.txt");
    if (fMarks.is_open()) {
        std::getline(fMarks, line); // Skip header
        while (std::getline(fMarks, line)) {
            std::stringstream ss(line);
            std::string id, s1, s2, s3, tot;
            if (std::getline(ss, id, ',') && std::getline(ss, s1, ',') && std::getline(ss, s2, ',') && std::getline(ss, s3, ',') && std::getline(ss, tot, ',')) {
                if (studentMap.count(id)) {
                    try {
                        studentMap.at(id).setMarks(std::stof(s1), std::stof(s2), std::stof(s3));
                    } catch (...) {}
                }
            }
        }
    }

    // Load attendance.txt
    std::ifstream fAttendance("data/attendance.txt");
    if (fAttendance.is_open()) {
        std::getline(fAttendance, line); // Skip header
        while (std::getline(fAttendance, line)) {
            std::stringstream ss(line);
            std::string id, p, t, perc;
            if (std::getline(ss, id, ',') && std::getline(ss, p, ',') && std::getline(ss, t, ',') && std::getline(ss, perc, ',')) {
                if (studentMap.count(id)) {
                    try {
                        studentMap.at(id).setAttendance(std::stoi(p), std::stoi(t));
                    } catch (...) {}
                }
            }
        }
    }

    for (const auto& pair : studentMap) {
        students.push_back(pair.second);
    }
    return students;
}
