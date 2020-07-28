#include<bits/stdc++.h>
using namespace std;

int diffPossible(vector<int> &A, int B) {
    int i = 0, j = 1;
    if(A.size()==1)
    return 0;
    while(j<A.size() && i<j) {
        if(abs(A[i]-A[j]) == abs(B) && i!=j) {
            return 1;
        } else if(abs(A[i]-A[j]) < abs(B)) {
            j++;
        } else {
            i++;
            j = i+1;
        }
    }
    return 0;
}


int main (){
    //code
    vector<int> v{0,2,4,8};
    // diffPossible(v,0);
    cout<<diffPossible(v,-8);
    return 0;
}
