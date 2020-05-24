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
    mod pow
    return pow(base, pow) % MOD
*/
long long mod_pow(const long long x, long long n, const long long mod) {
    long long res = 1;
    if (n == 0) return 1;
    if (n & 1) res = x;
    long long y = mod_pow(x, n >> 1, mod);
    res = (res * (y * y % mod)) % mod;
    return res;
}

/*
    mod (a can be negative)
*/
long long modulo(long long a, long long mod)
{
    return (a % mod + mod) % mod;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll ret = 0;

    ll count_table[k+1] = {};
    for(int i=k;i>=1;--i)
    {
        ll count_dividable = k / i;
        count_table[i] = mod_pow(count_dividable, n, MOD);

        for(int j=2;j*i<=k;++j)
        {
            count_table[i] = modulo(count_table[i] - count_table[i*j], MOD);
        }
    }

    for(int i=1;i<=k;++i)
    {
        ret += (count_table[i] * i) % MOD;
        ret %= MOD;
    }

    cout << ret << endl;
}