#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void inOrder(Node* root) {
    if(root == NULL)
    return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if(root == NULL)
    return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(Node* root) {
    if(root == NULL)
    return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inOrderItrativeWithStack(Node* root) {
    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) { 
            s.push(curr); 
            curr = curr->left; 
        } 
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
        curr = curr->right; 
    }
       
}

vector<int> levelOrder(Node* node)
{
  //Your code here
  queue<Node*> qu;
  qu.push(node);
  vector<int> ans;
  while(!qu.empty()) {
      Node* curr = qu.front();
      qu.pop();
      ans.push_back(curr->data);
      if(curr->left != NULL)
      qu.push(curr->left);
      if(curr->right != NULL)
      qu.push(curr->right);
  }
  return ans;
}

vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  stack<Node*> s;
  while(root != NULL || !s.empty()) {
      while(root != NULL) {
          ans.push_back(root->data);
          s.push(root);
          root = root->left;
      }
      root = s.top();
      root = root->right;
      s.pop();
  }
  return ans;
}

void postOrderItrativeWithStack (Node* root) {
    stack<Node*> stk;
    Node* curr = root;
    while (!stk.empty() || curr != NULL) {
        // cout<<"6";
        while (curr != NULL) {
            stk.push(curr);
            curr = curr->left;
        }
        // curr will definately be NULL here
        curr = stk.top();
        if(curr->right == NULL)
        cout << curr->data <<" ";
        else
        curr = curr->right;
        stk.pop();

        curr = curr->right;
        
    }
    
}

int findHeight (Node* root) {
    if(root == NULL) {
        return 0;
    } else {
         int maxHeight = 0;
         int a=0, b=0;
         a = findHeight(root->left);
         b = findHeight(root->right);
         maxHeight = a > b ? a+1 : b+1;
         return maxHeight;
    }
}

int getMinDepth (Node* A) {
    if(A == NULL) {
        return 0;
    } else {
        int minDepth, leftDepth, rightDepth;
        if(A != NULL) {
            leftDepth  = getMinDepth(A->left);
            rightDepth = getMinDepth(A->right);
        }
        minDepth = leftDepth < rightDepth ? leftDepth : rightDepth;
        return minDepth+1;
    }
}
    

int main() {

    Node* root = new Node(1);
    Node* l11 = new Node(2);
    Node* l12 = new Node(3);
    Node* l21 = new Node(4);
    Node* l22 = new Node(5);
    Node* l23 = new Node(6);
    Node* l24 = new Node(7);
    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;
    l12->left = l23;
    l12->right = l24;

    // inOrder(root);cout<<endl;
    // preOrder(root);cout<<endl;
    // postOrder(root);cout<<endl;
    // inOrderItrativeWithStack(root);
    // postOrderItrativeWithStack(root);
    cout<<getMinDepth(root);
    return 0;
}