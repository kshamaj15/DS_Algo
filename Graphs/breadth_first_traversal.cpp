// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// easy
// BFS

#include<bits/stdc++.h>
using namespace std; 

void getBfs(vector<int> &ans, vector<int>  g[], vector<bool> &isVisited, queue<int> &qu) {
    if(qu.empty())
    return;
    
    int v = qu.front();
    for(int i=0; i<g[v].size(); i++) {
        if(!isVisited[g[v][i]]) {
            ans.push_back(g[v][i]);
            isVisited[g[v][i]] = true;
            qu.push(g[v][i]);
        }
    }
    qu.pop();
    getBfs(ans, g, isVisited, qu);
}

vector <int> bfs(vector<int> g[], int N) {
    vector<bool> isVisited(N, false);
    vector<int> ans;
    queue<int> qu;
    qu.push(0);
    ans.push_back(0);
    isVisited[0] = true;
    getBfs(ans, g, isVisited, qu);
    return ans;
}

int main() 
{ 
    
} 