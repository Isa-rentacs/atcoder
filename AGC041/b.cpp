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
    ll n,m,v,p;
    cin >> n >> m >> v >> p;
    vector<ll> a(n);
    for(int i=0;i<n;++i)
    {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int threshold = a[p-1];
    int res = p-1;
    ll total_votes = v * m;
    ll cum_sum = 0;
    for(int i=p-1;i<n;++i)
    {
        if(threshold > (a[i] + m)) {
            cerr << "not reachable" << endl;
            cum_sum += a[i];
            continue;
        }
        int k = n - i;
        ll vote_consumable = (k + (p-1)) * m;
        if(vote_consumable >= total_votes) {
            cerr << "all safely consumable" << endl;
            res++;
            cum_sum += a[i];
            continue;
        }
        ll need_to_consume = total_votes - vote_consumable;
        ll capacity = (m + a[i]) * (n - k - (p - 1)) - cum_sum;
        if(capacity >= need_to_consume){
            cerr << "Can be selected" << endl;
            res++;
        }
        cum_sum += a[i];
    }
    cout << res << endl;
}