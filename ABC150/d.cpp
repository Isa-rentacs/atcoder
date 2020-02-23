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
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main(){
    std::ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> num_two_factor(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
        a[i] /= 2;
        int tmp = a[i];
        int cnt = 0;
        while((tmp % 2) == 0) {
            cnt++;
            tmp /= 2;
        }
        num_two_factor[i] = cnt;
        a[i] = tmp;
    }

    for(int i=0;i<n-1;++i)
    {
        if(num_two_factor[i] != num_two_factor[i+1])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    
    for(int i=0;i<num_two_factor[0];++i) m /= 2;
    // calc lcm
    ll lcm_ = 1;
    for(int i=0;i<n;++i)
    {
        lcm_ = lcm(lcm_, a[i]);
    }

    if (m < lcm_) {
        cout << 0 << endl;
    }
    else
    {
        // cout << ((m / lcm_) + 1) / 2
        cout << (m - lcm_) / (2 * lcm_) + 1 << endl;        
    }
}