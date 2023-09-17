// Program to implement KMP String Matching Algorithm

#include<bits/stdc++.h>
using namespace std;

vector<int> Compute_Prefix_Function(string pattern){
    vector<int> pi(pattern.size()+1);

    pi[1] = 0;
    int k = 0;

    for(int q=2; q<=pattern.size(); q++){
        while(k>0 && pattern[k] != pattern[q-1]){
            k = pi[k];
        }

        if(pattern[k] == pattern[q-1]){
            k++;
        }

        pi[q] = k;
    }
    return pi;
}

void KMP_Matcher(string text, string pattern){
    int n = text.size();
    int m = pattern.size();

    vector<int> pi = Compute_Prefix_Function(pattern);

    int q = 0;

    for(int i=1; i<=n; i++){
        while(q>0 && pattern[q] != text[i-1]){
            q = pi[q];
        }

        if(pattern[q] == text[i-1]){
            q++;        
        }

        if(q == m){
            cout << "Pattern found at " << (i-m) << " position" << endl;
        }
    }
}

int main(){
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    KMP_Matcher(text, pattern);

    return 0;
}