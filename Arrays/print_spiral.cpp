#include<iostream>
#include<vector>
using namespace std;

vector<int> spiralOrder(const vector<vector<int> > &A) {
    int rowEnd = A.size()-1;//2
    int colEnd = A[0].size()-1;//0
    int rowStart = 0;
    int colStart = 0;
    vector<int> ans;
    while (colStart <= colEnd && rowEnd >= rowStart) {
        for(int i=colStart; i<=colEnd; i++) {
            ans.push_back(A[rowStart][i]);
        }
        rowStart++;
        for(int i=rowStart; i<=rowEnd; i++) {
            ans.push_back(A[i][colEnd]);
        }
        colEnd--;
        
        if(colStart <= colEnd && rowEnd >= rowStart)
        for(int i=colEnd; i>=colStart; i--) {
            ans.push_back(A[rowEnd][i]);
        }
        rowEnd--;

        if(colStart <= colEnd && rowEnd >= rowStart)
        for(int i=rowEnd; i>=rowStart; i--) {
            ans.push_back(A[i][colStart]);
        }
        colStart++;
    }
    
    return ans;
}

int main() {
    vector<vector<int>> a({{1}, {2}, {3}});
    vector<int> ans = spiralOrder(a);
    for(auto i: ans) {
        cout<<i<<" ";
    }
    return 0;
}
