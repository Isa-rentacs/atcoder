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

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, u, v, s, t;
    cin >> n >> m;
    map<int, vector<int>> edges;
    int state[n] = {};
    int visited[n][3] = {};
    for(int i=0;i<m;++i)
    {
        cin >> u >> v;
        --u;
        --v;
        edges[u].push_back(v);
    }
    cin >> s >> t;
    --s;
    --t;
    queue<pair<int,pair<int,int>>> q;
    q.push(MP(s, MP(0, 0)));
    visited[s][0] = 1;
    ll res = -1;
    while(!q.empty()) {
        auto front = q.front();
        int cur = front.first;
        int mod = front.second.first;
        int depth = front.second.second;
        q.pop();
        int next_mod = (mod + 1) % 3;
        for(auto nxt : edges[cur]) {
            if(visited[nxt][next_mod] != 0) continue;
            if(nxt == t && next_mod == 0) {
                assert((depth + 1) % 3 == 0);
                cout << (depth + 1) / 3 << endl;
                return 0;
            }
            q.push(MP(nxt, MP(next_mod, depth + 1)));
            visited[nxt][next_mod] = true;
        }
    }
    cout << res << endl;
}