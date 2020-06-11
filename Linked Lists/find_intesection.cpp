#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    int lenA = 0;
    int lenB = 0;
    ListNode *node = NULL;
    ListNode *a = A;
    ListNode *b = B;
    while(a != NULL) {
        lenA++;
        a = a->next;
    }
    while(b != NULL) {
        lenB++;
        b = b->next;
    }
    
    if(lenA > lenB) {
        while(lenA > lenB) {
            A = A->next;
        }
    } else {
        while(lenA < lenB) {
            B = B->next;
        }
    }
    while(A->next != NULL && B->next != NULL) {
        if(A->next == B->next) {
            node = A->next;
            break;
        }
        A = A->next;
        B = B->next;
    }
    return node;
}

int main() {
    ListNode *head1 = new ListNode();
    ListNode *head2 = new ListNode();
    ListNode *two1 = new ListNode();
    ListNode *two2 = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();

    head1->next = two1;
    head1->val = 5;
    head2->next = two2;
    head2->val = 3;
    two1->next = three;
    two1->val = 6;
    two2->next = three;
    two2->val = 4;
    three->next = four;
    three->val = 6;
    four->val = 4;
    four->next = five;
    five->val = 3;
    five->next = NULL;

    cout<<getIntersectionNode(head1, head2)->val;

    return 0;
}