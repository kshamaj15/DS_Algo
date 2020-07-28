#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > solve(int A) {
    vector<vector<int>> ans;
    vector<int> temp{1};
    int count = 2;
    ans.push_back(temp);
    while(A>1) {
        int localc = 0;
        vector<int> ltemp;
        while(localc < count) {
            if(localc == count-1) {
                ltemp.push_back(1);
                localc++;
            } else {
                ltemp.push_back(temp[localc-1]+temp[localc]);
                localc++;
            }
        }
        ans.push_back(ltemp);
        temp.clear();
        temp = ltemp;
        A--;
        count++;
    }
    return ans;
}


int main (){
    //code
    vector<vector<int>> ans;
    ans = solve(12);
    for(auto v:ans) {
        for(auto el: v) {
            cout<<el<<" ";
        }
        cout<<endl;
    }
    return 0;
}
