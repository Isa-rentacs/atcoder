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

int a[50], b[50], c[50], d[50];

int calc(vector<int> &sol, int q)
{
    int ret = 0;
    for(int i=0;i<q;++i)
    {
        if((sol[b[i]] - sol[a[i]]) == c[i]) ret += d[i];
    }
    return ret;
}

int dfs(int pos, int n, int m, int q, vector<int> &sol)
{
    if(pos == n)
    {
        return calc(sol,q);
    }
    int start = sol.back();
    int ret = -1;
    for(int i = start; i<=m;++i)
    {
        sol.push_back(i);
        ret = max(ret, dfs(pos+1, n, m, q, sol));
        sol.pop_back();
    }

    return ret;
}

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> sol;
    for(int i=0;i<q;++i)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    int ret = -1;
    for(int i=1;i<=m;++i)
    {
        sol.push_back(i);
        ret = max(dfs(1, n, m, q, sol), ret);
        sol.pop_back();
    }

    cout << ret << endl;
}