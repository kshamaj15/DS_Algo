// https://practice.geeksforgeeks.org/problems/convert-ternary-expression-to-binary-tree/1/?category[]=Tree&problemStatus=unsolved&page=1&query=category[]TreeproblemStatusunsolvedpage1
// gonna write a blog
// Binary tree

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

Node *convertExpression(string str)
{
    stack<Node*> s;
    Node* root = new Node(str[0]);
    Node* curr = root;
    s.push(root);
    
    for(int i=2; i<str.size(); i+=2) {
        Node* node = new Node(str[i]);
        if(str[i-1] == '?') {
            s.push(node);
            curr->left = node;
            curr = curr->left;
        } else {
            s.pop();
            while(s.top()->right != NULL)
            s.pop();
            curr = s.top();
            curr->right = node;
            if(i+1 < str.size() && str[i+1] == '?') {
                s.push(node);
                curr = curr->right;
            }
        }
    }
    return root;
}

void preOrder(Node* root) {
    if(root == NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    string s = "w?l?r?b?b:m:q?b:h:c?d?a:r:z?o:w:k?k?y?h:i:d?d:q:s?c?d:x:r?j:m";
    Node* head = convertExpression(s);
    preOrder(head);
    cout<<endl;
}