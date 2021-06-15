// BFS
// easy

// in progress

#include<bits/stdc++.h>
using namespace std;

vector<int> getSssp(vector<int> (adj)[], int node, vector<bool> &visited, int size) {
    vector<int> ans(size);
    ans[node] = 0;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    while(!q.empty()) {
        node = q.front();
        for(int i=0; i<adj[node].size(); i++) {
            cout<<node<<" node "<<adj[node][i]<<endl;
            if(!visited[adj[node][i]]) {
                ans[adj[node][i]] = 1 + ans[node];
                visited[adj[node][i]] = true;
                q.push(adj[node][i]);
            }
        }
        q.pop();
    } 
    return ans;
}

int main() {
    int V, E;
    cin>>V>>E;
    int cnt = 0;
    vector<int> adj[V];
    vector<bool> visited(V, false);

    for(int i=0; i<E; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> sssp = getSssp(adj, 0, visited, V);
    for (auto el : sssp){
        cout<<el<<" ";
    }
    
}