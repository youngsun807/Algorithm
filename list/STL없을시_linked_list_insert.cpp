// 제대로 값 안나옴
#include <bits/stdc++.h>
using namespace std;

const long MX = 1000005;
long dat[MX];
long pre[MX];
long nxt[MX];
int unused = 6;//초기화


int insert(int idx, char val){
//(int idx = index 2번 위치, char val = 데이터 20넣을것)
    dat[unused] = val;//step 1 ,dat[6] = 20;
    pre[unused] = idx;//step 2 ,pre[6] = 2
    nxt[unused] = nxt[idx];//삽입할 위치의 다음 index값을 새값의 다음 index로 지정 ,nxt[6] = nxt[2] = 3, nxt[6]=3
    if(nxt[idx] != -1) pre[nxt[idx]] = unused;//pre[nxt[2]] = 6, pre[3] = 6
    nxt[idx] = unused;
    unused++;
    return pre[idx];
}
// char = 1byte 정수
// 아스키 코드 문자로 해석한다.
int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
  
    list<int> dat = {0,3,13,51,0,-2};
    list<int> pre = {-1,0,1,2,0,3};
    list<int> nxt = {1,2,3,5,0,-1};
    int insert_index = insert(3, 20);
    cout << "추가된 값의 index 위치 반환 : " << insert_index;
    
    return 0;
}

