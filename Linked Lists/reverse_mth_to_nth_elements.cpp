#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* reverseBetween(ListNode* a, int m, int n) {
    ListNode* newHead;
    ListNode* last;
    if(m != 1)
    newHead = a;
    while(m > 2) {
        a = a->next;
    }
    last = a;
    //reverse logic
    ListNode* prev = a->next;
    ListNode* curr = a->next->next;
    ListNode* nxt = curr->next;
    ListNode* rhead = prev;
    while(n > m+1) {
        n--;
        curr->next = prev;
        rhead = prev;
        prev = curr;
        curr = nxt;
        nxt = curr->next;
    }
    last->next = curr;
    rhead->next = nxt;
    cout<<rhead->val<<endl;
    cout<<nxt->val<<endl;
    cout<<prev->val<<endl;
    cout<<curr->val<<endl;
    curr->next= prev;
    // if(m != 1)
    // rhead->next = a->next;
    if(m == 1) {
        newHead = rhead;
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
    five->val = 5;
    five->next = NULL;

    ListNode* newHead = reverseBetween(head, 1, 4);
    while (newHead != NULL)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    return 0;
}