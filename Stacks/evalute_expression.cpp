#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string> &A) {
    stack<int> stk;
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == "+") {
            int temp = stk.top();
            stk.pop();
            temp = stk.top() + temp;
            stk.pop();
            stk.push(temp);
        } else if(A[i] == "-") {
            int temp = stk.top();
            stk.pop();
            temp = stk.top() - temp;
            stk.pop();
            stk.push(temp);
        } else if(A[i] == "*") {
            int temp = stk.top();
            stk.pop();
            temp = stk.top() * temp;
            stk.pop();
            stk.push(temp);
        } else if(A[i] == "/") {
            int temp = stk.top();
            stk.pop();
            temp = stk.top() / temp;
            stk.pop();
            stk.push(temp);
        } else {
            stk.push(std::stoi(A[i]));
        }
    }
    return stk.top();
}

int main() {
    vector<string> v({"2","1","+","3","*"});
    cout<<evalRPN(v);
    return 0;
}

