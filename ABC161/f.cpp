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

vector<pair<ll, ll>> factorize(ll x)
{
    vector<pair<ll, ll>> ret;
    for(ll i=2;i*i <= x; ++i)
    {
        int count_divided = 0;
        while(x % i == 0)
        {
            x /= i;
            count_divided++;
        }

        if(count_divided != 0)
        {
            ret.push_back(make_pair(i, count_divided));
        }
    }
    if(x != 1)
    {
        ret.push_back(make_pair(x, 1));
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    if(n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    auto n_fact = factorize(n);
    auto n_1_fact = factorize(n-1);

    ll ret = 1;
    for(auto pair : n_1_fact)
    {
        ret *= (pair.second + 1);
    }
    ret--;

    ll orig_n = n;
    for(ll i=1;i*i<=n;++i)
    {
        if(n % i == 0)
        {
            if(i != 1)
            {
                while(n % i == 0) n /= i;
                if(n % i == 1) ret++;
                n = orig_n;
            }
            if(i*i != n)
            {
                ll div = n/i;
                while(n % div == 0) n /= div;
                if(n % div == 1) ret++;
                n = orig_n;
            }   
        }
    }
    cout << ret << endl;
}