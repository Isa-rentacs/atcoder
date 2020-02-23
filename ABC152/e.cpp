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

inline ll toll(string s){ll v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

ll mod_pow(const ll x, ll n, const ll mod) {
    ll res = 1;
    if (n == 0) return 1;
    if (n & 1) res = x;
    ll y = mod_pow(x, n >> 1, mod);
    res = (res * (y * y % mod)) % mod;
    return res;
}

bool visited[1000100];
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);

    for(ll i=0;i<n;++i){
        cin >> a[i];
    }

    map<ll,ll> factors;
    for(ll i=0;i<n;++i)
    {
        ll tmp = a[i];
        ll cnt = 0;
        for(ll ind=2; (ind * ind) <= tmp; ++ind)
        {
            while((tmp % ind) == 0) {
                cnt++;
                tmp /= ind;
            }

            if(cnt != 0)
            {
                factors[ind] = max(factors[ind], cnt);
            }
            cnt = 0;
        }
        factors[tmp] = max(factors[tmp], 1ll);
    }
    // for each a, would like to calc gcd / a mod MOD
    ll lcm_mod = 1;
    for(const auto& factor : factors) {
        lcm_mod *= mod_pow(factor.first, factor.second, MOD);
        lcm_mod %= MOD;
    }

    ll res = 0;
    for(ll i=0;i<n;++i)
    {
        ll tmp = lcm_mod * mod_pow(a[i], MOD-2, MOD);
        res += tmp;
        res %= MOD;
    }

    cout << res << endl;

    return 0;
}
