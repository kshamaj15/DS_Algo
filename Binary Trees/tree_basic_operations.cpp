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
    // ======= MY CODE =========
    // stack<Node*> stk;
    // Node* curr = root;
    // stk.push(curr);
    // while (curr->right != NULL || !stk.empty()) {
    //     while(curr->left != NULL) {
    //         curr = curr->left;
    //         stk.push(curr);
    //     }
    //     cout<<curr->data;
    //     if(!stk.empty())
    //     stk.pop();
    //     if(!stk.empty()) {
    //         curr = stk.top();
    //         cout<<curr->data;
    //         curr = curr->right;
    //     }
        
    //     if(curr == NULL && !stk.empty())
    //     curr = stk.top();
    //     if(curr->right == NULL && stk.empty())
    //     break;
    // }

    stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        /* Reach the left most Node of the 
           curr Node */
        while (curr !=  NULL) 
        { 
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr); 
            curr = curr->left; 
        } 
  
        /* Current must be NULL at this point */
        curr = s.top(); 
        s.pop(); 
  
        cout << curr->data << " "; 
  
        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right; 
  
    } /* end of while */
       
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
    

int main() {

    Node* root = new Node(1);
    Node* l11 = new Node(2);
    Node* l12 = new Node(3);
    Node* l21 = new Node(4);
    Node* l22 = new Node(5);
    root->left = l11;
    root->right = l12;
    l11->left = l21;
    l11->right = l22;

    // inOrder(root);cout<<endl;
    // preOrder(root);cout<<endl;
    // postOrder(root);cout<<endl;
    // inOrderItrativeWithStack(root);
    // postOrderItrativeWithStack(root);
    cout<<findHeight(root);
    return 0;
}