#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

//추가된 위치를 반환
int insert(int idx, char val){
    dat[unused] = val;
    pre[unused] = idx;
    nxt[unused] = nxt[idx];
    if(nxt[idx] != -1) pre[nxt[idx]] = unused;
    nxt[idx] = unused;
    unused++;
    return nxt[idx];
}

int erase(int idx){
    nxt[pre[idx]] = nxt[idx];
    if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];
    return pre[idx];
}

void traversal(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    string init;
    cin >> init;
    list<char> L;
    int pos = 0;
    for(auto c : init){
        pos = insert(pos, c);
    }
    int Q;
    cin >> Q;
    string tmp;
    getline(cin,tmp);// 명령어 입력
    while(Q--){
        string op;
        getline(cin, op);
        if(op[0] == 'P'){
            pos = insert(pos, op[2]);
        }
        else if(op[0] == 'L'){
            if(pre[pos] != -1){
                pos = pre[pos];
            }
        }
        else if(op[0] == 'D'){
            if(nxt[pos] != -1){
                pos = nxt[pos];
            }
        }
        else{
            if(pos != 0){
                pos = erase(pos);
            }
        }
    }
    traversal();
}
