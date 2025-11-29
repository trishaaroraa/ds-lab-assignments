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

bool isCircular(Node* head) {
    if (!head) return true;
    Node* temp = head->next;
    while (temp && temp != head)
        temp = temp->next;
    return temp == head;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = head;

    if (isCircular(head))
        cout << "Circular Linked List";
    else
        cout << "Not Circular Linked List";

    return 0;
}
