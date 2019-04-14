// 제대로 값 안나옴
#include <bits/stdc++.h>
using namespace std;

const long MX = 1000005;
long dat[MX];
long pre[MX];
long nxt[MX];
int unused = 6;//초기화
//int unused = 1;
//int unused = sizeof(dat)/sizeof(dat[0]) + 1;

int erase(int idx){
    nxt[pre[idx]] = nxt[idx];
    if(nxt[idx] != -1) pre[nxt[idx]] = pre[idx];

    return nxt[idx];// 제거된 원소의 이전 index 반환
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre+MX, -1);
    fill(nxt, nxt+MX, -1);
    list<int> dat = {0,3,13,51,0,-2};
    int erase_place = erase(6);
    cout << "제거된 원소 이전 index값 : " << erase_place;

    return 0;
}