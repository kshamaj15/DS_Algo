// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// easy
// BFS

#include<bits/stdc++.h>
using namespace std; 

void dfs(int n, vector<int> adj[], vector<int> &ans, vector<bool> &visited){
    visited[n] = true;
	ans.push_back(n);
	for(int i=0; i<adj[n].size(); i++){
	    if(!visited[adj[n][i]]) {
	        dfs(adj[n][i], adj, ans, visited);
	    }
	}
}
	    
vector<int>dfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);
	vector<int> ans;
	dfs(0, adj, ans, visited);
	return ans;
}

int main() {
    int V, E; 
    cin>>V>>E;

    vector<int> adj[V];

    for(int i=0; i<E; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> dfs = dfsOfGraph(V, adj);
    for(auto el: dfs)
    cout<<el<<" ";
} 