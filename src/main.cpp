#include <iostream>
#include "../include/StudentManager.h"
#include "../include/ReportManager.h"

using namespace std;

void displayMenu() {
    cout << "\n====== Student Management System ======\n";
    cout << "1. Add Student\n";
    cout << "2. View Students\n";
    cout << "3. Search Student\n";
    cout << "4. Update Student\n";
    cout << "5. Delete Student\n";
    cout << "6. Enter Marks\n";
    cout << "7. Mark Attendance\n";
    cout << "8. Student Report\n";
    cout << "9. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    StudentManager manager;
    int choice;

    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.viewStudents(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.updateStudent(); break;
            case 5: manager.deleteStudent(); break;
            case 6: manager.enterMarks(); break;
            case 7: manager.markAttendance(); break;
            case 8: ReportManager::generateReport(manager.getStudents()); break;
            case 9: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 9);

    return 0;
}
