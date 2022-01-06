/*
LIS = 가장 긴 증가하는 부분 수열(Longest Increasing Subsequence)
전형적인 DP 문제 아이디어와 동일 -> O(n^2)
array = {4,2,5,8,4,11,15} -> LIS = {4,5,8,11,15}

본 문제는 가장 긴 감소하는 수열 찾는 문제
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n;
vector<int> arr;

int main(){
    clock_t start = clock();
    
    cin >> n;
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    reverse(arr.begin(), arr.end());
    
    int dp[2000];
    for(int i=0;i<n;i++) dp[i] = 1;
    for(int i=1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j] > arr[i]) dp[i] = max(dp[i], dp[j]+1);        
        }
    }
    
    int maxValue = 0;
    for(int i=0;i<n;i++) maxValue = max(maxValue, dp[i]);
    
    cout << maxValue << endl;
    
    clock_t end = clock();
    
    cout << end - start << "ms";
    return 0;
}