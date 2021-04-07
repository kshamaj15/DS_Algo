#include<bits/stdc++.h>
using namespace std;

int main(){
    int V, E;
    cin>>V>>E;
    vector<int> adj[V];

    for(int i=0; i<E; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    
}
