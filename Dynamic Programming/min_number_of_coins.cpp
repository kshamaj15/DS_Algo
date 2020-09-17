// dynamic programming
// gfg
// https://practice.geeksforgeeks.org/problems/number-of-coins/0
// medium

#include <bits/stdc++.h>
using namespace std;

int main() {
	    int a = 6;
        vector<int> coins{5,2,9,4,7,1};
        int b = 65;
	    vector<vector<int>> dp(a+1, vector<int>(b+1, -1));

        // top down
	   for(int i=0; i<=a; i++) {
	       dp[i][0] = 0;
	   }
	   for(int i=0; i<=b; i++) {
	       dp[0][i] = INT_MAX - 1;
	   }
	   for(int i=1; i<=a; i++) {
	       for(int j=1; j<=b; j++) {
	           if(coins[i-1] <= j) {
	                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
	            } else {
	                dp[i][j] = dp[i-1][j];
	            }
	       }
	   }
       if(dp[a][b] == INT_MAX - 1)
       cout<< -1<<endl;
       else
	   cout<<dp[a][b]<<endl;
}