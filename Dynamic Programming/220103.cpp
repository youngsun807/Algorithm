/*
ai = i를 1로 만들기 위한 최소 연산 횟수
ai = min(a(i-1), a(i/2), a(i/3), a(i/5))+1
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int d[30001];
int x;

int main(){
    clock_t start = clock();
    
    cin >> x;
    
    for(int i=2;i<=x;i++){
        d[i] = d[i-1] + 1;
        if (i%2==0){
            d[i] = min(d[i], d[i/2]+1);
        }
        if (i%3==0){
            d[i] = min(d[i], d[i/3]+1);
        }
        if (i%5==0){
            d[i] = min(d[i], d[i/5]+1);
        }
    }
    cout << d[x] << endl;
    clock_t end = clock();
    
    cout << end - start << "ms";
    
    return 0;
}

//-------------------------------------