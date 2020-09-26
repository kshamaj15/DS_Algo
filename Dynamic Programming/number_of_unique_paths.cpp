// https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0/?category[]=Dynamic%20Programming&problemStatus=solved&page=1&query=category[]Dynamic%20ProgrammingproblemStatussolvedpage1
// easy

#include <bits/stdc++.h>
using namespace std;

int countUniquePath(int m, int n, vector<vector<int>> &dp) {
    if(m==0 || n==0)
    return 1;
    
    if(m<0 || n<0)
    return 1;
    
    if(dp[m][n] != -1)
    return dp[m][n];
    if(dp[m-1][n] == -1)
    dp[m-1][n] = countUniquePath(m-1, n, dp);
    if(dp[m][n-1] == -1)
    dp[m][n-1] = countUniquePath(m, n-1, dp);
    dp[m][n] = dp[m-1][n] + dp[m][n-1];
    return dp[m][n];
}

int main() {
	    int m, n;
	    cin>>m>>n;
	    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
	    for(int i=0; i<=n; i++)
	    dp[0][i] = 1;
	    for(int i=0; i<=m; i++)
	    dp[i][0] = 1;
	    for(int i=1; i<=n; i++) {
	        for(int j=1; j<=m; j++) {
	            dp[j][i] = dp[j][i-1] + dp[j-1][i];
	        }
	    }
	    cout<<dp[m-1][n-1]<<endl;
}