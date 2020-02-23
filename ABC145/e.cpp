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

bool predication(const pair<int,int> &a, const pair<int,int> &b){
    return a.first < b.first;
}

int dpl[3003][3002] = {};
int dpr[3003][3002] = {};

int main(){
    std::ios::sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    int a[n] = {};
    int b[n] = {};
    vector<pair<int,int>> vpii;
    for(int i=0;i<n;++i)
    {
        cin >> a[i] >> b[i];
        vpii.push_back(MP(a[i], b[i]));
    }

    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<t;++j)
        {
            dpl[i][j] = max(dpl[i][j], dpl[i-1][j]);
            if(j + vpii[i-1].first <= t) {
                dpl[i][j + vpii[i-1].first] = max(dpl[i][j + vpii[i-1].first], dpl[i-1][j] + vpii[i-1].second);
            }
        }
    }

    for(int i=n;i>0;--i) {
        for(int j=0;j<t;++j)
        {
            dpr[i][j] = max(dpr[i][j], dpr[i+1][j]);
            if(j + vpii[i-1].first <= t) {
                dpr[i][j + vpii[i-1].first] = max(dpr[i][j + vpii[i-1].first], dpr[i+1][j] + vpii[i-1].second);
            }
        }
    }
    int res = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<t;++j)
        {
            res = max(res, dpl[i][j] + dpr[i+2][t - j - 1] + vpii[i].second);
        }
    }
    cout << res << endl;
}