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
#include <unordered_map>

using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int main(){
    std::ios::sync_with_stdio(false);
    vector<ll> subseq_sum;
    int n, k;
    cin >> n >> k;
    ll a[n];
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }

    for(int i=1;i<=n;++i)
    {
        // initial sum
        ll init = 0;
        for(int j=0;j<i;++j)
        {
            init += a[j];
        }
        subseq_sum.push_back(init);

        for(int j=0;j<n-i;++j)
        {
            init += a[i+j];
            init -= a[j];
            subseq_sum.push_back(init);
        }
    }

    ll ret = 0;
    for(int i=0;i<=40;++i)
    {
        int cnt = 0;
        for(auto val :subseq_sum)
        {
            ll mask = ret | (1ll << (40 - i));
            if((val & mask) == mask) cnt++;
        }

        if(cnt >= k)
        {
            ret |= (1ll <<(40 - i));
        }
    }
    cout << ret << endl;
}