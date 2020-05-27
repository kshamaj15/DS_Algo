#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

Node *newNode(int data)  
{  
    Node *new_node = new Node;  
    new_node->data = data;  
    new_node->next = NULL;  
    return new_node;  
}

void printList(Node *head) {
        while (head != NULL) {
            cout << head->data << "->";
            head = head->next;
        }
}

void reversell (Node **head) {
    Node *curr = *head;
    Node *prev = NULL;
    Node *next = (*head)->next;
    while (curr->next != NULL) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = curr->next;
    }
    *head = curr;
    curr->next = prev;
}

void addOne(Node *head) {
    reversell(&head);
    int carry = 1;
    Node *curr = head;
    while(carry > 0) {
        int sum = curr->data + carry;
        carry = sum / 10;
        curr->data = sum % 10;
        curr = curr->next;
    }   
    reversell(&head);
}

int main(){
    Node *head = new Node();
    Node *two = new Node();
    Node *three = new Node();
    Node *four = new Node();

    head->next = two;
    head->data = 1;
    two->next = three;
    two->data = 3;
    three->next = four;
    three->data = 9;
    four->data = 9;
    four->next = NULL;
    
    printList(head);
    cout << endl;
    addOne(head);
    cout<<endl;
    printList(head);

    return 0;
}

