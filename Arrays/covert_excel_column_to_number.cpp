#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int A) {
    string ans = "";
    while(A != 0) {
        if(A%26 != 0) {
            ans = (char)(A%26 + 64) + ans;
            A = A/26;
        } else {
            ans = (char)(26 + 64) + ans;
            A = A/26 - 1;
        }
    }
    return ans;
}

int main (){
    //code
    cout<<convertToTitle(943566);
    return 0;
}
