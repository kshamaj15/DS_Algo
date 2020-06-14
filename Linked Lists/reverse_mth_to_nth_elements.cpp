#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* reverseBetween(ListNode* a, int m, int n) {
    if(a->next != NULL) {
        ListNode* curr = a;
    ListNode* startPrev = NULL;
    ListNode* endNxt = NULL;
    ListNode* start;
    ListNode* end;
    ListNode* prev;
    ListNode* nxt;

    while(m > 2) {
        curr = curr->next;
        startPrev = curr;
        m--;
    }
    if(m == 2){
        startPrev = a;
    }
    prev = startPrev;
    if(startPrev != NULL) {
    curr = curr->next;

    } else {
        n++;
    }
    // nxt = curr->next;
    while (n-m > 0) {
        // if(nxt != NULL)
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        n--;
    }
    if(curr != NULL) {
endNxt = curr->next;
    curr->next = prev;
    }
    
    if(startPrev != NULL && startPrev->next != NULL) {
        startPrev->next->next = endNxt;
        startPrev->next = curr;
    } else if(startPrev == NULL)
    {
        a = prev;
        // cout<<prev->val;
    }
    
    }
    
    
    
    return a;
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

    ListNode* newHead = reverseBetween(head, 1, 5);
    while (newHead != NULL)
    {
        cout<<newHead->val;
        newHead = newHead->next;
    }
    return 0;
}