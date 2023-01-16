/*
next_permutation 알고리즘 내부 구조
> 참고 링크 : https://jeonggyun.tistory.com/110
+ 조건 만족하는 시작 쌍을 이룰때 (첫번째 원소 < 두번째 원소) 이어야 함
+ 맨 뒤 원소부터 앞으로 찾아올때 가장 처음으로 만난 쌍의 1번째 원소와 같거나 큰 원소 위치 = j
+ 쌍의 1번째 원소와 j위치 원소 swap
+ 쌍의 2번째 원소 포함 그 이후 원소들 오름차순 정렬
*/
//BOJ 15686 치킨집과의 최소거리 구하기
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define X first
#define Y second

int board[55][55];
int n, m;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house; 

int main(){
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1) house.push_back((i,j));
            if(board[i][j] == 2) chicken.push_back((i,j));
        }
    }
    
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin()+chicken.size() - m, 0);
    int mn = 0x7f7f7f;
    do{
        int dist = 0;
        for(auto h:house){
            int len = 0x7f7f7f;
            for(int i=0;i<chicken.size();i++){
                if(brute[i]==0) continue;
                len = min(len, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y)); //현재 집 위치에서 제일 가까운 치킨집과의 거리
            }
            dist += len; // 각 집 위치에서 최단거리 치킨집과의 거리 합
        }

        mn = min(mn, dist); // 치킨집 위치 조합마다 최단거리 합    
    }while(next_permutation(brute.begin(), brute.end()));

    cout << mn;
    return 0;
}
