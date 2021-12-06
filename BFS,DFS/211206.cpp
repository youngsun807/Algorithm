 /*
유클리드 호제법
> 두 자연수 A,B(A>B)애서 R = A % B일 때
A, B 최대공약수 = B, R 최대공약수
192, 168
162, 30
30, 12
12, 6

BFS = 모든 간선 길이 동일 시 최단 거리 탐색 용이
*/

#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int n,m;
int result = 0;
int graph[1001][1001];

bool dfs(int x, int y){
    if(x < 0 || x > n-1 || y < 0 || y > m-1){
        return false;
    }
    
    if(graph[x][y]==0){
        graph[x][y] = 1;
        dfs(x-1,y);
        dfs(x, y-1);
        dfs(x+1, y);
        dfs(x,y+1);
        return true;
    }
    
    return false;
}

int main()
{
    clock_t start = clock(); 
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dfs(i,j)) result++;
        }
    }
    
    cout << result << endl;
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}
//------------------------------------------------
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int n,m;
int graph[201][201];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x,y});
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            
            if (nx < 0 || nx > n-1 || ny < 0 || ny > m-1) continue;
            
            if (graph[nx][ny] == 0) continue;
            
            if(graph[nx][ny]==1){
                graph[nx][ny] = graph[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    return graph[n-1][m-1];
}

int main()
{
    clock_t start = clock(); 
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &graph[i][j]);
        }
    }
    
    cout << bfs(0,0) << endl;
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}