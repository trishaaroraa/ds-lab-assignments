#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

vector<TreeNode*> buildTrees(int start, int end) {
    vector<TreeNode*> trees;

    if(start > end) {
        trees.push_back(NULL);
        return trees;
    }

    for(int i = start; i <= end; i++) {
        vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
        vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

        for(int j = 0; j < leftTrees.size(); j++) {
            for(int k = 0; k < rightTrees.size(); k++) {
                TreeNode* root = new TreeNode(i);
                root->left = leftTrees[j];
                root->right = rightTrees[k];
                trees.push_back(root);
            }
        }
    }
    return trees;
}

vector<TreeNode*> generateTrees(int n) {
    if(n == 0)
        return vector<TreeNode*>();
    return buildTrees(1, n);
}

void preorder(TreeNode* root) {
    if(root == NULL) {
        cout << "null ";
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n = 3;
    vector<TreeNode*> result = generateTrees(n);

    for(int i = 0; i < result.size(); i++) {
        preorder(result[i]);
        cout << endl;
    }

    return 0;
}
