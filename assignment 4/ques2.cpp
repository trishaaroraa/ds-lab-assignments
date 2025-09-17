#include <iostream>
using namespace std;
#define SIZE 5   

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    
    bool isEmpty() {
        return (front == -1);
    }

   
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full! Cannot enqueue.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        arr[rear] = value;
        cout << value << " enqueued successfully.\n";
    }

   
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty! Cannot dequeue.\n";
            return;
        }
        cout << arr[front] << " dequeued successfully.\n";
        if (front == rear) {
            front = rear = -1; 
        } else {
            front = (front + 1) % SIZE;
        }
    }

  
    void peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }


    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            cq.enqueue(value);
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.peek();
            break;
        case 4:
            cq.display();
            break;
        case 5:
            if (cq.isEmpty()) cout << "Queue is Empty.\n";
            else cout << "Queue is NOT Empty.\n";
            break;
        case 6:
            if (cq.isFull()) cout << "Queue is Full.\n";
            else cout << "Queue is NOT Full.\n";
            break;
        case 0:
            cout << "Exiting program\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
