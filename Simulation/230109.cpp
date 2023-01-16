/*
카메라가 감시할 수 있는 방향 도출 = 진법으로 도출
4개의 방향 = 4진법
3개의 카메라 = 4^3 = 64개 조합 경우의 수 도출
*/
//BOJ 15683 CCTV 사각지대 최소 개수 구하기
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 남쪽, 동쪽, 북쪽, 서쪽 순서
int n, m;
int board1[10][10]; // 최초에 입력받은 board를 저장할 변수
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
vector<pair<int,int> > cctv; // cctv의 좌표를 저장할 변수

bool OOB(int a, int b){ // Out Of Bounds 확인
  return a < 0 || a >= n || b < 0 || b >= m;
}

// (x,y)에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈칸을 7로 바꿔버림
void upd(int x, int y, int dir){
  dir %= 4;
  while(1){
    x += dx[dir];
    y += dy[dir];
    if(OOB(x,y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수를 탈출
    if(board2[x][y] != 0) continue; // 해당 칸이 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
    board2[x][y] = 7; // 빈칸을 7로 덮음
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int mn = 0; // 사각 지대의 최소 크기 (=답)
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board1[i][j];
      if(board1[i][j] != 0 && board1[i][j] != 6)
        cctv.push_back({i,j});
      if(board1[i][j] == 0) mn++;
    }
  }
  // 1 << (2*cctv.size())는 4의 cctv.size()승을 의미.
  for(int tmp = 0; tmp < (1<<(2*cctv.size())); tmp++){ // tmp를 4진법으로 뒀을 때 각 자리수를 cctv의 방향으로 생각할 것이다.
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        board2[i][j] = board1[i][j];
    int brute = tmp;    
    for(int i = 0; i < cctv.size(); i++){
      int dir = brute % 4;
      brute /= 4;
      int x = cctv[i].X;
      int y = cctv[i].Y; // tie(x, y) = cctv[i];로 쓰면 1줄로 줄일 수 있음
      if(board1[x][y] == 1){
        upd(x,y,dir);
      }
      else if(board1[x][y] == 2){
        upd(x,y,dir);
        upd(x,y,dir+2);
      }
      else if(board1[x][y] == 3){
        upd(x,y,dir);
        upd(x,y,dir+1);
      }
      else if(board1[x][y] == 4){
        upd(x,y,dir);
        upd(x,y,dir+1);
        upd(x,y,dir+2);
      }
      else{ // board1[x][y] == 5
        upd(x,y,dir);
        upd(x,y,dir+1);
        upd(x,y,dir+2);
        upd(x,y,dir+3);
      }
    }
    int val = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        val += (board2[i][j]==0);
    mn = min(mn, val);
  }
  cout << mn;
}
//-----------------------------------
/*
회전에 대한 함수 구현 = Rotate(swap 사용)
*/
//BOJ 18808 노트북에 스티커가 모두 연결되게 붙이기
#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int note[42][42]; //노트북 내 스티커 좌표 저장할 변수
int r, c; // 스티커 크기
int paper[12][12]; //스티커의 좌표를 저장할 변수 

// paper를 90도 회전하는 함수
void rotate(){
  int tmp[12][12];
  
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      tmp[i][j] = paper[i][j];
  
  for(int i = 0; i < c; i++)
    for(int j = 0; j < r; j++)
      paper[i][j] = tmp[r-1-j][i];

  swap(r, c);
}

// note의 (x,y)에 모눈종이의 (0,0)이 올라가게 스티커를 붙일 수 있는지 판단하는 함수. 가능할 경우 note를 갱신한 후 true를 반환.
bool pastable(int x, int y){
  for(int i = 0; i < r; i++){
    for(int j = 0; j < c; j++){
      if(note[x+i][y+j] == 1 && paper[i][j] == 1) // 노트북에 이미 스티커가 있는 경우
        return false;
    }
  }
  for(int i = 0; i < r; i++){ //스티커 붙이기
    for(int j = 0; j < c; j++){
      if(paper[i][j] == 1)
        note[x+i][y+j] = 1;
    }
  }
  return true;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  while(k--){
    cin >> r >> c;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        cin >> paper[i][j]; //스티커 좌표 저장
    
    for(int rot = 0; rot < 4; rot++){ //시계방향 90도씩 회전
      bool is_paste = false; // 해당 스티커를 붙였는가?
      for(int x = 0; x <= n-r; x++){ //5-3=2, 세로 방향 스티커 가능 위치 확인
        if(is_paste) break;
        for(int y = 0; y <= m-c; y++){ // 4-3=1, 가로 방향 스티커 가능 위치 확인
          if(pastable(x, y)){
            is_paste = true;
            break;
          }
        }
      }
      if(is_paste) break;
      rotate();
    }
  }
  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cnt += note[i][j];
  cout << cnt << '\n';
}
//-----------------------------------
/*
1d array로 왼쪽으로 판을 움직였을 때 합쳐진 결과 도출 Code
Ver.1 시간 복잡도 : O(N^2)
Ver.2 시간 복잡도 : O(N)
*/
//BOJ 12100 Unit Test Code Ver.1
#include <iostream>
using namespace std;

int arr[8] = {0, 2, 0, 2, 8, 8, 0, 16};
int tilted[8] = {}; // 기울어진 결과 저장
int merged[8] = {}; // 추가 합치기 가능 여부 저장(bool)

int main(){
    for(int i=0; i<8; i++){
        cout << "i : " << i << "/arr[i] : " << arr[i] << "/tilted[i] : " << tilted[i] << '\n';
        if(arr[i] == 0) continue;
        if(tilted[0] == 0){
            cout << "tilted[0] == 0\n";
            tilted[0] = arr[i];
            continue;
        }
        int idx = i;
        cout << "i : " << i << '\n';
        while(tilted[idx] == 0){
            cout << "while문\n";
            idx--; //값이 0인 구간까지 전체 탐색 시 최대 N개 탐색함 -> O(N^2)이 됨
            cout << "idx : " << idx << "\n";
        }
        if(!merged[idx] && tilted[idx] == arr[i]){
            cout << "1-----merge------\n";
            merged[idx] == true;
            tilted[idx] *=2;
        }
        else{
            cout << "2-----merge------\n";
            tilted[idx+1] = arr[i];
        }
    }


    return 0;
}

//BOJ 12100 Unit Test Code Ver.2
#include <iostream>
using namespace std;

int arr[8] = {0, 2, 0, 2, 8, 8, 0, 16};
int tilted[8] = {}; // 기울어진 결과 저장
int merged[8] = {}; // 추가 합치기 가능 여부 저장(bool)
int idx = 0;

int main(){
    for(int i=0;i<8;i++){
        if(arr[i] == 0) continue;
        if(tilted[idx] == 0)
            tilted[idx] = arr[i];
        else if(tilted[idx] == arr[i])
            tilted[idx++] *=2;
        else
            tilted[++idx] = arr[i];
    }
    return 0;
}

//FULL Code
#include <bits/stdc++.h>
using namespace std;

int board1[21][21];
int board2[21][21];
int n;

void rotate(){ // board2를 시계 방향으로 90도 회전하는 함수
  int tmp[21][21];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      tmp[i][j] = board2[i][j];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      board2[i][j] = tmp[n-1-j][i];
}

void tilt(int dir){
  while(dir--) rotate();
  for(int i = 0; i < n; i++){
    int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
    int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지 가리키는 변수
    for(int j = 0; j < n; j++){
      if(board2[i][j] == 0) continue;
      if(tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
        tilted[idx] = board2[i][j];
      else if(tilted[idx] == board2[i][j]) // 같은 값을 갖는 블록이 충돌할 경우
        tilted[idx++] *= 2;
      else // 다른 값을 갖는 블록이 충돌
        tilted[++idx] = board2[i][j];
    }
    for(int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]에 tilted를 덮어씀
  }
}


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board1[i][j];

  int mx = 0;
  for(int tmp = 0; tmp < 1024; tmp++){
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        board2[i][j] = board1[i][j];
    int brute = tmp;
    for(int i = 0; i < 5; i++){
      int dir = brute % 4;
      brute /= 4;
      tilt(dir);
    }
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        mx = max(mx, board2[i][j]);
  }
  cout << mx;
}

