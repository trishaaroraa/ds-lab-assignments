#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = NULL; }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, NULL};
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void findMiddle() {
        if (!head) {
            cout << "List is empty\n";
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }

    cout << "Linked List: ";
    list.display();

    list.findMiddle();

    return 0;
}
