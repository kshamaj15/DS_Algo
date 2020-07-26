#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {
    vector<int> ans;
    int index = 0;
    for(int i=1; i<A.size(); i++) {
        if(A[i-1]<0 && A[i] >=0) {
            index = i;
            break;
        }
    }
    int left = index-1;
    int right = index;
    while(left >=0 && right < A.size()) {
        cout<<left<<" "<<right<<endl;
        if(abs(A[left]) >= abs(A[right])) {
            ans.push_back(A[right]*A[right]);
            right++;
        } else {
            ans.push_back(A[left]*A[left]);
            left--;
        }
    }
    if(left <= 0) {
        while(right < A.size()) {
            ans.push_back(A[right]*A[right]);
            right++;
        }
    } else if (right >= A.size()-1) {
        while (left >= 0) {
            ans.push_back(A[left]*A[left]);
            left--;
        }
        
    }
    return ans;
}


int main (){
    //code
    vector<int> v{-10, -6, -3, -1, 2, 4, 5, 6, 8, 21, 44};
    vector<int> ans;
    ans = solve(v);
    for(auto el: ans) {
        cout<<el<<" ";
    }
    return 0;
}
