#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
        string isbalanced = "YES";
        string s = "[{{}}{()}]";
        stack<char> stk;
        // cin>>s;
        // cout<<s<<endl;
        for(int j=0; j<s.length(); j++){
            if(s[j] == '[' || s[j] == '(' || s[j] == '{')
            stk.push(s[j]);
            else if(!stk.empty()) {
                if(s[j] == ']') {
                    if(stk.top() == '[')
                    stk.pop();
                    else {
                        isbalanced = "NO";
                        break;
                    }
                } else if(s[j] == ')') {
                    if(stk.top() == '(')
                    stk.pop();
                    else {
                        isbalanced = "NO";
                        break;
                    }
                } else {
                    if(stk.top() == '{')
                    stk.pop();
                    else {
                        isbalanced = "NO";
                        break;
                    }
                }              
            } else if (stk.empty()) {
        isbalanced = "NO";
            }
        }
        if(!stk.empty())
        isbalanced = "NO";
        cout<<isbalanced<<endl;
    return 0;
}