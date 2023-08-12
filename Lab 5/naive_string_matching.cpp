#include<iostream>
#include<string.h>
using namespace std;

void search(string text, string pattern){
    int n = text.length();
    int m = pattern.length();

    for(int i=0; i<=(n-m); i++){
        int j;
        for(j=0; j<m; j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }

        if(j == m){
            cout << "Pattern found at index/shift " << i << endl;
        }
    }
}

int main(){
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    search(text, pattern);

    return 0;
}