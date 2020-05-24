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
    ll h[n] = {};
    bool good[n] = {};
    vector<int> edges[n];
    for(int i=0;i<n;++i)
    {
        cin >> h[i];
        good[i] = true;
    }

    for(int i=0;i<m;++i)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if(h[u] == h[v])
        {
            good[u] = false;
            good[v] = false;
        }else if(h[u] > h[v])
        {
            good[v] = false;
        }else{
            good[u] = false;
        }
    }

    int ret = 0;
    for(int i=0;i<n;++i)
    {
        if(good[i]) ret++;
    }
    cout << ret << endl;

}