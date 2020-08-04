#include<bits/stdc++.h>
using namespace std;

int divide(int A, int B) {
    int sign = (A>0)^(B>0) ? -1:1;
    A = abs(A);
    B = abs(B);
    int ans = 0;
    while(A>=B) {
        A -= B;
        ++ans;
    }
    return sign*ans;
}


int main (){
    //code
    cout<<divide(-214748648, -1);
    return 0;
}
