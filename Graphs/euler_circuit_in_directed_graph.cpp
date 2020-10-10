// https://practice.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1/?category[]=DFS&category[]=BFS&page=1&query=category[]DFScategory[]BFSpage1
// medium
// graph

#include<bits/stdc++.h>
using namespace std; 

bool isEulerianCycle(list<int> adj[], int V)
{
    vector<int> idegree(V, 0);
    vector<int> odegree(V, 0);
    for(int i=0; i<V; i++) {
        
        for(auto c: adj[i]) {
            idegree[i]++;
            odegree[c]++;
        }
    }
    
    for(int i=0; i<V; i++) {
        if(idegree[i] != odegree[i])
        return false;
    }
    return true;
}

int main() 
{ 
    
} 