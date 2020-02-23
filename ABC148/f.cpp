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
    int n, u, v;
    cin >> n >> u >> v;
    u--; v--;
    vector<set<int>> edges(n);
    vector<int> dist_u(n, -1);
    vector<int> dist_v(n, -1);
    for(int i=0;i<n-1;++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a-1].insert(b-1);
        edges[b-1].insert(a-1);
    }
    int dist_u_v = 0;
    deque<pair<int,int>> q;
    q.push_back(MP(u, 0));
    while(!q.empty())
    {
        int current = q.front().first;
        int dist = q.front().second;
        q.pop_front();
        dist_u[current] = dist;
        for(const auto& nxt: edges[current]) {
            if(dist_u[nxt] == -1) q.push_back(MP(nxt, dist + 1));
        }
    }

    q.push_back(MP(v, 0));
    while(!q.empty())
    {
        int current = q.front().first;
        int dist = q.front().second;
        q.pop_front();
        dist_v[current] = dist;
        for(const auto& nxt: edges[current]) {
            if(dist_v[nxt] == -1) q.push_back(MP(nxt, dist + 1));
        }
    }
    int cand = -1;
    for(int i=0;i<n;++i)
    {
        if(dist_u[i] < dist_v[i]) {
            cand = max(cand, dist_u[i] + (dist_v[i] - dist_u[i] - 1));
        }
    }

    cout << cand << endl;
}