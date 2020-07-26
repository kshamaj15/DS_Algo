#include<bits/stdc++.h>
using namespace std;

void multiply(string *a, int n) {
    int carry = 0;
    for(int i=(*a).size()-1; i>=0; i--) {
        int temp  = (int)((*a)[i])-48;
        (*a)[i] = (char)((temp*n + carry)%10+48);
        carry = ((temp)*n + carry)/10;
    }
    if(carry != 0) {
        (*a) = to_string(carry) + (*a);
    }
}

string solve(int A) {
    string ans = "1";
    if(A==0 || A==1)
    return ans;
    else {
        while(A>1) {
            multiply(&ans, A);
            A--;
        }
        return ans;
    }
    // multiply(&ans, 100);
    return ans;
}

// string solve(int A) {
//     long long int ans = 1;
//     string n = "sa";
//     multiply(&n);
//     cout<<n<<" ";
//     if(A==0 || A==1)
//     return "1";
//     else {
//         while(A>1) {
//             ans = ans*A;
//             A--;
//         }
//         return to_string(ans);
//     }
// }


int main (){
    //code
    cout<<solve(10);
    return 0;
}
