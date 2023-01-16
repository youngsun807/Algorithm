/*
백트래킹 - 현재 상태에서 가능한 후보군을 따라 들어가며 탐색하는 알고리즘
*/
# BOJ 15649 순열 개수 구하기
#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[10];
bool isused[10];

void func(int k){ // 현재 k개까지 수를 택했음.
  if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
    cout << '\n';
    return;
  }

  for(int i = 1; i <= n; i++){ // 1부터 n까지의 수에 대해
    cout << "--------i : " << i << "/ k : " << k << '\n';
    if(!isused[i]){ // 아직 i가 사용되지 않았으면
      arr[k] = i; // k번째 수를 i로 정함
      isused[i] = 1; // i를 사용되었다고 표시
      func(k+1); // 다음 수를 정하러 한 단계 더 들어감
      isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
      cout << "8\n";
    }
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  cout << "-------Function IN-------\n";
  func(0);
  cout << "-------Function OUT-------\n";
}
#----------------------------------------------------------------
#BOJ 9663 N*N 체스판에 N개의 Queen 체스말 위치 시키기
#include <bits/stdc++.h>
using namespace std;
bool isused1[40]; // column을 차지하고 있는지
bool isused2[40]; // / 방향 대각선을 차지하고 있는지
bool isused3[40]; // \ 방향 대각선을 차지하고 있는지

int cnt = 0;
int n;
void func(int cur) { // cur번째 row에 말을 배치할 예정임
  if (cur == n) { // N개를 놓는데 성공했다면
    cnt++;
    return;
  }
  
  for (int i = 0; i < n; i++) { // (2, i)에 퀸을 놓을 예정
    if (isused1[i] || isused2[i+cur] || isused3[cur-i+n-1]) // column이나 대각선 중에 문제가 있다면
      continue;
    isused1[i] = 1;
    isused2[i+cur] = 1;
    isused3[cur-i+n-1] = 1;
    func(cur+1);
    isused1[i] = 0;
    isused2[i+cur] = 0;
    isused3[cur-i+n-1] = 0;
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  func(0);
  cout << cnt;
}
#----------------------------------------------------------------
#BOJ 1182 부분 집합 내 원소 합과 정해진 수가 같은 집합의 개수 
#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;
void func(int cur, int tot){
  if(cur == n){
    if(tot == s) cnt++;
    return;
  }
  
  func(cur+1, tot);
  func(cur+1, tot+arr[cur]);
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for(int i = 0; i < n; i++)
    cin >> arr[i];
  func(0, 0);
  if(s == 0) cnt--;
  cout << cnt;
}