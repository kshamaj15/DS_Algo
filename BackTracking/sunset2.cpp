#include<bits/stdc++.h>
using namespace std;

void getSubsets(vector<int> &A, vector<vector<int>> &ans, vector<int> &subset, int index, int last){
    bool isDupli = false;
    for(int i=0; i<ans.size(); i++) {
        isDupli = true;
        if(ans[i].size() != subset.size()) {
            isDupli = false;
            continue;
        }
        for(int j=0; j<ans[i].size(); j++) {
            if(ans[i][j] != subset[j]) {
                isDupli = false;
                break;
            }
        }
        if(isDupli)
        break;
    }
    if(!isDupli)
    ans.push_back(subset);
    for(int i = index; i<A.size(); i++) {
        if(i>last) {
            subset.push_back(A[i]);
            getSubsets(A, ans, subset, index+1, i);
            subset.pop_back();
        }
    }
}

vector<vector<int> > subsets2(vector<int> &A) {
    vector<vector<int> > ans;
    vector<int> subset;
    getSubsets(A, ans, subset, 0, -1);
    return ans;
}

int main (){
    //code
    vector<int> v{1,2,2};
    vector<vector<int>> ans;
    ans = subsets2(v);
    for(auto v: ans) {
        for(auto el: v) {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
