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
    ll h,w,n,a,b;
    map<pair<int,int>, int> counts;
    cin >> h >> w >> n;
    for(int i=0;i<n;++i)
    {
        cin >> a >> b;
        a--;
        b--;
        for(int x=-1;x<=1;++x)
        {
            for(int y=-1;y<=1;++y)
            {
                if((0 < (a+x) && (a+x) < h-1) && (0 < (b+y) && (b+y) < w-1))
                {
                    counts[MP(a+x, b+y)] += 1;
                }
            }
        }
    }
    ll ret[10] = {};
    ll sum_black = 0;
    for(auto& pair : counts)
    {
        //cout << pair.first.first << " " << pair.first.second << " " << pair.second << endl;
        ret[pair.second]++;
        sum_black++;
    }
    ret[0] = (h-2) * (w-2) - sum_black;
    for(int i=0;i<10;i++)
    {
        cout << ret[i] << endl;
    }
}
