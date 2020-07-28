#include<bits/stdc++.h>
using namespace std;

vector<int> getRow(int A) {
    A++;
    vector<int> ans;
    ans.push_back(1);
    for(int i=2; i<=A; i++) {
        int el = ans[i-2]*(A - i + 1)/(i-1);
        ans.push_back(el);
    }
    return ans;
}


int main (){
    //code
    vector<int> ans;
    ans = getRow(20);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    return 0;
}
