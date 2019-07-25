#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    deque<int> dq;
    int N, M;
    cin>> N >> M;
    int count=0;
    for(int i=1;i<N+1;i++){
        dq.push_back(i);
    }
    for(int j=0;j<M;j++){
        int num;
        cin >> num;
        int index;
        for(int k=0;k<dq.size();k++){
            if(dq[k]==num){
                index = k;
                break;
            }
        }
        if(index > dq.size()-index){
            while(dq.front()!=num){
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
            dq.pop_front();
        }
        else{
            while(dq.front()!=num){
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
            dq.pop_front();
        }
    }
    cout << count;
}