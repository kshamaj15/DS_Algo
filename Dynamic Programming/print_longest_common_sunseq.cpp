// dynamic programming
// hackerrank
// https://www.hackerrank.com/challenges/linkedin-practice-dynamic-programming-lcs/problem
// hard

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 5, b = 6;
    vector<int> v1{2,4,5,6,7};
    vector<int> v2{2,4,5,7,8,9};
    vector<vector<vector<int>>> dp(a+1, vector<vector<int>>(b+1));

    //top down
    for(int i=0; i<=a; i++) {
        vector<int> temp;
        dp[i][0] = temp;
    }
    for(int i=1; i<=b; i++) {
        vector<int> temp;
        dp[0][i] = temp;
    }
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            vector<int> temp;
            if(v1[i-1] == v2[j-1]) {
                temp = {dp[i-1][j-1].begin(), dp[i-1][j-1].end()};
                temp.push_back(v1[i-1]);
                dp[i][j] = temp;
            } else {
                if(dp[i-1][j].size() > dp[i][j-1].size())
                temp = dp[i-1][j];
                else
                temp = dp[i][j-1];
                dp[i][j] = temp;
            }
        }
    }
    for(int x=0; x<dp[a][b].size(); x++)
    cout<<dp[a][b][x]<<" ";
    return 0;
}
