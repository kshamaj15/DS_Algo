// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/
// time: O(n*n) or O(N) where N = number of element in a matrix
// extra space = O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A, int B) {
    int n = A.size();
    // int sum = INT_MIN;
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int top = i > 0 ? A[i-1][j] : 0;
            int left = j > 0 ? A[i][j-1] : 0;
            int topleft = (j > 0 && i > 0) ? A[i-1][j-1] : 0;
            A[i][j] = A[i][j] + top + left - topleft;
        }
    }
    int ans = INT_MIN;
    for(int i=B-1; i<n; i++){
        for(int j=B-1; j<n; j++){
            int top = i >= B ? A[i-B][j] : 0;
            int left = j >= B ? A[i][j-B] : 0;
            int topleft = (j >= B && i >= B) ? A[i-B][j-B] : 0;
            int s = A[i][j] - top - left + topleft;
            // cout<<i<<" "<<j<<" "<<A[i][j]<<" "<<top<<" "<<left<<" "<<topleft<<endl;
            ans = max(ans, s);
        }
    }
    return ans;
}

int bruteForce(vector<vector<int> > &A, int B) {
    int n = A.size();
    int sum = INT_MIN;
    for(int i=0; i+B<=n; i++){
        for(int j=0; j+B<=n; j++){
            int s = 0;
            for(int x=i; x<i+B; x++) {
                for(int y=j; y<j+B; y++) {
                    s += A[x][y];
                }
            }
            sum = max(sum, s);
        }
    }
    return sum;
}

int main() {
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>v[i][j];
        }
    }
    cout<<solve(v, 3)<<endl;
}
