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

int sumOfLeftLeaves(Node* root, bool isLeft = false) {
    if(root == NULL)
        return 0;

    if(root->left == NULL && root->right == NULL && isLeft)
        return root->data;

    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    cout << sumOfLeftLeaves(root);

    return 0;
}
