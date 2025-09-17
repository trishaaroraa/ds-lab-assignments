#include <iostream>
#include <queue>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q1.pop();
    }
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool empty() {
        return q1.empty();
    }
};

class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool empty() {
        return q.empty();
    }
};

int main() {
    int method;
    cout << "Choose implementation:\n";
    cout << "1. Stack using Two Queues\n";
    cout << "2. Stack using One Queue\n";
    cin >> method;

    StackTwoQueues s2;
    StackOneQueue s1;

    int choice, val;
    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Check Empty\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (method == 1) {
            if (choice == 1) { cout << "Enter value: "; cin >> val; s2.push(val); }
            else if (choice == 2) s2.pop();
            else if (choice == 3) cout << "Top: " << s2.top() << endl;
            else if (choice == 4) cout << (s2.empty() ? "Empty\n" : "Not Empty\n");
        } else {
            if (choice == 1) { cout << "Enter value: "; cin >> val; s1.push(val); }
            else if (choice == 2) s1.pop();
            else if (choice == 3) cout << "Top: " << s1.top() << endl;
            else if (choice == 4) cout << (s1.empty() ? "Empty\n" : "Not Empty\n");
        }
    } while (choice != 0);

    return 0;
}
