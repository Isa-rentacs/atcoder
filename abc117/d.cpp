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
    ll k;
    cin >> n >> k;
    vector<ll> a(n, 0);
    ll tmp;
    ll ans = 0;
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }

    for(int i=40;i>=0;--i){
        //dump(i)
        ll mask = 1ll << i;
        int bit = 0;
        if(mask > k)
        {
            // can't use k
            bit = 0;
            int count_ones = 0;
            for(int j=0;j<n;++j)
            {
                if ((a[j] & (1ll << i)) != 0)
                {
                    count_ones++;
                }
            }
            ans += count_ones * (1ll << i);
        }
        else
        {
            int count_zeros = 0;
            int count_ones = 0;
            for(int j=0;j<n;++j)
            {
                if ((a[j] & (1ll << i)) != 0)
                {
                    count_ones++;
                }
                else
                {
                    count_zeros++;
                }
            }
            if(count_ones > count_zeros)
            {
                bit = 0;
                ans += count_ones * (1ll << i);
            }
            else
            {
                bit = 1;
                ans += count_zeros * (1ll << i);
            }
            
            if (bit == 1)
            {
                k -= (1ll << i);
                //dump(k);
            }
        }
        //dump(ans);
    }
    cout << ans << endl;
}