/*
ai = 금액 i를 만들 수 있는 최소한의 화폐 개수
k = 각 화폐의 단위
각 화폐 단위인 k를 하나씩 확인하며
a(i-k) 만드는 방법 존재 시 ai = min(ai, a(i-k)+1)
				미존재시 ai = INF
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n,m;
vector<int> arr;

int main(){
    clock_t start = clock();
    
    cin >> n >> m;
    
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    vector<int> d[m+1, 10001];
    
    d[0] = 0;
    for(int i=0;i<n;i++){
        for(int j = arr[i];j<=m;j++){
            if(d[j - arr[i]] != 10001){
                d[j] = min(d[j], d[j-arr[i]]+1);
            }
        }
    }
    
    if(d[m] == 10001) cout << -1 << endl;
    else cout << d[m] << endl;
    clock_t end = clock();
    
    cout << end - start << "ms";
    
    return 0;
}

//---------------------------
/*
array[i][j] = i행 j열에 존재하는 금의 양
dp[i][j] = i행 j열까지의 최적해(얻을 수 있는 금의 최대값)
dp[i][j] = array[i][j]+max(dp[i-1][j-1], dp[i][j-1], dp[i+1][j-1])
이동 가능 범위 체크
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int testCase, n, m;
int arr[20][20];
int dp[20][20];

int main(){
    clock_t start = clock();
    cin >> testCase;
    for(int tc= 0;tc<testCase;tc++){
        cin >> n >> m;
        for(int i=0;i<n;i++){
            for(int j= 0;j<m;j++){
                cin >> arr[i][j];
            }
        }
    
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j] = arr[i][j];
            }
        }
        
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                int leftUp, leftDown, left;
                
                if(i==0) leftUp = 0;
                else leftUp = dp[i-1][j-1];
                
                if(i==n-1) leftDown = 0;
                else leftDown = dp[i+1][j-1];
                
                left = dp[i][j-1];
                dp[i][j] = dp[i][j] + max(left, max(leftDown, leftUp));
            }
        }
        
        int result = 0;
        for(int i=0;i<n;i++){
            result = max(result, dp[i][m-1]);
        }
        
        cout << result << endl;
    }
    clock_t end = clock();
    
    cout << end - start << "ms";
    
    return 0;
}