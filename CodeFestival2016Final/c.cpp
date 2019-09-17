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

struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N) { 
        for(int i = 0; i < N; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { 
        int rx = root(x); 
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    UnionFind uf(m+1);
    ll k, tmp, prev = -1;
    ll need_bridge[m+1] = {};
    for(int i=0;i<n;++i)
    {
        cin >> k;
        prev = -1;
        for(int j=0;j<k;++j)
        {
            cin >> tmp;
            if(prev != -1)
            {
                uf.unite(prev, tmp);
            }
            need_bridge[tmp] = 1;
            prev = tmp;
        }
    }

    ll root = -1;
    bool ret = true;
    // for(int i=1;i<=m;++i)
    // {
    //     cerr << uf.root(i) << endl;
    // }
    for(int i=1;i<=m;++i)
    {
        if(need_bridge[i] == 1)
        {
            if(root == -1)
            {
                root = uf.root(i);
            }
            else
            {
                if(root != uf.root(i)) ret = false;
            }
            
        }
    }

    cout << (ret ? "YES" : "NO") << endl;
}