#include <bits/stdc++.h>
using namespace std;

void test(int a){
    if(a>0) test(a-1);
}

int main(void){
    test(3500000);
    cout << "DONE ^_^";
}

