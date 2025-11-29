#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node* random;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->random = NULL;
    return newNode;
}

void correctRandomPointer(Node* head) {
    if (!head) return;
    Node* temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    temp = head;
    Node* randNode = NULL;
    while (temp) {
        if (temp->random) {
            randNode = temp->random;
            break;
        }
        temp = temp->next;
    }
    if (!randNode) return;
    Node* start = head;
    while (randNode->prev) randNode = randNode->prev;
    Node* end = randNode;
    while (end->next) end = end->next;
    if (randNode->data == start->data)
        start->random = end;
    else if (randNode->data == end->data)
        start->random = randNode;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    head->random = head->next->next->next;

    correctRandomPointer(head);
    printList(head);

    if (head->random)
        cout << "Random Pointer corrected to node: " << head->random->data;
    else
        cout << "No correction needed";

    return 0;
}
