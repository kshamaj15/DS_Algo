// BFS
// easy

// in progress

#include<bits/stdc++.h>
using namespace std;

int getNextUnVisitedIndex(vector<bool>& visited) {
    for (int i=0; i<visited.size(); i++) {
        if(!visited[i])
        return i;
    }
    return -1;
}

void dfs(int n, vector<int> adj[], vector<bool> &visited) {
    visited[n] = true;
    for(int i=0; i<adj[n].size(); i++){
	    if(!visited[adj[n][i]]) {
	        dfs(adj[n][i], adj, visited);
	    }
	}
}

int main() {
    int V, E;
    cin>>V>>E;

    if(V != E+1) {
        cout<<"NO";
        return 0;
    }
    
    vector<int> adj[V];

    for(int i=0 ;i<E; i++) {
        int u, v;
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }

    int conCount = 0;
    vector<bool> visited(V, false);
    int index = 0;
    
    do {
        dfs(index, adj, visited);
        conCount++;
        index = getNextUnVisitedIndex(visited);
    } while(index != -1);

    if(conCount == 1)
    cout<<"YES";
    else
    cout<<"NO";
}