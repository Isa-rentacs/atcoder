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

int main(){
    std::ios::sync_with_stdio(false);
    ll a, b, _q;
    cin >> a >> b >> _q;
    vector<ll> s(a);
    vector<ll> t(b);
    for(int i=0;i<a;++i)
    {
        cin >> s[i];
    }
    for(int i=0;i<b;++i)
    {
        cin >> t[i];
    }
    s.push_back(-1 * 1ll << 61);
    s.push_back(1ll << 61);
    t.push_back(-1 * 1ll << 61);
    t.push_back(1ll << 61);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for(int i=0;i<_q;++i)
    {
        ll q;
        cin >> q;
        // s lower bound
        auto s_lower_it = lower_bound(s.begin(), s.end(), q);
        ll s_lower = *(prev(s_lower_it));
        ll s_upper = *s_lower_it;
        auto t_lower_it = lower_bound(t.begin(), t.end(), q);
        ll t_lower = *(prev(t_lower_it));
        ll t_upper = *t_lower_it;
        // dump(s_lower);
        // dump(s_upper);
        // dump(t_lower);
        // dump(t_upper);
        ll same_lower = max(q - s_lower, q - t_lower);
        ll same_upper = max(s_upper - q, t_upper-q);
        ll s_upper_t_lower = s_upper - t_lower + min(s_upper - q, q - t_lower);
        ll s_lower_t_upper = t_upper - s_lower + min(t_upper - q, q - s_lower);

        cout << min(same_lower, min(same_upper, min(s_upper_t_lower, s_lower_t_upper))) << endl;
    }
}