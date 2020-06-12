#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};
// 3 3 6 8 8
ListNode* deleteDuplicates(ListNode* a) {
    ListNode* newHead = NULL;
    if(a->next != NULL && a->next->next != NULL) {
        ListNode* last = NULL;
        ListNode* prev = a;
        ListNode* curr = a->next;
        ListNode* nxt = a->next->next;
        if(prev->val != curr->val) {
            newHead = prev;
            last = prev;
        }
        while(curr->next != NULL) {
            if(curr->val != nxt->val && curr->val != prev->val) {
                if(newHead == NULL) {
                    newHead = curr;
                    last = curr;
                } else {
                    last->next = curr;
                    last = curr;
                }
            }
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        if(curr->val != prev->val) {
            last->next = curr;
        } else {
            last->next = NULL;
        }
    } else if(a->next == NULL) {
        newHead = a;
    } else {
        if(a->val != a->next->val) {
            newHead = a;
        } else {
            newHead = NULL;
        }
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
    head->val = 3;
    two->next = three;
    two->val = 3;
    three->next = four;
    three->val = 3;
    four->val = 6;
    four->next = five;
    five->val = 44;
    five->next = NULL;

    ListNode* newHead = deleteDuplicates(head);
    while (newHead != NULL)
    {
        cout<<newHead->val;
        newHead = newHead->next;
    }
    

    return 0;
}