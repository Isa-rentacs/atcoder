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
    int _a, _b, m;
    cin >> _a >> _b >> m;
    int a[_a] = {};
    int b[_b] = {};
    int x[m] = {};
    int y[m] = {};
    int c[m] = {};
    int min_a = 1 << 30;
    int min_b = 1 << 30;
    int ret = 0;
    for(int i=0;i<_a;++i)
    {
        cin >> a[i];
        min_a = min(min_a, a[i]);
    }

    for(int i=0;i<_b;++i)
    {
        cin >> b[i];
        min_b = min(min_b, b[i]);
    }
    ret = min_a + min_b;
    for(int i=0;i<m;++i)
    {
        cin >> x[i] >> y[i] >> c[i];
        x[i]--;
        y[i]--;
        ret = min(ret, a[x[i]] + b[y[i]] - c[i]);
    }

    cout << ret << endl;
}