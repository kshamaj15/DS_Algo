// https://www.interviewbit.com/problems/rotate-matrix/

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &arr) {
    int n = arr.size();
    for(int i=0; i< n/2; i++) {
        for(int j=i;j<n-i-1;j++) {
            swap(arr[i][j], arr[j][n-1-i]);
            swap(arr[i][j], arr[n-1-i][n-1-j]);
            swap(arr[i][j], arr[n-j-1][i]);
        }
    }
}


int main() {
    int n;
    cin>>n;
    vector<vector<int>> A(n, vector<int>(n));
    for(int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            cin>>A[i][j];
        }
    }
    rotate(A);
    for(int i=0; i<n; i++) {
        for(int j=0;j<n;j++) {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}