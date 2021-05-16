// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// easy
// BFS

#include<bits/stdc++.h>
using namespace std; 

vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    vector<bool> visited(V, false);
	    queue<int> qu;
	    vector<int> ans;

	    qu.push(0);
	    visited[0] = true;
        
	    while(!qu.empty()) {
	        int s = qu.front();
	        ans.push_back(s);
	        qu.pop();
	        for(int i=0; i<adj[s].size(); i++){
	            if(!visited[adj[s][i]]) {
	                visited[adj[s][i]] = true;
	                qu.push(adj[s][i]);
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

    vector<int> bfs = bfsOfGraph(V, adj);
    for(auto el: bfs)
    cout<<el<<" ";
} 