// a에서 b로 옮기기

#include <bits/stdc++.h>
using namespace std;

void hanoi(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    int c = 6-a-b;
    hanoi(a,c,n-1);
    cout << a << ' ' << b << '\n';
    hanoi(c,b,n-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1<<n)-1 << '\n';
     hanoi(1,3,n);
}