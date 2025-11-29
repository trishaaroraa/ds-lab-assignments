#include <iostream>
using namespace std;

class DoublyList {
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(NULL), prev(NULL) {}
    };
    Node* head;
    Node* tail;

public:
    DoublyList() : head(NULL), tail(NULL) {}

    void display() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void insertFirst(int val) {
        Node* nn = new Node(val);
        if (!head) {
            head = tail = nn;
            return;
}
        nn->next = head;
        head->prev = nn;
        head = nn;
    }

    void insertLast(int val) {
        Node* nn = new Node(val);
        if (!head) {
            head = tail = nn;
            return;
        }
        tail->next = nn;
        nn->prev = tail;
        tail = nn;
    }

    void insertAfter(int key, int val) {
        Node* p = head;
        while (p && p->data != key)
         p = p->next;
        if (!p) {
            cout << "Key not found\n";
            return;
        }
        Node* nn = new Node(val);
        nn->next = p->next;
nn->prev = p;
        if (p->next) p->next->prev = nn;
        else tail = nn;
        p->next = nn;
    }

    void insertBefore(int key, int val) {
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (!p) {
            cout << "Key not found\n";
            return;
        }
        if (p == head) {
            insertFirst(val);
            return;
        }
        Node* nn = new Node(val);
        nn->next = p;
        nn->prev = p->prev;
        p->prev->next = nn;
        p->prev = nn;
    }

void deleteNode(int key) {
        Node* p = head;
        while (p && p->data != key) p = p->next;
        if (!p) {
            cout << "Key not found\n";
            return;
        }
        if (p == head && p == tail) head = tail = NULL;
        else if (p == head) {
            head = head->next;
            head->prev = NULL;
        } else if (p == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            p->prev->next = p->next;
            p->next->prev = p->prev;
        }
        delete p;
    }

    void searchNode(int key) {
        Node* p = head;
        int pos = 1;
        while (p) {
            if (p->data == key) {
                cout << "Found at position " << pos << endl;
                return;
}
            p = p->next;
            pos++;
        }
        cout << "Not found\n";
    }
};

int main() {
    DoublyList d;
    int ch, val, key;
    do {
        cout << "\n1.Insert First\n2.Insert Last\n3.Insert After\n4.Insert Before\n5.Delete\n6.Search\n7.Display\n0.Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
        case 1: cout << "Enter value: "; cin >> val; d.insertFirst(val); break;
        case 2: cout << "Enter value: "; cin >> val; d.insertLast(val); break;
        case 3: cout << "Enter key: "; cin >> key; cout << "Enter value: "; cin >> val; d.insertAfter(key, val); break;
        case 4: cout << "Enter key: "; cin >> key; cout << "Enter value: "; cin >> val; d.insertBefore(key, val); break;
        case 5: cout << "Enter value to delete: "; cin >> val; d.deleteNode(val); break;
        case 6: cout << "Enter value to search: "; cin >> val; d.searchNode(val); break;
        case 7: d.display(); break;
        }
    } while (ch != 0);
}
