// https://www.interviewbit.com/problems/scramble-string/
// https://leetcode.com/problems/scramble-string/
// hard

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int solve(const string a, const string b) {
    if(a == b)
    return 1;
    
    if(a.size() != b.size())
    return 0;
    
    if(a == "" || b == "")
    return 0;
    
    string k = "";
    k += a + " " + b;
    if(mp.find(k) != mp.end())
    return mp[k];
    
    int ans = 0;
    int n = a.size();
    for(int i=1; i<n; i++) {
        if((solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i)))
        || solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i))) {
            ans = 1;
            break;
        }
    }
    mp[k] = ans;
    return ans;
}

int isScramble(const string A, const string B) {
    if(A.size() != B.size())
    return 0;
    
    if(A == "" && B == "")
    return 1;
    
    return solve(A, B);
}

int main() {
	    string a, b;
	    cin>>a>>b;
	    cout<<isScramble(a, b)<<endl;
	return 0;
}