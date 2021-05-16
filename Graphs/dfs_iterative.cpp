// https://practice.geeksforgeeks.org/problems/dfs-traversal-of-graph/1
// easy
// DFS

#include<bits/stdc++.h>
using namespace std; 

vector<int>dfsOfGraph(int V, vector<int> adj[]) {
	vector<bool> visited(V, false);
	stack<int> s;
	vector<int> ans;
	s.push(0);
        
	while(!s.empty()) {
	    int val = s.top();
	    if(!visited[val])
	    ans.push_back(val);
	    visited[val] = true;
	    s.pop();
	    for(int i=adj[val].size()-1; i>=0; i--){ // any order is fine
	        if(!visited[adj[val][i]]) {
	            s.push(adj[val][i]);
	        }
	    }
	}
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