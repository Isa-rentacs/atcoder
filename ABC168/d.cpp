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

vector<int> edges[100001];
int dst[100001];

int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for(int i=0;i<n;++i)
    {
        dst[i] = -1;
    }
    
    deque<int> q;
    q.push_back(0);
    dst[0] = 0;

    while(!q.empty())
    {
        int current = q.front();
        q.pop_front();

        for(int next: edges[current])
        {
            if(dst[next] != -1)
            {
                // already visited
                continue;
            }

            dst[next] = current;
            q.push_back(next);
        }
    }

    cout << "Yes" << endl;
    for(int i=1;i<n;++i)
    {
        cout << (dst[i] + 1) << endl;
    }
}