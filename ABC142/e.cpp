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

int dp[1002][1<<12];

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> cost(m);
    vector<int> open_set(m);
    for(int i=0;i<m;++i)
    {
        cin >> cost[i];
        int b, tmp;
        cin >> b;
        for(int j=0;j<b;++j)
        {
            cin >> tmp;
            open_set[i] |= 1 << (tmp-1);
        }
    }
    
    for(int i=0;i<m+1;++i)
        for(int j=0;j<(1<<12);++j)
            if(i==0 && j ==0)
            {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (1ll << 30) - 1;
            }

    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<(1<<12);++j)
        {
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][j|open_set[i-1]] = min(dp[i][j|open_set[i-1]], dp[i-1][j] + cost[i-1]);
        }
    }

    if(dp[m][(1<<n)-1] == (1ll<<30) - 1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[m][(1<<n)-1] << endl;
    }
}