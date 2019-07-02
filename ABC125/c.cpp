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

ll gcd(ll x, ll y)
{
    if((x % y) == 0)
    {
        return y;
    }

    return gcd(y, x % y);
}

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll a[n];

    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    
    ll left_gcd[n] = {};
    ll right_gcd[n] = {};

    left_gcd[0] = a[0];
    for(int i=1;i<n;++i)
    {
        left_gcd[i] = gcd(left_gcd[i-1], a[i]);
    }

    right_gcd[n-1] = a[n-1];
    for(int i=1;i<n;++i)
    {
        right_gcd[n-1-i] = gcd(right_gcd[n-1-i+1], a[n-1-i]);
    }

    ll ret = 0;

    for(int i=0;i<n;++i)
    {
        if (i == 0) {
            ret = max(ret, right_gcd[1]);
        } else if (i == (n-1)) {
            ret = max(ret, left_gcd[n-2]);
        } else {
            ret = max(ret, gcd(left_gcd[i-1], right_gcd[i+1]));
        }
    }

    cout << ret << endl;
}