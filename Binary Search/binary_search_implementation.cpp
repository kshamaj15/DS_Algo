#include<bits/stdc++.h>
using namespace std;

int recursiveBinarySearch(vector<int> &A, int l, int r, int B) {
    if(l<=r) {
        int m = (r-l)/2+l;
        if(A[m] == B) {
            return m;
        }
        else if(A[m] < B)
        recursiveBinarySearch(A, m+1, r, B);
        else
        recursiveBinarySearch(A, l, m-1, B);
    } else {
        return -1;
    }
}

int interativeBinarySearch(vector<int> &A, int l, int r, int B) {
    while (l<=r)
    {
        /* code */
        int m = l + (r-l)/2;
        if(A[m] == B)
        return m;
        else if(A[m] > B) {
            r = m-1;
        } else {
            l= m+1;
        }
    }
    return -1;
}

int main (){
    //code
    vector<int> A{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<recursiveBinarySearch(A, 0, 8, 9)<<endl;
    cout<<interativeBinarySearch(A, 0, 8, 1);
    return 0;
}
