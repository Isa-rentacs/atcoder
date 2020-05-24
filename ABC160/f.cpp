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

#define dump(x)  cerr << #x << " = " << (x) << endl;
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

    for(ll i = 2; i < MAX_K; ++i)
    {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i-1] * inv[i] % mod;
    }
}

// Used:
//   ABC151-E
long long combination_mod(ll n, ll k, ll mod)
{
    if (n < k || n < 0 || k < 0) return 0;
    if(!fact_initialized)
    {
        combination_init(mod);
        fact_initialized = true;
    } 
    return fact[n] * (fact_inv[k] * fact_inv[n-k] % mod) % mod;
}


/*
    extGCD
    calculate (x, y) where ax + by = gcd(a,b)
*/
long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    long long d = extGCD(b, a%b, y, x);
    y -= a / b  *x;
    return d;
}

/*
    mod (a can be negative)
*/
long long modulo(long long a, long long mod)
{
    return (a % mod + mod) % mod;
}

/*
    mod inverse
    return x where ax mod m === 1

    constraint : gcd(a, m) = 1
*/
long long mod_inverse(long long a, long long mod)
{
    long long x, y;
    extGCD(a, mod, x, y);
    return modulo(x, mod);
}

inline ll toll(string s){ll v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

pair<ll, ll> dfs1(int prev, int current, vector<vector<int>> &edges, map<pair<int,int>, ll> &num_nodes, map<pair<int,int>, ll> &num_ways)
{
    // dump(prev)
    // dump(current)
    auto prev_cur_pair = MP(prev, current);
    if(num_nodes.find(prev_cur_pair) != num_nodes.end())
    {
        return MP(num_nodes[prev_cur_pair], num_ways[prev_cur_pair]);
    }

    int subtree_nodes_sum = 0;
    vector<int> subtree_nodes;
    ll subtree_ways = 1;
    for(int next: edges[current])
    {
        if(next == prev) continue;
        auto child = dfs1(current, next, edges, num_nodes, num_ways);
        subtree_nodes_sum += child.first;
        subtree_nodes.push_back(child.first);
        subtree_ways *= child.second;
        subtree_ways %= MOD;
    }
    // dump(subtree_ways)
    num_nodes[prev_cur_pair] = subtree_nodes_sum + 1;
    for(auto tmp: subtree_nodes)
    {
        // dump(subtree_nodes_sum)
        // dump(tmp)
        subtree_ways *= combination_mod(subtree_nodes_sum, tmp, MOD);
        // dump(combination_mod(subtree_nodes_sum, tmp, MOD))
        subtree_ways %= MOD;
        subtree_nodes_sum -= tmp;
    }
    num_ways[prev_cur_pair] = subtree_ways;

    // dump(num_nodes[prev_cur_pair])
    // dump(num_ways[prev_cur_pair])
    
    return MP(num_nodes[prev_cur_pair], num_ways[prev_cur_pair]);
}

void dfs2(int prev, int current, vector<vector<int>> &edges, map<pair<int,int>, ll> &num_nodes, map<pair<int,int>, ll> &num_ways)
{    
    auto tmp = dfs1(-1, current, edges, num_nodes, num_ways);
    int sum_nodes = tmp.first - 1;
    ll base_ways = tmp.second;
    // ll sum_nodes = 0;
    // for(auto next: edges[current])
    // {
    //     dump(next)
    //     dump(num_nodes[MP(current, next)])
    //     sum_nodes += num_nodes[MP(current, next)];
    // }
    for(auto next: edges[current])
    {
        if(next == prev) continue;
 
        ll comb = combination_mod(sum_nodes, num_nodes[MP(current, next)], MOD);
        num_ways[MP(next, current)] = ((base_ways * mod_inverse(comb, MOD)) % MOD) * mod_inverse(num_ways[MP(current, next)], MOD) % MOD;
        num_nodes[MP(next, current)] = num_nodes[MP(-1, current)] - num_nodes[MP(current, next)];
        dfs2(current, next, edges, num_nodes, num_ways);
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    map<pair<int,int>, ll> num_nodes;
    map<pair<int,int>, ll> num_ways;    
    ll a, b;
    for(ll i=0;i<n-1;++i)
    {
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs1(-1, 0, edges, num_nodes, num_ways);
    dfs2(-1, 0, edges, num_nodes, num_ways);
    for(int i=0;i<n;++i)
    {
        cout << dfs1(-1, i, edges, num_nodes, num_ways).second % MOD << endl;
    }
}