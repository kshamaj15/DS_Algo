#include<iostream>
using namespace std;
class Node {
    public:
    int data;
    Node *next;
};

void insertBefore(Node **head, int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(Node **head, int value) {
    Node *newNode = new Node();
    newNode->data = value;
    if(head == NULL) {
        *head = newNode;
    } else {
        Node *last = *head;
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void deleteBefore(Node **head) {
    if(head == NULL) {
        cout << "LinkedList is empty";
    } else {
       Node *last = *head;
        while(last->next->next != NULL) {
            last = last->next;
        }
        delete last->next;
        last->next = NULL;
    } 
}

void deleteAfter(Node **head) {
    if(head == NULL) {
        cout << "LinkedList is empty";
    } else {
        Node *temp = *head;
        *head = temp->next;
        delete temp;
    }    
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
    head->data = 3;
    two->next = three;
    two->data = 4;
    three->next = four;
    three->data = 6;
    four->data = 2;
    four->next = NULL;

    // printList(head);

    // insertAfter(&head, 4);
    // insertAfter(&head, 4);
    // insertAfter(&head, 4);
    insertBefore(&head, 5444);
    insertBefore(&head, 54);
    insertBefore(&head, 5);
    deleteBefore(&head);
    // push(&head, 544);
    // push(&head, 544);
    // push(&head, 54);
    printList(head);

    return 0;
}

