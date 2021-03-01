// https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/xor-value-6dc9d9e4/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        unsigned long long n;
        cin>>n;
        vector<unsigned long long> v;
        for(unsigned long long i=0; i<n; i++){
            unsigned long long ele;
            cin>>ele;
            v.push_back(ele);
        }
        unsigned long long ans = 0;
        for(unsigned long long i=0; i<64; i++){
            unsigned long long z = 0, o = 0;
            for(unsigned long long j=0; j<n; j++) {
                if(v[j]&(1)) o++;
                else z++;
                v[j] = v[j]>>1;
            }
            if(o>z)
            ans = ans + ((1LL)<<(i));
        }
        cout<<ans<<endl;
    }
}