// https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

#include<bits/stdc++.h>
using namespace std;

int coverPoints(vector<int> &A, vector<int> &B) {
    int s = 0;
    int n = A.size();
    for(int i=1; i<n; i++) {
        s += max(abs(A[i]-A[i-1]), abs(B[i]-B[i-1]));
    }
    return s;
}


int main() {
    vector<int> A{0, 1, 1};
    vector<int> B{0, 1, 2};
    cout<<coverPoints(A, B)<<endl;
}