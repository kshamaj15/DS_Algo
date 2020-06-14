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
    ListNode* less = NULL;
    ListNode* great = NULL;
    ListNode* curr = A;
    if(A->next != NULL) {
        while(curr != NULL) {
        if(newHead == NULL && curr->val < B) {
            newHead = curr;
            less = curr;
            curr = curr->next;
            // if(midHead != NULL) {
            //     less->next = midHead;
            //     if(great != NULL)
            //     great->next = NULL;
            // }
        } else if(curr->val < B && great ==  NULL) {
            less->next = curr;
            less = less->next;
            curr = curr->next;
        } else if (curr->val >= B && great ==  NULL) {
            great = curr;
            midHead = curr;
            curr = curr->next;
        } else if (curr->val >= B && great !=  NULL) {
            great->next = curr;
            great = great->next;
            curr = curr->next;
        } else if (curr->val < B && great !=  NULL) {
            ListNode* temp;
            temp = curr->next;
            less->next = curr;
            less = less->next;
            less->next = midHead;
            curr = temp;
        }
    }
    if(newHead == NULL) {
        newHead = A;
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

    head->next = two;
    head->val = 9;
    two->next = three;
    two->val = 4;
    three->next = four;
    three->val = 7;
    four->val = 6;
    four->next = five;
    five->val = 4;
    five->next = NULL;

    ListNode* newHead = partition(head, 5);
    while (newHead != NULL)
    {
        cout<<newHead->val;
        newHead = newHead->next;
    }
    return 0;
}