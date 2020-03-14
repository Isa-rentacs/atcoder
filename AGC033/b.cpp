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
    int h,w,n,r,c,_r,_c;
    cin >> h >> w >> n >> r >> c;
    --r;
    --c;
    _r = r;
    _c = c;
    string s, t;
    cin >> s >> t;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    char _s[4] = {'R', 'U', 'L', 'D'};
    char _t[4] = {'L', 'D', 'R', 'U'};
    int ret = true;
    for(int dir=0;dir<4;++dir)
    {
        r = _r;
        c = _c;
        int cur_pos = dir % 2 ? r : c;
        int max_allowed = dir % 2 ? h : w;
        // s: try to remove, t: try to stay
        for(int i=0;i<n;++i)
        {
            if(s[i] == _s[dir])
            {
                cur_pos += dir % 2 ? dy[dir] : dx[dir];
            }

            if(cur_pos < 0 || max_allowed <= cur_pos)
            {
                ret = false;
                break;
            }

            if(t[i] == _t[dir])
            {
                int delta = dir % 2 ? dy[dir] : dx[dir];
                if(0 <= (cur_pos - delta) && (cur_pos - delta) < max_allowed)
                {
                    cur_pos -= delta;
                }
            }
        }
        if (!ret)
        {
            break;
        }
    }

    cout << (ret ? "YES" : "NO") << endl;
}