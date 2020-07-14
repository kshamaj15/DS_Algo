#include<bits/stdc++.h>
using namespace std;

void generateMatrix(int A) {
    vector<vector<int> > arr( A , vector<int> (A));
    int dir = 0;
    int erow = A-1, ecol = A-1;
    int srow = 0, scol = 0;
    int r = 0, c = 0;
    for(int i=1; i<=A*A; i++) {
        if(dir == 0) {
            if(c < ecol) {
                arr[r][c] = i;
                c++;
            }
            else {
                arr[r][c] = i;
                dir++;
                r++;
                srow++;;
            }
        } else if(dir == 1) {
            if(r < erow) {
                arr[r][c] = i;
                r++;
            } else {
                arr[r][c] = i; 
                dir++;
                c--;
                ecol--;
            }
        } else if(dir == 2) {
            if(c > scol) {
                arr[r][c] = i;
                if(c > scol)
                c--;
            } else {
                arr[r][c] = i;
                dir++;
                r--;
                erow--;
            }
        } else {
           if(r > srow) {
                arr[r][c] = i;
                if(r > srow)
                r--;
            } else {
                arr[r][c] = i;
                dir = 0;
                c++;
                scol++;
            } 
        }
    }
    for(auto el:arr) {
        for(auto i:el) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main (){
    //code
    generateMatrix(10);
    return 0;
}
