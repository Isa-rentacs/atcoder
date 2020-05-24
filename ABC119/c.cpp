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

int stick[8];

int calc(vector<int> &hist, int a, int b, int c)
{
    int len[4] = {};
    int cnt[4] = {};
    for(int i=0;i<hist.size();++i)
    {
        len[hist[i]] += stick[i];
        cnt[hist[i]]++;
    }
    if(cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0) return 1 << 30;

    return abs(a - len[1]) + abs(b - len[2]) + abs(c - len[3]) + 10 * (cnt[1] + cnt[2] + cnt[3] - 3);
}
int dfs(vector<int> &hist, int n, int a, int b, int c)
{
    int ret = 1 << 30;
    if(hist.size() == n)
    {
        return calc(hist, a, b, c);
    }

    for(int i=0;i<4;i++)
    {
        hist.push_back(i);
        ret = min(ret, dfs(hist, n, a, b, c));
        hist.pop_back();
    }

    return ret;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    for(int i=0;i<n;++i)
    {
        cin >> stick[i];
    }
    vector<int> hist;

    cout << dfs(hist, n, a, b, c) << endl;
}