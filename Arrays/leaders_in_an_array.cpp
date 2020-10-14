// https://www.interviewbit.com/problems/leaders-in-an-array/
// space: O(1)
// time: O(n)

#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &arr) {
    vector<int> ans;
    int mx=0;
    for(int i=arr.size()-1; i>=0; i--)
    {
        if(arr[i] > mx)
        {
            mx = arr[i];
            ans.push_back(mx);
        }
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
