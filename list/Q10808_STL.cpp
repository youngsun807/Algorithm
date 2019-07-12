#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    cin >> S;
    int freq[26] = {};
    for(auto s:S){
        freq[s-'a']++;
    }
    for(int i=0;i<26;i++) cout << freq[i]<< ' ';
}