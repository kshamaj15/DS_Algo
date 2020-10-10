// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1/?company[]=Goldman%20Sachs&page=1&query=company[]Goldman%20Sachspage1
// medium

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

void deleteNode(Node *node)
{
   // Your code here
   Node* temp = node->next;
   node->data = temp->data;
   node->next = temp->next;
   delete temp;
}

int main() {

}