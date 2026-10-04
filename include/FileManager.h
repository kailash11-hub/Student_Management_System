#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Student.h"
#include <vector>
#include <string>

class FileManager {
public:
    static void saveAll(const std::vector<Student>& students);
    static std::vector<Student> loadAll();
};

#endif
