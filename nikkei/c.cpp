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

/* Pass to std::sort */
bool predication(const pair<ll, pair<ll, ll> > &a, const pair<ll, pair<ll, ll> > &b){
    return a.first < b.first;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll t_sum = 0, a_sum = 0;
    ll a, b, n;
    cin >> n;
    vector<pair<ll,pair<ll, ll> > > piii;
    for(int i=0;i<n;++i)
    {
        cin >> a >> b;
        piii.push_back(make_pair(a+b, make_pair(a, b)));
    }

    sort(piii.rbegin(), piii.rend(), predication);

    for(int i=0;i<n;++i)
    {
        if((i%2) == 0)
        {
            t_sum += piii[i].second.first;
        }
        else
        {
            a_sum += piii[i].second.second;
        }
        
    }
    
    cout << t_sum - a_sum << endl;
}