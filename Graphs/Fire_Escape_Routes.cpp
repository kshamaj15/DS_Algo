// https://www.codechef.com/problems/FIRESC
// medium

#include <bits/stdc++.h>
using namespace std;

long long int cc_size;

void dfsOfGraph(long long int node, vector<bool> &visited, vector<long long int> adj[])
{
    visited[node] = true;
    cc_size++;
    for (auto child : adj[node])
    {
        if (!visited[child])
            dfsOfGraph(child, visited, adj);
    }
}

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int V, E;
        cin >> V >> E;

        vector<long long int> adj[V];
        vector<bool> visited(V, false);

        for (long long int i = 0; i < E; i++)
        {
            long long int u, v;
            cin >> u >> v;
            adj[u - 1].push_back(v - 1);
            adj[v - 1].push_back(u - 1);
        }
        long long int conC = 0;
        long long int numbrOfPossibleManager = 1;

        for (long long int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                cc_size = 0;
                dfsOfGraph(i, visited, adj);
                numbrOfPossibleManager = ((numbrOfPossibleManager%1000000007)*(cc_size%1000000007))%1000000007;
                conC++;
            }
        }
        cout << conC << " " << numbrOfPossibleManager << endl;
    }
}
