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

// A = 0, C = 1, G = 2, T = 3
ll dp[101][4][4][4] = {};

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    dp[0][0][0][0] = 1;
    dp[0][0][0][1] = 1;
    dp[0][0][0][2] = 1;
    dp[0][0][0][3] = 1;

    for(int i=0;i<n-1;++i){
        for(int j=0;j<4;++j){
            for(int k=0;k<4;++k){
                for(int l=0;l<4;++l){
                    for(int m=0;m<4;++m){
                        if(i >= 2 && j == 0 && k == 2 && m == 1) continue; // AGXC
                        if(i >= 2 && j == 0 && l == 2 && m == 1) continue; // AXGC
                        if(i >= 1 && k == 0 && l == 2 && m == 1) continue; // AGC
                        if(i >= 1 && k == 2 && l == 0 && m == 1) continue; // GAC
                        if(i >= 1 && k == 0 && l == 1 && m == 2) continue; // ACG

                        dp[i+1][k][l][m] += dp[i][j][k][l] % MOD;
                        dp[i+1][k][l][m] %= MOD;
                        //cerr << "(" << i + 1 << "," << k << "," << l << "," << m << ") = " << dp[i+1][k][l][m] << endl;
                    }
                }
            }
        }
    }
    ll ret = 0;
    for(int i=0;i<4;++i){
        for(int j=0;j<4;++j){
            for(int k=0;k<4;++k){
                ret += dp[n-1][i][j][k];
                ret %= MOD;
            }
        }
    }
    cout << ret << endl;
}