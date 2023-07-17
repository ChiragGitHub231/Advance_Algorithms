#include<iostream>
#include<limits.h>
#include<queue>
#define n 6
using namespace std;

bool bfs(int rgraph[n][n], int s, int t, int parent[]){
    int visited[n] = {0};
    
    // create a queue
    queue<int> q;
    
    // insert source s to queue
    q.push(s);
    
    // mark as visited 
    visited[s] = 1;
    
    // no parent of source node
    parent[s] = -1;
    
    
    while(!(q.empty())){
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++){
            if(visited[v] == 0 && rgraph[u][v] > 0){
                // if there is a sink
                if(v == t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
            }
        }
    }
    return false;
}

int ford_fulkerson(int graph[n][n], int s, int t){
    // create residual graph
    int rgraph[n][n];
    
    // Initially same as original graph
    for(int u=0; u<n; u++){
        for(int v=0; v<n; v++){
            rgraph[u][v] = graph[u][v];
        } 
    }
    
    // create an array parent with size n
    // parent will be assigned by bfs
    int parent[n];
    
    // count max flow of graph
    int max_flow = 0;
    
    while(bfs(rgraph, s, t, parent)){
        int path_flow = INT_MAX, u;
        
        for(int v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rgraph[u][v]);
        }
        
        for(int v=t; v!=s; v=parent[v]){
            u = parent[v];
            rgraph[u][v] -= path_flow;
            rgraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main(){
    int graph[n][n] = {
      {0, 16, 13, 0, 0, 0},
      {0, 0, 10, 12, 0, 0},
      {0, 4, 0, 0, 14, 0},
      {0, 0, 9, 0, 0, 20},
      {0, 0, 0, 7, 0, 4},
      {0, 0, 0, 0, 0, 0}
    };
    
    int max_flow = ford_fulkerson(graph, 0, 5);
    
    cout << "Max Flow is: " << max_flow;
    return 0;
}