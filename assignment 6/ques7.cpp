#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
};

struct CNode {
    int data;
    CNode* next;
};

int parity(int n) {
    int c = 0;
    while (n) {
        c += n & 1;
        n >>= 1;
    }
    return c;
}

DNode* createDNode(int data) {
    DNode* newNode = new DNode;
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

CNode* createCNode(int data) {
    CNode* newNode = new CNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void removeEvenParityDLL(DNode** head) {
    DNode* temp = *head;
    while (temp) {
        DNode* next = temp->next;
        if (parity(temp->data) % 2 == 0) {
            if (temp->prev) temp->prev->next = temp->next;
            else *head = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
        }
        temp = next;
    }
}

void removeEvenParityCLL(CNode** head) {
    if (*head == NULL) return;
    CNode *curr = *head, *prev = NULL;
    do {
        if (parity(curr->data) % 2 == 0) {
            if (curr == *head && curr->next == *head) {
                delete curr;
                *head = NULL;
                return;
            }
            if (curr == *head) {
                CNode* temp = *head;
                while (temp->next != *head) temp = temp->next;
                *head = (*head)->next;
                temp->next = *head;
                delete curr;
                curr = *head;
                continue;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
                continue;
            }
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
}

void printDLL(DNode* head) {
    DNode* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <=> ";
        temp = temp->next;
    }
    cout << endl;
}

void printCLL(CNode* head) {
    if (!head) return;
    CNode* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    DNode* d1 = createDNode(18);
    d1->next = createDNode(15);
    d1->next->prev = d1;
    d1->next->next = createDNode(8);
    d1->next->next->prev = d1->next;
    d1->next->next->next = createDNode(9);
    d1->next->next->next->prev = d1->next->next;
    d1->next->next->next->next = createDNode(14);
    d1->next->next->next->next->prev = d1->next->next->next;
    removeEvenParityDLL(&d1);
    printDLL(d1);

    CNode* c1 = createCNode(9);
    c1->next = createCNode(11);
    c1->next->next = createCNode(34);
    c1->next->next->next = createCNode(6);
    c1->next->next->next->next = createCNode(13);
    c1->next->next->next->next->next = createCNode(21);
    c1->next->next->next->next->next->next = c1;
    removeEvenParityCLL(&c1);
    printCLL(c1);

    return 0;
}
