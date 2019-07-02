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
    ll x, y, z, K;
    cin >> x >> y >> z >> K;
    ll ones[x] = {};
    ll twos[y] = {};
    ll threes[z] = {};
    for(int i=0;i<x;++i)
    {
        cin >> ones[i];
    }

    for(int i=0;i<y;++i)
    {
        cin >> twos[i];
    }

    for(int i=0;i<z;++i)
    {
        cin >> threes[i];
    }

    sort(ones, ones + x, greater<ll>());
    sort(twos, twos + y, greater<ll>());
    sort(threes, threes + z, greater<ll>());

    vector<ll> candidates;
    for(int i=0;i<x;++i)
    {
        for(int j=0;j<y;++j)
        {
            for(int k=0;k<z;++k)
            {
                if((ll)(i+1) * (j+1) * (k+1) > K) break;
                candidates.PB(ones[i] + twos[j] + threes[k]);
            }
        }
    }
    sort(candidates.rbegin(), candidates.rend());

    for(int i=0;i<K;++i)
    {
        cout << candidates[i] << endl;
    }
}