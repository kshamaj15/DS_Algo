// https://www.interviewbit.com/problems/reverse-integer/
// time: O(n)
// space: O(1)

#include<bits/stdc++.h>
using namespace std;

int reverse(int A) {
    long long int newA = 0;
    int prod = 10;
    bool isNeg = A < 0 ? true : false;
    A = abs(A);
    while(A > 0) {
        newA = newA*prod + A%10;
        A = A/10;
        prod = prod;
    }
    if(isNeg)
    newA = -1*newA;
    if(newA > INT_MAX || newA < INT_MIN)
    return 0;
    return (int)newA;
}


int main() {
    int n=-1146467285;
    cout<<reverse(n)<<endl;
}