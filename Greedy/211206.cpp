<Greedy Algorithm 12/06>

#include <iostream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int N, n;
vector<int> arr;

int group_count = 0;
int n_count = 0;

int main()
{
    clock_t start = clock();
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> n;
        
        arr.push_back(n);
    }
    
    sort(arr.begin(), arr.end());
    
    
    for(int i=0;i<N;i++){
        n_count += 1;
        
        if(n_count>=arr[i]){
           group_count += 1;
           n_count = 0;
        }
    }
    
    cout << group_count << endl;
    
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}
//------------------------------------------------