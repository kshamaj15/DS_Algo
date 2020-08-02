#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(const vector<int> &A, int B) {
    vector<vector<int>> ansA;
    vector<int> ans;
    unordered_map<int, int> map;
    for(int i=A.size()-1; i>=0; i--) {
        map[A[i]] = i+1;
    }
    for(auto el: map) {
        if(map[B-el.first] != 0) {
            ans.push_back(map[el.first]);
            ans.push_back(map[B-el.first]);
            break;
        }
    }
    return ans;
}


int main (){
    //code
    vector<int> v2{2, 7, 6, 11, 15, 7};
    vector<int> v{2,7,11,15};
    vector<int> v1{4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    // vector<vector<int>> ans;
    vector<int> ans;
    ans = twoSum(v2, 13);
    for(auto el:ans) {
        cout<<el<<" ";
    }
    return 0;
}
