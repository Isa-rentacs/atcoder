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

bool predication(const pair<int,int> &a, const pair<int,int> &b){
    return a.first > b.first;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n, tmp = 0;
    cin >> n;
    vector<pair<ll,ll>> a;
    for(int i=0;i<n;++i)
    {
        cin >> tmp;
        a.push_back(MP(tmp, i));
    }
    sort(a.begin(), a.end(), predication);

    ll dp[n+1][n+1] = {};
    // dp[i-th][right]
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {

            // put to the left : i-j
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i].first * abs(a[i].second - (i-j)));
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + a[i].first * abs(n-1-j - a[i].second));
        }
    }

    ll ret = -1;
    for(int i=0;i<=n;++i)
    {
        ret = max(ret, dp[n][i]);
    }
    cout << ret << endl;
}