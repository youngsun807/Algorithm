//binary search
/*
순차 탐색 - 리스트 안에 특정한 데이터를 찾기 위해 앞에서부터 하나씩 확인
이진 탐색 - 탐색 범위를 절반씩 좁혀가면서 탐색
(시작점, 끝점, 중간점을 이용하여 탐색 범위 설정)
연산횟수 = log2(N)에 비례 -> 절반씩 감소 -> O(logN)
*/

#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end){
    while(start <= end){
        int mid = (start+end) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) end = end - 1;
        else start = mid + 1;
    }
    
    return -1;
}

int n, target;
vector<int> arr;

int main(){
    clock_t start = clock();
    
    cin >> n >> target;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int result = binarySearch(arr, target, 0, n-1);
    if(result == -1){
        cout << "Can not Seach target" << endl;
    }
    else{
        cout << "target index is : " << result + 1 << endl;
    }
    clock_t end = clock();
    cout << (end-start) << "ms";
    
    return 0;
}

//---------------------------------------
//parametric search
/*
파라메트릭 서치 - 최적화 문제를 결정문제(예/아니오)로 바꾸어 해결하는 기법
(특정 조건을 만족하는 가장 알맞은 값을 빠르게 탐색하는 최적화 문제에 사용)
파라메트릭 서치 문제는 이진탐색을 이용하여 해결
*/ 
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end){
    while(start <= end){
        int mid = (start+end) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) end = end - 1;
        else start = mid + 1;
    }
    
    return -1;
}

int n, m;
vector<int> arr;

int main(){
    clock_t start_time = clock();
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int start = 0;
    int end = 1e9;
    
    int result = 0;
    while(start <= end){
        long long int total = 0;
        int mid = (start + end) / 2;
        for(int i=0;i<n;i++){
            if(arr[i] > mid) total += arr[i] - mid;
        }
        if(total < m){
            end = mid - 1;
        }
        else{
            result = mid;
            start = mid + 1;
        }
    }
    
    
    cout << result << endl;
    clock_t end_time = clock();
    cout << (end_time - start_time) << "ms";
    
    return 0;
}
//-------------------------------------------------
//binary search library
/*
lower_bound = 오름차순 정렬에서 배열 a에 x를 삽입할 가장 왼쪽 인텍스 반환
upper_bound = 오름차순 정렬에서 배열 a에 x를 삽입할 가장 오른쪽 인텍스 반환
*/
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int countByRange(vector<int>& v, int leftValue, int rightValue){
    vector<int>::iterator rightIndex = upper_bound(v.begin(), v.end(), rightValue);
    vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
    return rightIndex - leftIndex;
}

int n, m;
vector<int> arr;

int main(){
    clock_t start_time = clock();
    
    int count = 0;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    count = countByRange(arr, m, m);
    
    if (count == 0){
        cout << "Can not find target" << endl;
    }
    else{
        cout << count << endl;
    }

    clock_t end_time = clock();
    cout << (end_time - start_time) << "ms";
    
    return 0;
}