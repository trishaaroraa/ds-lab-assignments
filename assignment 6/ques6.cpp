#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void splitList(Node* head, Node** head1, Node** head2) {
    Node *slow = head, *fast = head;
    if (head == NULL) return;
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    if (fast->next->next == head) fast = fast->next;
    *head1 = head;
    if (head->next != head) *head2 = slow->next;
    fast->next = slow->next;
    slow->next = head;
}

void printList(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = createNode(10);
    head->next = createNode(4);
    head->next->next = createNode(9);
    head->next->next->next = head;

    Node* head1 = NULL;
    Node* head2 = NULL;
    splitList(head, &head1, &head2);

    printList(head1);
    printList(head2);

    return 0;
}
