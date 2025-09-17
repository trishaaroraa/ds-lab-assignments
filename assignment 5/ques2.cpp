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

    int countAndDeleteOccurrences(int key) {
        int count = 0;

        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count++;
        }

        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* delNode = curr->next;
                curr->next = curr->next->next;
                delete delNode;
                count++;
            } else {
                curr = curr->next;
            }
        }

        return count;
    }

    void display() {
        if (!head) {
            cout << "Empty List";
            return;
        }
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
    int arr[] = {1,2,1,2,1,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        list.insertAtEnd(arr[i]);
    }

    cout << "Original Linked List: ";
    list.display();

    int key = 1;
    int count = list.countAndDeleteOccurrences(key);

    cout << "Count: " << count << endl;
    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
