// https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
// dynamic programming
// gfg
// medium

#include <bits/stdc++.h>
using namespace std;

int maxSubSeq(int a, int b, string s1, string s2, vector<vector<int>> &dp) {
    if(a==0 || b==0) {
        return 0;
    }
    if(dp[a][b] != -1){
        return dp[a][b];
    }
    if(s1[a-1] == s2[b-1]) {
        dp[a][b] = 1 + maxSubSeq(a-1, b-1, s1, s2, dp);
        return dp[a][b];
    } else {
        dp[a][b] = max(maxSubSeq(a-1, b, s1, s2, dp), maxSubSeq(a, b-1, s1, s2, dp));
        return dp[a][b];
    }
}

int main() {
	    int a = 6, b = 6;
	    string s1 = "ABCDGH", s2 = "AEDFHR";
	    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));

        // memoization
	    // cout<<maxSubSeq(a, b, s1, s2, dp)<<endl;

        // top down
	   for(int i=0; i<=a; i++) {
	       dp[i][0] = 0;
	   }
	   for(int i=0; i<=b; i++) {
	       dp[0][i] = 0;
	   }
	   for(int i=1; i<=a; i++) {
	       for(int j=1; j<=b; j++) {
	           if(s1[i-1] == s2[j-1]) {
	               dp[i][j] = 1 + dp[i-1][j-1];
	           } else {
	               dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	           }
	       }
	   }
	   cout<<dp[a][b]<<endl;
}