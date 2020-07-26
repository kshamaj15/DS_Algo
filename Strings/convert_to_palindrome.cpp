#include<bits/stdc++.h>
using namespace std;

int solve(string A) {
    bool removed = false;
    int start = 0;
    int end = A.size()-1;
    while(start<=A.size()/2) {
        cout<<start<<" "<<end<<endl;
        if(A[start] != A[end]) {
            if(removed)
            return 0;
            else {
                if(A[start+1] == A[end]) {
                    start++;
                }
                else if(A[start] == A[end-1]) {
                    end--;
                } else {
                    return 0;
                }
                removed = true;
            }
        }
        cout<<start<<" "<<end<<endl;
        start++;
        end--;
    }
    if(removed || A.size()%2 == 1)
    return 1;
    return 0;
}


int main (){
    //code
    cout<<solve("mnwnn");
    return 0;
}
