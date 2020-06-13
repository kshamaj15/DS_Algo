#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* removeNthFromEnd(ListNode* A, int B) {
    ListNode* fast = A;
    ListNode* curr = A;
    while(B--) {
        if(fast != NULL && fast->next != NULL)
        fast = fast->next;
        else {
          A = A->next;
          break;  
        }
    }
    if(A != NULL && A->next != NULL && fast!= NULL) { 
        while(fast->next != NULL) {
            curr = curr->next;
            fast = fast->next;
        }
        curr->next = curr->next->next;
    }
}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    head->next = NULL;
    head->val = 5;
    two->next = three;
    two->val = 1;
    three->next = four;
    three->val = 3;
    four->val = 6;
    four->next = five;
    five->val = 4;
    five->next = NULL;

    removeNthFromEnd(head, 1);
    while (head != NULL) {
        cout<<head->val<< " ";
        head = head->next;
    }
    return 0;
}