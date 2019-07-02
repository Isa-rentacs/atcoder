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
    int n, m;
    cin >> n >> m;
    vector<ll> a;
    map<ll, int> replacements;
    for(int i=0;i<n;++i)
    {
        ll tmp;
        cin >> tmp;
        a.PB(tmp);
    }
    sort(a.begin(), a.end());
    for(int i=0;i<m;++i)
    {
        ll b, c;
        cin >> b >> c;
        replacements[c] += b;
    }

    auto iter = replacements.rbegin();
    for(int i=0;i<n;++i)
    {
        if(a[i] < iter->first)
        {
            iter->second--;
            a[i] = iter->first;
            if(iter->second == 0)
            {
                ++iter;
                if(iter == replacements.rend()) {
                    break;
                }
            }
        }
    }

    cout << std::accumulate(a.begin(), a.end(), 0ll) << endl;
}