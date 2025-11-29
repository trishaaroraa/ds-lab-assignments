#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = createNode('r');
    head->next = createNode('a');
    head->next->prev = head;
    head->next->next = createNode('d');
    head->next->next->prev = head->next;
    head->next->next->next = createNode('a');
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = createNode('r');
    head->next->next->next->next->prev = head->next->next->next;

    if (isPalindrome(head))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}
