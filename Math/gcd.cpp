#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if(a>=b) {
        if(b == 0){
            return a;
        } else {
            return gcd(b, a-b);
        }
    } else {
        return gcd(b, a);
    }
}

int main (){
    cout<<gcd(3, 6);
    return 0;
}
