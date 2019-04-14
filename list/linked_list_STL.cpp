#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
    list<int> L = {1,2};
    list<int>::iterator t = L.begin();
    L.push_front(10);
    cout << *t << '\n';//1
    L.push_back(5);
    L.insert(t, 6);
    t++;
    t = L.erase(t);
    t = L.end();
    for(auto i :L) cout << i << ' ';//{10,6,1,5}

    return 0;
}