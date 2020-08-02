#include<bits/stdc++.h>
using namespace std;

void subSetFunc(vector<int> &A, vector<int> &subset, vector<vector<int> > &res, int index) {
    res.push_back(subset); 
    for (int i = index; i < A.size(); i++) { 
  
        // include the A[i] in subset. 
        subset.push_back(A[i]); 
  
        // move onto the next element. 
        subSetFunc(A, subset, res, i + 1); 
  
        // exclude the A[i] from subset and triggers 
        // backtracking. 
        subset.pop_back(); 
    }

    // for(auto v: res) {
    //     for(auto el: v) {
    //         cout<<el<<" ";
    //     }
    //     cout<<index<<" "<<endl;
    // } 
  
    return; 
}

vector<vector<int> > subsets(vector<int> &A) {
    vector<vector<int> > res;
    vector<int> subset;
    int index = 0;
    subSetFunc(A, subset, res, index);
    // for(auto v: res) {
    //     for(auto el: v) {
    //         cout<<el<<" ";
    //     }
    //     cout<<endl;
    // }
    return res;
}


int main (){
    //code
    vector<int> v{1,2,3};
    vector<vector<int>> ans;
    ans = subsets(v);
    for(auto v: ans) {
        for(auto el: v) {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
