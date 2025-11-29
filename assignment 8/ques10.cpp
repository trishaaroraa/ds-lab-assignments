#include <iostream>
#include <queue>
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

Node* buildTree(int arr[], int n) {
    if(n == 0 || arr[0] == -1)
        return NULL;

    Node* root = createNode(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < n) {
        Node* current = q.front();
        q.pop();

        if(i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            q.push(current->left);
        }
        i++;

        if(i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

void rightView(Node* root) {
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int levelSize = q.size();

        for(int i = 1; i <= levelSize; i++) {
            Node* current = q.front();
            q.pop();

            if(i == levelSize)
                cout << current->data << " ";

            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        int arr[1000];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        Node* root = buildTree(arr, n);
        rightView(root);
        cout << endl;
    }

    return 0;
}
