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
#define MOD 998244353
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

long long mod_pow(const long long x, long long n, const long long mod) {
    long long res = 1;
    if (n == 0) return 1;
    if (n & 1) res = x;
    long long y = mod_pow(x, n >> 1, mod);
    res = (res * (y * y % mod)) % mod;
    return res;
}

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
    ll n, m, k;
    cin >> n >> m >> k;
    ll ret = 0;
    for(int i=0;i<=k;++i)
    {
        ll tmp = 0;
        tmp = m * mod_pow(m-1, n-1-i, MOD) % MOD;
        tmp *= combination_mod(n-1, i, MOD);
        tmp %= MOD;
        ret += tmp;
        ret %= MOD;
    }
    cout << ret << endl;
}