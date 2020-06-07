#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int braces(string A) {
    stack<char> stk;
    stack<char> ind;
    int ans = 0;
    for(int i=0; i<A.length(); i++) {
        if(A[i]=='(') {
            stk.push(i);
        }
        else if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/'){
            ind.push(i);
        }
        else if (A[i] == ')') {
            if(!ind.empty() && stk.top() < ind.top()) {
                stk.pop();
            } else {
                ans = 1;
                break;
            }
            ind.pop();
        }
    }
    if(!stk.empty()) {
            cout<<"this";
            ans = 1;
        }
    return ans;
}

int main() {
    string a = "(a*b)+(b*c)";
    cout<<braces(a);
    return 0;
}