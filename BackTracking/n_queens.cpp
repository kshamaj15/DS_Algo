#include<bits/stdc++.h>
using namespace std;

// void getQuuensPositions(int n, int count, vector<vector<int>> &ans, int index, vector<int> &position) {
//     // cout<<count<<" ";
//     if(index == n) {
//     // if(position.size() == n) {
//         ans.push_back(position);
//         count = n;
//     }
//     // if(index == n) 
//     // index = 0;
//     for(int i=index; i<count; i++) {
//         position.push_back(i);
//         // if(i+1 == n && position.size() < n) {
//         //     if(position.size() < n && i+1 == n) {
//         //         index = -1;
//         //         count = count - position.size();
//         //         // continue;
//         //     }
//         // }
//         getQuuensPositions(n, count, ans, i+1, position);
//         position.pop_back();
//     }
// }

bool isSafe(vector<vector<char>> &position, int row, int col, int n) {
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < row; i++) 
        if (position[i][col]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) 
        if (position[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row+1, j = col-1; j >= 0 && i < n; i++, j--) 
        if (position[i][j]) 
            return false; 

            // cout<<"a ";
    return true; 
}

void getUtilQueesn(vector<vector<char>> &position, int row, int col, int n, vector<vector<vector<char>>> &ans) {
    // cout<<row<<" r";
    if(row == n) {
        ans.push_back(position);
    }
    for(int i=row; i<n; i++) {
        for(int j=col; j<n; j++) {
            position[row][col] = 'Q';
            if(isSafe(position, row, col, n)) {
                getUtilQueesn(position, row+1, 0, n, ans);
                break;
            }
            position[row][i] = '.';
        }
    }
}

vector<vector<vector<char>>> nQueens(int n) {
    vector<vector<vector<char>>> ans;
    vector<vector<char>> position(n, vector<char> (n,'.'));
    getUtilQueesn(position, 0, 0, n, ans);
    
    return ans;
}

int main (){
    //code
    vector<vector<vector<char>>> ans;
    ans = nQueens(4);
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
