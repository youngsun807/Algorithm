<Greedy Algorithm 11/30>
/*
Big O(K) = number of coin type
no relation with n, only effected by number of coin type
*/
#include <iostream>
#include <string>
using namespace std;

int n = 1260;
int count = 0;

int a[4] = {500, 100, 50, 10};
int length = sizeof(a) / sizeof(int);
int main(){
    for(int i=0;i<length;i++){
        count += n / a[i];
        n %= a[i];
        cout << "cost : " << a[i] << " count : " << count << " n : "<< n <<endl;
    }
    
    cout << "total : " << count;
    
    return 0;
}

//--------------------------------------------------------------------------------------


#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

// my code
int N, K;
int count = 0;

int main(){
    clock_t start_time = clock();
    cin >> N >> K;
    while(N!=1){
        if(N%K!=0){
            while(N%K==0){
                N -=1;
                count +=1;
                cout << "count1 : " << count << endl;
            }
        }
    
    
        N /= K;
        count += 1;
        cout << "count2 : " << count <<endl;
    }
    
    cout << "total : " << count << endl;
    
    clock_t end_time = clock();
    cout << (double)(end_time - start_time) << "ms";
    
    return 0;
}

//example
int n,k;
int result;

int main(){
    cin >> n >> k;
    while(true){
        int target = (n / k) * k;
        result += (n - target);
        n = target;
        
        if(n < k) break;
        
        n /= k;
        result +=1;
    }
    
    result += (n - 1);
    cout << result << endl;
    return 0;
}

//------------------------------------------------------------
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// my code
string S;
int result;
int length;

int main(){
    clock_t start_time = clock();
    cin >> S;
    result = S[0] - '0';
    
    for(int i=1;i<S.length();i++){
        int n = S[i] - '0';
        if(S[i] <=1 || result <=1)  result += n;
        else                        result *= n;
    }
    
    cout << "result : " << result << endl;
    clock_t end_time = clock();
    cout << (double)(end_time - start_time) << "ms";
    
    return 0;
}

//----------------------------------------------------