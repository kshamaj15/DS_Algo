#include<bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d) {
    if(d==1)
    return 0;
    if(n==0)
    return 1;
    int n1 = n;
    long long ans;
    long long mul = x;
    while(n1/2 != 0) {
        mul = mul*mul;
        n1 = n1/2;
        mul = mul%d;
    }
    n1--;
    while(n1--) {
        mul = mul*x;
        mul = mul%d;
    }
    if(mul%d < 0)
    ans = mul%d + d;
    else
    ans = mul%d;
    return (int)ans;
}


int main (){
    //code
    // cout<<pow(71045970,41535484,64735492);
    cout<<pow(7,8,10);
    return 0;
}
