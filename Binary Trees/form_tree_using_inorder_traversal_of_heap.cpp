// https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) {
        this->val = x;
        this->left = this->right = NULL;
    }
};

void inOrderItrativeWithStack(TreeNode* root) {
    stack<TreeNode *> s; 
    TreeNode *curr = root; 
    cout<<endl<<endl;
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) { 
            s.push(curr); 
            curr = curr->left; 
        } 
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->val << " "; 
        curr = curr->right; 
    }
    cout<<endl<<endl; 
}

int maxIndex(vector<int> &A, int s, int e) {
    int index = -1;
    int maxV = INT_MIN;
    for(int i=s; i<=e; i++) {
        if(maxV < A[i]) {
            maxV = A[i];
            index = i;
        }
    }
    return index;
}

void build(vector<int> &A, TreeNode* node, int i, int s, int e) {
    if(s>e || i == -1)
    return;
    
    int l = maxIndex(A, s, i-1);
    int r = maxIndex(A, i+1, e);

    if(l >= 0) node->left = new TreeNode(A[l]);
    else node->left = NULL;

    if(r >= 0) node->right = new TreeNode(A[r]);
    else node->right = NULL;

    build(A, node->left, l, s, i-1);
    build(A, node->right, r, i+1, e);
}

TreeNode* buildTree(vector<int> &A) {
    int s = 0;
    int e = A.size() - 1;
    TreeNode* root = NULL;
    
    int i = maxIndex(A, s, e);
    TreeNode* curr = new TreeNode(A[i]);
    build(A, curr, i, s, e);
    
    return curr;
}

int main() {
    vector<int> v{2, 1, 3};
    TreeNode* node = buildTree(v);
    inOrderItrativeWithStack(node);
}
