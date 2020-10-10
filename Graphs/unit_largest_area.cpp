// https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s/0/?category[]=DFS&category[]=BFS&page=1&query=category[]DFScategory[]BFSpage1
// medium

#include <bits/stdc++.h>
using namespace std;

int findArea(vector<vector<int>> &mat, vector<vector<bool>> &isVisited, int i, int j) {
    if(i < 0 || i >= mat.size() || j < 0 || j>= mat[0].size())
    return 0;
    
    if(isVisited[i][j])
    return 0;
    
    isVisited[i][j] = true;
    
    if(mat[i][j] == 0)
    return 0;
    
	return (1 + findArea(mat, isVisited, i-1, j) +
	findArea(mat, isVisited, i, j-1) +
	findArea(mat, isVisited, i+1, j) +
	findArea(mat, isVisited, i, j+1) +
	findArea(mat, isVisited, i-1, j-1) + 
	findArea(mat, isVisited, i-1, j+1) +
	findArea(mat, isVisited, i+1, j+1) +
	findArea(mat, isVisited, i+1, j-1));
}
int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n, m;
	    int mx = 0;
	    cin>>n>>m;
	    vector<vector<int>> mat(n, vector<int>(m));
	    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<m; j++) {
                cout<<isVisited[i][j]<<endl;
	            if(!isVisited[i][j])
	            mx = max(mx, findArea(mat, isVisited, i, j));
	        }
	    }
	    cout<<mx<<endl;
    }
}