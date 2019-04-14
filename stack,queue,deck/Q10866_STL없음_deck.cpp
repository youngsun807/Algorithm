#include <bits/stdc++.h>
using namespace std;

const int MX = 1000007;
int dat[2*MX+3];
int head = MX, tail = MX;

void push_front(int val){
    dat[--head] = val; //head는 맨 처음 값이 있는 위치 가리킴
}

void push_back(int val){
    dat[tail++] = val;//tail은 맨 마지막 값이 있는 위치 다음 위치 가리킴
}

void pop_front(){
    head++;
}

void pop_back(){
    tail--;
}

int front(){
    return dat[head];
}

int back(){
    return dat[tail-1];
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        string dq;
        cin >> dq;
        if(dq == "push_front"){
            int val;
            cin >> val;
            push_front(val);
        }
        else if(dq == "push_back"){
            int val;
            cin >> val;
            push_back(val);
        }
        else if(dq == "pop_front"){
            if(tail==head){
                cout << -1 << '\n';
            }
            else{
                cout << front() << '\n';
                pop_front();
            }
        }
        else if(dq == "pop_back"){
            if(tail==head){
                cout << -1 << '\n';
            }
            else{
                cout << back() << '\n';
                pop_back();
            }
        }
        else if(dq == "size"){
            cout << (tail-head) << '\n';
        }
        else if(dq == "empty"){
            cout << (tail==head) << '\n';
        }
        else if(dq == "front"){
            if(tail==head){
                cout << -1 << '\n';
            }
            else{
                cout << front() << '\n';
            }
        }
        else{
            if(tail==head){
                cout << -1 << '\n';
            }
            else{
                cout << back() << '\n';
            }
        }
    }
}