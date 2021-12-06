/*
cin.ignore(); only ERASE first character not all buffer

1. cin으로 입력받을 경우, 버퍼에 '\n'이 남는다.
2. cin 다음 입력을 cin으로 받을경우, 전 버퍼에 있던 공백 및 개행문자를 무시하기 때문에 버퍼를 굳이 비워줄 필요가 없다.
3. cin 다음 입력을 getline으로 받을경우, 전 버퍼에 있던 공백 및 개행문자를 포함해서 입력받기 때문에 버퍼를 지워주는 작업이 필요하다.
4. getline 다음 입력을 getline으로 받을경우, getline은 '\n' 문자를 버퍼에 포함시키기 않기때문에 버퍼를 비워줄 필요가 없다.
*/

#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int N;
string plans;
int x =1, y = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main()
{
    clock_t start = clock();
    cin >> N;
    cin.ignore();
    getline(cin, plans);
    
    
    for(int i=0;i<plans.size();i++){
        char plan = plans[i];
        
        int nx = -1, ny = -1;
        for(int j=0;j<4;j++){
            if(plan == moveTypes[j]){
                nx = x+dx[j];
                ny = y+dy[j];
            }
        }
        
        if(nx < 1 || ny < 1 || nx > N || ny > N) continue;
        
        x = nx;
        y = ny;
    }
    
    cout << x << ' ' << y << endl;
    
    
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}

//------------------------------------------
/*
caculation speed
1s = 200 million(200백만)

24*60*60 = 86400 < 200million

Exhaustive Search(완전 탐색) available
*/


#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int h;
int cnt;

bool check(int i, int j, int k){
    if(i % 10 == 3 || j % 10 == 3 || j / 10 == 3 || k % 10 == 3 ||k / 10 == 3){
        return true;
    }
    return false;
}

int main()
{
    clock_t start = clock();
    cin >> h;
    
    for(int i=0;i<=h;i++){
        for(int j=0;j<60;j++){
            for(int k=0;k<60;k++){
                if (check(i,j,k) == true) cnt += 1;;
            }
        }
    }
    
    cout << cnt <<endl;
    
    
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}
//------------------------------------------
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

string p;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int cnt;

int main()
{
    clock_t start = clock();
    cin >> p;
    int row = p[1] - '0';
    int column = p[0] - 'a'+ 1;
    
    
    for(int i=0;i<8;i++){
        int nextRow = row + dx[i];
        int nextColumn = column + dy[i];
        
        if(nextRow > 0 && nextRow < 9 && nextColumn > 0 && nextColumn < 9){
            cnt++;
        }
    }
    
    cout << cnt <<endl;
    
    
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}

//----------------------------------------
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

string S;
vector<char> arr;

int main()
{
    clock_t start = clock();
    cin >> S;
    
    int value = 0;
    for(int i=0;i<S.size();i++){
        if(isalpha(S[i])){
            arr.push_back(S[i]);
        }
        else{
            value += S[i] - '0';
        }
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i=0;i<arr.size();i++){
        cout << arr[i];
    }
    
    if(value != 0) cout << value << endl;
    
    
    clock_t end = clock();
    cout << (double)(end - start) << "ms";

    return 0;
}
