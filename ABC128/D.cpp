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
    ll n, k;
    cin >> n >> k;
    ll v[n];
    for(int i=0;i<n;++i)
    {
        cin >> v[i];
    }

    ll ret = 0;
    for(int i=0;i<=k;++i)
    {
        for(int j=0;j<=k-i;++j)
        {
            if(i + j > n) {
                continue;
            }

            int remaining_steps = k - (i + j);
            ll sum = 0;
            vector<ll> gems;
            for(int jj = 0; jj < i; ++jj)
            {
                sum += v[jj];
                gems.PB(v[jj]);
            }

            for(int jj = 0; jj < j; ++jj)
            {
                sum += v[n-1 - jj];
                gems.PB(v[n - 1 - jj]);
            }

            sort(gems.rbegin(), gems.rend());
            while(!gems.empty() && remaining_steps > 0 && gems.back() < 0)
            {
                sum -= gems.back();
                gems.pop_back();
                remaining_steps--;
            }

            ret = max(ret, sum);
        }
    }

    cout << ret << endl;
}