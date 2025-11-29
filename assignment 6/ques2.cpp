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

void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl; // repeat head node value at the end
}

int main() {
    Node* head = createNode(20);
    Node* second = createNode(100);
    Node* third = createNode(40);
    Node* fourth = createNode(80);
    Node* fifth = createNode(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = head; 

    display(head);
    return 0;
}
