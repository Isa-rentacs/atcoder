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

int a[1000001];
int f[1000001];
int n;
ll k;
bool fillable(ll val){
    vector<double> thresh(n);
    //dump(val)
    for(int i=0;i<n;++i)
    {
        thresh[i] = val * 1.0 / f[i];
        //dump(thresh[i])
    }
    sort(thresh.begin(), thresh.end());
    double diff = 0;
    for(int i=0;i<n;++i)
    {
        diff += max(0.0, ceil(a[i] - thresh[i]));
        //dump(diff)
    }
    return diff <= k;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll l = -1;
    ll r = 1000000000001ll;
    cin >> n >> k;
    for(int i=0;i<n;++i) cin >> a[i];
    for(int i=0;i<n;++i) cin >> f[i];
    sort(a, a + n);
    while((r-l) > 1)
    {
        ll mid = (l + r) / 2;
        if(fillable(mid))
        {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}