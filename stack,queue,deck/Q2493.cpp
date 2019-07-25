#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    stack<pair<int, int>> S;
    queue<int> q;
    int temp = 0;
    for(int i=1;i<N+1;i++){
        int x;
        cin >> x;
        while(!S.empty()){
            if(S.top().second > x){
                q.push(S.top().first);
                break;
            }
            else if(S.top().second <= x){
                S.pop();
            }
        }
        if(S.empty()) q.push(0);
        S.push(make_pair(i, x));
    }
    for(int j=0;j<N;j++){
        cout << q.front() << ' ';
        q.pop();
    }
}