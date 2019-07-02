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
    int n;
    cin >> n;
    map<int, vector<pair<int,ll>>> m;
    for(int i=0;i<n-1;++i)
    {
        int src, dst, cost;
        cin >> src >> dst >> cost;
        m[src-1].PB(MP(dst-1, cost));
        m[dst-1].PB(MP(src-1, cost));
    }

    bool visited[n] = {};
    int color[n] = {};
    visited[0] = true;

    deque<int> q;
    q.push_back(0);

    while(!q.empty())
    {
        int start = q.front();
        q.pop_front();
        auto links = m[start];

        for(const auto& link : links)
        {
            int dst = link.first;
            ll cost = link.second;

            if(!visited[dst])
            {
                if ((cost % 2) == 0)
                {
                    color[dst] = color[start];
                }
                else
                {
                    color[dst] = 1 - color[start];
                }

                q.push_back(dst);
                visited[dst] = true;
            }
        }
    }

    for(int i=0;i<n;++i)
    {
        cout << color[i] << endl;
    }
}