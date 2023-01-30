/*
바로 옆에 닿아있는 왼쪽만 확인
왼쪽 확인 후 전진 OR 회전

*/
//BOJ14503 로봇청소기
#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, d;
int board[52][52];
int result;

int dx[4] = {-1, 0, 1, 0}; //북, 동, 남, 서
int dy[4] = {0, 1, 0, -1};

int main(){
    
    cin >> N >> M >> x >> y >> d;
    
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin >> board[i][j];
            
    while(true){
        if(board[x][y]==0) result = result + 1; //가장 처음 현재 위치 청소
        board[x][y] = -1; //청소한 위치 표시
        bool cleaned = false; 
        for(int i=0;i<4;i++){
            d = (d+3) %4; //왼쪽으로만 회전
            if(board[x+dx[d]][y+dy[d]] == 0){
                x += dx[d];
                y += dy[d];
                cleaned = true;
                break;
            }
        }
        
        //왼쪽에 청소할 구역이 있다면 해당 방향으로 회전 -> 해당 구역 청소 완료 상태
        //다시 현재 회전된 상태에서 왼쪽 확인해야 하므로 아래 코드 확인 필요 없음
        if(cleaned) continue; 
        

        //4번 회전하면서 청소할 곳 없었음
        //뒤에 벽 존재 여부 확인(바라보고 있는 방향 반대 방향) -> 로봇 정지
        if(board[x-dx[d]][y-dy[d]] == 1) 
            break;


        // 로봇 후진    
        x -= dx[d];
        y -= dy[d];
    }
    
    cout << result;
    
    return 0;
}