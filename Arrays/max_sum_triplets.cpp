
// https://www.interviewbit.com/problems/maximum-sum-triplet/
// time - O(n^2) --- getting TLE (need to optimize more)
// extra space - O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        int max1 = INT_MIN;
        int max3 = INT_MIN;
        for(int j=0; j<i; j++) {
            if(A[i] > A[j] && A[j] > max1) {
                max1 = A[j];
            }
        }
        for(int j=i+1; j<n; j++) {
            if(A[i] < A[j] && A[j] > max3) {
                max3 = A[j];
            }
        }
        if(max1 != INT_MIN && max3 != INT_MIN) {
            ans = max(ans, max1 + A[i] + max3);
        }
    }
    return ans;
}

int main() {
    int n;
    // cin>>n;
    vector<int> v{32592, 18763, 1656, 17411, 6360, 27625, 20538, 21549, 6484, 27596};
    // for(int i=0; i<n; i++)
    // cin>>v[i];
    cout<<solve(v)<<endl;
}
