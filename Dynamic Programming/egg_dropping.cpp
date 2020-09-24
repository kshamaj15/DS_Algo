// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
// gfg - medium
// NEED TO OPTIMIZE MORE : TLE ON IB
// https://www.interviewbit.com/problems/egg-drop-problem/

#include <bits/stdc++.h>
using namespace std;

int getMinAttemts(int e, int f, vector<vector<int>> &dp) {
    if(dp[e][f] != -1)
    return dp[e][f];
    
    if(e == 0) {
        return INT_MAX;
    }
    if(e == 1) {
        return f;
    }
    if(f <= 1) {
        return f;
    }
    
    int ans = INT_MAX;
    for(int k=1; k<=f; k++){
        if(dp[e-1][k-1] == -1)
        dp[e-1][k-1] = getMinAttemts(e-1, k-1, dp);
        
        if(dp[e][f-k] == -1)
        dp[e][f-k] = getMinAttemts(e, f-k, dp);
        
        int temp = 1 + max(dp[e-1][k-1], dp[e][f-k]);
        ans = min(ans, temp);
    }
    dp[e][f] = ans;
    return ans;
}

int main() {
	int t;
	cin>>t;
	vector<vector<int>> dp(101, vector<int>(101, -1));
	while(t--) {
	    int e, f;
	    cin>>e>>f;
	    cout<<getMinAttemts(e, f, dp)<<endl;
	} 
	return 0;
}