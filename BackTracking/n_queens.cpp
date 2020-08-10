#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>> &position, int row, int col, int n) {
    int i, j; 
    for(i=0; i<row; i++) {
        if(position[i][col] == 'Q')
        return false;
    }

    if(row > 0 && col > 0) {
        i = row-1, j=col-1;
        while(i>=0 && j >=0) {
            if(position[i][j] == 'Q')
            return false;
            i--;j--;
        }
    }

    if(row > 0 && col < n-1) {
        i = row-1, j=col+1;
        while(i>=0 && j <= n-1) {
            if(position[i][j] == 'Q')
            return false;
            i--;j++;
        }
    }
    
    return true; 
}

void getQuuensPositions(int n, int row, int col, vector<vector<char>> &position, vector<vector<vector<char>>> &ans) {
    if(row == n) {
        ans.push_back(position);
        col = n;
    }
    for(int i=col; i<n; i++) {
        position[row][i] = 'Q';
        if(isSafe(position, row, i, n)) {
            getQuuensPositions(n, row+1, 0, position, ans);
        }
        position[row][i] = '.';
    }
}

vector<vector<vector<char>>> nQueens(int n) {
    vector<vector<vector<char>>> ans;
    vector<vector<char>> position(n, vector<char> (n,'.'));
    getQuuensPositions(n, 0, 0, position, ans);
    
    return ans;
}

int main (){
    //code
    vector<vector<vector<char>>> ans;
    ans = nQueens(10);
    for(auto v: ans) {
        for(auto el: v) {
            for(auto e: el) {
                cout<<e<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
