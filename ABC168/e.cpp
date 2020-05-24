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

class Counts {
public:
    long long x;
    long long y;
    long long count;
    bool operator < (const Counts &arg) const{
        return atan2(y, x) < atan2(arg.y, arg.x);
    }
};

ll gcd(ll a, ll b)
{
    if(a%b == 0) return b;

    return gcd(b, a%b);
}

long long mod_pow(const long long x, long long n, const long long mod) {
    long long res = 1;
    if (n == 0) return 1;
    if (n & 1) res = x;
    long long y = mod_pow(x, n >> 1, mod);
    res = (res * (y * y % mod)) % mod;
    return res;
}

map<pair<ll, ll>, int> counts;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int zero_zero = 0;
    ll ret = 1;
    for(int i=0;i<n;++i)
    {
        ll a, b;
        cin >> a >> b;
        if(a==0 && b==0){
            zero_zero++;
            continue;
        }
        if(a==0 || b == 0)
        {
            if(a==0) b = 1;
            if(b==0) a = 1;
            counts[MP(a,b)]++;
            continue;
        }

        if(b < 0)
        {
            a *= -1;
            b *= -1;
        }
        ll _gcd = gcd(abs(a), abs(b));
        counts[MP(a/_gcd, b/_gcd)]++;
    }

    for(auto& tmp: counts)
    {
        ll x = tmp.first.first;
        ll y = tmp.first.second;
        ll count_a = tmp.second;
        ll count_b = counts[MP(-y, x)] + counts[MP(y, -x)];

        ret *= (mod_pow(2, count_a, MOD) + mod_pow(2, count_b, MOD)) - 1;
        ret %= MOD;

        tmp.second = 0;
        counts[MP(-y, x)] = 0;
        counts[MP(y, -x)] = 0;
    }

    ret += zero_zero;
    ret %= MOD;
    ret -= 1;
    if(ret < 0) ret += MOD;
    cout << ret << endl;
}