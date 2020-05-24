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
#include <cassert>
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

int parent[100001];
ll c[100001];

int fin(int node)
{
    vector<int> hist;
    int cur = node;
    while(parent[cur] != cur)
    {
        hist.push_back(cur);
        cur = parent[cur];
    }

    for(int x: hist)
    {
        parent[x] = cur;
    }

    return cur;
}

ll uni(int a, int b)
{
    int root_a = fin(a);
    int root_b = fin(b);
    
    if(root_a == root_b)
    {
        return 0;
    }

    ll count_a = c[root_a];
    ll count_b = c[root_b];

    parent[root_a] = root_b;
    c[root_b] = count_a + count_b;
    return count_a * count_b;
}

int main(){
    std::ios::sync_with_stdio(false);
    ll n, m, a, b;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    fill(c, c + 100001, 1);
    for(int i=0;i<m;++i)
    {
        cin >> a >> b;
        edges.push_back(MP(a, b));
    }
    for(int i=0;i<n;++i)
    {
        parent[i] = i;
    }

    ll ret = n * (n - 1) / 2;
    vector<ll> ret_vec;
    ret_vec.push_back(ret);
    for(int i=m-1;i>=0;--i)
    {
        ll diff = uni(edges[i].first, edges[i].second);
        ret -= diff;
        ret_vec.push_back(ret);
    }

    assert(ret == 0);

    for(int i=0;i<m;++i)
    {
        cout << ret_vec[m-1-i] << endl;
    }
}