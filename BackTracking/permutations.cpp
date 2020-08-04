#include<bits/stdc++.h>
using namespace std;

void getAllPermute(vector<vector<int> > &ans, vector<int> &A, int l, int r) {
    if(l == r) {
        ans.push_back(A);
    }
    for(int i=l; i<=r; i++) {
            // Swapping done  
            swap(A[l], A[i]);  
  
            // Recursion called  
            getAllPermute(ans, A, l+1, r);  
  
            //backtrack  
            swap(A[l], A[i]); 
    }
    return;
}

vector<vector<int> > permute(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> set;
    getAllPermute(ans, A, 0, A.size()-1);
    return ans;
}


int main (){
    //code
    vector<int> v{1,2,3};
    vector<vector<int>> ans;
    ans = permute(v);
    for(auto el: ans) {
        for(auto e: el) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    return 0;
}
