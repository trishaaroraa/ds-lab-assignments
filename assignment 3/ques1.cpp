#include <iostream>
using namespace std;

int stack[100]; 
int top = -1;   

bool isEmpty() {
    return top == -1;
}

bool isFull() {
    return top == 99;
}

void push(int value) {
    if (isFull()) {
        cout << "Stack Overflow\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed onto stack.\n";
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
    } else {
        cout << "Popped element: " << stack[top] << "\n";
        top--;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Top element: " << stack[top] << "\n";
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << "\n";
    }
}

int main() {
    int choice, value;

    while (true) {
        cout << "\nStack Menu\n";
        cout << "1. Push\n2. Pop\n3. Check if Empty\n4. Check if Full\n5. Display Stack\n6. Peek\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push ";
                cin >> value;
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                if (isEmpty())
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not empty\n";
                break;
            case 4:
                if (isFull())
                    cout << "Stack is full\n";
                else
                    cout << "Stack is not full\n";
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting program\n";
                return 0;
            default:
                cout << "Invalid choice! Try again\n";
        }
    }

    return 0;
}
