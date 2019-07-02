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
    int mask[10] = {};
    int p[10] = {};
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;++i)
    {
        int k;
        int _mask = 0;
        cin >> k;
        for(int j=0;j<k;++j)
        {
            int tmp;
            cin >> tmp;
            _mask |= 1 << (tmp - 1);
        }
        mask[i] = _mask;
    }

    for(int i=0;i<m;++i)
    {
        cin >> p[i];
    }

    int ret = 0;
    for(int i=0;i<(1<<n);++i)
    {
        bool ok = true;
        for(int j=0;j<m;++j)
        {
            int lit = i & mask[j];
            int litCount = 0;
            while(lit > 0)
            {
                litCount += lit & 1;
                lit >>= 1;
            }
            if ((litCount % 2) != p[j])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            ret++;
        }
    }
    cout << ret << endl;
}