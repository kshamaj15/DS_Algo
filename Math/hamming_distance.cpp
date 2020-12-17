// https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
// time: O(32*n)
// space O(1)

#include<bits/stdc++.h>
using namespace std;

int hammingDistance(const vector<int> &B) {
    long long int mod = 1000000007;
    long long int sum = 0;
    long long int rem = 1;
    for(long long int i=0; i<32; i++) {
        long long int x=0, y=0;
        for(long long int j=0; j<B.size(); j++) {
            if(B[j]/rem > 0) {
                if((B[j]/rem)%2 == 1) x++;
                else y++;
                x = x%mod; 
                y = y%mod;
            } else if(B[j]/rem == 0) {
                y++;
            }
        }
        sum = (sum + 2*((x*y)%mod)%mod)%mod;
        rem = 2*rem;
    }
    return (int)sum;
}


int main() {
    vector<int> v{2,4,6};
    cout<<hammingDistance(v)<<endl;
}
