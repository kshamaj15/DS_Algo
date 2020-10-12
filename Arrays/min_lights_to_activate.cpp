// https://www.interviewbit.com/problems/minimum-lights-to-activate/
// time - O(n)
// space - O(1)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int p = B-1;
    int n = A.size();
    int ans = 0;
    int lastIndex = INT_MIN;
    for(int i=0; i<n; i++) {
        if(A[i] == 1) {
            lastIndex = i;
            if(p==0) {
                ans++;
                p = 2*B-2;
            }
            else if(p > 0)
            p--;
        } else {
            p--;
            if(p<0 && lastIndex<0)
            return -1;
            else if(p < 0 && i-lastIndex <= 2*B-2) {
                p = 2*B - 2 - i + lastIndex;
                ans++;
            }
            else if (p<0 && i-lastIndex > 2*B-2) {
                return -1;
            }
        }
    }
    if(p < B-1 && n-lastIndex <= B)
    ans++;
    else if(p < B-1 && n-lastIndex > B)
    return -1;
    return ans;
    
}

int main() {
    vector<int> v{0,0,1,1};
    int b = 2;
    cout<<solve(v, b)<<endl;
}
