// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0#:~:text=The%20first%20line%20of%20each,case%20in%20a%20new%20line.
// dynamic programming
// gfg
// easy

#include <bits/stdc++.h>
using namespace std;

int main() {
        cout<<"Please Enter the string"<<endl;
	    string s;
	    cin>>s;
	    string rs = s; 
	    int n = s.size();
	    
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    for(int i=0; i<=n; i++) {
	        dp[0][i] = 0;
	        dp[i][0] = 0;
	    }
	    
	    for(int i=1; i<=n; i++) {
	        for(int j=1; j<=n; j++) {
	            if(s[i-1] == rs[j-1] && i != j) {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            } else {
	                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
	            }
	        }
	    }
	    cout<<dp[n][n]<<endl;
	return 0;
}