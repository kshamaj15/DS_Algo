#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    // int ans=0;
    // int i;
    // bool matched = true;
    // for(i=A.size()-1; i>0; i--) {
    //     matched = true;
    //     int start = 0;
    //     int end = i;
    //     while(end>=start) {
    //         if(A[start] != A[end]) {
    //             matched = false;
    //             break;
    //         }
    //         end--;
    //         start++;
    //     }
    //     if(matched) {
    //         break;
    //     }
    //     ans++;
    // }
    // return ans;
    int ans = 0;
    bool isSame;
    int start = 0;
    for(int i=0; i<A.size(); i++) {
        if(i>0) {
            isSame = A[A.size()-i-2] == A[A.size()-i-1];
        }
        if(A[A.size()-i-1] != A[start]) {
            cout<<i<<" "<<A.size()-i-1<<" "<<start<<" "<<A[A.size()-i-1]<<" "<<A[start]<<endl;
            if(isSame) {
                ans++;
                start--;
            }
            else {
                ans = i+1;
                start = start - i;
            }
        }
        start++;
    }
    return ans;
}


int main (){
    //code

    cout<<solve("AACECAAAA");
    return 0;
}
