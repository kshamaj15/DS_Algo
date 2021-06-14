// DFS
// easy

#include<bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

map<TreeNode*, int> getSssp(TreeNode* node) {
    map<TreeNode*, int> ans;
    ans[node] = 0;
    queue<TreeNode*> q;
    q.push(node);
    do {
        TreeNode* node = q.front();
        q.pop();
        if(node->left) {
            ans[node->left] = 1 + ans[node];
            q.push(node->left);
        } 
        if(node->right) {
            ans[node->right] = 1 + ans[node];
            q.push(node->right);
        }
    } while(q.front() != NULL);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* l11 = new TreeNode(2);
    TreeNode* l12 = new TreeNode(3);
    TreeNode* l21 = new TreeNode(4);
    TreeNode* l22 = new TreeNode(5);
    TreeNode* l23 = new TreeNode(6);
    TreeNode* l24 = new TreeNode(7);

    root->left = l11;
    root->right = l12;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;
    l24->left = l21;

    map<TreeNode*, int> ans = getSssp(root);

    for(auto el: ans) {
        cout<<el.first->val<<" "<<el.second<<endl;
    }
    
    return 0;
}