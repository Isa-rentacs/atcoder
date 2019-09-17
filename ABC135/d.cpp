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

ll dp[100002][13] = {};

int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    dp[0][0] = 1;
    int n = s.length();
    int base = 1;
    for(int i=1;i<=n;++i)
    {
        int index = n - i;
        if(s[index] == '?')
        {
            for(int j=0;j<=9;++j)
            {
                for(int k=0;k<13;++k)
                {
                    dp[i][(k + j * base) % 13] += dp[i-1][k];
                    dp[i][(k + j * base) % 13] %= MOD;
                }
            }
        }
        else
        {
            int offset = s[index] - '0';
            for(int j=0;j<13;++j)
            {
                dp[i][(j + offset * base) % 13] += dp[i-1][j];
                dp[i][(j + offset * base) % 13] %= MOD;
            }
        }
        base = base * 10 % 13;
    }

    cout << dp[n][5] << endl;
}