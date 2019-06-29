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
#define MOD 1000000007
inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}

int dp_blue[2001][2001];
int dp_red[2001][2001];
int main(){
    std::ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int cnt_blue = k;
    int cnt_red = n - k;

    // dp for blue
    dp_blue[1][1] = 1;

    for(int i=1;i<cnt_blue;++i)
    {
        for(int j=0;j<=cnt_blue;++j)
        {
            dp_blue[i+1][j] += dp_blue[i][j] % MOD; // add to an existing group
            dp_blue[i+1][j] %= MOD;
            dp_blue[i+1][j+1] += dp_blue[i][j] % MOD; // create a new group
            dp_blue[i+1][j+1] %= MOD;
        }
    }

    // dp for red
    dp_red[1][1] = 1;
    if(n==k)
    {
        dp_red[0][0] = 1;
    }
    for(int i=1;i<cnt_red;++i)
    {
        for(int j=0;j<=cnt_red;++j)
        {
            dp_red[i+1][j] += dp_red[i][j] % MOD; // add to an existing group
            dp_red[i+1][j] %= MOD;
            dp_red[i+1][j+1] += dp_red[i][j] % MOD; // create a new group
            dp_red[i+1][j+1] %= MOD;
        }
    }

    for(int i=1;i<=k;++i)
    {
        ll ret = 0;
        ll blue_ptn = dp_blue[k][i];
        ll red_minus1 = (blue_ptn * dp_red[n-k][i-1]) % MOD;
        ll red_same = (blue_ptn * dp_red[n-k][i] * 2) % MOD;
        ll red_plus1 = (blue_ptn * dp_red[n-k][i+1]) % MOD;
        ret = (red_minus1 + red_same + red_plus1) % MOD;
        cout << ret << endl;
    }
}