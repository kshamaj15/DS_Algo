// https://practice.geeksforgeeks.org/problems/boolean-parenthesization/0
// https://www.interviewbit.com/problems/evaluate-expression-to-true/
// on gfg (hard): TLE
// on Interviewbit: working fine

#include <bits/stdc++.h>
using namespace std;

int getCount(string s, int i, int j, vector<vector<int>> &dpT, vector<vector<int>> &dpF, bool isTrue) {
    if(isTrue && dpT[i][j] != -1)
    return dpT[i][j];
    
    if(!isTrue && dpF[i][j] != -1)
    return dpF[i][j];
    
    if(i == j) {
        if(isTrue)
        return s[i] == 'T';
        else
        return s[i] == 'F';
    }
    
    int ans = 0;
    for(int k=i; k<j-1; k++) {
        
        if(dpT[i][k] == -1)
        dpT[i][k] = getCount(s, i, k, dpT, dpF, true);
        int lt = (dpT[i][k]);
        
        if(dpF[i][k] == -1)
        dpF[i][k] = getCount(s, i, k, dpT, dpF, false);
        int lf = (dpF[i][k]);
        
        if(dpT[k+2][j] == -1)
        dpT[k+2][j] = getCount(s, k+2, j, dpT, dpF, true);
        int rt = (dpT[k+2][j]);
        
        if(dpF[k+2][j] == -1)
        dpF[k+2][j] = getCount(s, k+2, j, dpT, dpF, false);
        int rf = (dpF[k+2][j]);
        
        if(s[k+1] == '|') {
            if(isTrue) {
                dpT[i][j] = (lt*rf + lt*rt + lf*rt)%1003;
                ans += dpT[i][j];
            } else {
                dpF[i][j] = (lf*rf)%1003;
                ans += dpF[i][j];
            }
        } else if(s[k+1] == '&') {
            if(isTrue) {
                dpT[i][j] = (lt*rt)%1003;
                ans += dpT[i][j];
            } else {
                dpF[i][j] = (lt*rf + lf*rf + lf*rt)%1003;
                ans += dpF[i][j];
            }
        } else {
            if(isTrue) {
                dpT[i][j] = (lt*rf + lf*rt)%1003;
                ans += dpT[i][j];
            } else {
                dpF[i][j] = (lt*rt + lf*rf)%1003;
                ans += dpF[i][j];
            }
        }
        k++;
    }
    return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    string s;
	    cin>>n;
	    cin>>s;
	    vector<vector<int>> dpT(n+1, vector<int>(n+1, -1));
	    vector<vector<int>> dpF(n+1, vector<int>(n+1, -1));
	    cout<<(getCount(s, 0, n-1, dpT, dpF, true))%1003<<endl;
	} 
	return 0;
}