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

#define dump(x) cerr << #x << " = " << (x) << endl;
#define PB push_back
#define MP make_pair
#define ll long long

inline int toInt(string s)
{
    int v;
    istringstream sin(s);
    sin >> v;
    return v;
}
template <class T>
inline string toString(T x)
{
    ostringstream sout;
    sout << x;
    return sout.str();
}

int visited_depth[201];
int res = 0;
bool check_loop(vector<string> &s, int prev, int node, int n, int odd)
{
    visited_depth[node] = odd;
    bool ret = false;
    for (int i = 0; i < n; i++)
    {
        if (s[node][i] == '1')
        {
            if (i != prev)
            {
                if (visited_depth[i] != -1)
                {
                    if ((1-visited_depth[node]) != visited_depth[i])
                    {
                        return true;
                    }
                }
                else
                {
                    ret = ret || check_loop(s, node, i, n, 1 - odd);
                }
            }
        }
    }
    return ret;
}

int main()
{
    std::ios::sync_with_stdio(false);
    // check there's no loop
    int n;
    cin >> n;
    vector<string> s(n);
    int dist[n][n] = {};
    for (int i = 0; i < n; ++i)
    {
        visited_depth[i] = -1;
        cin >> s[i];
        for (int j = 0; j < n; ++j)
        {
            int tmp = s[i][j] - '0';
            if (tmp == 0)
            {
                if (i == j)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    dist[i][j] = 1 << 29;
                }
            }
            else
            {
                dist[i][j] = 1;
            }
        }
    }
    if (check_loop(s, -1, 0, n, 0))
    {
        cout << -1 << endl;
        return 0;
    }

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int max_len = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            max_len = max(max_len, dist[i][j]);
        }
    }
    cout << max_len + 1 << endl;
}