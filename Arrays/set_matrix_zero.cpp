// https://www.interviewbit.com/problems/set-matrix-zeros/

#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int> > &A) {
    int n, m;
    n = A.size();
    m = A[0].size();
    int firstRowZero = false;
    int firstColZero = false;
    for(int i=0; i<n; i++) {
        if(A[i][0] == 0) {
            firstRowZero = true;
            break;
        }
    }
    for(int i=0; i<m; i++) {
        if(A[0][i] == 0) {
            firstColZero = true;
            break;
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(A[i][j] == 0) {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(A[i][0] == 0 || A[0][j] == 0) {
                A[i][j] = 0;
            }
        }
    }
    if(firstRowZero) {
        for(int i=0; i<n; i++) {
            A[i][0] = 0;
        }
    } 
    if(firstColZero) {
        for(int i=0; i<m; i++) {
            A[0][i] = 0;
        }
    }
}


int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            cin>>v[i][j];
        }
    }
    setZeroes(v);
    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}