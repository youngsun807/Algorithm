#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    string S = to_string(a*b*c);
    // cout << S << '\n';
    int freq[10] = {};
    for(auto s:S){
        //s = char타입
        // 숫자 char(0~9)는 아스키코드 48부터 시작
        // s-48 또는 s-'0'을 하면 해당 숫자에 대한 값이 나온다.
        freq[int(s-48)]++;
    }
    for(int i=0;i<10;i++) cout << freq[i] << endl;
}