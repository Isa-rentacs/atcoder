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
    int n, w;
    cin >> n >> w;
    int weight[n] = {};
    ll value[n] = {};
    for(int i=0;i<n;++i)
    {
        cin >> weight[i] >> value[i];
    }

    ll dp[n+1][w+1] = {};
    dp[0][0] = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=w;++j)
        {
            if(j+weight[i] <= w)
            {
                dp[i+1][j + weight[i]] = max(dp[i+1][j+weight[i]], dp[i][j] + value[i]);
            }
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    ll ret = 0;
    for(int i=0;i<=w;++i)
    {
        ret = max(ret, dp[n][i]);
    }

    cout << ret << endl;
}