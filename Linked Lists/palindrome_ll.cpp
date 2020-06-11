#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};
int lPalin(ListNode* a) {
    int ans = 1;
    int len = 0;
    ListNode* curr = a;
    ListNode* mid = a;
    while(curr != NULL) {
        len++;
        curr = curr->next;
    }
    if(len == 1) {
        ans = 1;
    } else {
        curr = a; 
        while((len-1)/2 > 0) {
            mid = mid->next;
            len = len - 2;
        }
        curr = mid->next;
        ListNode* pre = NULL;
        ListNode* nxt;
        while(curr->next != NULL) {
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }
        curr->next = pre;
        mid = curr;
        while(mid != NULL) {
            if(mid->val != a->val) {
                ans = 0;
                break;
            }
            mid = mid->next;
            a = a->next;
        }
    }
    return ans;
}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    head->next = two;
    head->val = 3;
    two->next = NULL;
    two->val = 4;
    three->next = four;
    three->val = 6;
    four->val = 4;
    four->next = five;
    five->val = 3;
    five->next = NULL;

    cout << lPalin(head);

    return 0;
}