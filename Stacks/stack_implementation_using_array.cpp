#include <bits/stdc++.h> 
using namespace std;
#define MAX 1000

class Stack {
    int top;
    public:
    int a[MAX];
    bool push(int value);
    int pop();
    bool isEmpty();
    int peek();
};

bool Stack::push(int value) {
    if(top>MAX) {
        cout<<"Stack overflow";
        return false;
    } else {
        a[top+1] = value;
        top++;
        return true;
    }
}

int Stack::pop() {
    if(top<0) {
        cout << "Stack is empty";
        return 0;
    } else {
        int temp = a[top];
        a[top] = 0;
        top--;
        return temp;
    }
}

int Stack::peek() {
    if(top<0) {
        cout << "Stack is empty";
        return 0;
    } else {
        return a[top];
    }
}

bool Stack::isEmpty() {
    return (top < 0)?true:false;
}

int main() {
    Stack stk;
    stk.push(5);
    stk.push(4);
    stk.push(52);
    stk.push(522);
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    cout<<stk.pop();
    return 0;
}
