#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include "Student.h"
#include <vector>

class ReportManager {
public:
    static void generateReport(const std::vector<Student>& students);
};

#endif
