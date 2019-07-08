// #include<iostream>
// #include<string>
// #include<vector>
// #include<algorithm>
// using namespace std;

// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
    
//     int n, s;
//     cin >> n >> s;
//     vector<int> v;

//     for(int i=0;i<n;i++){
//         v.push_back(i+1);
//     }
//     // for(int ii=0;ii<n;ii++){
//     //     cout << v[ii] << ' ';
//     // }
//     cout << "<" ;
    
//     while(v.size()>0){
//         // cout << x << ' ' << v[0] << endl;

//             v.push_back(v[0]);
//             v.erase(v.begin());
//             v.push_back(v[0]);
//             v.erase(v.begin());

//             cout << v.front() 
//             v.erase(v.begin());
//         }
//         // cout << v.front() << ' ' << v.back() << endl;
//         if(v.size()!=0){
//             cout << ", ";
//         }
//     }
//     cout << ">" ;
// }
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, s;
    cin >> n >> s;
    vector<int> v;
    for(int i=0;i<n;i++){
        v.push_back(i+1);
    }
    vector<int>::iterator it = v.begin();
    cout << "<";
    while(v.size()>1){
        for(int c=0;c<s-1;c++){
            it++;
            if(it == v.end()){
                it = v.begin();
            }
        }
        cout << *it << ", ";
        v.erase(it);
        if(it == v.end()){
            it = v.begin();
        }
    }
    cout << *it;
    cout << ">";
}
// #include <iostream>
// #include <vector>
// using namespace std;
// int main() { 
//     int n, m, k = 0;
//     cin >> n >> m;
//     vector<int> lst; 
//     for (int i = 0; i < n; ++i) {
//         lst.push_back(i + 1);
//     }
//     cout << '<';
//     while (lst.size() > 0) {
//         k = (k + m - 1) % lst.size();
//         cout << lst.at(k);
//         lst.erase(lst.begin() + k);
//         if (lst.size() > 0) {
//             cout << ", ";
//         }
//     }
//     cout << '>' << endl;
// }
