#include <bits/stdc++.h>
using namespace std;

const int MX = 10000007;
int dat[MX];
int pos;//알아서 0으로 초기화

void push(int val){
    dat[pos++] = val;
}

void pop(){
    pos--;
}

int top(){
    return dat[pos-1];
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string c;
        cin >> c;
        if(c == "push"){
            int t;
            cin >> t;
            push(t);
        }
        else if(c == "pop"){
            if(pos == 0){
                cout << -1 << '\n';
            }
            else{
                cout << top() << '\n';
                pop();
            }
        }
        else if(c == "size"){
            cout << pos << '\n';
        }
        else if(c == "empty"){
            if(pos == 0){
                cout << 1;
            }
            else{
                cout << 0;
            }
        }
        else{
            if(pos == 0){
                cout << -1 << '\n';
            }
            else
            {
                cout << top() << '\n';
            }
            
        }
    }
}