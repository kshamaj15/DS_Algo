// https://practice.geeksforgeeks.org/problems/rod-cutting/0
// dynamic programming
// gfg
// easy

#include <bits/stdc++.h>
using namespace std;

int maxPrice(int index, int remainingLen, vector<int> &arr, vector<vector<int>> &dp) {
    if(index == 0 || remainingLen == 0) {
        return 0;
    }
    
    if(dp[index][remainingLen] != -1)
    return dp[index][remainingLen];
    
    if(index <= remainingLen) {
        dp[index][remainingLen] = max(arr[index-1] + 
        maxPrice(index, remainingLen-index, arr, dp),
        maxPrice(index-1, remainingLen, arr, dp));
        return dp[index][remainingLen];
    } else {
        dp[index][remainingLen] = maxPrice(index-1, remainingLen, arr, dp);
        return dp[index][remainingLen];
    }
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int j=0; j<n; j++) {
	        cin>>arr[j];
	    }
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    cout<<maxPrice(n, n, arr, dp)<<endl;
	} 
	return 0;
}