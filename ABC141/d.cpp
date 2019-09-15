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

    multiset<ll> prices;
    ll n, m;
    cin >> n >> m;
    for(int i=0;i<n;++i)
    {
        int tmp;
        cin >> tmp;
        prices.insert(tmp);
    }

    while(m > 0)
    {
        ll largest = *(prices.rbegin());
        prices.erase(std::prev(prices.end()));
        prices.insert(largest / 2);
        --m;
    }
    ll ret = std::accumulate(prices.begin(), prices.end(), 0LL);
    cout << ret << endl;
}