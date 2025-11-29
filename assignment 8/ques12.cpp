#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int inorder[], int postorder[], int start, int end, int &postIndex) {
    if(start > end)
        return NULL;

    Node* root = new Node();
    root->data = postorder[postIndex--];
    root->left = NULL;
    root->right = NULL;

    if(start == end)
        return root;

    int pos = search(inorder, start, end, root->data);

    root->right = buildTree(inorder, postorder, pos + 1, end, postIndex);
    root->left = buildTree(inorder, postorder, start, pos - 1, postIndex);

    return root;
}

void printPreorder(Node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main() {
    int n;
    cin >> n;

    int inorder[100], postorder[100];

    for(int i = 0; i < n; i++)
        cin >> inorder[i];

    for(int i = 0; i < n; i++)
        cin >> postorder[i];

    int postIndex = n - 1;
    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);

    printPreorder(root);

    return 0;
}
