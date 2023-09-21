// Program to implement the Minimum Vertex Cover using Randomized Approximation strategy.

#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;  // No. of Vertices
    list<int> *adj;   // Array of List

public: 
    Graph(int V);
    void addEdge(int u, int v);
    void Min_Vertex_Cover();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::Min_Vertex_Cover(){
    // Initialize all vertices as not visited 
    bool visited[V];
    for(int i=0; i<V; i++){
        visited[i] = false;
    }

    list<int>::iterator i;

    // Consider all the edges one by one
    for(int u=0; u<V; u++){
        if(visited[u] == false){
            // Go through all edges of u and
            // pick the first not visited yet
            for(i=adj[u].begin(); i!=adj[u].end(); ++i){
                int v = *i;
                if(visited[v] == false){
                    visited[v] = true;
                    visited[u] = true;
                    break;
                }
            }
        }
    }

    // print the vertex cover
    for(int i=0; i<V; i++){
        if(visited[i]){
            cout << i << " ";
        }
    }
}

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.Min_Vertex_Cover();

    return 0;
}