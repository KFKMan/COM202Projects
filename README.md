# Data Structures: Custom Stack and Queue Implementations in C++

This repository contains two C++ console applications developed for the Data Structures course (Midterm and Final projects). Both projects are built entirely from scratch without using any standard C++ collection libraries (like `<stack>`, `<queue>`, or `<vector>`). They demonstrate a deep understanding of pointer manipulation, dynamic memory allocation, and object-oriented programming.

## 🚀 Projects Overview

### 1. Midterm Project: UAV Flight Path Backtracking (Stack)
A simulation of a drone's flight logging system utilizing a **Custom Stack (LIFO - Last-In-First-Out)**. 
- **Scenario:** As a drone flies, it logs its actions (e.g., "Takeoff", "Move North 10m"). In an emergency, it must reverse these actions to return to home safely.
- **Key Features:** - `push()`: Records a new flight action.
  - `pop()`: Reverts the latest action and frees memory.
  - `display()`: Iterates through pointers to show the current flight log.

### 2. Final Project: Mission Command Execution Queue (Queue)
A simulation of a ground control station dispatching tasks utilizing a **Custom Queue (FIFO - First-In-First-Out)**.
- **Scenario:** Mission commands are sent to an autonomous system. They must be executed strictly in the order they were received to prevent system failure.
- **Key Features:**
  - `enqueue()`: Adds a new command to the rear of the pending list.
  - `dequeue()`: Executes the command at the front and frees memory.
  - `display()`: Shows all pending commands in execution order.

## 🛠️ Technical Details
- **Language:** C++
- **Architecture:** Generic template classes (`template <typename T>`) based on Linked-List principles.
- **Memory Management:** Custom destructors (`~CustomStack` and `~CustomQueue`) are strictly implemented to prevent memory leaks by traversing and deleting all remaining `Node` pointers upon program termination.

## 💻 How to Compile and Run
Just open the project in Visual Studio and click to run button.
Anyway you can just copy cpp files to your other IDEs, or you can directly compile them. 
