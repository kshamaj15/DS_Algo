#include<bits/stdc++.h>
using namespace std;

int main (){
    //code
    int row, col;
    cin>>row>>col;
    vector<vector<int> > mat( row , vector<int> (col));
    int dir = 0;
    int i =0, j=0;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin>>mat[i][j];
        }
    }
    cout<<mat[i][j]<<" ";
    for(int k=0 ;k<row*col-1; k++) {
        if(dir == 0) {
            j++;
            if(j < col) 
            cout<<mat[i][j]<<" ";
        } else if (dir == 1) {
            while(i<row-1 && j>=1) {
                i++; j--;
                cout<<mat[i][j]<<" ";
            }
        } else if(dir == 2) {
            i++;
            if(i < row) 
            cout<<mat[i][j]<<" ";
        } else {
            while(i>=1 && j<col-1) {
                i--; j++;
                cout<<mat[i][j]<<" ";
            }
        }
        dir = (dir+1)%4;
    }
    return 0;
}
