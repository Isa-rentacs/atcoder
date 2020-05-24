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
#include <unordered_map>

using namespace std;

#define dump(x) cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long
#define MOD 1000000007

/*
    init : O(n)
    query : O(1)
    constrall : 1 < k <= n < (about 10^7), mod is a prime, k,n < mod

    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

    p = (p / a) * a + (p % a)
    ( mod p * a^-1 for both ) <=> 0 = (p / a) + (p % a) * a^-1
    <=> - (p/a) = (p % a) * a^-1
    <=> a^-1 = - (p/a)^-1 * (p/a)
    <=> a^-1 = MOD - (p/a)^-1 * (p/a) % MOD

*/
const ll MAX_K = 300000;
bool fact_initialized = false;
long long fact[MAX_K], fact_inv[MAX_K], inv[MAX_K];

// This will be automatically called during combination_mod
void combination_init(ll mod)
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (ll i = 2; i < MAX_K; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % mod;
    }
}

// Used:
//   ABC151-E
long long combination_mod(ll n, ll k, ll mod)
{
    if (n < k || n < 0 || k < 0)
        return 0;
    if (!fact_initialized)
    {
        combination_init(mod);
        fact_initialized = true;
    }
    return fact[n] * (fact_inv[k] * fact_inv[n - k] % mod) % mod;
}

inline ll toll(string s)
{
    ll v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template <class T>
inline string toString(T x)
{
    ostringstream sout;
    sout << x;
    return sout.str();
}

pair<ll, ll> dfs1(int prev, int current, vector<vector<int>> &edges, map<pair<int, int>, ll> &num_nodes, map<pair<int, int>, ll> &num_ways)
{
    // dump(prev)
    // dump(current)
    auto prev_cur_pair = MP(prev, current);
    if (num_nodes.find(prev_cur_pair) != num_nodes.end())
    {
        return MP(num_nodes[prev_cur_pair], num_ways[prev_cur_pair]);
    }

    int subtree_nodes_sum = 0;
    vector<int> subtree_nodes;
    ll subtree_ways = 1;
    for (int next : edges[current])
    {
        if (next == prev)
            continue;
        auto child = dfs1(current, next, edges, num_nodes, num_ways);
        subtree_nodes_sum += child.first;
        subtree_nodes.push_back(child.first);
        subtree_ways *= child.second;
        subtree_ways %= MOD;
    }

    num_nodes[prev_cur_pair] = subtree_nodes_sum + 1;
    for (auto tmp : subtree_nodes)
    {
        subtree_ways *= combination_mod(subtree_nodes_sum, tmp, MOD);
        subtree_ways %= MOD;
        subtree_nodes_sum -= tmp;
    }
    num_ways[prev_cur_pair] = subtree_ways;

    return MP(num_nodes[prev_cur_pair], num_ways[prev_cur_pair]);
}

void dfs2(int prev, int current, vector<vector<int>> &edges, map<pair<int, int>, ll> &num_nodes, map<pair<int, int>, ll> &num_ways)
{
    auto tmp = dfs1(-1, current, edges, num_nodes, num_ways);

    int child_size = edges[current].size();
    ll l_nodes[child_size] = {};
    ll l_ways[child_size] = {};
    ll r_nodes[child_size] = {};
    ll r_ways[child_size] = {};

    int tmp_nodes = 0;
    ll tmp_ways = 1;
    // dump(current)
    for (int i = 0; i < child_size; ++i)
    {
        int next = edges[current][i];
        auto pair = dfs1(current, next, edges, num_nodes, num_ways);
        tmp_nodes += pair.first;
        tmp_ways *= pair.second;
        tmp_ways %= MOD;
        tmp_ways *= combination_mod(tmp_nodes, pair.first, MOD);
        tmp_ways %= MOD;
        l_nodes[i] = tmp_nodes;
        l_ways[i] = tmp_ways;
        // dump(next)
        // dump(l_nodes[i])
        // dump(l_ways[i])                
    }

    tmp_nodes = 0;
    tmp_ways = 1;
    for (int i = child_size - 1; i >= 0; --i)
    {
        int next = edges[current][i];
        auto pair = dfs1(current, next, edges, num_nodes, num_ways);
        tmp_nodes += pair.first;
        tmp_ways *= pair.second;
        tmp_ways %= MOD;
        tmp_ways *= combination_mod(tmp_nodes, pair.first, MOD);
        tmp_ways %= MOD;
        r_nodes[i] = tmp_nodes;
        r_ways[i] = tmp_ways;
        // dump(next)
        // dump(r_nodes[i])
        // dump(r_ways[i])                
    }
    
    for (int i = 0; i < child_size; ++i)
    {
        int next = edges[current][i];
        if (next == prev)
            continue;
        if(child_size == 1)
        {
            num_nodes[MP(next, current)] = 1;
            num_ways[MP(next, current)] = 1;
        }
        else
        {
            if (i == 0)
            {
                num_nodes[MP(next, current)] = r_nodes[1] + 1;
                num_ways[MP(next, current)] = r_ways[1];
            }
            else if (i == child_size - 1)
            {
                num_nodes[MP(next, current)] = l_nodes[i - 1] + 1;
                num_ways[MP(next, current)] = l_ways[i - 1];
            }
            else
            {
                tmp_nodes = l_nodes[i - 1] + r_nodes[i + 1];
                num_nodes[MP(next, current)] = tmp_nodes + 1;
                tmp_ways = l_ways[i - 1] * r_ways[i + 1] % MOD;
                tmp_ways *= combination_mod(tmp_nodes, l_nodes[i - 1], MOD);
                tmp_ways %= MOD;
                num_ways[MP(next, current)] = tmp_ways;
            }
        }

        dfs2(current, next, edges, num_nodes, num_ways);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    map<pair<int, int>, ll> num_nodes;
    map<pair<int, int>, ll> num_ways;
    ll a, b;
    for (ll i = 0; i < n - 1; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs1(-1, 0, edges, num_nodes, num_ways);
    dfs2(-1, 0, edges, num_nodes, num_ways);
    for (int i = 0; i < n; ++i)
    {
        cout << dfs1(-1, i, edges, num_nodes, num_ways).second % MOD << endl;
    }
}