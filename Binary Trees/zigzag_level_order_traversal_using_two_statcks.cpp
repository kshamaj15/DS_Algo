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
    TreeNode* curr = root;
    // declare two stacks 
    stack<TreeNode*> currentlevel; 
    stack<TreeNode*> nextlevel; 
    bool ltr = true;
    currentlevel.push(curr);
    while(!currentlevel.empty() || !nextlevel.empty()) {
        curr = currentlevel.top();
        cout<< curr->val<< " ";
        currentlevel.pop();
        if(ltr) {
            if(curr->left)
            nextlevel.push(curr->left);
            if(curr->right)
            nextlevel.push(curr->right);
        } else {
            if(curr->right)
            nextlevel.push(curr->right);
            if(curr->left)
            nextlevel.push(curr->left);
        }
        if(currentlevel.empty()) {
            ltr = !ltr;
            currentlevel.swap(nextlevel);
        }
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