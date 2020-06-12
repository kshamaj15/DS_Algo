#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};
// 3 3 6 8 8
ListNode* deleteDuplicates(ListNode* a) {
        ListNode* curr = a;
        ListNode* pre = a;
        if (a->next != NULL) {
            int data = curr->val;
            curr = curr->next;
            while(curr != NULL) {
                if(curr->val != data) {
                    pre->next = curr;
                    pre = curr;
                    data = curr->val;
                } 
                curr = curr->next;
            }
            pre->next = NULL;
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
    head->val = 3;
    two->next = three;
    two->val = 4;
    three->next = four;
    three->val = 4;
    four->val = 5;
    four->next = five;
    five->val = 5;
    five->next = NULL;

    ListNode* newHead = deleteDuplicates(head);
    while (newHead != NULL)
    {
        cout<<newHead->val;
        newHead = newHead->next;
    }
    

    return 0;
}