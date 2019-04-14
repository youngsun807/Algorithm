// queue 사용

#include <bits/stdc++.h>
using namespace std;

//pair 관련 별칭 생성
#define X first // first를 X로
#define Y second // second를 Y로 사용

int board[502][502] =
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0}}; // 1=파랑, 0=빨강
bool visit[502][502];//칸 방문 여부 저장
int n = 7, m = 10; // n=행수, m=열수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};//상하좌우 네방향

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    visit[0][0] = 1;//(0,0) 방문햇다고 명시
    Q.push({0,0});// 큐에 시작점 삽입
    while(!Q.empty()){
        auto cur = Q.front();//방문할 지점 저장 
        Q.pop(); // 방문지점 도착
        cout << '(' << cur.X << "," << cur.Y << ") -> ";
        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue; 
            if(visit[nx][ny] or board[nx][ny] !=1) continue;
            visit[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    cout << "END";
}