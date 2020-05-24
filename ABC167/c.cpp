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
    int n, m, x;
    cin >> n >> m >> x;
    int cost[n] = {};
    int plus[n][m] = {};

    for(int i=0;i<n;++i)
    {
        cin >> cost[i];
        for(int j=0;j<m;++j)
        {
            cin >> plus[i][j];
        }
    }
    int ret = 1 << 30;
    for(int i = 0; i < (1 << n);++i)
    {
        int tmp_cost = 0;
        int score[m] = {};
        for(int j=0;j<n;++j)
        {
            if((i & (1 << j)) != 0)
            {
                tmp_cost += cost[j];
                for(int k=0;k<m;++k)
                {
                    score[k] += plus[j][k];
                }
            }
        }
        bool ok = true;
        for(int j=0;j<m;++j)
        {
            if(score[j] < x)
            {
                ok = false;
            }
        }
        if(ok){
            ret = min(ret, tmp_cost);
        }
    }
    if(ret == (1<<30))
    {
        cout << -1 << endl;
    }else{
        cout << ret << endl;
    }
}