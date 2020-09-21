// https://www.interviewbit.com/problems/palindrome-partitioning-ii
// interviewbit
// dp - MCM
// hard

#include <bits/stdc++.h>
using namespace std;

bool isThere(string str, vector<string> &B, int i, int j) {
    string r = str.substr(i, j-i+1);
    for(int x=0; x<B.size(); x++) {
        cout<<r<<" "<<B[x]<<endl;
        if(B[x] == r)
        return true;
    }
    return false;
}

bool isPalindrome(string str, int i, int j)
    {
        while(i <= j) {
            if(str[i] != str[j])
            return false;
            i++;j--;
        }
        return true;
    }
    int getMinNumberOfPartitions(string str, vector<vector<int>> &dp, int i, int j)
    {
        if(isPalindrome(str, i, j))
        return 0;
        
        if(dp[i][j] != -1)
        return dp[i][j];
        
        int minValue = INT_MAX;
        for(int k=i; k<j; k++) {
            int left, right;
            
            if(dp[i][k] == -1)
            dp[i][k] = getMinNumberOfPartitions(str, dp, i, k);
            
            
            if(dp[k+1][j] == -1)
            dp[k+1][j] = getMinNumberOfPartitions(str, dp, k+1, j);
            
            dp[i][j] = dp[i][k] + dp[k+1][j] + 1;
            minValue = min(minValue, dp[i][j]);
        }
        return minValue;
    }
    int palindromicPartition(string str)
    {
        int i=0;
        int j=str.size()-1;
        vector<vector<int>> dp(j+1, vector<int>(j+1, -1));
        return getMinNumberOfPartitions(str, dp, i, j);
    }

int main() {
    string s;
    // cout<<endl<<"Please Enter the String"<<endl;
    // cin>>s;
    cout<<endl;
    // cout<<palindromicPartition(s);
    string str = "myinterviewtrainer";
    vector<string> B{"trainer", "my", "interview"};
    cout<<isThere(str, B, 0, 1)<<endl;
    cout<<endl;
}