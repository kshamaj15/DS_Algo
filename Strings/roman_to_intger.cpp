#include<bits/stdc++.h>
using namespace std;

int romanToInt(string A) {
    int ans = 0;
    for(int i=A.size()-1; i>=0; i--) {
        if(A[i]=='I') {
            if(ans >= 5) 
            ans = ans - 1;
            else
            ans = ans + 1;
        } else if (A[i]=='V') {
            cout<<"v";
            if(ans >= 10)
            ans = ans - 5;
            else
            ans = ans + 5;
        } else if (A[i]=='X') {
            cout<<"x";
            if(ans >= 50)
            ans = ans - 10;
            else
            ans = ans + 10;
        } else if (A[i]=='L') {
            if(ans >= 100)
            ans = ans - 50;
            else
            ans = ans + 50;
        } else if (A[i]=='C') {
            if(ans >= 500)
            ans = ans - 100;
            else
            ans = ans + 100;
        } else if (A[i]=='D') {
            if(ans >= 1000)
            ans = ans - 500;
            else
            ans = ans + 500;
        } else if (A[i]=='M') {
            ans = ans + 1000;
        }
    }
    return ans;
}


int main (){
    //code

    cout<<romanToInt("IX");
    return 0;
}
