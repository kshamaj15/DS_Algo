#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* mergeTwoLists(ListNode* A, ListNode* B) {
    ListNode* head = NULL;
    ListNode* currA = A;
    ListNode* currB = B;
    ListNode* curr;
    while(currA != NULL || currB != NULL) {
        if(currA != NULL && currB != NULL) {
            if(currA->val < currB->val) {
                if(head == NULL) {
                head = currA;
                curr = head; 
                } else {
                curr->next = currA;
                curr = curr->next;
                }
                currA = currA->next;
            } else {
                if(head == NULL) {
                head = currB;
                curr = head;
                } else {
                curr->next = currB;
                curr = curr->next;
                }
                currB = currB->next;
            }
        } else if (currA == NULL) {
            curr->next = currB;
            curr = curr->next;
            currB = currB->next;
        } else if (currB == NULL) {
            curr->next = currA;
            curr = curr->next;
            currA = currA->next;
        }
    }
    return head;
}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    ListNode *head1 = new ListNode();
    ListNode *two1 = new ListNode();
    ListNode *three1 = new ListNode();
    ListNode *four1 = new ListNode();
    ListNode *five1 = new ListNode();

    head->next = two;
    head->val = 3;
    two->next = three;
    two->val = 4;
    three->next = four;
    three->val = 5;
    four->val = 6;
    four->next = five;
    five->val = 9;
    five->next = NULL;

    head1->next = two1;
    head1->val = 1;
    two1->next = three1;
    two1->val = 7;
    three1->next = four1;
    three1->val = 8;
    four1->val = 8;
    four1->next = five1;
    five1->val = 11;
    five1->next = NULL;

    ListNode *newHead = mergeTwoLists(head, head1);
    while (newHead != NULL)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }

    return 0;
}