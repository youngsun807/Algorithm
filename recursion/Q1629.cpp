#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll POW(ll a, ll b, ll m){
  if(b==0) return 1;
  ll val = POW(a,b/2,m);
  val = val*val%m;
  if(b%2 == 0) return val;
  return val*a%m;
}
int main(void){
  ll a,b,c;
  cin >> a >> b >> c;
  cout << POW(a,b,c); // 나머지 구하는 공식
}