//Dynamic Programming
/*
다이나믹 프로그래밍(동적 계획법) - 메모리를 적절히 사용하여 수행시간 효율성 향상 시키는 방법
이미 계산된 결과(작은 문제)는 별도의 메모리 영역에 저장하여 다시 계산 X

구현 방식
1)top down
1-1) 메모이제이션(Memoization)
> 재귀함수 사용
> DP에만 국한된 개념 X
> 한번 계산한 결과를 메모리 공간에 메모리
	- 같은 문제 호출 시 메모했던 결과 그대로 가져옴
	- 값을 기록한다는 점 -> 캐싱(cashing)
2)bottom up
> 반복문 사용
> 결과 저장용 리스트(배열) = DP 테이블


사용 조건
1) 최적 부분 구조(Optimal Substructure)
> 큰 문제를 작은 문제로 나눌 수 있으며 작은 문제의 답을 모아 큰 문제 해결
2) 중복되는 부분 문제(Overlapping Subproblem)
> 동일한 작은 문제를 반복적으로 해결

DP vs 분할정복(sorting)
> 공통점 - 최적 부분 구조 조건에서 사용
> 차이점 - 부분 문제 중복 여부(DP 중복 / 분할정복 중복X)

DP 접근 방법
1) 주어진 문제가 DP 유형임을 파악
2) 그리디, 구현, 완전탐색 등 다른 아이디어로 문제 해결 가능 여부 검토
3) 재귀 함수로 비효율적 완전 탐색 프로그램 작성 후 top down 방식으로 사용가능하면 코드 개선
*/

//Fibonacci - Bottom up
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

long long d[100];
    
int main(){
    clock_t start = clock();
    clock_t end = clock();
    
    d[1] = 1;
    d[2] = 1;
    int n = 50;
    
    for(int i=3;i<=50;i++){
        d[i] = d[i-1]+d[i-2];
    }
    
    cout << d[n] << endl;
    cout << end - start << "ms";
    return 0;
}

//--------------------------------------
//Fibonacci - Top down - O(N)
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

long long d[100];
int x;

int fibo(int x){
    cout << "f(" << x << ") ";
    if(x==1 or x==2){
        return 1;
    }
    
    if(d[x]!=0){
        return d[x];
    }
    
    d[x] = fibo(x-1) + fibo(x-2);
    return d[x];
}

int main(){
    clock_t start = clock();
    clock_t end = clock();
    
    cout << fibo(6) << endl;
    
    cout << end - start << "ms";
    return 0;
}
//-------------------------------------
/*
a(i) = i번째 식량창고의 최적해(얻을 수 있는 식량 최댓값)
k(i) = i번째 식량창고의 양
점화식 a(i) = max(a(i-1), a(i-2)+k(i)
한 칸 이상 떨어진 식량창고는 항상 털 수 있으므로 (i-3)번째 이하 고려X
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int d[100];
int n;
vector<int> arr;


int main(){
    clock_t start = clock();
    clock_t end = clock();
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    d[0] = arr[0];
    d[1] = max(arr[0], arr[1]);
    
    for(int i=2;i<n;i++){
        d[i] = max(d[i-1], d[i-2]+arr[i]);
    }
    
    cout << d[n-1] << endl;
    
    cout << end - start << "ms";
    return 0;
}
