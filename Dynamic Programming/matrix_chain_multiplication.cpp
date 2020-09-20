#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &d, vector<vector<int>> &dp, int i, int j) {
    if(i >= j) {
        return 0;
    } 
    if(dp[i][j] != -1)
    return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k<j; k++) {
        int temp = minCost(d, dp, i, k) + minCost(d, dp, k+1, j) + d[i-1]*d[k]*d[j];
        dp[i][j] = temp;
        ans = min(ans, temp);
    }
    return ans;
}

int main() {
    vector<int> dimentions{1,3,4,5};
    int n = dimentions.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<endl;
    cout<<minCost(dimentions, dp, 1, 3);
    cout<<endl;
}