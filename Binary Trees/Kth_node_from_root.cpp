// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/?category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1
// functional problem
// easy

#include<bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	Node *left,*right;
    Node(char x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void getK(vector<int> &ans, struct Node *root, int k) {
    if(k==0 && root != NULL) {
        ans.push_back(root->data);
    } 
    if(k < 0) {
        return;
    }
    if(root == NULL)
    return;
    
    getK(ans, root->left, k-1);
    getK(ans, root->right, k-1);
}

vector<int> Kdistance(struct Node *root, int k)
{
     vector<int> ans;
     getK(ans, root, k);
     return ans;
}

int main() {

}