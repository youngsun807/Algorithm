#include<iostream>
#include<string>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string S;
    cin >> S;
    int freq[10] = {};
    for(auto s:S){
        if(s=='6') freq[9]++;
        else{
            freq[(int)s-'0']++;
        }
    }
    // for(int n=0;n<10;n++){
    //     cout << freq[n] << ' ';
    // }
    // cout << endl;
    freq[9] = (freq[9]+1)/2;
    int max = 0;
    for(int i=0;i<10;i++){
        if(freq[i]>max) max = freq[i];
    }
    cout << max;
}