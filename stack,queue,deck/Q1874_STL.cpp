# include <iostream>
# include <stack>
# include <queue>
# include <list>
# include <string.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    stack<int> S;
    string result;
    list<int> L;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        L.push_back(x);
    }
    // for(auto s:L){
    //     cout << s;
    // }
    
    int max = 1;
    bool end = false;
    list<int>::iterator it = L.begin();
    for(int k=1;k<=*it;k++){
        S.push(max++);
        result += '+';
    }
    for(auto s:L){
        if(S.empty() || s > S.top()){
            for(int i=max;i<=s;i++){
                S.push(max++);
                result += '+';
            }
            S.pop();
            result += '-';
        }
        // cout << s << ' ' << S.top() << endl;
        else if(s==S.top()){
            S.pop();
            result += '-';
            // cout << "success" << endl;
        }
        // else if(S.empty()){
        //     for(int k=max;k<=s;k++){
        //         S.push(k);
        //         max++;
        //         Q.push("+");
        //     }
        //     S.pop();
        //     Q.push("-");
        // }
        else{
            end = true;
            break;
        }
    }
    // cout << Q.back() << endl;
    if(end){
        cout << "NO\n";  
    }
    else{
        for(int v=0;v<result.size();v++){
            cout << result[v] << '\n';
        }
    }
}