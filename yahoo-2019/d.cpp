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
    int l;
    ll tmp;
    vector<ll> a;
    cin >> l;
    vector<ll> l_accum(l, 0), r_accum(l, 0), l_end(l+1, 0), l_ret(l+1, 0), r_end(l+1, 0), r_ret(l+1, 0);
    for(int i=0;i<l;++i)
    {
        cin >> tmp;
        a.push_back(tmp);
    }

    ll l_tmp = 0;
    ll r_tmp = 0;
    for(int i=0;i<l;++i)
    {
        l_tmp += a[i];
        r_tmp += a[l - i - 1];
        l_accum[i] = l_tmp;
        r_accum[l - i - 1] = r_tmp;
    }

    bool l_end_returned = false;
    
    l_end[1] = a[0] == 0 ? 0 : (a[0] + 1) % 2;
    l_ret[1] = a[0] % 2;
    for(int i=2;i<=l;++i)
    {
        if(l_accum[i-1] <= l_end[i-1] + (a[i-1] + 1) % 2)
        {
            l_end_returned = true;
        }

        l_end[i] = min(l_end[i-1] + (a[i-1] + 1) % 2, l_accum[i-1]);
        l_ret[i] = min(l_ret[i-1] + (a[i-1] == 0 ? 2 : a[i-1] % 2), l_accum[i-1]);
    }

    // cerr << "l_end : ";
    // for(int i=0;i<=l;++i) cerr << l_end[i] << " ";
    // cerr << endl;

    // cout << "l_ret : ";
    // for(int i=0;i<=l;++i) cerr << l_ret[i] << " ";
    // cerr << endl;
    bool r_end_returned = false;
    r_end[l-1] = a[l-1] == 0 ? 0 : (a[l-1] + 1) % 2;
    r_ret[l-1] = a[l-1] % 2;
    for(int i=l-2;i>=0;--i)
    {
        if(r_accum[i] <= r_end[i+1] + (a[i] + 1) % 2)
        {
            r_end_returned = true;
        }
        r_end[i] = min(r_end[i+1] + (a[i] + 1) % 2, r_accum[i]);
        r_ret[i] = min(r_ret[i+1] + (a[i] == 0 ? 2 : a[i] % 2), r_accum[i]);
    }

    // cerr << "r_end : ";
    // for(int i=0;i<=l;++i) cerr << r_end[i] << " ";
    // cerr << endl;

    // cout << "r_ret : ";
    // for(int i=0;i<=l;++i) cerr << r_ret[i] << " ";
    // cerr << endl;

    // cerr << "l_accum : ";
    // for(int i=0;i<l;++i) cerr << l_accum[i] << " ";
    // cerr << endl;

    // cerr << "r_accum : ";
    // for(int i=0;i<l;++i) cerr << r_accum[i] << " ";
    // cerr << endl;

    ll res = 1ull << 63 - 1;
    for(int i=0;i<=l;++i)
    {
        ll ret_ret = l_ret[i] + r_ret[i];
        ll end_ret = l_end[i] + r_ret[i];
        ll ret_end = l_ret[i] + r_end[i];
        ll end_end = l_end[i] + r_end[i];
        res = min(res, min(ret_ret, min(end_ret, min(ret_end, end_end))));

    }

    cout << res << endl;
}