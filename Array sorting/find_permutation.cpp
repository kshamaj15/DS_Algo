// https://www.interviewbit.com/problems/find-permutation/

#include<bits/stdc++.h>
using namespace std;

vector<int> findPerm(const string A, int n) {
    int inc = 1, dec = n;
    vector<int> ans;
    for(int i=0; i<n-1; i++){
        if(A[i] == 'D') {
            ans.push_back(dec);
            dec--;
        } else {
            ans.push_back(inc);
            inc++;
        }
    }
    ans.push_back(inc);
    return ans;
}


int main() {
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<int> ans = findPerm(s, n);
    for(auto el: ans) {
        cout<<el<<" ";
    }
}