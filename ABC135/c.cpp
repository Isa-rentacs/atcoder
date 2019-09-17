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
    int n;
    cin >> n;
    ll a[n+1] = {};
    ll b[n] = {};
    ll ret = 0;
    for(int i=0;i<n+1;++i)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin >> b[i];
    }

    for(int i=0;i<n;++i)
    {
        ll cnt_i = min(a[i], b[i]);
        ret += cnt_i;
        b[i] -= cnt_i;
        ll cnt_ip1 = min(a[i+1], b[i]);
        a[i+1] -= cnt_ip1;
        ret += cnt_ip1;
    }
    cout << ret << endl;
}