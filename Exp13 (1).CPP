#include <iostream>
using namespace std;

class Pizza {
    int front, rear, q[5]; // Array for storing orders

public:
    Pizza() {
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    int isFull() {
        return (front == 0 && rear == 4) || (front == rear + 1);
    }

    // Check if the queue is empty
    int isEmpty() {
        return front == -1 && rear == -1;
    }

    // Add a pizza order
    void add() {
        if (!isFull()) {
            cout << "\nEnter the Pizza ID: ";
            if (front == -1 && rear == -1) { // First order
                front = 0;
                rear = 0;
            } else {
                rear = (rear + 1) % 5; // Circular increment
            }
            cin >> q[rear];

            char c;
            cout << "Do you want to add another order? (y/n): ";
            cin >> c;
            if (c == 'y' || c == 'Y') {
                add(); // Recursive addition
            }
        } else {
            cout << "\nOrders are full.";
        }
    }

    // Serve a pizza order
    void serve() {
        if (!isEmpty()) {
            cout << "\nOrder served is: " << q[front];
            if (front == rear) { // Only one order left
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % 5; // Circular increment
            }
        } else {
            cout << "\nOrders are empty.";
        }
    }

    // Display all orders
    void display() {
        if (!isEmpty()) {
            cout << "\nCurrent orders: ";
            for (int i = front; i != rear; i = (i + 1) % 5) {
                cout << q[i] << " <- ";
            }
            cout << q[rear]; // Display the last order
        } else {
            cout << "\nOrders are empty.";
        }
    }

    // Main menu for user interaction
    void check() {
        int choice;
        do {
            cout << "\n\n*** PIZZA PARLOUR ***\n";
            cout << "1. Add a Pizza\n";
            cout << "2. Display the Orders\n";
            cout << "3. Serve a Pizza\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    add();
                    break;
                case 2:
                    display();
                    break;
                case 3:
                    serve();
                    break;
                case 4:
                    cout << "Exiting program. Goodbye!\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.";
            }
        } while (true);
    }
};

int main() {
    Pizza p1;
    p1.check(); // Start the program
    return 0;
}
