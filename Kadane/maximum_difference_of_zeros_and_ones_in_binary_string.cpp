// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1/?category[]=Kadane&page=1&query=category[]Kadanepage1
// easy

#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string s)
	{
	    // Your code goes here
	    int n = s.size();
	    vector<int> dp(n, -1);
	    
	    //
	    for(int i=0; i<n; i++) {
	        if(s[i] == '0') {
	            dp[i] = 1;
	        }
	    }
	    
	    int ans = 0;
	    int fans = 0;
	    for(int i=0; i<n; i++) {
	        ans += dp[i];
	        if(ans < 0)
	        ans = 0;
	        fans = max(ans, fans);
	    }
	    
	    return fans;
	}

    int main() {
        string s = "11000010001";
        cout<<maxSubstring(s)<<endl;
    }