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
    int n, k, a, b;
    cin >> n >> k;
    map<int,vector<int>> edges;
    int colors[n] = {};
    fill(colors, colors+n, -1);
    for(int i=0;i<n-1;++i)
    {
        cin >> a >> b;
        // make 0-indexed
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<pair<int,pair<int,int>>> q;
    q.push(MP(0, MP(0, 0)));
    while(!q.empty()){
        auto front = q.front();
        int index = front.first;
        int depth = front.second.first;
        int sibling = front.second.second;
        q.pop();
        if(depth == 0) {
            colors[index] = k;
        } else if (depth == 1)
        {
            colors[index] = k - 1 - sibling;
        } else
        {
            colors[index] = k - 2 - sibling;
        }
        int sibling_count = 0;
        for(int i=0;i<edges[index].size();++i)
        {
            if(colors[edges[index][i]] == -1)
            {
                q.push(MP(edges[index][i], MP(depth + 1, sibling_count)));
                sibling_count++;
            }
        }        
    }

    ll res = 1;
    for(int i=0;i<n;++i)
    {
        res *= colors[i];
        res %= 1000000007;
    }
    cout << res << endl;
}