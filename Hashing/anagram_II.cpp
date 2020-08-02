#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > anagrams( vector<string> &A) {
    vector<vector<int>> ans;
    map<string, vector<int>> mp;
    for(int i=0; i<A.size(); i++) {
        sort(A[i].begin(), A[i].end()); 
    }
    for(int i=0; i<A.size(); i++) {
        vector<int> temp;
        mp[A[i]].push_back(i+1);
    }
    for(auto el: mp){
        ans.push_back(el.second);
    }
    return ans;
}


int main (){
    //code
    vector<string> v{"cat", "dog", "tca", "god"};
    vector<vector<int> > ans;
    ans = anagrams(v);
    for(auto vec: ans) {
        for(auto el: vec) {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
