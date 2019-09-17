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
#include <unordered_set>
using namespace std;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
int depth[2][100001];
int main(){
    std::ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n;
    vector<int> edges[n];
    for(int i=0;i<n-1;++i)
    {
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<n;++j)
        {
            depth[i][j] = 1 << 30;
        }
    }
    // bfs for black
    deque<int> q;
    q.push_back(0);
    depth[0][0] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop_front();
        for(const int nxt: edges[cur])
        {
            if(nxt == n-1) continue;
            if(depth[0][nxt] == 1 << 30)
            {
                q.push_back(nxt);
            }

            depth[0][nxt] = min(depth[0][nxt], depth[0][cur] + 1);
            
        }
    }
    q.push_back(n-1);
    depth[1][n-1] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop_front();
        for(const int nxt: edges[cur])
        {
            if(nxt == 0) continue;
            if(depth[1][nxt] == 1 << 30)
            {
                q.push_back(nxt);
            }
            depth[1][nxt] = min(depth[1][nxt], depth[1][cur] + 1);
        }
    }

    int black_count = 0;
    int white_count = 0;
    for(int i=0;i<n;++i)
    {
        //cerr << depth[0][i] << " " << depth[1][i] << endl;
        if(depth[0][i] <= depth[1][i])
        {
            black_count++;
        }
        else
        {
            white_count++;
        }
        
    }
    //cerr << black_count << " " << white_count << endl;
    if(black_count > white_count)
    {
        cout << "Fennec" << endl;
    }
    else
    {
        cout << "Snuke" << endl;
    }
    


}