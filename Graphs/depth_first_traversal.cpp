// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// easy
// DFS

#include<bits/stdc++.h>
using namespace std; 

void getDfs(vector<int> &ans, vector<int>  g[], vector<bool> &isVisited, int v) {
    ans.push_back(v);
    isVisited[v] = true;
    for(int i=0; i<g[v].size(); i++) {
        if(!isVisited[g[v][i]])
        getDfs(ans, g, isVisited, g[v][i]);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<bool> isVisited(N, false);
    vector<int> ans;
    getDfs(ans, g, isVisited, 0);
    return ans;
}

int main() 
{ 
    
} 