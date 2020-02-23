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

    string n;
    int k;
    cin >> n >> k;
    int len = n.length();
    // dp[pos][# of non-zero][OK=0/NG=1]
    ll dp[len][4][2] = {};
    for(int i=0;i<len;++i) {
        int current_val = n[i] - '0';
        if (i == 0) {
            dp[i][1][0] = current_val - 1;
            dp[i][1][1] = 1;
        } else {
            dp[i][1][0] += 9 + dp[i-1][1][0];
            if(current_val != 0) {
                // append 0 makes NG -> OK
                dp[i][1][0] += dp[i-1][1][1];
            } else {
                // append 0 makes NG -> NG
                dp[i][1][1] += dp[i-1][1][1];
            }
            for(int j=2;j<=3;++j) {
                // OK -> OK with 1-9
                dp[i][j][0] += dp[i-1][j-1][0] * 9;
                // OK -> OK with 0
                dp[i][j][0] += dp[i-1][j][0];
                if(current_val == 0)
                {
                    // append 0 makes NG -> NG, no other values are possible
                    dp[i][j][1] += dp[i-1][j][1];
                }
                else
                {
                    // append 0 makes NG -> OK
                    dp[i][j][0] += dp[i-1][j][1];
                    dp[i][j][0] += dp[i-1][j-1][1] * (current_val - 1);
                    // append current_val makes NG -> NG;
                    dp[i][j][1] += dp[i-1][j-1][1];
                }
            }
        }
    }
    cout << dp[len-1][k][0] + dp[len-1][k][1] << endl;
}