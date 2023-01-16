/*
다익스트라 최단 경로 알고리즘
[동작과정]
1. 출발 노드 설정
2. 최단 거리 테이블 초기화
3. 방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택
4. 해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단거리 테이블 갱신
5. 3~4번 과정 반복
*/

#include <bits/stdc++.h>
#define INF 1e9 //무한을 의미하는 값으로 10억 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 10만개라고 가정
int n, m, start;

//각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int,int>> graph[100001];

//방문한 적이 있는지 체크하는 목적의 배열
bool visited[100001];

//최단 거리 테이블 만들기
int d[100001];

//방문하지 않은 노드 중에서 가장 최단 거리가 짧은 노드의 번호 반환
int getSmallestNode(){
	int min_value = INF;
	int index = 0; //가장 최단 거리가 짧은 노드(인덱스)
	for(int i=1;i<=n;i++){
		if(d[i] < min_value && !visitied[i]){
			min_value = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start){
	//시작 노드에 대해서 초기화
	d[start] = 0;
	visited[start] = true;
	for(int j = 0;j < graph[start].size();j++){
		d[graph[start][j].first] = graph[start[][j.second;
	}
	
	//시작 노드를 제외한 전체 n-1개의 노드에 대해 반복
	for(int i=0;i<n-1;i++){
		int now = getSmallestNode();
		visited[now] = true;
		
		//현재 노드와 연결된 다른 노드를 확인
		for(int j=0;j<graph[now].size();j++){
			int cost = d[now] + graph[now][j].second;
			//현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
			if(cost < d[graph[now][j].first]){
				d[graph[now][j].first] = cost;
			}
		}
	}
}

int main(void){
	cin >> n >> m >> start;
	
	//모든 간선 정보를 입력받기
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		graph[a].push_back({b,c});
	}
	
	//최단 거리 테이블을 모두 무한으로 초기화
	fill_n(d,100001,INF);
	
	//다익스트라 알고리즘 수행
	dijkstra(start);
	
	//모든 노드로 가기 위한 최단 거리 출력
	for(int i=0;i<=n;i++){
		//도달할 수 없는 경우, 무한(INFINITY) 출력
		if(d[i] == INF){
			cout << "INFINITY" << '\n';
		}
		//도달할 수 있는 경우 거리 출력
		else{
			cout << d[i] << '\n';
		}
	}
}