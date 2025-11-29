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
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

Node* searchRecursive(Node* root, int key) {
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while(root != NULL) {
        if(root->data == key)
            return root;
        else if(key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL;
}

Node* findMin(Node* root) {
    if(root == NULL)
        return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* findMax(Node* root) {
    if(root == NULL)
        return NULL;
    while(root->right != NULL)
        root = root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* current) {
    if(current->right != NULL)
        return findMin(current->right);

    Node* successor = NULL;
    while(root != NULL) {
        if(current->data < root->data) {
            successor = root;
            root = root->left;
        } else if(current->data > root->data) {
            root = root->right;
        } else
            break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* current) {
    if(current->left != NULL)
        return findMax(current->left);

    Node* predecessor = NULL;
    while(root != NULL) {
        if(current->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if(current->data < root->data) {
            root = root->left;
        } else
            break;
    }
    return predecessor;
}

int main() {
    Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    Node* x = searchRecursive(root, 40);
    Node* y = searchNonRecursive(root, 70);

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);

    Node* succ = inorderSuccessor(root, x);
    Node* pred = inorderPredecessor(root, y);

    if(x) cout << "Found: " << x->data << endl;
    if(y) cout << "Found: " << y->data << endl;
    if(minNode) cout << "Min: " << minNode->data << endl;
    if(maxNode) cout << "Max: " << maxNode->data << endl;
    if(succ) cout << "Successor: " << succ->data << endl;
    if(pred) cout << "Predecessor: " << pred->data << endl;

    return 0;
}
