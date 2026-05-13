#include <iostream>
#include <string>

using namespace std;

// Custom Node class representing an element in the queue
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

// Custom Queue Data Structure (Linked-List Based)
template <typename T>
class CustomQueue {
private:
    Node<T>* frontNode;
    Node<T>* rearNode;
    int count;

public:
    CustomQueue() {
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;
    }

    // Destructor to clean up memory
    ~CustomQueue() {
        while (!isEmpty()) {
            dequeue(false); // Call without printing to console during destruction
        }
    }

    // Adds an object to the end of the queue
    void enqueue(T item) {
        Node<T>* newNode = new Node<T>(item);

        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        count++;
        cout << "[System]: Command queued successfully -> " << item << "\n";
    }

    // Removes and returns the object at the front of the queue
    void dequeue(bool printLog = true) {
        if (isEmpty()) {
            if (printLog) cout << "[Warning]: Queue underflow. No commands to execute!\n";
            return;
        }

        Node<T>* temp = frontNode;
        T dequeuedData = temp->data;

        frontNode = frontNode->next;

        // If front becomes null, rear must also be null
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }

        delete temp;
        count--;

        if (printLog) {
            cout << "[System]: Command Executed -> " << dequeuedData << "\n";
        }
    }

    // Displays all pending elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "[Info]: No pending commands. Queue is empty.\n";
            return;
        }

        cout << "\n--- Pending Mission Commands (Front to Rear) ---\n";
        Node<T>* current = frontNode;
        int position = 1;
        while (current != nullptr) {
            cout << " " << position++ << ". " << current->data;
            if (current == frontNode) cout << " <- [NEXT TO EXECUTE]";
            cout << "\n";
            current = current->next;
        }
        cout << "------------------------------------------------\n";
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }
};

// Interactive Menu
int main() {
    CustomQueue<string> commandQueue;
    int choice;
    string command;

    do {
        cout << "\n=== Mission Command Execution Queue ===\n";
        cout << "1. Add Command to Queue (Enqueue)\n";
        cout << "2. Execute Next Command (Dequeue)\n";
        cout << "3. Display Pending Commands (List)\n";
        cout << "4. Exit System\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter mission command (e.g., 'Activate Sensors', 'Increase Altitude', 'RPC Handshake'): ";
            getline(cin, command);
            commandQueue.enqueue(command);
            break;
        case 2:
            commandQueue.dequeue();
            break;
        case 3:
            commandQueue.display();
            break;
        case 4:
            cout << "Shutting down execution system...\n";
            break;
        default:
            cout << "[Error]: Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}