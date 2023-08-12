#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

bool compare(string a, string b, int p, int r){
    if(a.size() < b.size()){
        return false;
    }
    else{
        int k = 0;
        for(int i=p; i<=r; i++){
            if(a[i] != b[k++]){
                return false;
            }
        }
        return true;
    }
}

vector<int> horsepool_search(string text, string pattern){
    if(pattern.size() > text.size()){
        return {};
    }
    else if(text == pattern){
        return {0};
    }
    else{
        vector<int> ans;
        int n = text.size();
        int m = pattern.size();

        unordered_map<char, int> last_occur;
        int count = 0;
        for(int i=0; i<m-1; i++){
            last_occur[pattern[i]] = m-i-1;
        }

        int j = m-1, i=0;
        while(j < n){
            count++;
            if(compare(text, pattern, i, j)){
                ans.push_back(i);
            }
            if(last_occur[text[j]] != 0){
                i += last_occur[text[j]];
                j += last_occur[text[j]];
            }
            else{
                i += m;
                j += m;
            }
        }
        // ans.push_back(count);            // It counts the number of comparisons
        return ans;
    }
}

int main(){
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    vector<int> ans = horsepool_search(text, pattern);

    for(auto r:ans){
        cout << "Pattern found at shift " << r << endl;
    }

    return 0;
}