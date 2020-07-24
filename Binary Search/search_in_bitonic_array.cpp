#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B) {
    int s = 1;
    int e = A.size()-2;
    int index;
    while(s<=e) {
        int m = s+(e-s)/2;
        if(A[m]>A[m-1] && A[m]>A[m+1]) {
            index = m;
            break;
        } else if(A[m]>=A[m-1] && A[m]<=A[m+1]) {
            s = m+1;
        } else if(A[m]<=A[m-1] && A[m]>=A[m+1]) {
            e=m-1;
        }
    }
    if(A[index]==B)
    return index;
    if(A[0] <= B) {
        s=0;
        e=index-1;
        while(s<=e) {
            int m=s+(e-s)/2;
            if(A[m]==B)
            return m;
            else if(A[m]>B)
            e=m-1;
            else if(A[m]<B)
            s=m+1;
        }
    }
    if(A[A.size()-1] <= B) {
        s=index+1;
        e=A.size()-1;
        while(s<=e) {
            int m=s+(e-s)/2;
            if(A[m]==B)
            return m;
            else if(A[m]>B)
            s=m+1;
            else if(A[m]<B)
            e=m-1;
        }
    }
    return -1;
}


int main (){
    //code
    vector<int> v{1,2, 5,4,3};
    cout<<solve(v, 12);
    return 0;
}
