//counting sort
/*
계수정렬 - 특정한 조건이 부합할 때만 사용 가능, 매우 빠르게 동작
(데이터 크기 범위 제한으로 정수 형태로 표현 가능 시에만 사용)
데이터 개수 = N/ 데이터(양수) 중 max = K -> 최악의 경우에도 O(N+K)
*/
#include <bits/stdc++.h>
#include <time.h>
#define MAX_VALUE 9
using namespace std;

int n = 15;
int target[15] = {7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2};
int cnt[MAX_VALUE + 1];

int main(){
    clock_t start = clock();
    
    for(int i=0;i<n;i++){
        cnt[target[i]] += 1;
    }
    
    for(int i=0;i<MAX_VALUE+1;i++){
        for(int j=0;j<cnt[i];j++){
            cout << i << ' ';
        }
    }
    
    cout << endl;
    clock_t end = clock();
    cout << end - start << "ms";
    return 0;
}

//-----------------------------
#include <bits/stdc++.h>
#include <time.h>
#define MAX_VALUE 9
using namespace std;

int n,k;
vector<int> a,b;

bool compare(int x, int y){
    return x>y;    
}

int main(){
    clock_t start = clock();
    
    cin >> n >> k;
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), compare);
    
    int result = 0;
    for(int i=0;i<k;i++){
        if(a[i] < b[i]) swap(a[i], b[i]);
        else break;
    }
    
    for(int i=0;i<n;i++){
        result += a[i];
    }
    cout << result << endl;
    clock_t end = clock();
    cout << end - start << "ms";
    return 0;
}