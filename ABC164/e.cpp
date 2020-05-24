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

#define dump(x)  cout << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
ll dp[51][2451] = {};
int main(){
    std::ios::sync_with_stdio(false);
    ll n,m,s;
    cin >> n >> m >> s;
    vector<pair<int,pair<int,int>>> edges[n];
    pair<int,int> exchange[n];
    for(int i=0;i<51;++i)
    {
        for(int j=0;j<2451;++j)
        {
            dp[i][j] = 1ll << 60;
        }
    }
    for(int i=0;i<m;++i)
    {
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        --u;
        --v;
        edges[u].push_back(MP(v, MP(a, b)));
        edges[v].push_back(MP(u, MP(a, b)));
    }
    for(int i=0;i<n;++i)
    {
        int c, d;
        cin >> c >> d;
        exchange[i] = MP(c,d);
    }

    deque<pair<int,pair<int, ll>>> q;
    q.push_back(MP(0, MP(s, 1ll)));
    s = min(2450ll, s);
    dp[0][s] = 0;
    while(!q.empty())
    {
        auto top = q.front();
        q.pop_front();
        int current = top.first;
        int coin = top.second.first;
        ll state = top.second.second;
        int exchange_coin = exchange[current].first;
        int exchange_time = exchange[current].second;

        for(auto edge : edges[current]){
            int dst = edge.first;
            //if((state & (1 << dst)) != 0 ) continue;
            int cost_coin = edge.second.first;
            int cost_time = edge.second.second;
            int exchange_times = 0;
            while(true)
            {
                int next_coin = min(coin + exchange_times * exchange_coin, 2450);
                if(next_coin >= cost_coin)
                {
                    if(dp[dst][next_coin - cost_coin] > dp[current][coin] + exchange_times * exchange_time + cost_time)
                    {
                        q.push_back(MP(dst, MP(next_coin - cost_coin, state | 1 << dst)));
                        dp[dst][next_coin - cost_coin] = dp[current][coin] + exchange_times * exchange_time + cost_time;
                        // dump(dst)
                        // dump(dp[current][coin])
                        // dump(exchange_times)
                        // dump(next_coin)
                        // dump(cost_coin)
                        // dump(exchange_time)
                        cout << "dp[" << dst << "][" << next_coin - cost_coin << "] = " << dp[current][coin] + exchange_times * exchange_time + cost_time << endl;
                    }
                }

                if(next_coin == 2450) break;
                exchange_times++;
            }
        }
    }
    for(int i=1;i<n;++i)
    {
        ll ret = 1ll << 60;
        for(int j=0;j<2451;++j)
        {
            ret = min(ret, dp[i][j]);
        }
        cout << ret << endl;
    }
}