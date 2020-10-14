// https://www.interviewbit.com/problems/majority-element/
// moore voting algorithm

#include<bits/stdc++.h>
using namespace std;

int majorityElement(const vector<int> &A) {
    int n = A.size();
    int c=0;
    int me;
    for(int i=0; i<n; i++) {
        if(A[i] == me) {
            c++;
        } else if(c==0) {
            c++;
            me = A[i];
        } else {
            c--;
        }
    }
    c=0;
    for(int i=0; i<n; i++) {
        if(A[i] == me) {
            c++;
        }
    }
    if(c > n/2)
    return me;
    return -1;
}


int main() {
    vector<int> v{5,4,2,5,5};
    cout<<majorityElement(v)<<endl;
}