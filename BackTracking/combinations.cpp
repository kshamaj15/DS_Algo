#include<bits/stdc++.h>
using namespace std;

void getCombinations(int n, int k, vector<vector<int> > &ans, vector<int> &set, int x) {
    if(k==0) {
        ans.push_back(set);
        return;
    }
    for(int i=1; i<=n-k+1; i++) {
        if(i>x) {
            set.push_back(i);
            k--;
            x = i;
            getCombinations(n, k, ans, set, x);
            k++;
            set.pop_back();
        } 
    }
}

int main (){
    //code
    vector<vector<int> > ans;
    vector<int> set;
    int start = 1;
    int end = 3;
    getCombinations(4, 2, ans, set, 0);

    for(auto v: ans) {
        for(auto el: v) {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
