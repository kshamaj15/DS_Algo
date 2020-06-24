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

int hasPathSum(TreeNode* A, int B) {
    stack<int> sum;
    int currSum = 0;
    stack<TreeNode*> node;
    TreeNode* curr = A;
    node.push(curr);
    sum.push(curr->val);
    while(!node.empty()) {
        if(curr != NULL) {
            curr = curr->left;
            node.push(curr);
            if(curr != NULL) {
                currSum += curr->val;
                sum.push(currSum);
            }
        }
        if(currSum == B) {
            return 1;
            break;
        } else {
            node.pop();
            if(!node.empty()) {
                curr = node.top();
            curr = curr->right;
            node.push(curr);
            if(curr != NULL) {
                currSum += curr->val;
                sum.push(currSum);
            } 
            if(currSum == B) {
                return 1;
                break;
            } else {
                node.pop();
            }
            }
        }
    }
    return 0;
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
    // root->right = l12;
    // l11->left = l21;
    // l11->right = l22;
    // l12->left = l23;
    // l12->right = l24;
    cout<<hasPathSum(root, 5);
    return 0;
}