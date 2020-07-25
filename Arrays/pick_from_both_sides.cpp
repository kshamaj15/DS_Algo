#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    vector<int> left;
    vector<int> right;
    int lsum = 0;
    int rsum = 0;
    for(int i=0; i<B; i++) {
        lsum += A[i];
        left.push_back(lsum);
    }
    for(int i=0; i<B; i++) {
        rsum += A[A.size()-1-i];
        right.push_back(rsum);
    }
    int ans;
    ans = left[B-1] > right[B-1] ? left[B-1] : right[B-1];
    for(int i=0; i<B-1; i++) {
        ans = ans > (left[i]+right[B-2-i]) ? ans : (left[i]+right[B-2-i]);
    }
    return ans;
}


int main (){
    //code
    vector<int> v{5, -2, 3, 1, 2};
    cout<<solve(v,3);
    return 0;
}
