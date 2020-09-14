#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    long long int count(int S[], int n, int m )
    {
        vector<vector<long long int>> dp(n+1, vector<long long int>(m+1, -1));
       return getWays(S, m, n, dp);
    }
    long long int getWays(int S[], int m, int n, vector<vector<long long int>> &dp) {
        
        if(m==0)
        return 1;
        
        if(n==0)
        return 0;
        
        if(dp[n][m] != -1)
        return dp[n][m];
        
        if(S[n-1] <= m) {
            dp[n][m] = getWays(S, m-S[n-1], n, dp) + getWays(S, m, n-1, dp);
            return dp[n][m];
        } else {
            dp[n][m] = getWays(S, m, n-1, dp);
            return dp[n][m];
        }
    }
};



int main() {
	//code
	int t;
	cin>>t;
	while(t--) {
	    int n, m;
	    cin>>m>>n;
	    int arr[n];
	    for(int j=0; j<n; j++) {
	        cin>>arr[j];
	    }
	    cout<<count(arr, n, m)<<endl;
	} 
	return 0;
}