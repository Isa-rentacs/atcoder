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
ll dp[3][2020] = {};
int main(){
    std::ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int cur = 0;
    int nxt = 1;
    ll ret = 0;
    int len = s.length();
    for(int i=0;i<len;++i){
        int digit = s[i] - '0';
        //dump(digit)
        dp[nxt][digit] += 1;
        for(int j=0;j<2019;++j)
        {
            int mod = (j * 10 + digit) % 2019;
            dp[nxt][mod] += dp[cur][j];
        }
        ret += dp[nxt][0];
        cur = 1 - cur;
        nxt = 1 - nxt;
        for(int j=0;j<2019;++j)
        {
            dp[nxt][j] = 0;
        }
    }

    cout << ret << endl;
}