#include<bits/stdc++.h>
using namespace std;

int sqrt(int A) {
    long long int start = 0, end = A, mid = A/2;
    long long int x = 100;
    if(A==0 || A==1){
        return A;
    }
    while(mid != end) {
        if(mid*mid <= A && (mid+1)*(mid+1) > A) {
            return mid;
        } else if (mid*mid > A) {
            end = mid;
            mid = (end - start)/2 + 1 + start;
        } else if (mid*mid < A){
            start = mid;
            mid = (end - start)/2 + 1 + start;
        }
    }
    return mid - 1;
}


int main (){

    cout<<sqrt(740819855);
    //code
    return 0;
}
