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

const int MAX_K = 300000;
bool fact_initialized = false;
long long fact[MAX_K], fact_inv[MAX_K], inv[MAX_K];

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

long long MOD = 1000000007;
int main(){
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    ll ret = 0;
    for(int i=0;i<n;++i)
    {
        ret -= combination_mod(i, k-1, MOD) * a[i];
        ret += combination_mod(n-1-i, k-1, MOD) * a[i];
        ret %= MOD;
    }

    cout << ret << endl;
}