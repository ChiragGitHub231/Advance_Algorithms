#include<bits/stdc++.h>
using namespace std;
#define no_of_char 256

int getNextState(string pattern, int m, int state, int x){
    if(state < m && x == pattern[state]){
        return state+1;
    }

    int ns, i;          // Store result of next state

    for(ns=state; ns > 0; ns--){
        if(pattern[ns-1] == x){
            for(i=0; i < ns-1; i++){
                if(pattern[i] != pattern[state-ns+1+i]){
                    break;
                }
            }

            if(i == ns-1){
                return ns;
            }
        }
    }
    return 0;
}

void computTF(string pattern, int m, int Finite_Table[][no_of_char]){
    int state, x;

    for(state=0; state <= m; state++){
        for(x=0; x < no_of_char; x++){
            Finite_Table[state][x] = getNextState(pattern, m, state, x);
        }
    }
}

void Finite_Automata_String_Matching(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    int Finite_Table[m+1][no_of_char];

    computTF(pattern, m, Finite_Table);

    int i, state=0;
    for(i=0; i<n; i++){
        state = Finite_Table[state][text[i]];

        if(state == m){
            cout << "Pattern occurs with shift " << i-m+1 << endl;
        }
    }
}

int main(){
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    Finite_Automata_String_Matching(text, pattern);

    return 0;
}