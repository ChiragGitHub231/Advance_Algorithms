#include<bits/stdc++.h>
using namespace std;

int power(int a, int x, int n){
    int result = 1;
    while(x > 0){
        if(x % 2 == 1){
            result = (result * a) % n;
        }
        x = x / 2;
        a = (a * a) % n;
    }
    return result;
}

Rabin_Karp(string text, string pattern, int radix, int q){
    int n = text.length();
    int m = pattern.length();

    int p = 0, t = 0;

    int h = power(radix, (m-1), q);

    for(int i=0; i<m; i++){
        p = (radix * p + pattern[i]) % q;
        t = (radix * t + text[i]) % q;
    }

    for(int j=0; j<(n-m); j++){
        if(p == t){
            int k;
            for(k=0; k<m; k++){
                if(pattern[k] != text[j+k]){
                    break;
                }
            }

            if(k == m){
                cout << "Pattern occurs with shift " << j << endl;
            }
        }

        if(j < (n-m)){
            t = (radix * (t - text[j] * h) + text[j + m]) % q;

            if(t < 0){
                t = (t + q);
            }
        }
    }
}

int main(){
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    int radix = 10;
    int q = INT_MAX;

    Rabin_Karp(text, pattern, radix, q);

    return 0;
}