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
    int n, k;
    cin >> n >> k;
    int h[n] = {};
    for(int i=0;i<n;++i)
    {
        cin >> h[i];
    }
    int dp[n] = {};
    for(int i=0;i<n;++i)
    {
        dp[i] = 1 << 30;
    }

    dp[0] = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            if((i + j) < n)
            {
                dp[i+j] = min(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
            }
        }
    }

    cout << dp[n-1] << endl;
}