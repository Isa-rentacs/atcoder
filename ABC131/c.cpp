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

ll gcd(ll a, ll b)
{
    if (a % b == 0)
    {
        return b;
    }

    return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll a, b, c, d;
    cin >> b >> a >> c >> d;
    ll c_d_lcm = lcm(c,d);

    ll a_c = a / c;
    ll a_d = a / d;
    ll a_c_d = a / c_d_lcm;
    ll a_ans = a - a_c - a_d + a_c_d;

    ll b_c = (b-1) / c;
    ll b_d = (b-1) / d;
    ll b_c_d = (b-1) / c_d_lcm;
    ll b_ans = (b-1) - b_c - b_d + b_c_d;

    cout << a_ans - b_ans << endl;
}