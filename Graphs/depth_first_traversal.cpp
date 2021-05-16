// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
// easy
// DFS

#include<bits/stdc++.h>
using namespace std; 

// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
// easy
// BFS

#include<bits/stdc++.h>
using namespace std; 

vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<bool> visited(V, false);
	    stack<int> stk;
	    vector<int> ans;

	    stk.push(0);
	    visited[0] = true;
        
	    while(!stk.empty()) {
	        int s = stk.top();
	        ans.push_back(s);
	        stk.pop();
	        for(int i=0; i<adj[s].size(); i++){
	            if(!visited[adj[s][i]]) {
	                visited[adj[s][i]] = true;
	                stk.push(adj[s][i]);
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