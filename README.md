# Student Management System

A complete capstone project demonstrating a C++ console-based Student Management System using STL, file handling, and best practices.

## Features
- Add, View, Search, Update, Delete students
- Marks & Grade management
- File persistence (`students.txt`)
- Generate Reports

## How to build & run
1. Open your terminal in the project root folder.
2. Compile the project using `g++`:
   ```bash
   g++ -std=c++17 src/*.cpp -Iinclude -o app.exe
   ```
3. Run the executable:
   ```bash
   .\app.exe
   ```

## Architecture
- `Student`: Represents a single student.
- `StudentManager`: Manages a collection of students (uses `std::vector`) and orchestrates CRUD operations.
- `FileManager`: Handles reading from and writing to files.
- `ReportManager`: Generates reports for students.
