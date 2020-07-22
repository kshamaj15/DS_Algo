#include<bits/stdc++.h>
using namespace std;

int searchMatrix(vector<vector<int> > &A, int B) {
    int n=A.size();
    int m = A[0].size();
    int l=0, r=n*m-1;
    
    while(l<=r) {
        int mid = l+(r-l)/2;
        int i = mid/m, j=mid%m;
        if(A[i][j] == B) {
            return mid;
        } else if(A[i][j] > B) {
            r = mid-1;
        } else {
            l=mid+1;
        }
    }
    return 0;
}

int main (){
    //code
    vector<vector<int>> v{{1,2,3},{4,5,6}};
    cout<<searchMatrix(v,5);
    return 0;
}
