//selection sort
/*
선택 정렬 - 처리되지 않은 데이터 중에서 가장 작은 데이터를 선택해 맨앞 데이터와 바꾸는 것을 반복
전체 횟수 = n + (n-1) + (n-2) + (n-3) ... + 2 = (n^2+n-2)/2 = O(N2)
*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n = 10;
int target[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(){
    clock_t start = clock();
    for(int i=0;i<n;i++){
        int min_index = i;
        for(int j=i+1;j<n;j++){
            if(target[min_index] > target[j]){
                min_index = j;
            }
        }
        swap(target[i], target[min_index]);
    }    
    
    for(int i=0;i<n;i++){
        cout << target[i] << ' ';
    }
    clock_t end = clock();
    cout << end - start << "ms";
    return 0;
}

//----------------------------------------------------
//insertion sort
/*
삽입 정렬 - 처리되지 않은 데이터를 하나씩 골라 적절한 위치에 삽입(왼쪽 데이터와 비교)
*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n = 10;
int target[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

int main(){
    clock_t start = clock();
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(target[j]< target[j-1]){
                swap(target[j], target[j-1]);   
            }
            else    break;
        }
    }    
    
    for(int i=0;i<n;i++){
        cout << target[i] << ' ';
    }
    clock_t end = clock();
    cout << end - start << "ms";
    return 0;
}

//-----------------------------------
//quick sort
/*
퀵 정렬 - 기준 데이터 설정 후 해당 기준보다 큰 데이터와 작은 데이터의 위치를 바꾸는 방법
정렬 라이브러리의 근간
기본 Logic - 1번째 데이터를 기준 데이터(Pivot)으로 설정
pivot 값 다음 위치부터 왼쪽을 시작할 때는 pivot값보다 큰 값, 오른쪽을 시작할 때는 pivot값보다 작은값 선택 후 swap
왼쪽에서 큰값, 오른쪽에서 작은값이 엇갈렸을 때는 작은값과 pivot값 위치 swap
pivot을 기준으로 양옆에 데이터 묶음 생성하는 작업 = 분할(divide, partition)
pivot 왼쪽 = pivot보다 작은값 / 오른쪽 = pivot보다 큰 값
데이터 묶음끼리 퀵정렬 수행 -> 퀵정렬이 재귀적으로 사용
O(NlogN) ~~ O(N2) -> 표준 라이브러리에서는 NlogN 보장
*/
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

int n = 10;
int target[10] = {7, 5, 9, 0, 3, 1, 6, 2, 4, 8};

void quickSort(int* target, int start, int end){
    if(start >= end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;
    while(left<=right){
        while(left <= end && target[left] <= target[pivot]) left++;
        while(right >= start+1 && target[right]>=target[pivot]) right--;
        if(left>right)  swap(target[pivot], target[right]);
        else    swap(target[left], target[right]);
    }

    quickSort(target, start, right-1);
    quickSort(target, left, end);
}

int main(){
    clock_t start = clock();
    
    quickSort(target, 0, n-1);
    
    for(int i=0;i<n;i++){
        cout << target[i] << ' ';
    }
    clock_t end = clock();
    cout << end - start << "ms";
    return 0;
}