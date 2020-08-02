#include<iostream>
using namespace std;
class ListNode {
    public:
    int val;
    ListNode *next;
};

// ListNode* reorderList1(ListNode* A) {
//     ListNode* curr = A;
//     ListNode* nnode;
//     while(curr != NULL) {
//         bool inside= false;
//         nnode = curr->next;
//         ListNode* prev = curr;
//         while(nnode != NULL && nnode->next != NULL) {
//             inside= true;
//             prev = prev->next;
//             nnode = nnode->next;
//             if(nnode->next == NULL) {
//                 prev->next = NULL;
//             }
//         }
//         prev->next = NULL;
//         ListNode* nxt = NULL;
//             nxt = curr->next;
//             curr->next = nnode;
//             curr = curr->next;
//             if(curr != NULL) {
//             curr->next = nxt;
//             curr = curr->next;
//             }
//         }
    
//     return A;
// }

ListNode* reorderList(ListNode* A) {
    ListNode* curr = A;
    int len = 0;
    while (curr != NULL) {
        curr = curr->next;
        len++;
    }
    if(len == 1 || len == 2)
    return A;
    int l = len/2 -1;
    curr = A;
    while (l > 0) {
        curr = curr->next;
        l--;
    }
    int backLen = (len+1)/2;
    ListNode* last = curr;
    ListNode* prev = curr->next;
    curr = prev->next;
    prev->next = NULL;
    ListNode* nxt = curr->next;
    while(backLen > 2) {
        backLen--;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    last->next = curr;
    curr->next = prev;

    ListNode* curr1 = last->next;
    curr = A;
    cout<<curr->val<<" "<<curr1->val<<endl;
    backLen = (len+1)/2;
    cout<<backLen<<endl;
    // while (backLen > 1) {
    //     nxt = curr->next;
    //     curr->next = curr1;
    //     curr1 = curr1->next;
    //     curr = curr->next;
    //     if(curr1->next != NULL) {
    //         curr->next = nxt; 
    //         curr = curr->next;
    //     }
    //     if(len%2 == 0 && curr1->next == NULL) {
    //         curr->next = nxt;
    //         curr = curr->next;
    //         curr->next = curr1;
    //     } 
        
    //     backLen--;
    //     cout<<curr->val<<" "<<curr1->val<<endl;
    // }

    return A;

}

int main() {
    ListNode *head = new ListNode();
    ListNode *two = new ListNode();
    ListNode *three = new ListNode();
    ListNode *four = new ListNode();
    ListNode *five = new ListNode();
    ListNode *six = new ListNode();
    ListNode *seven = new ListNode();
    ListNode *eight = new ListNode();
    ListNode *nine = new ListNode();
    ListNode *ten = new ListNode();

    head->next = two;
    head->val = 1;
    two->next = three;
    two->val = 2;
    three->next = four;
    three->val = 3;
    four->val = 4;
    four->next = five;
    five->val = 5;
    five->next = six;
    six->val = 6;
    six->next = seven;
    seven->val = 7;
    seven->next = eight;
    eight->val = 8;
    nine->next = NULL;
    nine->val = 9;
    ten->val = 10;
    ten->next = NULL;
    ListNode* newHead = reorderList(head);
    while (newHead != NULL) {
        cout<<newHead->val<<" ";
        newHead = newHead->next;
    }
    return 0;
}