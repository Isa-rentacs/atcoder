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
    int n,m,tmp;
    cin >> n >> m;
    vector<int> x(m, 0);
    vector<int> dist(m-1, 0);
    for(int i=0;i<m;++i)
    {
        cin >> tmp;
        x[i] = tmp;
    }

    sort(x.begin(), x.end());

    for(int i=1;i<m;++i)
    {
        dist[i-1] = x[i] - x[i-1];
    }
    sort(dist.rbegin(), dist.rend());

    int ans = 0;
    for(int i=0;i<m-1;i++)
    {
        if(i < n-1)
        {
            continue;
        }
        ans += dist[i];
    }

    cout << ans << endl;
}