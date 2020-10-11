// https://www.interviewbit.com/problems/balance-array/
// space compexity = O(1) --- solve()
// space compexity = O(n) --- solve1()
// time compexity = O(n)

#include<bits/stdc++.h>
using namespace std;

// O(1) space and O(n) time
int solve(vector<int> &A) {
    int rodd = 0, reven = 0;
    for(int i=0; i<A.size(); i++) {
        if(i%2)
        rodd += A[i];
        else
        reven += A[i];
    }
    int ans = 0;
    int lodd = 0, leven = 0;
    for(int i=0; i<A.size(); i++) {
        if(i%2)
        rodd -= A[i];
        else
        reven -= A[i];
        
        if(leven + rodd == lodd + reven)
        ans++;
        
        if(i%2)
        lodd += A[i];
        else
        leven += A[i];
    }
    return ans;
}

// O(1) space and O(n) time
int solve1(vector<int> &A) {
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
    vector<int> v{2,1,6,4};
    cout<<solve(v)<<endl;
}
