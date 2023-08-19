// Sum of Subset to 0/1 Knapsack
#include<iostream>
using namespace std;
#define n 6

string Knapsack(int p[], int w[], int c, int v){
    int m[n+1][c+1];
    for(int i=0; i<=c; i++){
        m[0][i] = 0;
    } 
    for(int j=0; j<=n; j++){
        m[j][0] = 0;
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=c; j++){
            if(w[i] <= j){
                if( (p[i] + m[i-1][j-w[i]]) > m[i-1][c] ){
                    m[i][j] = p[i] + m[i-1][j-w[i]]; 
                }
                else{
                    m[i][j] = m[i-1][j];
                }
            }
            else{
                m[i][j] = m[i-1][j];
            }
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    
    if(m[n][c] >= c){
        return "TRUE";
    }
    else{
        return "FALSE";
    }
}

string Sum_of_Subset(int s[], int sum){
    int p[n], w[n];
    for(int i=0; i<n; i++){
        p[i] = s[i];
        w[i] = s[i];
    }
    int c = sum;
    int v = sum;
    
    if(Knapsack(p, w, c, v) == "TRUE"){
        return "TRUE";
    }
    else{
        return "FALSE";
    }
}

int  main(){
    int s[] = {4, 3, 6, 8, 5, 9};
    int sum = 23;
    
    string ans = Sum_of_Subset(s, sum);
    cout << ans;
    
    return 0;
}