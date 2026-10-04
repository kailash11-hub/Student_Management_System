#include "../include/ReportManager.h"
#include <iostream>
#include <iomanip>

void ReportManager::generateReport(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No data to generate report.\n";
        return;
    }

    std::cout << "\n+------------+----------------------+------------+------------+-------+-----------------+\n";
    std::cout << "| " << std::left << std::setw(11) << "ID" 
              << "| " << std::setw(21) << "Name" 
              << "| " << std::setw(11) << "Course" 
              << "| " << std::setw(11) << "Total Marks" 
              << "| " << std::setw(6) << "Grade" 
              << "| " << std::setw(16) << "Attendance %" << "|\n";
    std::cout << "+------------+----------------------+------------+------------+-------+-----------------+\n";

    for (const auto& student : students) {
        std::cout << "| " << std::left << std::setw(11) << student.getId() 
                  << "| " << std::setw(21) << student.getName() 
                  << "| " << std::setw(11) << student.getCourse() 
                  << "| " << std::setw(11) << student.getTotalMarks() 
                  << "| " << std::setw(6) << student.getGrade() 
                  << "| " << std::setw(16) << student.getAttendancePercentage() << "|\n";
    }
    std::cout << "+------------+----------------------+------------+------------+-------+-----------------+\n";
}
