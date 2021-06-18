// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#
// Medium
// In progress
#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<bool> &vis, int parent)
{
    vis[node] = true;
    for (auto child : adj[node])
    {
        if (!vis[child])
        {
            if (dfs(child, adj, vis, node))
                return true;
        }
        else if (child != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    return dfs(0, adj, vis, -1);
}

int main()
{
    int V, E;
    cin >> V >> E;

    vector<int> adj[V];

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << isCycle(V, adj);
}
