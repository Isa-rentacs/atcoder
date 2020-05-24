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
#define MOD 1000000007
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
/*
    init : O(n)
    query : O(1)
    constraint : 1 < k <= n < (about 10^7), mod is a prime, k,n < mod

    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;

    p = (p / a) * a + (p % a)
    ( mod p * a^-1 for both ) <=> 0 = (p / a) + (p % a) * a^-1
    <=> - (p/a) = (p % a) * a^-1
    <=> a^-1 = - (p/a)^-1 * (p/a)
    <=> a^-1 = MOD - (p/a)^-1 * (p/a) % MOD

*/
const int MAX_K = 300000;
bool fact_initialized = false;
long long fact[MAX_K], fact_inv[MAX_K], inv[MAX_K];

// This will be automatically called during combination_mod
void combination_init(int mod)
{
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for(int i = 2; i < MAX_K; ++i)
    {
        fact[i] = fact[i-1] * i % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        fact_inv[i] = fact_inv[i-1] * inv[i] % mod;
    }
}

// Used:
//   ABC151-E
long long combination_mod(int n, int k, int mod)
{
    if (n < k || n < 0 || k < 0) return 0;
    if(!fact_initialized)
    {
        combination_init(mod);
        fact_initialized = true;
    } 
    return fact[n] * (fact_inv[k] * fact_inv[n-k] % mod) % mod;
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll ret = 0;
    for(ll i=k;i<=n+1;++i)
    {
        ll start = (0 + (i-1)) * i / 2;
        ll end = (n + (n - i + 1)) * i / 2;
        ret += end - start + 1;
        ret %= MOD;
    }
    cout << ret << endl;
}