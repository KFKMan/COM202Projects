#include <iostream>
#include <string>

using namespace std;

// Custom Node class representing an element in the stack
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

// Custom Stack Data Structure (Linked-List Based)
template <typename T>
class CustomStack {
private:
    Node<T>* topNode;
    int count;

public:
    CustomStack() {
        topNode = nullptr;
        count = 0;
    }

    // Destructor to free memory and prevent memory leaks
    ~CustomStack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Pushes an item onto the top of the stack
    void push(T item) {
        Node<T>* newNode = new Node<T>(item);
        newNode->next = topNode;
        topNode = newNode;
        count++;
        cout << "[System]: Successfully added to flight log -> " << item << "\n";
    }

    // Removes and returns the object at the top of the stack
    void pop() {
        if (isEmpty()) {
            cout << "[Warning]: Stack underflow. Flight log is empty!\n";
            return;
        }

        Node<T>* temp = topNode;
        T poppedData = temp->data;
        topNode = topNode->next;
        delete temp; // Free the allocated memory
        count--;

        cout << "[System]: Backtracked (Reverted) action -> " << poppedData << "\n";
    }

    // Displays all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "[Info]: No actions recorded yet. Stack is empty.\n";
            return;
        }

        cout << "\n--- Current Flight Log (Top to Bottom) ---\n";
        Node<T>* current = topNode;
        int index = count;
        while (current != nullptr) {
            cout << " " << index-- << ". " << current->data;
            if (current == topNode) cout << " <- [LATEST]";
            cout << "\n";
            current = current->next;
        }
        cout << "------------------------------------------\n";
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

// Interactive Menu
int main() {
    CustomStack<string> flightLog;
    int choice;
    string action;

    do {
        cout << "\n=== UAV Flight Path Backtracking System ===\n";
        cout << "1. Record Flight Action (Push)\n";
        cout << "2. Undo Last Action (Pop)\n";
        cout << "3. Display Flight Log (List)\n";
        cout << "4. Exit System\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(); // Clear the newline character

        switch (choice) {
        case 1:
            cout << "Enter flight action (e.g., 'Takeoff', 'Move Forward 10m', 'Turn Left'): ";
            getline(cin, action);
            flightLog.push(action);
            break;
        case 2:
            flightLog.pop();
            break;
        case 3:
            flightLog.display();
            break;
        case 4:
            cout << "Exiting system. Safe flights!\n";
            break;
        default:
            cout << "[Error]: Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}