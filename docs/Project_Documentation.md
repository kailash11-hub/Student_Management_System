# Advanced Student Management System
## Linux System Programming & Device Drivers Project

### Stage 1 – Project Introduction

**Project Idea and Objective**
The objective of this project is to develop an Advanced Student Management System that goes beyond a standard C++ console application by integrating core Linux System Programming concepts and a custom Linux Device Driver. The project will manage student records while demonstrating system-level resource management, concurrency, and hardware-software interaction.

**Problem to be Solved**
Standard file-based management systems suffer from concurrency issues (multiple instances overwriting data) and lack of security. This project solves this by introducing process synchronization via Inter-Process Communication (IPC), graceful shutdown handling via Linux Signals, and a custom character device driver to handle secure/synchronized data access or locking.

**Project Scope**
- **C++ Application**: A robust console interface using STL for managing student records (CRUD operations, reporting).
- **System Programming (Linux)**: 
  - Implementation of POSIX threads (pthreads) to handle long-running tasks (like report generation) asynchronously without freezing the UI.
  - Linux Signal handling (e.g., catching `SIGINT` / `Ctrl+C`) to ensure safe data flushing before exit.
  - IPC (Inter-Process Communication) using Shared Memory or Pipes to separate the front-end CLI from a back-end data worker.
- **Linux Device Driver**: A custom loadable kernel module (LKM) character device (e.g., `/dev/student_db_lock`) that the C++ application interacts with to enforce system-wide mutual exclusion (mutex), ensuring that only one instance of the app can write to the database file at any given time.

**Expected Outcome and Application**
The outcome will be a highly robust, production-like management system. It will demonstrate a full-stack understanding of C++ application development, Linux OS-level API utilization, and Kernel-level module programming.

---

### Stage 2 – Project Requirements & Development Plan

**Functional Requirements**
1. The system must allow users to Add, View, Search, Update, and Delete student records.
2. The system must persist data to a file (`students.txt`).
3. The system must allow asynchronous generation of performance reports.
4. The system must safely catch termination signals to save data before exiting.
5. The system must request a lock from a custom Linux Device Driver before modifying the database.

**Non-Functional Requirements**
1. **Concurrency**: The UI must remain responsive during file I/O operations.
2. **Reliability**: Data corruption must be prevented when multiple users attempt to open the system.
3. **Platform**: Must run on a Linux environment (Ubuntu/Debian) to utilize POSIX APIs and Kernel Modules.

**Project Modules & Features**
1. **Core C++ Module**: `Student`, `StudentManager`, `FileManager`, `ReportManager`.
2. **System Module**: `SignalHandler`, `ThreadManager`.
3. **Kernel Module**: `student_lock_drv.c` (Loadable Kernel Module).

**Development Plan and Timeline (6 Stages)**
- **Stage 1**: Define scope, objectives, and architecture (Completed).
- **Stage 2**: Finalize requirements, document PRD, and set up Git repository (Current).
- **Stage 3**: Create UML diagrams (Class, Sequence, State Machine), set up Linux VM environment.
- **Stage 4**: Develop the C++ core and integrate POSIX threads/signals.
- **Stage 5**: Develop the custom Linux Character Device Driver and integrate it with the C++ app. Perform unit/system testing.
- **Stage 6**: Final debugging, complete documentation, and prepare presentation.
