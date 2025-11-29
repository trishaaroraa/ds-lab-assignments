#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* down;
    Node* left;
    Node* up;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->right = newNode->down = newNode->left = newNode->up = NULL;
    return newNode;
}

Node* constructDLL(vector<vector<int> >& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<Node*> > nodes(n, vector<Node*>(m, NULL));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nodes[i][j] = createNode(mat[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j > 0) nodes[i][j]->left = nodes[i][j - 1];
            if (j < m - 1) nodes[i][j]->right = nodes[i][j + 1];
            if (i > 0) nodes[i][j]->up = nodes[i - 1][j];
            if (i < n - 1) nodes[i][j]->down = nodes[i + 1][j];
        }

    return nodes[0][0];
}

void printList(Node* head, int n, int m) {
    Node* row = head;
    for (int i = 0; i < n; i++) {
        Node* col = row;
        for (int j = 0; j < m; j++) {
            cout << col->data << " ";
            col = col->right;
        }
        cout << endl;
        row = row->down;
    }
}

int main() {
    vector<vector<int> > mat;
    vector<int> row1, row2, row3;

    row1.push_back(1);
    row1.push_back(2);
    row1.push_back(3);

    row2.push_back(4);
    row2.push_back(5);
    row2.push_back(6);

    row3.push_back(7);
    row3.push_back(8);
    row3.push_back(9);

    mat.push_back(row1);
    mat.push_back(row2);
    mat.push_back(row3);

    Node* head = constructDLL(mat);
    printList(head, 3, 3);

    return 0;
}
