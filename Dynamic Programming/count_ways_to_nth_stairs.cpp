// https://practice.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter5639/1/?category[]=Dynamic%20Programming&problemStatus=solved&page=1&query=category[]Dynamic%20ProgrammingproblemStatussolvedpage1
// Medium

#include <bits/stdc++.h>
using namespace std;

int countWays(int n, int i, vector<vector<int>>& dp, vector<int> &steps) {
	    if(n==0)
	    return 1;
	    
	    if(i==0)
	    return 0;
	    
	    if(dp[i][n] != -1)
	    return dp[i][n];
	    
	    if(n >= steps[i-1]) {
	        dp[i][n] = countWays(n-steps[i-1], i, dp, steps) + countWays(n, i-1, dp, steps);
	        return dp[i][n];
	    } else {
	        dp[i][n] = countWays(n, i-1, dp, steps);
	        return dp[i][n];
	    }
	}

int main() {
	int n;
	cin>>n;

	vector<vector<int>> dp(3, vector<int>(n+1, -1));
	vector<int> steps{1,2};
    cout<<countWays(n, 2, dp, steps);
	return 0;
}