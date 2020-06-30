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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int getMaxHeight(TreeNode* root){
    if(root == NULL) {
        return 0;
    } else {
        int leftHeight = getMaxHeight(root->left);
        int rightHeight = getMaxHeight(root->right);
        int maxHeight = leftHeight > rightHeight ? leftHeight : rightHeight;
        return maxHeight+1;
    }
}
 
 
int isBalanced(TreeNode* A) {
    if((A->left == NULL && A->right == NULL) || (A == NULL && A->right == NULL) || (A == NULL && A->left == NULL)) {
        return 1;
    } else {
        int left = 0, right = 0, heightDiff = 2; 
        if(A->left != NULL)
        int left = isBalanced(A->left);
        if(A->right != NULL)
        right = isBalanced(A->right);
        if(A->left != NULL && A->right != NULL)
        heightDiff = abs(getMaxHeight(A->left) - getMaxHeight(A->left));
        if(left == 0 || right == 0 || heightDiff > 1)
        return 0;
        else
        return 1;
    }
}


int main() {

    TreeNode* root = new TreeNode(135);
    TreeNode* l11 = new TreeNode(2);
    TreeNode* l12 = new TreeNode(3);
    TreeNode* l21 = new TreeNode(4);
    TreeNode* l22 = new TreeNode(5);
    TreeNode* l23 = new TreeNode(6);
    TreeNode* l24 = new TreeNode(7);
    // root->left = l11;
    // root->right = l12;
    // l11->left = l21;
    // l11->right = l22;
    // l12->left = l23;
    // l12->right = l24;

    root->left = l11;
    root->right = l12;
    // l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;
    l24->left = l21;
    

    cout << isBalanced(root);
    return 0;
}
