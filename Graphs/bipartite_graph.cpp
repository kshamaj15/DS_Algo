// https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
// medium
// BFS

// 6 5
// 0 3
// 0 4
// 0 5
// 1 3
// 4 5


#include<bits/stdc++.h>
using namespace std; 

bool dfs(int colour, int node, vector<int>adj[], vector<int>& color) {
        color[node] = colour;
        for(auto el: adj[node]) {
            if(color[el] == -1) {
                if (dfs(!colour, el, adj, color) == false)
                return false;
            } else if(color[el] == colour) {
                return false;
            }
        }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    bool ans = dfs(0, 0, adj, color);
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
        adj[v].push_back(u);
    }

    cout<<isBipartite(V, adj);
} 