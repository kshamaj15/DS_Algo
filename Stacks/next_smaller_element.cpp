#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> &A) {
    stack<int> stk;
    vector<int> ans;
    ans.push_back(-1);
    stk.push(A[0]);
    for(int i=1; i<A.size(); i++) {
        cout<<stk.top()<<" "<<A[i]<<endl;
        if(stk.top()<A[i]) {
            ans.push_back(stk.top());
            stk.push(A[i]);
        }
        else if(stk.top() >= A[i]) {
            while(!stk.empty() && stk.top() >= A[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                ans.push_back(-1);
                stk.push(A[i]);
            } else {
                ans.push_back(stk.top());
                stk.push(A[i]);
            }
        }
    }
    return ans;
}


int main (){
    //code
    vector<int> v{34, 35, 27, 42, 5, 28, 39, 20, 28};
    vector<int> ans;
    ans = prevSmaller(v);
    for(auto a: ans) {
        cout<<a<<" ";
    }
    return 0;
}
