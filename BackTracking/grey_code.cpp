#include<bits/stdc++.h>
using namespace std;

void getGreyArr(int n, vector<int> &ans) {
    if(n==0) {
        return;
    }
    ans.push_back(0);
    ans.push_back(1);
    int mul = 2;
    for(int i=2; i<=n; i++) {
        cout<<"d ";
        int n = ans.size();
        for(int j=n-1; j>=0; j--){
            ans.push_back(mul + ans[j]);
        }
        mul *= 2;
    }
}

int main (){
    //code
    vector<int> ans;
    getGreyArr(4, ans);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    return 0;
}
