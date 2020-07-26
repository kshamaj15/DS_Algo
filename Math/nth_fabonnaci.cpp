#include<bits/stdc++.h>
using namespace std;

int solve(int A) {
    if(A==0 || A==1)
    return A;
    long long int prev = 0;
    long long int curr = 1;
    while(A>1) {
        long long int temp = curr%1000000009;
        curr = (curr + prev)%1000000009;
        prev = temp%1000000009;
        A--;
        cout<<prev<<" "<<curr<<endl;
    }
    return curr;
}


int main (){
    //code
    cout<<solve(40);
    return 0;
}
