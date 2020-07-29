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
    ListNode* prev = a;
    ListNode* curr;
    bool isDupli = false;
    bool isnewNode = false;
    a = a->next;
    while(a != NULL) {
        cout<<a->val<<" "<<prev->val<<endl;
        if(a->val != prev->val && isnewNode) {
            if(!isDupli) {
            curr = curr->next;
            curr = prev;
            // cout<<curr->val<<" ";
            }
            isDupli = false;
            prev = a;
        } else if(a->val != prev->val && !isnewNode) {
            if(!isDupli) {
                newHead = prev;
            curr = newHead;
            // cout<<curr->val<<" ";
            // curr = curr->next;
            isnewNode = true;
            }
            isDupli = false;
            prev = a;
        } else if(a->val == prev->val) {
            isDupli = true;
        }
        a = a->next;
    }
    // cout<<curr->val;
    cout<<endl;
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
    two->val = 5;
    three->next = four;
    three->val = 5;
    four->val = 6;
    four->next = five;
    five->val = 7;
    five->next = NULL;

    ListNode* newHead = deleteDuplicates(head);
    while (newHead != NULL)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    

    return 0;
}