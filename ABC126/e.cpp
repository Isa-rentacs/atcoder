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
    int n,m,x,y,z;
    cin >> n >> m;
    vector<int> edges[n];
    for(int i=0;i<m;++i)
    {
        cin >> x >> y >> z;
        x--;
        y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    bool visited[n] = {};
    int res = 0;
    for(int i=0;i<n;++i)
    {
        if(!visited[i])
        {
            res++;
            deque<int> q;
            q.push_back(i);
            visited[i] = true;
            while(!q.empty())
            {
                int src = q.front();
                q.pop_front();
                for(int dst: edges[src])
                {
                    if(!visited[dst])
                    {
                        visited[dst] = true;
                        q.push_back(dst);
                    }
                }
            }
        }
    }
    cout << res << endl;

}