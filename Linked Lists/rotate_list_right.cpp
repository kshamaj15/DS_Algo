#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* rotateRight(ListNode* A, int B) {
    ListNode* fast = A;
    ListNode* curr = A;
    ListNode* newHead;
    while(B--) {
        if(fast->next != NULL)
        fast = fast->next;
        else {
            fast = A;
        }
    }
    if (fast != NULL && fast != A) {
        while(fast->next != NULL) {
        fast = fast->next;
        curr = curr->next;
    }
    newHead = curr->next;
    curr->next = NULL;
    
    ListNode* currN = newHead;
    while(currN->next != NULL) {
        currN = currN->next;
    }
    while(A != NULL) {
        currN->next = A;
        A = A->next;
        currN = currN->next;
    }
    } else {
        newHead = A;
    }
    
    return newHead;
}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    head->next = NULL;
    head->val = 5;
    two->next = three;
    two->val = 1;
    three->next = four;
    three->val = 3;
    four->val = 6;
    four->next = five;
    five->val = 4;
    five->next = NULL;

    ListNode* newHead = rotateRight(head, 3);
    while (newHead != NULL)
    {
        cout<<newHead->val;
        newHead = newHead->next;
    }
    return 0;
}