// https://practice.geeksforgeeks.org/problems/number-of-ways2552/1/?category[]=Dynamic%20Programming&problemStatus=solved&page=1&query=category[]Dynamic%20ProgrammingproblemStatussolvedpage1
// Medium

#include <bits/stdc++.h>
using namespace std;

long long arrangeTiles(int n, vector<long long> &dp){
    if(n < 4)
        return 1; 
        
    if(n < 0)
        return 0;
        
    if(dp[n] != -1)
        return dp[n];
        
    if(n >= 4) {
        dp[n] = arrangeTiles(n-4, dp) + arrangeTiles(n-1, dp);
        return dp[n];
    }
}

int main() {
	int n;
	cin>>n;
	vector<long long> dp(101, -1);
	cout<<arrangeTiles(n, dp)<<endl;
}