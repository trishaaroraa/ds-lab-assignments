#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* n = new Node();
    n->data = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Node* insert(Node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void BSTtoDLL(Node* root, Node*& head, Node*& prev) {
    if(root == NULL)
        return;

    BSTtoDLL(root->left, head, prev);

    if(prev == NULL)
        head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    BSTtoDLL(root->right, head, prev);
}

Node* mergeDLL(Node* head1, Node* head2) {
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    Node* head = NULL;

    if(head1->data < head2->data) {
        head = head1;
        head->right = mergeDLL(head1->right, head2);
        if(head->right) head->right->left = head;
    } else {
        head = head2;
        head->right = mergeDLL(head1, head2->right);
        if(head->right) head->right->left = head;
    }
    head->left = NULL;
    return head;
}

void printDLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;

    root1 = insert(root1, 50);
    root1 = insert(root1, 30);
    root1 = insert(root1, 70);
    root1 = insert(root1, 20);
    root1 = insert(root1, 40);

    root2 = insert(root2, 60);
    root2 = insert(root2, 10);
    root2 = insert(root2, 90);
    root2 = insert(root2, 80);

    Node* head1 = NULL;
    Node* prev1 = NULL;
    BSTtoDLL(root1, head1, prev1);

    Node* head2 = NULL;
    Node* prev2 = NULL;
    BSTtoDLL(root2, head2, prev2);

    Node* mergedHead = mergeDLL(head1, head2);

    printDLL(mergedHead);

    return 0;
}
