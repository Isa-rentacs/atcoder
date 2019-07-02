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
    int n, k;
    cin >> n >> k;
    double dp[2][k+1];
    int cur = 0;
    int nxt = 1;

    for(int i=0;i<2;++i)
    {
        for(int j=0;j<k+1;++j)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=1;i<=n;++i){
        dp[cur][min(i, k)] += 1.0 / n;
    }

    while(true)
    {
        // printf("====================\n");
        // for(int i=0;i<=k;++i)
        // {
        //     printf("%lf\n", dp[cur][i]);
        // }
        // printf("====================\n");

        double remaining = 0;
        for(int i=1;i<k;++i)
        {
            remaining += dp[cur][i];
        }

        if(remaining < 1e-12)
        {
            break;
        }
        dp[nxt][0] += dp[cur][0];
        dp[nxt][k] += dp[cur][k];
        for(int i=1;i<k;++i)
        {
            int next_score = min(i * 2, k);
            dp[nxt][next_score] += 0.5 * dp[cur][i];
            dp[nxt][0] += 0.5 * dp[cur][i];
        }
        
        for(int i=0;i<=k;++i)
        {
            dp[cur][i] = 0;
        }

        cur = 1 - cur;
        nxt = 1 - nxt;
    }

    printf("%.12lf\n", dp[cur][k]);
}