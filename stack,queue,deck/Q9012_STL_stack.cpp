#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        stack<int> S;
        for(auto c : s){
            if(c=='(' or c=='{'){
                S.push(c);
            }
            else{
                if(S.empty()){
                    S.push('x');
                    break;
                }
                if(c==')'){
                    if(S.top() != '(') break;
                }
                else{
                    if(S.top()!='{') break;
                }
                S.pop();
            }
        }
        if(S.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}