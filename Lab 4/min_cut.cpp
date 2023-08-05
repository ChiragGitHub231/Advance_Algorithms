// Program to implement kargar's algorithm to find min-cut from algorithm.

#include<iostream>
#include<time.h>
#define N 4
using namespace std;

int mincut(int u, int v, int g[N][N], int n){
   do{
    int g1[N][N] = {0}; 
    for(int i=0; i<(n-1); i++){
        for(int j=(i+1); j<n; j++){
            int counter = 0;
            if((i == u) && (j == v)){
                g1[i][j] = 0;
                g1[j][i] = 0;
            }
            else if((i == u) || (i == v)){
                if(g[u][j] > 0){
                    counter += g[u][j];
                }
                if(g[v][j] > 0){
                    counter += g[v][j];
                }
                g1[u][j] = counter;
                g1[v][j] = counter;
            }
            else if((j == u) || (j == v)){
                if(g[u][i] > 0){
                    counter += g[u][i];
                }
                if(g[v][i] > 0){
                    counter += g[v][i];
                }
                g1[i][u] = counter;
                g1[i][v] = counter;
            }
            else{
                g1[i][j] = g[i][j];
            }
        }        
    }
    
    // Copy upper triangular value to lower triangular value
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i >= j){
                g1[i][j] = g1[j][i];
            }
        }
    }
    
    // Remove v'th row and v'th column
    int g2[n-1][n-1] = {0};
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if((i != v) || (j != v)){
                g2[i][j] = g1[i][j];
            }
        }
    }
        
        
    for(int i=0; i<(n-1); i++){
        for(int j=0; j<(n-1); j++){
            g[i][j] = g2[i][j];
        }
    } 
    n--;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << g[i][j] << " ";
        }
        cout << endl;
    } 
   }while(n>2);
}

int main(){
    // Create a graph
    int g[4][4] = {
        {0, 1, 1, 1},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {1, 1, 1, 0},
    };

    srand(time(0));
    int u = rand() % 4;
    int v = rand() % 4;

    cout << u << " - " << v << "\n" << endl; 
    
    int result = mincut(u, v, g, 4);
    cout << "\nMin cut: " << result;
    return 0;
}