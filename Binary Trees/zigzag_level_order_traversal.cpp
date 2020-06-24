#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data) {
        this->val = data;
        this->left = this->right = NULL;
    }
};

void printZigzagInOrder(TreeNode* root) {
    queue<TreeNode*> qu;
    TreeNode* curr = root;
    qu.push(curr);
    int count = 0;
    while(!qu.empty()) {
        cout << qu.front()->val << " ";
        curr = qu.back();
        qu.pop();
        if(count%2) {
            if(curr->left) 
            qu.push(curr->left);
            if(curr->right)
            qu.push(curr->right);
        } else {
            if(curr->right)
            qu.push(curr->right);
            if(curr->left)
            qu.push(curr->left);
        }
        count++;
    }
}

int main() {

    TreeNode* root = new TreeNode(1);
    TreeNode* l11 = new TreeNode(2);
    TreeNode* l12 = new TreeNode(3);
    TreeNode* l21 = new TreeNode(4);
    TreeNode* l22 = new TreeNode(5);
    TreeNode* l23 = new TreeNode(6);
    TreeNode* l24 = new TreeNode(7);
    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;
    printZigzagInOrder(root);
    return 0;
}