#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> ans;
    stack<int> stk;
    stk.push(A[A.size()-1]);
    for(int i=A.size()-2; i>=0; i--) {
        if(A[i] > stk.top())
        stk.push(A[i]);
    }
    while(!stk.empty()) {
        ans.push_back(stk.top());
        stk.pop();
    }
    return ans;
}


int main (){
    //code
    vector<int> v{12, 4, 5, 6, 7, 6};
    vector<int> ans = solve(v);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    
    return 0;
}
