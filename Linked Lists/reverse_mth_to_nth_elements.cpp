#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* reverseBetween(ListNode* a, int m, int n) {
    if(a->next == NULL || m==n) {
        return a;
    }
    ListNode* newHead;
    ListNode* last;
    if(m != 1)
    newHead = a;
    while(m > 2) {
        a = a->next;
    }
    last = a;
    //reverse logic
    if(m != 1) {
        a = a->next;
    }
    
    ListNode* prev = a;
    ListNode* curr = a->next;
    ListNode* nxt = curr->next;
    ListNode* rhead = prev;
    while(n > m+1) {
        n--;
        // cout<<curr->val<<"sa ";
        // cout<<prev->val<<"sa ";
        curr->next = prev;
        rhead = prev;
        prev = curr;
        curr = nxt;
        if(curr != NULL)
        nxt = curr->next;
    }
    if(m != 1) {
        last->next = curr;
        rhead->next = nxt;
        // if(curr->next == NULL)
        // newHead = curr;
        curr->next= prev;
        cout<<rhead->val<<"sa ";
        cout<<curr->val<<"sa ";
        // cout<<prev->val<<"sa ";
        // cout<<nxt->val<<"sa ";
    }
    else {
        newHead = curr;
        rhead->next = nxt;
        curr->next= prev;
        // cout<<rhead->val<<"sa ";
        // cout<<curr->val<<"sa ";
        // cout<<prev->val<<"sa ";
        // cout<<nxt->val<<"sa ";
    }
    
    
    // cout<<rhead->val<<"SA"<<endl;
    // cout<<nxt->val<<endl;
    // cout<<prev->val<<endl;
    // cout<<curr->val<<endl;
    
    // if(m != 1)
    // rhead->next = a->next;
    // if(m == 1) {
    //     newHead = rhead;
    // }
    
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

    ListNode* newHead = reverseBetween(head, 3, 5);
    while (newHead != NULL) {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    return 0;
}