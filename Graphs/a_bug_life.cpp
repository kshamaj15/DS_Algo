// https://www.spoj.com/problems/BUGLIFE/
// medium

#include<bits/stdc++.h>
using namespace std; 

bool dfs(int color, int node, map<int, vector<int>>& adj, map<int, int>& ver) {
        ver[node] = color;
        for(auto el: adj[node]) {
            if(!ver[el]) {
                return dfs(color%2+1, el, adj, ver);
            } else if(ver[el] == color) {
                return false;
            }
        }
    return true;
}

bool isBipartite(int V, map<int, vector<int>>& adj, int startV){
	    map<int, int> ver;
	    bool ans = dfs(1, startV, adj, ver);
        return ans;
}

int main() {
    int t;
    cin>>t;

    int V, E; 
    cin>>V>>E;

    for(int x=1; x<=t; x++) {
        // vector<int> adj[V];
        map<int, vector<int>> adj;
        int startV;

        for(int i=0; i<E; i++) {
            int u, v;
            cin>>u>>v;
            if(!startV) startV = u;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        string s = isBipartite(V, adj, startV) ? "No suspicious bugs found!" : "Suspicious bugs found!";
        cout<<"Scenario #"<<x<<":"<<endl;
        cout<<s<<endl;
    }
} 