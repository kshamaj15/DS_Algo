// https://www.interviewbit.com/problems/word-break/
// interviewbit
// dp - MCM
// hard
// in progress: This is not the most optimum solution

#include <bits/stdc++.h>
using namespace std;

bool isThere(string str, vector<string> &B, int i, int j, unordered_set <string> &stringSet) {
    string r = str.substr(i, j-i+1);
    if(stringSet.find(r) != stringSet.end())
    return true;
    for(int x=0; x<B.size(); x++) {
        if(B[x] == r) {
            stringSet.insert(r);
            return true;
        }
    }
    return false;
}

int solve(string str, vector<string> &B, vector<vector<int>> &dp, int i, int j, unordered_set <string> &stringSet) {
    if(dp[i][j] != -1)
    return dp[i][j];
    
    if(i == j && !isThere(str, B, i, j, stringSet))
    return 0;
    
    if(j-i+1 <=20) {
        if(isThere(str, B, i, j, stringSet))
        return 1;
    }
    
    int maxV = 0;
    for(int k=i; k<j; k++) {
            
            if(dp[i][k] == -1)
            dp[i][k] = solve(str, B, dp, i, k, stringSet);
            
            
            if(dp[k+1][j] == -1)
            dp[k+1][j] = solve(str, B, dp, k+1, j, stringSet);
            
            dp[i][j] = dp[i][k] * dp[k+1][j];
            maxV = max(maxV, dp[i][j]);
    }
    return maxV;
}

int wordBreak(string str, vector<string> &B) {
    int i=0;
    int j=str.size()-1;
    unordered_set <string> stringSet; 
    vector<vector<int>> dp(j+1, vector<int>(j+1, -1));
    return solve(str, B, dp, i, j, stringSet);
}


int main() {
    string str = "bbabababaabbbabbaabaabbaabbbbbaaaaaaaaaabbaaabbabaababaabaabaabbbababbabbbbaaabbbbbbbabaaabbaababbabaabbbabbbaababbabababbabaabbabbaabbbabbbbbbbabaabbbbbbabbabbaabbababbabaaaaabbbbaaabbbaabbbbbaabbbbaabaaabbbbbbbbbaaabaabaabaababbabbaaabbabbbaaababbababbabaabaababbbbbaabbbababbabaaabaabbaababbbaaaaabbbabbaaaababbbbaaabbaabaaabbaaaaabbbabaabaabaabbbbbbaaaabbababbabaaabbabbaaababababbaabbaabbbbbabbabbbabbaababaabbbbbbbaaababbbbabaaabbabbbabaaaaaaaaababbaaaaaaaaabbbabbbbbabbbbaabbababaaabaabbaaabbbabbaababbbababbaabbbabbabbbbaaaabababababbbabaaababbaaaaabbbbbbababbabaabbaabbbbaaabbbaaabaaaaababbbaaabbaaabaababbbabaaaaaaaabbbaabaababbbbaaababaaaaabbbabbbaaabbabaabbaaabaaabaababbbbaaabaababbabaaaababbaaaababbbbabaabbabababbaaaababaaaaaabaaaaabbaaaaaabbbbbbbababbbbbaabbbbbbbbbbabbbbaaabaaaaaababaabababaaabbbabbaaaabbaabbaababaaaabbabaababbabaaba";
    vector<string> B{"bba", "b", "baabbaa", "bab", "b", "bbaabaabbb", "abb", "aabbabba", "baaa", "abba", "babababbba", "a", "aabb", "baaabbbaa", "bbaaba", "abaababa", "abba", "b", "bbaababbb", "aaaab", "aba", "bbaabbab", "aaa", "bbbbbbb", "bbbbba", "abbabbbab", "aba", "aaaaabba", "bbaaab", "aaaabaaa", "abbaab", "abab", "bbbba", "ab", "abbbab", "abaaaaa", "aababbb", "abbaab", "aba", "aa", "bbaa", "bbab", "aababbbb", "bababaaa", "bbaabbbaa", "abaaabbaab", "b", "aabbaa", "babbbabba", "aba", "aaab", "aaabbbab", "ababa", "bbaabb", "bb", "b", "baaababaa", "b", "abbaa", "abbaba", "aababbab", "b", "baaababaab", "abba", "baaaaaa", "aaaaaaa", "aaabb", "abbbbaaa", "aaaabbaa", "bbbbab", "a", "aabaaaabba", "abba", "abababaaaa", "baabaabab", "bbaabb", "aaabbbbaa", "bbaaa", "bba", "abaaabba", "aabbbba", "aaabaaabbb", "aaaababa", "ababba", "abaababaa", "b", "bbbbabab", "bb", "b", "aab", "ab", "ababbbbbba", "bababaaa", "abbba"};
    cout<<wordBreak(str, B)<<endl;
    cout<<endl;
}