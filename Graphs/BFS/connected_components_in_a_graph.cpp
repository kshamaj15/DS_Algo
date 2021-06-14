// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/
// DFS
// easy

#include<bits/stdc++.h>
using namespace std;

void dfs(int n, vector<int> adj[], vector<bool> &visited){
    visited[n] = true;
	for(int i=0; i<adj[n].size(); i++){
	    if(!visited[adj[n][i]]) {
	        dfs(adj[n][i], adj, visited);
	    }
	}
}

int getNextUnVisitedVertex(vector<bool> &visited) {
    for(int i=0; i<visited.size(); i++){
        if(!visited[i]) return i;
    }
    return -1;
}

int main() {
    int V, E;
    cin>>V>>E;
    int cnt = 0;
    vector<int> adj[V];
    vector<bool> visited(V, false);
    // save graph
    for(int i=0; i<E; i++) {
        int u,v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int nextV = 0; // next vertex to traverse graph
    do {
        dfs(nextV, adj, visited);
        nextV = getNextUnVisitedVertex(visited);
        cnt++;
    } while(nextV != -1);
    cout<<cnt;
}