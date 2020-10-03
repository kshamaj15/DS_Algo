// https://practice.geeksforgeeks.org/problems/find-perimeter-of-shapes/1/?category[]=Geometric&page=1&query=category[]Geometricpage1
// easy

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int getperi(int mat[MAX][MAX], int i, int j, int n, int m) {
    // corner check
    if(i==0 && j==0) {
        int peri = 2;
        if(mat[1][0] == 0)
        peri++;
        if(mat[0][1] == 0)
        peri++;
        return peri;
    } else if(i==0 && j==m-1) {
        int peri = 2;
        if(mat[1][m-1] == 0)
        peri++;
        if(mat[0][m-2] == 0)
        peri++;
        return peri;
    } else if(i==n-1 && j==0) {
        int peri = 2;
        if(mat[n-1][1] == 0)
        peri++;
        if(mat[n-2][0] == 0)
        peri++;
        return peri;
    } else if(i==n-1 && j==m-1) {
        int peri = 2;
        if(mat[n-1][m-2] == 0)
        peri++;
        if(mat[n-2][m-1] == 0)
        peri++;
        return peri;
    } else if(i==0) {
        int peri = 1;
        if(mat[0][j-1] == 0)
        peri++;
        if(mat[0][j+1] == 0)
        peri++;
        if(mat[1][j] == 0)
        peri++;
        return peri;
    } else if(i==n-1) {
        int peri = 1;
        if(mat[n-1][j-1] == 0)
        peri++;
        if(mat[n-1][j+1] == 0)
        peri++;
        if(mat[n-2][j] == 0)
        peri++;
        return peri;
    } else if(j==0) {
        int peri = 1;
        if(mat[i-1][0] == 0)
        peri++;
        if(mat[i+1][0] == 0)
        peri++;
        if(mat[i][1] == 0)
        peri++;
        return peri;
    } else if(j==m-1) {
        int peri = 1;
        if(mat[i-1][m-1] == 0)
        peri++;
        if(mat[i+1][m-1] == 0)
        peri++;
        if(mat[i][m-2] == 0)
        peri++;
        return peri;
    } else {
        int peri = 0;
        if(mat[i][j-1] == 0)
        peri++;
        if(mat[i][j+1] == 0)
        peri++;
        if(mat[i-1][j] == 0)
        peri++;
        if(mat[i+1][j] == 0)
        peri++;
        return peri;
    }
}

int findPerimeter(int mat[MAX][MAX], int n, int m)
{
    //Your code here
    int p = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 1) {
                p += getperi(mat, i, j, n, m);
            }
        }
    }
    return p;
}

int main() {
    int n, m;
    cin>>n>>m;
    int ma[MAX][MAX];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>ma[i][j];
        }
    }
    cout<<findPerimeter(ma, n, m)<<endl;
}