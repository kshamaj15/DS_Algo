// DFS

#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &subSize)
{
    visited[node] = true;
    int size = 1;
    for(auto child: adj[node]){
        if(!visited[child])
        size += dfs(child, adj, visited, subSize);
    }
    subSize[node] = size;
    return size;
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    vector<bool> visited(n, false);
    vector<int> subSize(n, 0);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0, adj, visited, subSize);

cout<<endl;
    for(auto el: subSize)
    cout<<el<<" ";
}
