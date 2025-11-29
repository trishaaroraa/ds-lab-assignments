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

Node* buildTree(int preorder[], int inorder[], int start, int end, int &preIndex) {
    if(start > end)
        return NULL;

    Node* root = new Node();
    root->data = preorder[preIndex++];
    root->left = NULL;
    root->right = NULL;

    if(start == end)
        return root;

    int pos = search(inorder, start, end, root->data);

    root->left = buildTree(preorder, inorder, start, pos - 1, preIndex);
    root->right = buildTree(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

void printInorder(Node* root) {
    if(root == NULL)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int n;
    cin >> n;

    int preorder[100], inorder[100];

    for(int i = 0; i < n; i++)
        cin >> preorder[i];

    for(int i = 0; i < n; i++)
        cin >> inorder[i];

    int preIndex = 0;
    Node* root = buildTree(preorder, inorder, 0, n - 1, preIndex);

    printInorder(root);

    return 0;
}
