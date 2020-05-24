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
ll a[200001];
int ret[200001];


ll INF = 1ll << 60;
int calc_depth(int depth, int prev, int cur, vector<vector<int>> &edges)
{
    if(edges[cur].size() == 1)
    {
        return depth;
    }

    int ret = -1;
    for(auto next: edges[cur])
    {
        if(next == prev) continue;
        ret = max(ret, calc_depth(depth+1, cur, next, edges));
    }

    return ret;
}

void calc_lis(int prev, int cur, ll *dp, int max_depth, vector<vector<int>> &edges)
{
    int update_index = lower_bound(dp, dp+max_depth, a[cur]) - dp;
    ll back = dp[update_index];
    dp[update_index] = a[cur];
    ret[cur] = lower_bound(dp, dp+max_depth, INF) - dp;
    for(auto next: edges[cur])
    {
        if(next == prev) continue;
        calc_lis(cur, next, dp, max_depth, edges);
    }
    dp[update_index] = back;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    for(int i=0;i<n-1;++i)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    // First path, check depth
    for(auto dst: edges[0])
    {
        int depth = calc_depth(1, 0, dst, edges) + 1;
        ll dp[depth] = {};
        for(int i=0;i<depth;++i) dp[i] = INF;
        dp[0] = a[0];
        calc_lis(0, dst, dp, depth, edges);
    }
    cout << 1 << endl;
    for(int i=1;i<n;++i)
    {
        cout << ret[i] << endl;
    }
}