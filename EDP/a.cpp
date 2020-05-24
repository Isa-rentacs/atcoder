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
    int n;
    cin >> n;
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
        if(i+1 < n)
        {
            dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        }

        if(i+2 < n)
        {
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
        }
    }

    cout << dp[n-1] << endl;
}