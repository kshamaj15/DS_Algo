// https://practice.geeksforgeeks.org/problems/bipartite-graph/1#
// easy
// BFS

#include<bits/stdc++.h>
using namespace std; 

bool dfs(int color, int node, vector<int>adj[], vector<int>& ver) {
        ver[node] = color;
        for(auto el: adj[node]) {
            cout<<el<<" "<<ver[el]<<" "<<color<<endl;
            if(ver[el] == -1) {
                return dfs(!color, el, adj, ver);
            } else if(ver[el] == color) {
                return false;
            }
        }
    return true;
}

bool isBipartite(int V, vector<int>adj[]){
	    vector<int> ver(V, -1);
	    bool ans = dfs(0, 0, adj, ver);
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