#include<bits/stdc++.h>
using namespace std; 

class Graph {
    public:
    int v;
    vector<list<int>> adj;
    void addEgde(int a, int b);
    Graph(int v);
};

void Graph::addEgde(int a, int b) {
    adj[a].push_back(b);
}

Graph::Graph(int v) {
    this->v = v;
    // adj = new vector<list<int>>[v];
}

class Vertex {
    public:
    int index;
    list<int> list;
    Vertex(int index);
};

Vertex::Vertex(int i) {
    this->index = i;
}

int main() 
{ 
    
    return 0; 
} 