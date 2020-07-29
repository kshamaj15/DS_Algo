#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* solve(ListNode* A) {
    ListNode *newNode;
    ListNode *curr = A;
    ListNode *newcurr = NULL;
    ListNode *onesHead;
    ListNode *curr1;
    bool isnew = true;
    bool isonesHead = true;
    while(curr != NULL) {
        if(curr->val == 0 && isnew) {
            newNode = curr;
            newcurr = curr;
            isnew = false;
        } else if(curr->val == 0 && !isnew) {
            newcurr->next = curr;
            newcurr = newcurr->next;
        } else if(curr->val == 1 && isonesHead) {
            onesHead = curr;
            curr1 = curr;
            isonesHead = false;
        } else if(curr->val == 1 && !isonesHead) {
            curr1->next = curr;
            curr1 = curr1->next;
        }
        curr = curr->next;
    }
    if(newcurr != NULL) {
        newcurr->next = onesHead;
        curr1->next = NULL;
        return newNode;
    } else {
        return onesHead;
    }
}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    head->next = two;
    head->val = 1;
    two->next = three;
    two->val = 0;
    three->next = four;
    three->val = 0;
    four->val = 1;
    four->next = five;
    five->val = 0;
    five->next = NULL;

    ListNode* newHead = solve(head);
    while (newHead != NULL)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    

    return 0;
}