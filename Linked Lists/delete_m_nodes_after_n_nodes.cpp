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
    int n = 1;
    int m = 3;
    Node *current = head;
    
    while (n>1) {
        if(current->next != NULL) {
            current = current->next;
        } else {
            cout << "Linked List size is smaller"<<endl;
            break;
        }  
        n--;    
    }
    Node *temp = current;
    while (m--) {
        if(temp != NULL) {
            temp = temp->next;
        } else {
            cout << "Linked List size is smaller"<<endl;
            break;
        }
    }
    current->next = temp->next;
    if (n==0) {
        current = temp;
    }
    cout << endl;
    
    printList(head);

    return 0;
}

