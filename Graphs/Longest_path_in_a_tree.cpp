// https://www.spoj.com/problems/PT07Z/

#include <bits/stdc++.h>
using namespace std;

int maxD = -1;
int maxDNode = 0;

void dfs(int node, vector<int> adj[], vector<bool> &visited, int distanceFromRoot)
{
    visited[node] = true;
    if (maxD < distanceFromRoot)
    {
        maxD = distanceFromRoot;
        maxDNode = node;
    }
    for (auto child : adj[node])
    {
        if (!visited[child])
            dfs(child, adj, visited, distanceFromRoot + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> adj[n];
    vector<bool> visited(n, false);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    dfs(0, adj, visited, 0);
    vector<bool> visited1(n, false);
    dfs(maxDNode, adj, visited1, 0);
    cout << maxD << endl;
}
