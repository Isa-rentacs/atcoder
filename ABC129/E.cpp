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

int main(){
    std::ios::sync_with_stdio(false);
    string input;
    cin >> input;
    ll dp[100002][2] = {};
    dp[0][0] = 1;
    dp[0][1] = 2;
    int len = input.length();

    for(int i=1;i<len;++i)
    {
        char c = input[i];
        dp[i][0] += dp[i-1][0] * 3;
        dp[i][0] %= MOD;
        if (c == '1'){
            dp[i][0] += dp[i-1][1]; 
            dp[i][0] %= MOD;
            dp[i][1] += dp[i-1][1] * 2;
        }else{
            dp[i][1] += dp[i-1][1];
        }
        dp[i][1] %= MOD;
    }

    cout << (dp[len-1][0] + dp[len-1][1])  % MOD << endl;
}