#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* partition(ListNode* A, int B) {
    ListNode* newHead = NULL;
    ListNode* midHead = NULL;
    ListNode* curr0 = NULL;
    ListNode* curr1 = NULL;
    // if(A->val < B) {
    //     newHead = A;
    //     curr0 = A;
    // }
    
    while(A != NULL) {
        cout<<A->val<<endl;
        if(A->val < B && curr0 == NULL) {
            newHead = A;
            curr0 = A;
        } else if (A->val < B && curr0 != NULL) {
            curr0->next = A;
            curr0 = curr0->next;
        } else if(A->val >= B && curr1 == NULL) {
            midHead = A;
            curr1 = A;
        } else if (A->val >= B && curr1 != NULL) {
            curr1->next = A;
            curr1 = curr1->next;
        }
        A = A->next;
    }
    // curr0->next = NULL;
    // curr1->next = NULL;
    if(curr0 != NULL) {
        curr0->next = midHead;
    } else {
        newHead = midHead;
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
    head->val = 1;
    two->next = three;
    two->val = 2;
    three->next = four;
    three->val = 3;
    four->val = 4;
    four->next = five;
    five->val = 5;
    five->next = NULL;

    ListNode* newHead = partition(head, 5);
    while (newHead != NULL)
    {
        cout<<newHead->val;
        newHead = newHead->next;
    }
    return 0;
}