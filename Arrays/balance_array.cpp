// https://www.interviewbit.com/problems/balance-array/
// space compexity = O(n) ---- NEED TO OPTIMIZE
// time compexity = O(n)

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {
    int n = A.size();
    vector<int> leftodd;
    vector<int> lefteven;
    vector<int> rightodd(n);
    vector<int> righteven(n);
    
    int sumOdd = 0;
    int sumEven = 0;
    for(int i=0; i<A.size(); i++) {
        leftodd.push_back(sumOdd);
        lefteven.push_back(sumEven);
        if(i%2) 
        sumOdd += A[i];
        else
        sumEven += A[i];
    }
    
    sumOdd = 0;
    sumEven = 0;
    for(int i=A.size()-1; i>=0; i--) {
        rightodd[i] = sumOdd;
        righteven[i] = sumEven;
        if(i%2) 
        sumOdd += A[i];
        else
        sumEven += A[i];
    }
    
    int ans = 0;
    for(int i=0; i<A.size(); i++) {
        if(leftodd[i] + righteven[i] == lefteven[i] + rightodd[i])
        ans++;
    }
    return ans;
}

int main() {
    vector<int> v{2,3,2,1,1};
    cout<<solve(v)<<endl;
}
