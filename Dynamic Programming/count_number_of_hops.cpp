// https://practice.geeksforgeeks.org/problems/count-number-of-hops/0/?category[]=Dynamic%20Programming&problemStatus=unsolved&difficulty[]=0&page=1&query=category[]Dynamic%20ProgrammingproblemStatusunsolveddifficulty[]0page1
// v easy

#include <bits/stdc++.h>
using namespace std;

int countWays(int dist, vector<int> &dp) {
    
    // Base cases 
    if (dist<0)      return 0; 
    if (dist==0)  return 1; 

    if(dp[dist] != -1)
    return dp[dist];
  
    // Recur for all previous 3 and add the results 
    dp[dist] = countWays(dist-1, dp) + 
           countWays(dist-2, dp) + 
           countWays(dist-3, dp);
           
    return dp[dist];
}

int main() {
	int n;
	cin>>n;
	vector<int> dp(51, -1);
	cout<<countWays(n, dp)<<endl;
}