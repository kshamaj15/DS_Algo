// https://www.interviewbit.com/problems/redundant-braces/

#include<bits/stdc++.h>
using namespace std;

int braces(string A) {
    stack<int> s;
    int prevDiff = 0;
    for(int i=0; i<A.size(); i++) {
        if(A[i] == '(')
        s.push(i);
        else if(A[i] == ')') {
            cout<<i<<" "<<s.top()<<" "<<prevDiff<<endl;
            if((i - s.top()) == 2 || (i - s.top() - prevDiff) == 2)
            return 1;
            else {
                prevDiff = i - s.top();
                s.pop();
            }
        }
    }
    return 0;
}

int main() {
    string s = "((A+B))";
    cout<<braces(s);
}