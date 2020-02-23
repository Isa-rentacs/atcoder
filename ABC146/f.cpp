#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    int dp[n+1] = {};
    int prev[n+1] = {};
    for(int i=0;i<=n;++i)
    {
        dp[i] = 1 << 30;
        prev[i] = -1;
    }
    // 0001000
    dp[n] = 0;
    int current = n;
    bool updated = false;
    while(current > 0){
        updated=false;
        for(int j=m;j>0;--j)
        {
            if((current - j) < 0) continue;
            if(s[current-j] == '1') continue;
            if(dp[current-j] > dp[current] + 1)
                dp[current-j] = dp[current] + 1;
                prev[current-j] = j;
                current -= j;
                updated=true;
                break;
        }
        if(!updated) break;
    }

    if(dp[0] == (1<<30))
    {
        cout << "-1" << endl;
    }
    else {
        current = 0;
        while(current != n)
        {
            cout << prev[current];
            current += prev[current];
            if(current != n) {
                cout << " ";
            }
        }
        cout << endl;
    }
}