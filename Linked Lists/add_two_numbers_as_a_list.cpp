#include<iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode* newHead = A;
    int carry = 0;
    // bool isnew = true;
    bool isA = true;
   ListNode* copyB = B;
   ListNode* copyA = A;
   int a = 0;
   int b = 0;
   
   while(copyA != NULL) {
       a++;
       copyA = copyA->next;
   }
   while(copyB != NULL) {
       b++;
       copyB = copyB->next;
   }
   if(b>=a)
   newHead = B;
    while(A != NULL && B != NULL) {
        if(a>b) {
            int temp = (A->val + B->val + carry);
            A->val = temp%10;
            carry = temp/10;
        }
        else {
            int temp = (A->val + B->val + carry);
            B->val = temp%10;
            carry = temp/10;
        }
        A = A->next;
        B = B->next;
    }
    while(A != NULL) {
        int temp = (A->val + carry);
        A->val = temp%10;
        carry = temp/10;
        if(A->next == NULL && carry != 0) {
            ListNode* node  = new ListNode();
            node->val = carry;
            node->next = NULL;
            A->next = node;
            A = A->next;
        }
        A = A->next;
    }
    while(B != NULL) {
        int temp = (B->val + carry);
        B->val = temp%10;
        carry = temp/10;
        if(B->next == NULL && carry != 0) {
            ListNode* node = new ListNode();
            node->val = carry;
            node->next = NULL;
            B->next = node;
            B = B->next;
        }
        B = B->next;
    }
    return newHead;
}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    head->next = NULL;
    head->val = 1;
    two->next = three;
    two->val = 0;
    three->next = four;
    three->val = 0;
    four->val = 1;
    four->next = five;
    five->val = 0;
    five->next = NULL;

    ListNode *head1 = new ListNode();
    ListNode *two1 = new ListNode();
    ListNode *three1 = new ListNode();
    ListNode *four1 = new ListNode();
    ListNode *five1 = new ListNode();

    head1->next = two1;
    head1->val = 9;
    two1->next = three1;
    two1->val = 9;
    three1->next = NULL;
    three1->val = 9;
    four1->val = 6;
    four1->next = five1;
    five1->val = 7;
    five1->next = NULL;

    ListNode* newHead = addTwoNumbers(head, head1);
    while (newHead != NULL)
    {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    

    return 0;
}