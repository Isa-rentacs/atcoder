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

bool visited[401][401];
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, -1, 0, 1};
int h, w;

pair<ll,ll> dfs(int r, int c, vector<string> &map)
{
    ll black = 0, white = 0, nr, nc;
    char current_color = map[r][c];
    if(current_color == '.')
    {
        white++;
    } 
    else
    {
        black++;
    }

    visited[r][c] = true;
    for(int i=0;i<4;++i)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if((nr < 0 || h <= nr) ||
           (nc < 0 || w <= nc)) continue;
        if(visited[nr][nc]) continue;
        char next_color = map[nr][nc];
        if(current_color == next_color) continue;
        // dump(nr)
        // dump(nc)
        auto tmp = dfs(nr, nc, map);
        black += tmp.first;
        white += tmp.second;
    }

    return MP(black, white);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin >> h >> w;
    vector<string> map;
    string tmp;
    for(int i=0;i<h;++i)
    {
        cin >> tmp;
        map.push_back(tmp);
    }
    ll ret = 0;
    for(int i=0;i<h;++i)
    {
        for(int j=0;j<w;++j)
        {
            if(!visited[i][j])
            {
                auto pair = dfs(i, j, map);
                // dump(pair.first)
                // dump(pair.second)
                ret += (ll)(pair.first) * (pair.second);
            }
        }
    }

    cout << ret << endl;
}