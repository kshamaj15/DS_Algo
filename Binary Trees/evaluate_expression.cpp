// https://practice.geeksforgeeks.org/problems/expression-tree/1/?category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1
// easy

#include<bits/stdc++.h>
using namespace std;

struct Node{
	string data;
	Node *left,*right;
    Node(char x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

int getValue(Node* root) {
    if(root != NULL && root->data == "+") {
        return getValue(root->left) + getValue(root->right);
    } else if(root != NULL && root->data == "-") {
        return getValue(root->left) - getValue(root->right);
    } else if(root != NULL && root->data == "*") {
        return getValue(root->left) * getValue(root->right);
    } else if(root != NULL && root->data == "/") {
        return getValue(root->left) / getValue(root->right);
    } else if(root != NULL) {
        return stoi(root->data);
    }
}

/*You are required to complete below method */
int evalTree(Node* root) {
    // Your code here
    return getValue(root);
}

int main() {

}