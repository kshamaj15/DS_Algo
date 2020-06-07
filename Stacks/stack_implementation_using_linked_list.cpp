#include<iostream>
using namespace std;

class Element {
    public:
    int data;
    Element *prev;
};

// class Stack {
//     public:
//     Element *top;
//     bool push(Element** root, int value);
//     int pop();
//     bool isEmpty();
//     int peek();
// };

bool push(Element** top, int value) {
    Element *newEl = new Element();
    newEl->data = value;
    newEl->prev = *top;
    *top = newEl;
}

int pop(Element** top) {
    if(*top == NULL) {
        cout<<"Stack is Empty"<<endl;
        return 0;
    } else {
        Element *el = *top;
        int temp = (*top)->data;
        *top = (*top)->prev;
        return temp;
    }
}

int peek(Element** top) {
    if(*top == NULL) {
        cout<<"Stack is Empty"<<endl;
        return 0;
    } else {
        return (*top)->data;
    }
}

bool isEmpty(Element** top) {
    if(*top == NULL) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Element *el = NULL;
    push(&el, 2);
    push(&el, 90);
    push(&el, 45);
    push(&el, 11);
    cout<<pop(&el);
    cout<<pop(&el);
    cout<<peek(&el);
    return 0;
}