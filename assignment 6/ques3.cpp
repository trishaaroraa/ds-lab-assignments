#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int sizeOfDoubly(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sizeOfCircular(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    Node* headD = createNode(10);
    headD->next = createNode(20);
    headD->next->prev = headD;
    headD->next->next = createNode(30);
    headD->next->next->prev = headD->next;
    cout << "Size of Doubly Linked List: " << sizeOfDoubly(headD) << endl;

    Node* headC = createNode(10);
    Node* n2 = createNode(20);
    Node* n3 = createNode(30);
    headC->next = n2;
    n2->next = n3;
    n3->next = headC;
    cout << "Size of Circular Linked List: " << sizeOfCircular(headC) << endl;

    return 0;
}
